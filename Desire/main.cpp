#include "includes.h"
#include "hooks.h"

DWORD CurrentTitle;
bool DashLoaded;
volatile bool UnloadPlugin;
bool HasBeenOnDash = false;
DWORD(__cdecl* XamGetCurrentTitleID)() = (DWORD(__cdecl*)())ResolveFunction("xam.xex", 0x1CF);

namespace game
{
	bool moduleunloading()
	{
		return UnloadPlugin;
	}	

	int current_title = 0;

	PHANDLE camo_thread = nullptr;
	DWORD camo_threadid = 0;

	bool begin_set = false;

	int cached_host_idx = -1;
}

void titlecheck(DWORD TitleID)
{
	CurrentTitle = TitleID;

	game::current_title = TitleID;

	switch (TitleID)
	{
		case BOOTUP:
		{
			Sleep(1500);

			break;
		}

		case DASHBOARD:
		{
			if (!DashLoaded)
			{
				Sleep(1500);

				if (!HasBeenOnDash)
				{
					HasBeenOnDash = true;
				}

				DashLoaded = true;
			}

			break;
		}

		case MW2:
		{
			if (!strcmp((char*)0x82001270, "multiplayer"))
			{
				Sleep(1500);
				MountPath("hdd:", "\\Device\\Harddisk0\\Partition1", TRUE);

				game::hooks::init();
				starthooks();
			}

			break;
		}

		case BO2:
		{
			//if (!strcmp((char*)0x82003580, "multiplayer"))
			//{
				//Sleep(1500);
				//MountPath("hdd:", "\\Device\\Harddisk0\\Partition1", TRUE);

				//game::hooks::init();
				//starthooks();
			//}

			break;
		}

		default: break;
	}
}

DWORD titlemonitor()
{
	while (!UnloadPlugin)
	{
		if (XamGetCurrentTitleID() != CurrentTitle)
		{
			titlecheck(XamGetCurrentTitleID());
		}

		Sleep(100);
	}

	return 0;
}

void unhookgames()
{
	if (XamGetCurrentTitleID() == DASHBOARD)
	{

	}
	else if (XamGetCurrentTitleID() == MW2 && !strcmp((char*)0x82001270, "multiplayer"))
	{
		stophooks();
		cleanhooks();
	}
	else if (XamGetCurrentTitleID() == BO2 && !strcmp((char*)0x82003580, "multiplayer"))
	{
		stophooks();
		cleanhooks();
	}
}


MESSAGEBOX_RESULT result;
XOVERLAPPED ol;
DWORD dwResult = 0;
const wchar_t* message = L"Why are you trying to load a blacklisted module lil bro... i'm going to slime the absolute FUCK out of you";
LPCWSTR buttons[1] = { __w(L"FUCK, NOW I CAN'T FAKE SHOTS") };
auto title = __w(L"Desire's S&D (Dual Loading Detected)");

// honestly.. i dont think this is needed, i could've just done module names but fuck it
const DWORD whitelisted_checksums[] =
{
	0x16B651,   // xboxkrnl.exe
	0x4A9C52,   // xam.xex
	0x29EEE,    // launch.xex
	0x35690,    // ximecore.xex
	0x574BF,    // Xam.Community.xex
	0x30B16,    // hud.xex
	0x3C3A4,    // aac.xex
	0x1E0BB,    // xbdm.xex
	0x10080C,   // xbGuard.xex
	0x393C0,    // JRPC2.xex
	0x3479D,    // XDRPC.xex
	0x90CB,     // xosc9v2.xex
	0x1286E,    // xbGBypass.xex
	0x120E4,	// virtualkeyboard.xex (vk.xex)
	0x4FF43,	// Guide.Friends.xex
	0x690A6,	// Guide.Beacons.xex
	0x19434,	// Guide.ChatAndMessenger.xex
	0x326EA,    // gamerprofile.xex
	0xAAB81,	// Guide.MP.Payment.xex
	0x36E94,	// signin.xex
	0x1616F,	// Guide.PlayerFeedback.xex
};

const wchar_t* whitelisted_names[] =
{
	L"xrpc.xex",
	L"SNet.xex",
	L"gInterface.xex",
	L"default_mp.xex",
	L"Desire.xex",
	L"signin.xex",
	L"gamerprofile.xex",
	L"Guide.Friends.xex",
	L"Guide.Beacons.xex",
	L"Guide.ChatAndMessenger.xex",
	L"Guide.MP.Payment.xex",
	L"Guide.PlayerFeedback.xex"
};

const DWORD blacklisted_checksums[] =
{
	0x66156,   // jimbo
	0x44969,   // matrix
	0xB02FE,   // matrix
	0x2E8E4,   // medaka
	0x447DB,   // infinityloader
	0x244FA,   // shakemw2
	0x26F4B,   // shakemw2
	0x1226A5   // myten free
};

const LPCWSTR messages[] =
{
	L"So we're dual loading an azza with unsetup...?", // jimbo
	L"Dude tryna run matrix hahahahahahah faggot", // matrix
	L"Dude tryna run matrix hahahahahahah faggot", // matrix
	L"I have no words for this one.. medaka.. in the big 25..", // medaka
	L"So now you tryna load a shit gsc team menu aswell? wtf u doin bruh...", // infinityloader
	L"Bro is trying to load shake aswell like pick a pak bro", // shakemw2
	L"Bro is trying to load shake aswell like pick a pak bro", // shakemw2
	L"Aw hell nawww oohh ohhhhhh" // myten free
};

const LPCWSTR button[] =
{
	L"FUCK, NOW I CAN'T FAKE SHOTS",
	L"i'm sorry, blow up my console",
	L"i'm sorry, blow up my console",
	L"im a retard",
	L"my bad bro",
	L"my bad bro",
	L"my bad bro",
	L"im a retard"
};

void antitamper()
{
	while (!UnloadPlugin)
	{
		PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY)(*XexExecutableModuleHandle);
		if (!entry)
		{
			Sleep(5000);
			continue;
		}

		PLDR_DATA_TABLE_ENTRY firstentry = entry;
		bool shouldReboot = false;
		DWORD startTime = GetTickCount();

		do
		{
			if (!entry || !entry->BaseDllName.Buffer || entry->BaseDllName.Length == 0 || entry->BaseDllName.Length > 256)
			{
				entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;
				continue;
			}

			bool isWhitespaceOnly = true;
			for (size_t i = 0; i < entry->BaseDllName.Length / sizeof(wchar_t); i++)
			{
				if (!iswspace(entry->BaseDllName.Buffer[i]))
				{
					isWhitespaceOnly = false;
					break;
				}
			}
			if (isWhitespaceOnly)
			{
				entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;
				continue;
			}

			if (_wcsicmp(entry->BaseDllName.Buffer, L"Desire.xex") == 0 && entry->SizeOfFullImage != 0x3D000)
			{
				buttons[0] = L"i'm sorry, blow up my console";

				while (XShowMessageBoxUI(0, L"Desire's S&D (Anti Tamper)", L"Fuck we doin tryna modify shit in the module?\n\nBro tryna bypass dis shit cmon twin wtffffff\nthis really sad bro like cmon man wtf man just go spin around in circles in air and shit twin we dont gotta be doin all dis twin cmon bro", 1, buttons, 0, XMB_ERRORICON, &result, &ol) == ERROR_ACCESS_DENIED)
					Sleep(500);

				while (!XHasOverlappedIoCompleted(&ol))
					Sleep(500);

				if (result.dwButtonPressed == 0)
				{
					XLaunchNewImage(XLAUNCH_KEYWORD_DASH, 0);
				}

				shouldReboot = true;
				break;
			}

			entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;

			if (GetTickCount() - startTime > 1000)
				break;

		} while (entry && entry != firstentry);

		if (shouldReboot)
			return;

		Sleep(5000);
	}
}

void dualloadprotection()
{
	while (!UnloadPlugin)
	{
		PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY)(*XexExecutableModuleHandle);
		if (!entry)
		{
			Sleep(5000);
			continue;
		}

		PLDR_DATA_TABLE_ENTRY firstentry = entry;
		bool shouldReboot = false;
		DWORD startTime = GetTickCount();

		do
		{
			if (!entry || !entry->BaseDllName.Buffer || entry->BaseDllName.Length == 0 || entry->BaseDllName.Length > 256)
			{
				entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;
				continue;
			}

			bool isWhitespaceOnly = true;
			for (size_t i = 0; i < entry->BaseDllName.Length / sizeof(wchar_t); i++)
			{
				if (!iswspace(entry->BaseDllName.Buffer[i]))
				{
					isWhitespaceOnly = false;
					break;
				}
			}
			if (isWhitespaceOnly)
			{
				entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;
				continue;
			}

			bool whitelisted = false;
			if (entry->CheckSum == 0x0)
			{
				for (int i = 0; i < ARRAYSIZE(whitelisted_names); ++i)
				{
					if (_wcsicmp(entry->BaseDllName.Buffer, whitelisted_names[i]) == 0)
					{
						whitelisted = true;
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < ARRAYSIZE(whitelisted_checksums); ++i)
				{
					if (entry->CheckSum == whitelisted_checksums[i])
					{
						whitelisted = true;
						break;
					}
				}
			}

			if (!whitelisted)
			{
				char modulename[128] = { 0 };
				size_t converted = 0;
				wcstombs_s(&converted, modulename, sizeof(modulename), entry->BaseDllName.Buffer, min(entry->BaseDllName.Length / sizeof(wchar_t), 127));

				//printf("%s, 0x%X\n", modulename, entry->CheckSum);

				for (int i = 0; i < ARRAYSIZE(blacklisted_checksums); ++i)
				{
					if (entry->CheckSum == blacklisted_checksums[i])
					{
						message = messages[i];
						buttons[0] = button[i];
						break;
					}
				}

				while (XShowMessageBoxUI(0, title, message, 1, buttons, 0, XMB_ERRORICON, &result, &ol) == ERROR_ACCESS_DENIED)
					Sleep(500);

				while (!XHasOverlappedIoCompleted(&ol))
					Sleep(500);

				if (result.dwButtonPressed == 0)
				{
					XLaunchNewImage(XLAUNCH_KEYWORD_DASH, 0);
				}

				shouldReboot = true;
				break;
			}

			entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;

			if (GetTickCount() - startTime > 1000)
				break;

		} while (entry && entry != firstentry);

		if (shouldReboot)
			return;

		Sleep(5000);
	}
}

HANDLE hThread;
DWORD dwThreadId;

HANDLE moduleThread;
DWORD moduleThreadId;

HANDLE tamperThread;
DWORD tamperThreadId;
BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		// so many threads wow.... fuck me
		// i still dont know if this is safe on xbox 360, on pc i could spam threads and still be safe
		// xbox memory seems to be very delicate though

		ExCreateThread(&hThread, 0, &dwThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)titlemonitor, 0, 2 | CREATE_SUSPENDED);
		XSetThreadProcessor(hThread, 4);
		SetThreadPriority(hThread, THREAD_PRIORITY_NORMAL);
		ResumeThread(hThread);

		//ExCreateThread(&tamperThread, 0, &tamperThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)antitamper, 0, 2 | CREATE_SUSPENDED);
		//SetThreadPriority(tamperThread, THREAD_PRIORITY_BELOW_NORMAL);
		//ResumeThread(tamperThread);

		//ExCreateThread(&moduleThread, 0, &moduleThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)dualloadprotection, 0, 2 | CREATE_SUSPENDED);
		//SetThreadPriority(moduleThread, THREAD_PRIORITY_BELOW_NORMAL);
		//ResumeThread(moduleThread);

		titlecheck(XamGetCurrentTitleID());
	}

	if (dwReason == DLL_PROCESS_DETACH)
	{
		UnloadPlugin = true;
		unhookgames();
		Sleep(1500);
	}

	return true;
}
