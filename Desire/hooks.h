#pragma once
#include "includes.h"
#include "render.h"
#include "menu.h"
#include "teammenu.h"
#include "gsc.h"

#pragma warning(push)
#pragma warning(disable : 4214)
#include <xbdm.h>
#pragma warning(pop)

namespace game
{
	namespace hooks
	{
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

			return MinHook["XamInputGetState"].Stub(r3, r4, r5);
		}

		void R_EndFrame()
		{
			if (moduleunloading())
				MinHook["R_EndFrame"].Stub();

			menu::init();

			if (helpers::isingame() && features::pregame::vars.forcehost)
			{
				features::ingame::handle_in_game_features();
			}
			else
			{
				features::pregame::handle_pre_game_features();
			}

			MinHook["R_EndFrame"].Stub();
		}

		void UI_DrawText(const char* r3, int r4, void* r5, float f1, float f2, float f3, float f4, float f5, const float* color, int something)
		{
			if (moduleunloading())
				MinHook["UI_DrawText"].Stub(r3, r4, r5, f1, f2, f3, f4, f5, color, something);

			auto txt = const_cast<char*>(r3);

			if (!strcmp(txt, "Searching"))
				r3 = "Searching For Random";

			if (!strcmp(txt, "Searching."))
				r3 = "Searching For Random.";

			if (!strcmp(txt, "Searching.."))
				r3 = "Searching For Random..";

			if (!strcmp(txt, "Searching..."))
				r3 = "Searching For Random...";

			if (!strcmp(txt, "Matched Player"))
				r3 = "Found Random";

			if (!strcmp(txt, "1.4.163842"))
				r3 = va("^8bastard");

			MinHook["UI_DrawText"].Stub(r3, r4, r5, f1, f2, f3, f4, f5, color, something);
		}

		void AddCmdDrawStretchPic(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, const float* color, Material* material)
		{
			if (moduleunloading())
				MinHook["AddCmdDrawStretchPic"].Stub(f1, f2, f3, f4, f5, f6, f7, f8, color, material);

			if (CURGAME == MW2)
			{
				if (!strcmp(material->name, "mw2_main_cloud_overlay") ||
					!strcmp(material->name, "mw2_main_cloud_overlay_write_dest_alpha") ||
					!strcmp(material->name, "mw2_main_cloud_overlay_dest_alpha_masked") ||
					!strcmp(material->name, "mw2_popup_bg_fogscroll") ||
					!strcmp(material->name, "mockup_popup_bg_stencilfill") ||
					!strcmp(material->name, "mw2_popup_bg_fogstencil"))
				{
					color = render::colors::accenthalfalpha;
				}

				if (!strcmp(material->name, "mockup_bg_glow"))
				{
					color = render::colors::blacknoalpha;
				}

				if (!helpers::isingame())
				{
					if (!memcmp(material, helpers::getmaterial("mw2_main_background"), sizeof(material)))
					{
						material = helpers::getmaterial("mw2_main_mp_image");
						helpers::injectimage(0xB9567000, "Hdd:\\Desire\\background.bin");
					}
				}
			}

			MinHook["AddCmdDrawStretchPic"].Stub(f1, f2, f3, f4, f5, f6, f7, f8, color, material);
		}

		int LUIDrawRectangle(int r3, float x, float y, float w, float h, float r, float g, float b, float a, Material* material, int f10)
		{
			if (moduleunloading())
				return MinHook["LUIDrawRectangle"].Stub(r3, x, y, w, h, r, g, b, a, material, f10);

			if (!strcmp(material->name, "menu_mp_soldiers") ||
				!strcmp(material->name, "ui_globe") ||
				!strcmp(material->name, "ui_smoke"))
			{
				r = render::colors::accent[0];
				g = render::colors::accent[1];
				b = render::colors::accent[2];
				a = render::colors::accent[3];
			}

			return MinHook["LUIDrawRectangle"].Stub(r3, x, y, w, h, r, g, b, a, material, f10);
		}

		void PM_Weapon(pmove_t* a1, pml_t* a2)
		{
			if (moduleunloading())
				MinHook["PM_Weapon"].Stub(a1, a2);

			int clientidx = a1->ps->clientNum;
				
			if (helpers::isonhostteam(clientidx))
			{
				if (ent_handlr.insta_sprint_enabled[clientidx])
				{
					if (a1->ps->weapState->weaponState == WEAPON_SPRINT_RAISE)
					{
						a1->ps->weapState->weapAnim = WEAP_SPRINT_LOOP;
						a1->ps->weapState->weaponState = WEAPON_SPRINT_LOOP;
					}
				}

				if (ent_handlr.always_zoomload_enabled[clientidx])
				{
					if (a1->ps->weapState->weaponState == WEAPON_RELOADING)
					{
						a1->ps->weapState->weaponState = WEAPON_READY;
					}
				}
			}

			//if (a1->ps->weapState->weaponState == WEAPON_RAISING)
			//{
			//	a1->ps->weapState->weaponState = WEAPON_DROPPING_QUICK;
			//}

			MinHook["PM_Weapon"].Stub(a1, a2);
		}

		void PM_Weapon_Process_Hand(int a1, int a2, int a3, int a4)
		{
			if (moduleunloading())
				MinHook["PM_Weapon_Process_Hand"].Stub(a1, a2, a3, a4);

			MinHook["PM_Weapon_Process_Hand"].Stub(a1, a2, a3, a4);
		}

		void VM_Notify(unsigned int notify_list_owner_id, uint16_t string_value, uint32_t count)
		{
			if (moduleunloading())
				MinHook["VM_Notify"].Stub(notify_list_owner_id, string_value, count);

			int clientidx = Scr_GetSelf(notify_list_owner_id);
			const char* event_name = SL_ConvertToString(string_value);

			if (!strcmp(event_name, "spawned_player"))
			{
				helpers::setclientdvar(clientidx, "loc_warnings", "0");
				helpers::setclientdvar(clientidx, "loc_warnings", "0");
				
				game::menu::ingame::onplayerspawned(clientidx);
			}

			if (!strcmp(event_name, "weapon_change"))
			{

			}

			MinHook["VM_Notify"].Stub(notify_list_owner_id, string_value, count);
		}

		// from jokers tu9 base
		void SV_ExecuteClientCommand(unsigned long client, const char* s, int ok)
		{
			if (moduleunloading())
				MinHook["SV_ExecuteClientCommand"].Stub(client, s, ok);

			DWORD clientidx = (client - *(int*)0x83623B98) / 0x97F80;
			SV_Cmd_TokenizeString(s);
			ClientCommand(clientidx);
			SV_Cmd_EndTokenizedString();
			game::menu::ingame::monitorplayers(clientidx, s);
		}

		void Scr_PlayerDamage(gentity_s* self, const gentity_s* inflictor, const gentity_s* attacker, int damage, int flags, int meansofdeath, int weapon, const float* point, const float* dir, int hitloc, int offsettime)
		{
			if (moduleunloading())
				MinHook["Scr_PlayerDamage"].Stub(self, inflictor, attacker, damage, flags, meansofdeath, weapon, point, dir, hitloc, offsettime);

			if (game::features::ingame::vars.no_fall_damage && (meansofdeath == 11 || meansofdeath == 14) && helpers::isonhostteam(self->client->ps.clientNum))
				return;

			if (attacker != self)
			{
				if (game::features::ingame::vars.miniscule_health)
				{
					if (!helpers::isonhostteam(self->client->ps.clientNum))
					{
						damage = 9999;
					}
				}
			}

			MinHook["Scr_PlayerDamage"].Stub(self, inflictor, attacker, damage, flags, meansofdeath, weapon, point, dir, hitloc, offsettime);
		}

		void __declspec(naked) HvxGetVersions(int magic, int mode, unsigned addr, __int64 outBuff, DWORD length)
		{
			__asm
			{
				li    r0, 0
				sc
				blr
			}
		}

		// goodbye
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

		// doesnt work
		bool faggotdetected()
		{
			int bannedshit[] = {
				0x66156,   // Jimbo
				0x44969,   // Matrix
				0x2E8E4    // MedakaMW2
			};

			int bannedshitsize = sizeof(bannedshit) / sizeof(bannedshit[0]);

			HRESULT hr = S_OK;
			PDM_WALK_MODULES walkmodules = NULL;
			DMN_MODLOAD loadedmodule = { 0 };
			bool foundafaggot = false;

			while ((hr = DmWalkLoadedModules(&walkmodules, &loadedmodule)) == XBDM_NOERR)
			{
				for (int i = 0; i < bannedshitsize; i++)
				{
					if (loadedmodule.CheckSum == bannedshit[i])
					{
						foundafaggot = true;
					}
				}
			}

			if (hr != XBDM_ENDOFLIST)
			{
				DmCloseLoadedModules(walkmodules);
				return false;
			}

			DmCloseLoadedModules(walkmodules);

			return foundafaggot;
		}

		void init()
		{
			//if (faggotdetected())
			//{
			//	// idk how to bring up the info box so for now just xnotify
			//	XNotify("[Desire] disallowed module(s) found running, try again", XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_AVOID_REVIEW);
			//	return;
			//}

			inithookaddresses();
			initgamefunctions();

			if (spasticdetected())
			{
				*(int*)addr.R_EndFrame = 0xFF;
			}

			if (CURGAME == MW2)
			{
				// precache shaders
				if (*(int*)(0x83109D9C) != 1)
					*(int*)(0x83109D9C) = 1;

				// disable cheat protection
				*(int*)(0x8216906C) = 0x60000000;
				*(int*)(0x821690E4) = 0x60000000;
			}

			MinHook["R_EndFrame"] = DetourAttach((void*)addr.R_EndFrame, (void*)R_EndFrame);
			MinHook["XamInputGetState"] = DetourAttach((void*)addr.XamInputGetState, (void*)XamInputGetState);

			if (CURGAME == BO2)
			{
				MinHook["LUIDrawRectangle"] = DetourAttach((void*)addr.LUIDrawRectangle, (void*)LUIDrawRectangle);
			}

			if (CURGAME == MW2)
			{
				MinHook["PM_Weapon"] = DetourAttach((void*)addr.PM_Weapon, (void*)PM_Weapon);

				//MinHook["PM_Weapon_Process_Hand"] = DetourAttach((void*)addr.PM_Weapon_Process_Hand, (void*)PM_Weapon_Process_Hand);

				MinHook["VM_Notify"] = DetourAttach((void*)addr.VM_Notify, (void*)VM_Notify);
				MinHook["SV_ExecuteClientCommand"] = DetourAttach((void*)addr.SV_ExecuteClientCommand, (void*)SV_ExecuteClientCommand);

				MinHook["AddCmdDrawStretchPic"] = DetourAttach((void*)addr.AddCmdDrawStretchPic, (void*)AddCmdDrawStretchPic);
				MinHook["UI_DrawText"] = DetourAttach((void*)addr.UI_DrawText, (void*)UI_DrawText);

				MinHook["Scr_PlayerDamage"] = DetourAttach((void*)addr.Scr_PlayerDamage, (void*)Scr_PlayerDamage);
			}

			if (CURGAME == MW2)
			{
				XNotify("Desire's S&D Loaded! (MW2)", XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_SONGPLAYING);
			}

			if (CURGAME == BO2)
			{
				XNotify("Desire's S&D Loaded! (BO2)", XNOTIFYQUEUEUI_TYPE::XNOTIFYUI_TYPE_SONGPLAYING);
			}

			features::injectgsc();
		}
	}
}