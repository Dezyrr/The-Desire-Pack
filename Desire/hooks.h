#pragma once
#include "includes.h"
#include "render.h"
#include "menu.h"
#include "teammenu.h"
#include "gsc.h"

namespace game
{
	GfxImage* getShader(const char* shader)
	{
		return DB_FindXAssetHeader(ASSET_TYPE_IMAGE, shader).image;
	}

	Material* getMaterial(const char* shader)
	{
		return Material_RegisterHandle(shader, 0);
	}

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

			void init()
			{
				switch (CURGAME)
				{
					case MW2:
					{
						R_EndFrame = 0x82351748;
						UI_DrawText = 0x82350278;
						XamInputGetState = 0x823B64C4;
						AddCmdDrawStretchPic = 0x8234F9B8;
						PM_Weapon = 0x820E1118;
						PM_Weapon_Process_Hand = 0x820E1008;
						VM_Notify = 0x82209710;
						SV_ExecuteClientCommand = 0x82253140;
						break;
					}

					case BO2:
					{
						R_EndFrame = 0x821BCEF0;
						XamInputGetState = 0x8293D884;
						AddCmdDrawStretchPic = 0x828B86C0;
						LUIDrawRectangle = 0x82717790;
						break;
					}

					default: break;
				}
			}
		} addr;

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
			menu::init();

			if (helpers::isingame())
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
					if (!memcmp(material, getMaterial("mw2_main_background"), sizeof(material)))
					{
						material = getMaterial("mw2_main_mp_image");
						InjectImage(0xB9567000, "Hdd:\\Desire\\background.bin");
					}
				}
			}

			MinHook["AddCmdDrawStretchPic"].Stub(f1, f2, f3, f4, f5, f6, f7, f8, color, material);
		}

		int LUIDrawRectangle(int r3, float x, float y, float w, float h, float r, float g, float b, float a, Material* material, int f10)
		{
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
			int clientidx = a1->ps->clientNum;

			if (ent_handlr.insta_sprint_enabled[clientidx])
			{
				if (a1->ps->weapState->weaponState == WEAPON_SPRINT_RAISE)
				{
					a1->ps->weapState->weapAnim = WEAP_SPRINT_LOOP;
					a1->ps->weapState->weaponState = WEAPON_SPRINT_LOOP;
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
			MinHook["PM_Weapon_Process_Hand"].Stub(a1, a2, a3, a4);
		}

		void VM_Notify(gentity_s* entity, uint16_t string_value, uint32_t count)
		{
			MinHook["VM_Notify"].Stub(entity, string_value, count);

			int clientidx = entity->s.number;
			const char* event_name = SL_ConvertToString(string_value);

			if (!strcmp(event_name, "begin"))
			{
				game::menu::ingame::onplayerbegin(clientidx);
			}

			if (!strcmp(event_name, "spawned_player"))
			{
				game::menu::ingame::onplayerspawned(clientidx);
			}
		}

		void SV_ExecuteClientCommand(unsigned long client, const char* s, int ok, int oldserver)
		{
			MinHook["SV_ExecuteClientCommand"].Stub(client, s, ok, oldserver);

			DWORD idx = (client - *(int*)0x83623B98) / 0x97F80;
			SV_Cmd_TokenizeString(s);
			ClientCommand(idx);
			SV_Cmd_EndTokenizedString();
			game::menu::ingame::monitorplayers(idx, s);
		}

		void init()
		{
			// init addresses
			addr.init();

			// init funcs
			setgamefuncs();

			// inject team menu gsc
			features::injectgsc();

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
				MinHook["AddCmdDrawStretchPic"] = DetourAttach((void*)addr.AddCmdDrawStretchPic, (void*)AddCmdDrawStretchPic);
				MinHook["UI_DrawText"] = DetourAttach((void*)addr.UI_DrawText, (void*)UI_DrawText);
			}

			//MinHook["PM_Weapon"] = DetourAttach((void*)PM_Weapon, (void*)PM_Weapon);
			//MinHook["PM_Weapon_Process_Hand"] = DetourAttach((void*)PM_Weapon_Process_Hand, (void*)PM_Weapon_Process_Hand);
			//MinHook["VM_Notify"] = DetourAttach((void*)VM_Notify, (void*)VM_Notify);
			//MinHook["SV_ExecuteClientCommand"] = DetourAttach((void*)SV_ExecuteClientCommand, (void*)SV_ExecuteClientCommand);		
		}
	}
}