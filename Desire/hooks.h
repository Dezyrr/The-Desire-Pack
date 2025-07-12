#pragma once
#include "includes.h"
#include "render.h"
#include "menu.h"
#include "teammenu.h"
#include "gsc.h"
#include "customisation.h"

#pragma warning(push)
#pragma warning(disable : 4214)
#include <xbdm.h>
#pragma warning(pop)

namespace game
{
	namespace hooks
	{
		void __declspec(naked) HvxGetVersions(int magic, int mode, unsigned addr, __int64 outBuff, DWORD length)
		{
			__asm
			{
				li    r0, 0
				sc
				blr
			}
		}

		// aciph
		bool spasticdetected()
		{
			BYTE cpukey[0x10] = { 0xD5, 0xB1, 0x8C, 0x80, 0xDC, 0x9A, 0x58, 0xCD, 0x83, 0xAA, 0x7A, 0x2A, 0xF3, 0x7B, 0x62, 0x96 };
			int size = sizeof(cpukey);

			BYTE* key = (BYTE*)XPhysicalAlloc(0x10, MAXULONG_PTR, NULL, PAGE_READWRITE);
			__int64 addr = ((INT64)MmGetPhysicalAddress(key) & 0xFFFFFFFF) | 0x8000000000000000;
			HvxGetVersions(0x72627472, 5, 0x20, addr, 0x10);

			int arraycheck = areArraysDifferent(cpukey, key, size);

			if (arraycheck != 0)
				return 0;

			return 1;
		}

		bool spastic2detected()
		{
			XUSER_SIGNIN_INFO userInfo; ZeroMemory(&userInfo, sizeof(XUSER_SIGNIN_INFO));
			if (XUserGetSigninInfo(0, XUSER_GET_SIGNIN_INFO_ONLINE_XUID_ONLY, &userInfo) == ERROR_SUCCESS)
			{
				const char* name = (const char*)userInfo.szUserName;

				if (strstr(name, "kaine"))
				{
					return 1;
				}
			}

			return 0;
		}

		bool ismoduleloaded(DWORD checksum)
		{
			PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY)XexExecutableModuleHandle;
			PLDR_DATA_TABLE_ENTRY firstentry = entry;
			int counted = 0;

			do
			{
				if (entry->CheckSum == checksum)
					return true;

				entry = (PLDR_DATA_TABLE_ENTRY)entry->InLoadOrderLinks.Flink;

				if (++counted > 64)
					break;

			} while (entry != firstentry);

			return false;
		}

		void dualloadingdetectionversion1stopallniggasprotocalcl_junkcodebypassundetectedbyvac2025()
		{
			const DWORD checksums[] =
			{
				0x66156, // jimbo
				0x44969, // matrix
				0x2E8E4, // medaka
				0x447DB  // infinityloader
			};

			for (int i = 0; i < 4; i++)
			{
				if (ismoduleloaded(checksums[i]))
				{
					const wchar_t* message = L"";

					if (ismoduleloaded(checksums[0]))
						message = __w(L"So we're dual loading an azza with unsetup...?\n\nUnload jimbo and you can play retard");

					if (ismoduleloaded(checksums[1]))
						message = __w(L"Dude tryna run matrix hahahahahahah faggot\n\nHonestly i should straight up blacklist your console from this but hey, unload matrix and you can play");

					if (ismoduleloaded(checksums[2]))
						message = __w(L"I have no words for this one.. medaka.. in the big 25..\n\nUnload Medaka and you can play");

					if (ismoduleloaded(checksums[3]))
						message = __w(L"So now you tryna load a shit gsc team menu aswell? wtf u doin bruh...\n\nUnload infinityloader and shiitt i might let you play g");

					LPCWSTR buttons[1] = { __w(L"FUCK, NOW I CAN'T FAKE SHOTS") };
					MESSAGEBOX_RESULT result;

					XOVERLAPPED ol;
					ZeroMemory(&ol, sizeof(ol));

					XShowMessageBoxUI(
						0,
						__w(L"Desire's S&D (Dual Loading Detected)"),
						message,
						1,
						buttons,
						0,
						XMB_ERRORICON,
						&result,
						&ol
					);

					while (!XHasOverlappedIoCompleted(&ol))
					{
						Sleep(25);
					}

					//XLaunchNewImage("dash.xex", 0);

					return;
				}
			}
		}

		struct addrs
		{
			int R_EndFrame;
			int UI_DrawText;
			int XamInputGetState;
			int AddCmdDrawStretchPic;
			int LUIDrawRectangle;
			int PM_Weapon;
			int PM_Weapon_Process_Hand;
			int VM_Notify;
			int SV_ExecuteClientCommand;
			int Scr_PlayerDamage;
			int BG_CanPlayerHaveWeapon;
			int BG_IsWeaponValid;
			int BG_IsWeaponUsableInState;
			int CG_ForceSwitchToValidWeapon;
		} addr;

		void inithookaddresses()
		{
			switch (CURGAME)
			{
				case MW2:
				{
					addr.R_EndFrame = 0x82351748;
					addr.UI_DrawText = 0x82350278;
					addr.XamInputGetState = 0x823B64C4;
					addr.AddCmdDrawStretchPic = 0x8234F9B8;
					addr.PM_Weapon = 0x820E1118;
					addr.PM_Weapon_Process_Hand = 0x820E1008;
					addr.VM_Notify = 0x8224A9A0;
					addr.SV_ExecuteClientCommand = 0x82253140;
					addr.Scr_PlayerDamage = 0x82205360;
					addr.BG_CanPlayerHaveWeapon = 0x820E2CE0;
					addr.BG_IsWeaponValid = 0x820E2F10;
					addr.BG_IsWeaponUsableInState = 0x820E2FB0;
					addr.CG_ForceSwitchToValidWeapon = 0x82135900;

					break;
				}

				case BO2:
				{
					addr.R_EndFrame = 0x821BCEF0;
					addr.XamInputGetState = 0x8293D884;
					addr.AddCmdDrawStretchPic = 0x828B86C0;
					addr.LUIDrawRectangle = 0x82717790;
					break;
				}

				default: break;
			}
		}

		DWORD XamInputGetState(DWORD r3, DWORD r4, PXINPUT_STATE r5)
		{
			int input = XInputGetState(r3, r5);

			if (menu::handler::controls.isopen)
			{
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_DPAD_UP;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_DPAD_DOWN;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_DPAD_LEFT;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_DPAD_RIGHT;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_A;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_B;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_X;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_Y;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_LEFT_SHOULDER;
				r5->Gamepad.wButtons &= ~XINPUT_GAMEPAD_RIGHT_SHOULDER;

				return input;
			}

			return MinHook[_("XamInputGetState")].Stub(r3, r4, r5);
		}

		void R_EndFrame()
		{
			ExCreateThread(0, 0, 0, 0, (LPTHREAD_START_ROUTINE)dualloadingdetectionversion1stopallniggasprotocalcl_junkcodebypassundetectedbyvac2025, 0, 0);

			menu::init();

			//bool shouldruningamestuff = CURGAME == MW2 ? helpers::ishost(helpers::getlocalidx()) : CURGAME == BO2 ? features::pregame::vars.forcehost : false;

			if (helpers::isingame())
			{
				if (CURGAME == MW2)
				{
					if (helpers::ishost(helpers::getlocalidx()))
					{
						features::ingame::handle_in_game_features();
					}

					static bool isalive = helpers::isalive(helpers::getlocalidx());
					if (isalive != helpers::isalive(helpers::getlocalidx()))
					{
						if (features::customisation::vars.has_camo_selected)
						{
							features::customisation::customcamos();
						}

						isalive = helpers::isalive(helpers::getlocalidx());
					}
				}

				if (CURGAME == BO2)
				{
					if (features::pregame::vars.forcehost)
					{
						features::ingame::handle_in_game_features();
					}
				}
			}
			else
			{
				features::pregame::handle_pre_game_features();

				// reset this shit
				if (game::begin_set)
					game::begin_set = false;
			}

			MinHook[_("R_EndFrame")].Stub();
		}

		void UI_DrawText(const char* r3, int r4, void* r5, float f1, float f2, float f3, float f4, float f5, const float* color, int something)
		{
			auto txt = const_cast<char*>(r3);

			if (!strcmp(txt, _("Searching")))
				r3 = _("Searching For Random");

			if (!strcmp(txt, _("Searching.")))
				r3 = _("Searching For Random.");

			if (!strcmp(txt, _("Searching..")))
				r3 = _("Searching For Random..");

			if (!strcmp(txt, _("Searching...")))
				r3 = _("Searching For Random..");

			if (!strcmp(txt, _("Finding more players to balance teams")))
				r3 = va(_("Finding more randoms to fuck"));

			if (!strcmp(txt, _("Finding more players to balance teams.")))
				r3 = va(_("Finding more randoms to fuck."));

			if (!strcmp(txt, _("Finding more players to balance teams..")))
				r3 = va(_("Finding more randoms to fuck.."));

			if (!strcmp(txt, _("Finding more players to balance teams...")))
				r3 = va(_("Finding more randoms to fuck..."));

			if (!strcmp(txt, _("Waiting for 1 more player")))
				r3 = va(_("Waiting for 1 more random"));

			if (!strcmp(txt, _("Waiting for 1 more player.")))
				r3 = va(_("Waiting for 1 more random."));

			if (!strcmp(txt, _("Waiting for 1 more player..")))
				r3 = va(_("Waiting for 1 more random.."));

			if (!strcmp(txt, _("Waiting for 1 more player...")))
				r3 = va(_("Waiting for 1 more random..."));

			if (!strcmp(txt, _("Matched Player")))
				r3 = _("Found Random");

			if (!strcmp(txt, _("Making balanced teams")))
				r3 = va(_("Cooking shit up"));

			if (!strcmp(txt, _("1.4.163842")))
				r3 = va(_("^8bastard"));

			if (features::customisation::vars.custom_callingcards_enabled)
			{
				if (!strcmp(txt, _("FNG")))
					r3 = va(_("   "));

				if (!strcmp(txt, _("S.S.D.D.")))
					r3 = va(_("        "));

				if (!strcmp(txt, _("Sgt.")))
					r3 = va(_("     "));

				if (!strcmp(txt, _("1st Sgt.")))
					r3 = va(_("        "));

				if (!strcmp(txt, _("1st Lt.")))
					r3 = va(_("       "));

				if (!strcmp(txt, _("Maj.")))
					r3 = va(_("    "));

				if (!strcmp(txt, _("FNG")))
					r3 = va(_("   "));

				if (!strcmp(txt, _("Gen.")))
					r3 = va(_("    "));

				if (!strcmp(txt, _("Commander")))
					r3 = va(_("         "));
			}

			MinHook[_("UI_DrawText")].Stub(r3, r4, r5, f1, f2, f3, f4, f5, color, something);
		}

		void AddCmdDrawStretchPic(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, const float* color, Material* material)
		{
			if (CURGAME == MW2)
			{
				if (!strcmp(material->name, _("mw2_main_cloud_overlay")) ||
					!strcmp(material->name, _("mw2_main_cloud_overlay_write_dest_alpha")) ||
					!strcmp(material->name, _("mw2_main_cloud_overlay_dest_alpha_masked")) ||
					!strcmp(material->name, _("mw2_popup_bg_fogscroll")) ||
					!strcmp(material->name, _("mockup_popup_bg_stencilfill")) ||
					!strcmp(material->name, _("mw2_popup_bg_fogstencil")))
				{
					color = render::colors::accenthalfalpha;
				}

				if (!strcmp(material->name, _("mockup_bg_glow")))
				{
					color = render::colors::blacknoalpha;
				}

				if (!helpers::isingame())
				{
					if (!memcmp(material, helpers::getmaterial(_("mw2_main_background")), sizeof(material)))
					{
						material = helpers::getmaterial(_("mw2_main_mp_image"));

						helpers::injectimage(0xB9567000, _("hdd:\\desire\\backgrounds\\mw2.bin"));
					}
				}

				if (helpers::isingame())
				{
					if (features::customisation::vars.custom_hud_color)
					{
						if (strstr(material->name, _("minimap")) ||
							strstr(material->name, _("radar")) ||
							strstr(material->name, _("compass")) ||
							strstr(material->name, _("compassping_player")) ||
							strstr(material->name, _("ammo")) ||
							strstr(material->name, _("sweep")) ||
							strstr(material->name, _("hud")))
						{
							color = render::colors::fromrgb(
								features::customisation::vars.hudcolor_r,
								features::customisation::vars.hudcolor_g,
								features::customisation::vars.hudcolor_b,
								255
							);
						}
					}
				}
			}

			MinHook[_("AddCmdDrawStretchPic")].Stub(f1, f2, f3, f4, f5, f6, f7, f8, color, material);
		}

		int LUIDrawRectangle(int r3, float x, float y, float w, float h, float r, float g, float b, float a, Material* material, int f10)
		{
			if (!strcmp(material->name, _("ui_globe")) ||
				!strcmp(material->name, _("menu_mp_title_screen")) ||
				!strcmp(material->name, _("menu_mp_title_screen_mp")))
			{
				r = 0;
				g = 0;
				b = 0;
				a = 0;
			}

			if (/*!strcmp(material->name, _("lui_bkg")) ||
				!strcmp(material->name, _("menu_mp_background_main2")) ||
				!strcmp(material->name, _("menu_mp_soldiers")) ||*/
				!strcmp(material->name, _("ui_smoke")) ||
				!strcmp(material->name, _("lui_random_map_vote")))
			{
				r = render::colors::accent[0];
				g = render::colors::accent[1];
				b = render::colors::accent[2];
				a = render::colors::accent[3];
			}

			if (!helpers::isingame())
			{
				if (!strcmp(material->name, _("lui_bkg")))
				{
					material = helpers::getmaterial(_("menu_mp_soldiers"));

					helpers::replacematerial(_("menu_mp_soldiers"), _("hdd:\\desire\\backgrounds\\bo2.bin"));
				}
			}

			return MinHook[_("LUIDrawRectangle")].Stub(r3, x, y, w, h, r, g, b, a, material, f10);
		}

		void PM_Weapon(pmove_t* a1, pml_t* a2)
		{
			//if (helpers::ishost(helpers::getlocalidx()))
			//{
				int clientidx = a1->ps->clientNum;

				if (helpers::shouldrunonteamorself(features::ingame::vars.insta_sprint, clientidx))
				{
					if (!helpers::isholdingakimboweapon(clientidx))
					{
						if (a1->ps->weapState->weaponState == WEAPON_SPRINT_RAISE)
						{
							a1->ps->weapState->weapAnim = WEAP_SPRINT_LOOP;
							a1->ps->weapState->weaponState = WEAPON_SPRINT_LOOP;
						}
					}
				}

				if (helpers::shouldrunonteamorself(features::ingame::vars.always_zoomload, clientidx))
				{
					if (a1->ps->weapState->weaponState == WEAPON_RELOADING &&
						a1->ps->weapState->weapAnim != WEAP_RELOAD_EMPTY)
					{
						a1->ps->weapState->weaponState = WEAPON_READY;
					}
				}

				if (helpers::shouldrunonteamorself(features::ingame::vars.insta_shoots, clientidx))
				{
					if (a1->ps->weapState->weaponState == WEAPON_RAISING)
					{
						a1->ps->weapState->weaponTime = 0;
						a1->ps->weapState->weaponDelay = 0;
						a1->ps->weapState->weaponRestrictKickTime = 1;
					}
				}

				if (helpers::shouldrunonteamorself(features::ingame::vars.always_lunge, clientidx))
				{
					if (a1->ps->weapState->weaponState == WEAPON_MELEE_INIT)
					{
						a1->ps->weapState->weapAnim = WEAP_MELEE_CHARGE;
					}
				}

				if (helpers::shouldrunonteamorself(features::ingame::vars.insta_spas_pump, clientidx))
				{
					if (helpers::isholdingpumpshotgun(clientidx))
					{
						if (a1->ps->weapState->weaponState == WEAPON_FIRING)
						{
							a1->ps->weapState->weapAnim = WEAP_RECHAMBER;

							if (a1->ps->weapState->weapAnim == WEAP_RECHAMBER)
							{
								a1->ps->weapState->weaponState = WEAPON_RECHAMBERING;
								a1->ps->weapState->weaponState = WEAPON_READY;
							}
						}
					}
				}
			//}

			MinHook[_("PM_Weapon")].Stub(a1, a2);
		}

		void PM_Weapon_Process_Hand(int a1, int a2, int a3, int a4)
		{
			MinHook[_("PM_Weapon_Process_Hand")].Stub(a1, a2, a3, a4);
		}

		void VM_Notify(unsigned int notify_list_owner_id, uint16_t string_value, uint32_t count)
		{
			auto event = SL_ConvertToString(string_value);
			auto clientidx = Scr_GetSelf(notify_list_owner_id);

			MinHook[_("VM_Notify")].Stub(notify_list_owner_id, string_value, count);

			if (!strcmp(event, "begin"))
			{
				helpers::setclientdvar(clientidx, _("loc_warnings"), _("0"));
				helpers::setclientdvar(clientidx, _("loc_warnings"), _("0"));

				menu::ingame::onplayerspawned(clientidx);

				//game::begin_set = true;
			}
		}

		void SV_ExecuteClientCommand(unsigned long client, const char* s, int ok)
		{
			DWORD clientidx = (client - *(int*)0x83623B98) / 0x97F80;

			SV_Cmd_TokenizeString(s);
			ClientCommand(clientidx);
			SV_Cmd_EndTokenizedString();

			//if (helpers::ishost(helpers::getlocalidx()))
			//{
				game::menu::ingame::monitorplayers(clientidx, s);
			//}
		}

		// from ascension ps3, playerdamage address by shield
		void Scr_PlayerDamage(gentity_s* self, const gentity_s* inflictor, const gentity_s* attacker, int damage, int flags, int meansofdeath, int weapon, const float* point, const float* dir, int hitloc, int offsettime)
		{
			if (damage > 1000 && flags == 2 && (meansofdeath == 9 || meansofdeath == 2))
				return;

			if (game::features::ingame::vars.no_fall_damage && (meansofdeath == 11 || meansofdeath == 14) && helpers::isonhostteam(self->client->ps.clientNum))
				return;

			if (attacker && inflictor && self != inflictor && self->client && inflictor->client && attacker->client)
			{
				if (game::features::ingame::vars.miniscule_health && damage != 2)
				{
					if (!helpers::isonhostteam(self->client->ps.clientNum))
					{
						damage = 9999;
					}
					else
					{
						damage -= (damage / 4);
					}
				}
			}

			MinHook[_("Scr_PlayerDamage")].Stub(self, inflictor, attacker, damage, flags, meansofdeath, weapon, point, dir, hitloc, offsettime);
		}

		bool BG_CanPlayerHaveWeapon(unsigned int a1)
		{
			return true;
		}

		bool BG_IsWeaponValid(playerState_s* ps, unsigned int a2)
		{
			return true;
		}

		bool BG_IsWeaponUsableInState(playerState_s* ps, unsigned int a2)
		{
			return true;
		}

		bool CG_ForceSwitchToValidWeapon(int a1)
		{
			return false;
		}

		void init()
		{
			if (spasticdetected() || spastic2detected())
			{
				*(int*)addr.R_EndFrame = 0xDEADBEEF;
			}

			inithookaddresses();
			initgamefunctions();

			if (CURGAME == MW2)
			{
				features::customisation::vars.init();

				// precache shaders
				if (*(int*)(0x83109D9C) != 1)
					*(int*)(0x83109D9C) = 1;

				// disable cheat protection
				*(int*)(0x8216906C) = 0x60000000;
				*(int*)(0x821690E4) = 0x60000000;
			}

			MinHook[_("R_EndFrame")] = DetourAttach((void*)addr.R_EndFrame, (void*)R_EndFrame);
			MinHook[_("XamInputGetState")] = DetourAttach((void*)addr.XamInputGetState, (void*)XamInputGetState);

			if (CURGAME == BO2)
			{
				MinHook[_("LUIDrawRectangle")] = DetourAttach((void*)addr.LUIDrawRectangle, (void*)LUIDrawRectangle);
			}

			if (CURGAME == MW2)
			{
				//MinHook[_("BG_CanPlayerHaveWeapon")] = DetourAttach((void*)addr.BG_CanPlayerHaveWeapon, (void*)BG_CanPlayerHaveWeapon);
				//MinHook[_("BG_IsWeaponValid")] = DetourAttach((void*)addr.BG_IsWeaponValid, (void*)BG_IsWeaponValid);
				//MinHook[_("BG_IsWeaponUsableInState")] = DetourAttach((void*)addr.BG_IsWeaponUsableInState, (void*)BG_IsWeaponUsableInState);
				//MinHook[_("CG_ForceSwitchToValidWeapon")] = DetourAttach((void*)addr.CG_ForceSwitchToValidWeapon, (void*)CG_ForceSwitchToValidWeapon);

				MinHook[_("PM_Weapon")] = DetourAttach((void*)addr.PM_Weapon, (void*)PM_Weapon);
				//MinHook[_("PM_Weapon_Process_Hand")] = DetourAttach((void*)addr.PM_Weapon_Process_Hand, (void*)PM_Weapon_Process_Hand);

				//MinHook[_("VM_Notify")] = DetourAttach((void*)addr.VM_Notify, (void*)VM_Notify);
				MinHook[_("SV_ExecuteClientCommand")] = DetourAttach((void*)addr.SV_ExecuteClientCommand, (void*)SV_ExecuteClientCommand);

				MinHook[_("AddCmdDrawStretchPic")] = DetourAttach((void*)addr.AddCmdDrawStretchPic, (void*)AddCmdDrawStretchPic);
				MinHook[_("UI_DrawText")] = DetourAttach((void*)addr.UI_DrawText, (void*)UI_DrawText);

				MinHook[_("Scr_PlayerDamage")] = DetourAttach((void*)addr.Scr_PlayerDamage, (void*)Scr_PlayerDamage);
			}

			if (CURGAME == MW2)
			{
				XNotify(_("Desire's S&D Loaded! (MW2)"), XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_PREFERRED_REVIEW);

				// replace IW logo with our cool epic swag drawn one
				helpers::replacematerial("logo_iw", "hdd:\\desire\\backgrounds\\logo_iw.bin");
			}

			if (CURGAME == BO2)
			{
				XNotify(_("Desire's S&D Loaded! (BO2)"), XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_PREFERRED_REVIEW);
			}

			if (game::moduleunloading())
			{
				if (features::customisation::vars.custom_callingcards_enabled)
				{
					if (game::callingcard_thread)
					{
						CloseHandle(game::callingcard_thread);
					}
				}
			}
		}
	}
}