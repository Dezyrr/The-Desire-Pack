#include "includes.h"
#include "utilities.h"

std::uint32_t ResolveImport(const char* importName, std::int32_t index)
{
	HMODULE hMod = GetModuleHandleA(importName);
	return hMod ? (std::uint32_t)GetProcAddress(hMod, (LPCSTR)index) : NULL;
}
 
wchar_t* ConvertToWChar(const char* text)
{
	const size_t cSize = strlen(text) + 1;
	wchar_t* wc = new wchar_t[cSize];
	size_t tmp = 0;
	mbstowcs_s(&tmp, wc, cSize, text, cSize);
	return wc;
}

char* va(const char* fmt, ...)
{
	va_list argList;
	va_start(argList, fmt);
	char buffer[0x1000];
	vsprintf(buffer, fmt, argList);
	va_end(argList);
	return buffer;
	delete[] buffer;
}

char* concat(const char* text, ...)
{
	va_list list;
	char buffer[0x1000];
	va_start(list, text);
	vsprintf(buffer, text, list);
	va_end(list);
	char* result = (char*)malloc(strlen(buffer) + 1);
	strcpy(result, buffer);

	return result;
}

size_t GetStringLength(const char* address)
{
	if (!address) return 0;
	return std::strlen(address);
}

void NullString(void* address)
{
	if (!address) return;

	size_t length = GetStringLength((const char*)address);

	for (size_t i = 0; i < length; ++i)
	{
		*((uint8_t*)address + i) = 0x00;
	}
}

void SetMemoryString(unsigned int address, const char* str, size_t size)
{
	if (!address || !str || size == 0)
		return;

	std::memset((void*)address, 0, size);

	std::strncpy((char*)address, str, size - 1);
}

void SetMemoryRawString(void* dest, const char* src)
{
	if (!dest || !src)
		return;

	size_t length = std::strlen(src) + 1;

	std::memcpy(dest, src, length);
}

HRESULT SetMemory(VOID* Destination, VOID* Source, DWORD Length) 
{
	memcpy(Destination, Source, Length);
	return ERROR_SUCCESS;
}

BOOL FileExists(CONST PCHAR FilePath)
{
	if (GetFileAttributes(FilePath) == -1)
	{
		DWORD LastError = GetLastError();

		if (LastError == ERROR_FILE_NOT_FOUND || LastError == ERROR_PATH_NOT_FOUND)
			return FALSE;
	}

	return TRUE;
}


XINPUT_STATE Buttons;
bool KeyIsDown(XINPUT_STATE xState, short button)
{
	return (xState.Gamepad.wButtons & button) ? true : false;
}


byte* stubAlloc = NULL;
bool stubSpaceUsed[0x200];

DWORD* AllocateStubSpace() {
	for (int i = 0; i < sizeof stubSpaceUsed; i++) {
		if (!stubSpaceUsed[i]) {
			stubSpaceUsed[i] = true;
			return (DWORD*)(stubAlloc + i * 0x80);
		}
	}

	Sleep(1000);
	ExitThread(-1);
}
void FreeStub(void* stub) {
	if ((DWORD)stub < (DWORD)stubAlloc
		|| (DWORD)stub >= (DWORD)(stubAlloc + 0x10000))
		return;

	memset((void*)((DWORD)stub & ~0x7F), 0, 0x80);
	stubSpaceUsed[((DWORD)stub - (DWORD)stubAlloc) / 0x80] = false;
}

DWORD revertBranch(byte* addr, DWORD instr)
{
	return (instr < 0x4A000000) ? ((DWORD)addr + (instr & 0x3FFFFFE)) : ((DWORD)addr - (~instr & 0x3FFFFFE)) & ~3;
}

MinHook_t::MinHook_t(unsigned long address, unsigned long destination, bool stub)
{
	this->address = (unsigned long*)address;
	this->destination = destination;
	memcpy(this->originalStub, (void*)address, 0x10);

	if (stub) {
		if (!stubAlloc)
			stubAlloc = (byte*)XEncryptedAlloc(0x10000);

		this->saveStub = AllocateStubSpace();
		this->Stub = (StubCallback)this->saveStub;
	}
	else
		this->saveStub = NULL;
}

void MinHook_t::Start()
{
	if (this->address == NULL)
		return;

	if (this->saveStub != NULL)
	{
		DWORD* pFunc = (DWORD*)this->address;

		int stubSize = 4;
		for (int i = 0; i < 4; i++) {
			if ((pFunc[i] & 0xFC000002) == 0x48000000)
				stubSize += 4;
			else
				stubSize += 1;
		}

		for (int i = 0, stubIndex = 0; i < 4; i++) {
			if ((pFunc[i] & 0xFC000002) == 0x48000000) {
				DWORD calladdr = revertBranch((byte*)&pFunc[i], pFunc[i]);
				this->saveStub[stubIndex] = 0x3D600000 | (calladdr >> 16);
				this->saveStub[stubIndex + 1] = 0x616B0000 | (calladdr & 0xFFFF);
				this->saveStub[stubIndex + 2] = 0x7D6903A6;
				this->saveStub[stubIndex + 3] = 0x4E800421;
				stubIndex += 4;
			}
			else {
				this->saveStub[stubIndex] = pFunc[i];
				stubIndex++;
			}
		}

		DWORD jumpback = (DWORD)this->address + 0x10;
		this->saveStub[stubSize - 4] = 0x3D800000 | (jumpback >> 16); // lis r12, addrhi
		this->saveStub[stubSize - 3] = 0x618C0000 | (jumpback & 0xFFFF); // ori r12, r12, addrlo
		this->saveStub[stubSize - 2] = 0x7D8903A6; // mtctr r12
		this->saveStub[stubSize - 1] = 0x4E800420; // bctr
	}

	this->address[0] = ((this->destination & 0x8000) ? 0x3D600000 + (((this->destination >> 16) & 0xFFFF) + 1) : 0x3D600000 + ((this->destination >> 16) & 0xFFFF));
	this->address[1] = 0x396B0000 + (this->destination & 0xFFFF);
	this->address[2] = 0x7D6903A6;
	this->address[3] = 0x4E800420;
}

void MinHook_t::Stop()
{
	if (this->address)
		memcpy(this->address, this->originalStub, 0x10);

	if (this->saveStub)
		FreeStub(this->saveStub);
}

void MinHook_t::Clean()
{
	this->address = NULL;
}

std::map<const char*, MinHook_t> MinHook;

void stophooks()
{
	for each (auto min in MinHook)
	{
		min.second.Stop();
	}
}

void cleanhooks()
{
	for each (auto min in MinHook)
		min.second.Clean();
}

void starthooks()
{
	for each (auto min in MinHook)
		min.second.Start();
}

void XNotify(const char* text, XNOTIFYQUEUEUI_TYPE icon)
{
	XNotifyQueueUI(icon, 0xFF, XNOTIFY_SYSTEM, ConvertToWChar(text), 0);
}

float ScaledSize(float current, float base, float min, float factor, float distance)
{
	float Size = current + base - ((current / factor) * distance);

	if (Size > current)
		Size = current;

	if (Size < min)
		Size = min;
	return Size;
}

MinHook_t DetourAttach(void* func, void* dest)
{
	return MinHook_t((int)func, (std::uint64_t)dest, true);
}

void DetourRemove(const std::string& key, void* func, void* dest)
{
	MinHook[key.data()].Stop();
	MinHook[key.data()].Clean();
}

unsigned long ResolveFunction(const char* moduleName, unsigned long ordinal)
{
	HMODULE mHandle = GetModuleHandle(moduleName);

	return (mHandle == NULL) ? NULL : (unsigned long)GetProcAddress(mHandle, (LPCSTR)ordinal);
}

VOID XEXThread(LPTHREAD_START_ROUTINE Thread)
{
	HANDLE hThread;
	DWORD ThreadID;

	ExCreateThread(&hThread, 0, &ThreadID, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)Thread, 0, 2);
	XSetThreadProcessor(hThread, 4);
	ResumeThread(hThread);
	CloseHandle(hThread);
}

#define SYS_STRING "\\System??\\%s"
#define USR_STRING "\\??\\%s"

HRESULT doMountPath(const char* szDrive, const char* szDevice, const char* sysStr) {
	STRING DeviceName, LinkName;
	CHAR szDestinationDrive[MAX_PATH];
	sprintf_s(szDestinationDrive, MAX_PATH, sysStr, szDrive);
	RtlInitAnsiString(&DeviceName, szDevice); 
	RtlInitAnsiString(&LinkName, szDestinationDrive);
	ObDeleteSymbolicLink(&LinkName);
	return (HRESULT)ObCreateSymbolicLink(&LinkName, &DeviceName);
}

HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both) {
	HRESULT res;
	if (both)
	{
		res = doMountPath(szDrive, szDevice, SYS_STRING);
		res = doMountPath(szDrive, szDevice, USR_STRING);
	}
	else
	{
		if (KeGetCurrentProcessType() == 2) //SYSTEM_PROC
			res = doMountPath(szDrive, szDevice, SYS_STRING);
		else
			res = doMountPath(szDrive, szDevice, USR_STRING);
	}
	return res;
}

#pragma region Auth
std::vector<unsigned char> intToByteArray(const std::string& hexString)
{
	std::vector<unsigned char> byteArray;

	// If the number of characters is odd, add a leading '0'
	std::string formattedHexString = hexString;
	if (hexString.length() % 2 != 0)
		formattedHexString = "0" + formattedHexString;

	// Iterate through the hexadecimal string and convert every two characters to bytes
	for (size_t i = 0; i < formattedHexString.length(); i += 2)
	{
		std::string byteString = formattedHexString.substr(i, 2);
		unsigned char byte = static_cast<unsigned char>(std::stoul(byteString, nullptr, 16));
		byteArray.push_back(byte);
	}

	return byteArray;
}

int areArraysDifferent(const unsigned char* array1, const unsigned char* array2, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array1[i] != array2[i])
		{
			return 1;
		}
	}
	return 0;
}
#pragma endregion