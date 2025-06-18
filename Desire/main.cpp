#include "includes.h"
#include "hooks.h"

DWORD CurrentTitle;
bool DashLoaded, UnloadPlugin;
bool HasBeenOnDash = false;
DWORD(__cdecl* XamGetCurrentTitleID)() = (DWORD(__cdecl*)())ResolveFunction("xam.xex", 0x1CF);

namespace game
{
	bool moduleunloading()
	{
		return UnloadPlugin;
	}	

	int current_title = 0;
}

void titlecheck(DWORD TitleID)
{
	CurrentTitle = TitleID;

	game::current_title = TitleID;

	switch (TitleID)
	{
	case DASHBOARD:
		goto Dash;
		break;
	case MW2:
		if (!strcmp((char*)0x82001270, "multiplayer"))
		{
			Sleep(1500);
			MountPath("Hdd:", "\\Device\\Harddisk0\\Partition1", TRUE);

			XNotify("Desire's S&D Loaded! (MW2)", XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_SONGPLAYING);
			game::hooks::init();

			starthooks();
		}
		break;
	case BO2:
		if (!strcmp((char*)0x82003580, "multiplayer"))
		{
			Sleep(1500);
			MountPath("Hdd:", "\\Device\\Harddisk0\\Partition1", TRUE);

			XNotify("Desire's S&D Loaded! (BO2)", XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_SONGPLAYING);
			game::hooks::init();

			starthooks();
		}
		break;
	default:
		goto End;

	Dash:
		if (!DashLoaded)
		{
			if (!HasBeenOnDash)
			{
				HasBeenOnDash = true;
			}
			DashLoaded = true;
		}

		goto End;
		break;
	}

End:
	return;
}

DWORD titlemonitor()
{
	while (!UnloadPlugin)
	{
		if (XamGetCurrentTitleID() != CurrentTitle)
		{
			titlecheck(XamGetCurrentTitleID());
		}
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

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		HANDLE hThread;
		DWORD dwThreadId;
		ExCreateThread(&hThread, 0, &dwThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)titlemonitor, 0, 2 | CREATE_SUSPENDED);
		XSetThreadProcessor(hThread, 4);
		SetThreadPriority(hThread, THREAD_PRIORITY_NORMAL);
		ResumeThread(hThread);

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
