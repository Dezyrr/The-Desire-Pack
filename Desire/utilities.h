#ifndef UTILITIES_H
#define UTILITIES_H

#define ArraySize(arr) (sizeof(arr) / sizeof(arr[0]))

namespace Concurrency
{
	template <typename T>
	class Container
	{
	public:
		T& getRaw() { return object_; }
		const T& getRaw() const { return object_; }

	private:
		T object_;
	};
}

//std::uint32_t ResolveImport(const char* importName, std::int32_t index);
//void XNotify(const char* text, XNOTIFYQUEUEUI_TYPE icon = XNOTIFYUI_TYPE_PREFERRED_REVIEW);

char* va(const char* fmt, ...);
char* concat(const char* text, ...);
BOOL FileExists(CONST PCHAR FilePath);
HRESULT SetMemory(VOID* Destination, VOID* Source, DWORD Length);
template<typename T>
inline T GetMemory(void* pSource)
{
	if (pSource == nullptr)
	{
		return T();
	}

	return *static_cast<T*>(pSource);
}

template<typename T>
inline T GetMemory(uintptr_t address)
{
	return GetMemory<T>(reinterpret_cast<void*>(address));
}

extern XINPUT_STATE Buttons;
bool KeyIsDown(XINPUT_STATE xState, short button);
int auth();
typedef long long(*StubCallback)(...);

class MinHook_t
{
	unsigned long* address,
		* saveStub,
		destination,
		originalStub[4];

public:
	MinHook_t() {};
	MinHook_t(unsigned long address, unsigned long destination, bool stub);

	void Start();
	void Stop();
	void Clean();
	StubCallback Stub;
};

extern std::map<const char*, MinHook_t> MinHook;

void stophooks();
void cleanhooks();
void starthooks();

float ScaledSize(float current, float base, float min, float factor, float distance);
MinHook_t DetourAttach(void* func, void* dest);
void DetourRemove(const std::string& key, void* func, void* dest);

void XNotify(const char* text, XNOTIFYQUEUEUI_TYPE icon);
unsigned long ResolveFunction(const char* moduleName, unsigned long ordinal);
VOID XEXThread(LPTHREAD_START_ROUTINE Thread);
HRESULT doMountPath(const char* szDrive, const char* szDevice, const char* sysStr);
HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both);
int areArraysDifferent(const unsigned char* array1, const unsigned char* array2, int size);
class MemoryBuffer {
public:
	MemoryBuffer(DWORD Size = 0x200)
	{
		m_Buffer = 0;
		m_DataLength = 0;
		m_BufferSize = 0;
		if ((Size != 0) && (Size < UINT_MAX))
		{
			m_Buffer = (PBYTE)malloc(Size + 1);
			if (m_Buffer)
			{
				m_BufferSize = Size;
				m_Buffer[0] = 0;
			}
		}
	}
	~MemoryBuffer()
	{
		if (m_Buffer) free(m_Buffer);
		m_Buffer = 0;
		m_DataLength = 0;
		m_BufferSize = 0;
	}
	BOOL CheckSize(DWORD Size)
	{
		if (m_BufferSize >= (m_DataLength + Size)) return TRUE;
		else
		{
			DWORD NewSize = max((m_DataLength + Size), (m_BufferSize * 2));
			PBYTE NewBuffer = (PBYTE)realloc(m_Buffer, NewSize + 1);
			if (NewBuffer)
			{
				m_BufferSize = NewSize;
				m_Buffer = NewBuffer;
				return TRUE;
			}
			else return FALSE;
		}
	}
	VOID Add(CONST PVOID Buffer, DWORD Size)
	{
		if (CheckSize(Size))
		{
			memcpy(m_Buffer + m_DataLength, Buffer, Size);
			m_DataLength += Size;
			*(m_Buffer + m_DataLength) = 0;
		}
	}
	DWORD GetSize() CONST { return m_DataLength; }
	PBYTE GetBuffer() CONST { return m_Buffer; }
private:
	PBYTE m_Buffer;
	DWORD m_DataLength;
	DWORD m_BufferSize;
};
#endif