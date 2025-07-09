#pragma once
#include "functions.h"

namespace game
{
	namespace features
	{
		namespace account
		{
			struct varrs
			{
				int prestige;
			};
			varrs vars;

			void unlockall()
			{
				if (helpers::isingame())
					return;

				if (CURGAME == MW2)
				{

				}

				if (CURGAME == BO2)
				{

				}
			}

			void setprestige()
			{
				if (helpers::isingame())
					return;

				if (CURGAME == MW2)
				{
					*(char*)0x831A0DD4 = features::account::vars.prestige;
				}

				if (CURGAME == BO2)
				{
					*(char*)0x843491A4 = features::account::vars.prestige;
					Cbuf_AddText(0, "updategamerprofile;uploadstats;");
				}
			}

			void gamertagthread()
			{
				char buf[32];

				XUSER_SIGNIN_INFO ui;
				ZeroMemory(&ui, sizeof(XUSER_SIGNIN_INFO));

				if (XUserGetSigninInfo(0, XUSER_GET_SIGNIN_INFO_ONLINE_XUID_ONLY, &ui) == ERROR_SUCCESS)
				{
					XOVERLAPPED ol;
					WCHAR val[32];
					ZeroMemory(&ol, sizeof(ol));
					XShowKeyboardUI(0, VKBD_HIGHLIGHT_TEXT, L"", L"Desire", L"Enter a custom Gamertag", val, 32, &ol);

					while (!XHasOverlappedIoCompleted(&ol))
					{
						Sleep(25);
					}

					wcstombs(buf, val, 32);

					if (CURGAME == MW2)
					{
						std::strcpy((char*)0x838BA824, buf);
					}

					if (CURGAME == BO2)
					{
						BYTE o[] = { 0x7C, 0x83, 0x23, 0x78, 0x3D, 0x60, 0x82, 0xC5, 0x38, 0x8B, 0x5D, 0x60, 0x3D, 0x60, 0x82, 0x4A, 0x39, 0x6B, 0xDC, 0xA0, 0x38, 0xA0, 0x00, 0x20, 0x7D, 0x69, 0x03, 0xA6, 0x4E, 0x80, 0x04, 0x20 };
						BYTE t[] = { 0x3D, 0x60, 0x82, 0xC5, 0x39, 0x6B, 0x5D, 0x00, 0x7D, 0x69, 0x03, 0xA6, 0x4E, 0x80, 0x04, 0x20 };
						BYTE tt[] = { 0x00 };
						BYTE f[] = { 0x40 };
						SetMemory((PVOID)0x82C55D00, o, 32);
						SetMemory((PVOID)0x8293D724, t, 16);
						SetMemory((PVOID)0x8259B6A7, tt, 1);
						SetMemory((PVOID)0x822D1110, f, 1);

						std::strcpy((char*)0x82C55D60, buf);
						std::strcpy((char*)0x841E1B30, buf);
					}
				}
			}

			void docustomgamertag()
			{
				if (helpers::isingame())
					return;

				ExCreateThread(0, 0, 0, 0, (LPTHREAD_START_ROUTINE)gamertagthread, 0, 0);
			}

			void resetgamertag()
			{
				XUSER_SIGNIN_INFO userInfo; ZeroMemory(&userInfo, sizeof(XUSER_SIGNIN_INFO));
				if (XUserGetSigninInfo(0, XUSER_GET_SIGNIN_INFO_ONLINE_XUID_ONLY, &userInfo) == ERROR_SUCCESS)
				{
					char ResetName[32];
					sprintf(ResetName, "%s", userInfo.szUserName);

					if (CURGAME == MW2)
					{
						std::strcpy((char*)0x838BA824, ResetName);
					}

					if (CURGAME == BO2)
					{
						BYTE o[] = { 0x7C, 0x83, 0x23, 0x78, 0x3D, 0x60, 0x82, 0xC5, 0x38, 0x8B, 0x5D, 0x60, 0x3D, 0x60, 0x82, 0x4A, 0x39, 0x6B, 0xDC, 0xA0, 0x38, 0xA0, 0x00, 0x20, 0x7D, 0x69, 0x03, 0xA6, 0x4E, 0x80, 0x04, 0x20 };
						BYTE t[] = { 0x3D, 0x60, 0x82, 0xC5, 0x39, 0x6B, 0x5D, 0x00, 0x7D, 0x69, 0x03, 0xA6, 0x4E, 0x80, 0x04, 0x20 };
						BYTE tt[] = { 0x00 };
						BYTE f[] = { 0x40 };
						SetMemory((PVOID)0x82C55D00, o, 32);
						SetMemory((PVOID)0x8293D724, t, 16);
						SetMemory((PVOID)0x8259B6A7, tt, 1);
						SetMemory((PVOID)0x822D1110, f, 1);

						std::strcpy((char*)0x82C55D60, ResetName);
						std::strcpy((char*)0x841E1B30, ResetName);
					}
				}
			}
		}
	}
}