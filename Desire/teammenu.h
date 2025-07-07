#pragma once
#include "ingame.h"

#define BUTTON_A         "n 25"
#define BUTTON_B         "n 23"
#define BUTTON_X         "n 11"
#define BUTTON_Y         "n 28"
#define BUTTON_RS        "n 3"
#define BUTTON_LS        "n 9"
#define BUTTON_RB        "n 5"
#define BUTTON_LB        "n 7"
#define BUTTON_RT        "n 1"
#define BUTTON_LT        "n 13"
#define BUTTON_DPADUP    "n 16"
#define BUTTON_DPADDOWN  "n 18"
#define BUTTON_DPADLEFT  "n 19"
#define BUTTON_DPADRIGHT "n 21"
#define BUTTON_BACK      "n 30"
#define BUTTON_START     "n 27"

namespace game
{
	namespace menu
	{
		namespace ingame
		{
			bool buttondown(const char* s, const void* button)
			{
				if (!memcmp(s, button, 4))
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			struct structure_s
			{
				bool isopen;
				bool justjoined;
				int currentoption;
				int maxoption;
				int wait;

				void reset()
				{
					if (isopen)
						isopen = false;

					if (justjoined)
						justjoined = false;

					if (currentoption != 0)
						currentoption = 0;

					if (maxoption != 0)
						maxoption = 0;
				}
			} structure[18];

			struct hud_s
			{
				bool initialized;
				game_hudelem_s* background;
				game_hudelem_s* titlebar;
				game_hudelem_s* title;
				game_hudelem_s* option[64];

				void free()
				{
					if (background != 0)
						HudElem_Free(background);

					if (titlebar != 0)
						HudElem_Free(titlebar);

					if (title != 0)
						HudElem_Free(title);

					for (int i = 0; i < 64; i++)
					{
						if (option[i] != 0)
							HudElem_Free(option[i]);
					}
				}
			} hud[18];

			void addoption(int i, const char* text, int idx)
			{
				hudelems::set_text(hud[idx].option[i], text, 0, 1.3, -300, 140 / 2 + 90 + (i * 15), 1, 3 + i, 255, 255, 255, 100);
				hudelems::move_over_time(hud[idx].option[i], 300, 255, 140 / 2 + 90 + (i * 15), 0);
				structure[idx].maxoption = i;
			}	

			void updateselectedoption(int idx)
			{
				for (int i = 0; i < 64; i++)
				{
					int final_alpha = i == structure[idx].currentoption ? 255 : 100;
					hud[idx].option[i]->elem.color.a = final_alpha;
				}
			}

			void openmenu(int idx)
			{
				structure[idx].isopen = true;

				hudelems::set_shader(hud[idx].background, "black", -300, 200, 140, 140, 1, 0, 20, 20, 20, 255);
				hudelems::set_shader(hud[idx].titlebar, "white", -300, 140 / 2 + 70, 140, 20, 1, 1, 255, 169, 215, 255);
				hudelems::set_text(hud[idx].title, "desire team menu", 0, 1.4, -300, 140 / 2 + 70, 1, 2, 255, 255, 255, 255);

				hudelems::move_over_time(hud[idx].background, 300, 250, 200, 0);
				hudelems::move_over_time(hud[idx].titlebar, 300, 250, 140 / 2 + 70, 0);
				hudelems::move_over_time(hud[idx].title, 300, 255, 140 / 2 + 70, 0);

				addoption(0, "unstuck", idx);
				addoption(1, "insta sprint", idx);
				addoption(2, "zoomloads", idx);
				addoption(3, "drop canswap", idx);
			}

			void closemenu(int idx)
			{
				structure[idx].isopen = false;

				hudelems::move_over_time(hud[idx].background, 400, 1200, 200, 0);
				hudelems::move_over_time(hud[idx].titlebar, 400, 1200, 140 / 2 + 70, 0);
				hudelems::move_over_time(hud[idx].title, 400, 1200, 140 / 2 + 70, 0);

				for (int i = 0; i < 64; i++)
				{
					hudelems::move_over_time(hud[idx].option[i], 400, 1200, 140 / 2 + 90 + (i * 15), 0);
				}
			}

			void resethud(int idx)
			{
				structure[idx].reset();
				hud[idx].free();
			}

			void inithud(int idx)
			{
				resethud(idx);

				hud[idx].background = HudElem_Alloc(idx, 0);
				hud[idx].titlebar = HudElem_Alloc(idx, 0);
				hud[idx].title = HudElem_Alloc(idx, 0);

				for (int i = 0; i < 64; i++)
				{
					hud[idx].option[i] = HudElem_Alloc(idx, 0);
				}
			}

			void monitorplayers(int idx, const char* str)
			{
				if (helpers::isonhostteam(idx))
				{
					gentity_s player = g_entities[idx];

					if (!structure[idx].isopen)
					{
						if (buttondown(str, BUTTON_DPADLEFT))
						{
							openmenu(idx);
							updateselectedoption(idx);
						}
					}
					else if (structure[idx].isopen)
					{
						if (buttondown(str, BUTTON_RS))
						{
							closemenu(idx);
						}

						if (buttondown(str, BUTTON_X))
						{
							switch (structure[idx].currentoption)
							{
							case 0:
							{
								SetClientOrigin(&player, vec3_t(player.client->ps.origin.x, player.client->ps.origin.y, player.client->ps.origin.z + 10));
								break;
							}
							case 1:
							{
								ent_handlr.insta_sprint_enabled[idx] = !ent_handlr.insta_sprint_enabled[idx];
								helpers::notifyclient(idx, ent_handlr.insta_sprint_enabled[idx] ? "^2instasprint" : "^1instasprint");
								break;
							}
							case 2:
							{
								ent_handlr.always_zoomload_enabled[idx] = !ent_handlr.always_zoomload_enabled[idx];
								helpers::notifyclient(idx, ent_handlr.always_zoomload_enabled[idx] ? "^2zoomloads" : "^1zoomloads");
								break;
							}
							case 3:
							{
								int weaponidx = G_GetWeaponIndexForName("kriss_mp");
								int validweapon = *(int*)(BG_GetWeaponDef(weaponidx) + 0x38);

								G_GivePlayerWeapon(&player.client->ps, weaponidx, 0, 0);
								Add_Ammo(&player, weaponidx, 0, 9999, 1);

								if (validweapon != 3)
								{
									Drop_Weapon(&player, weaponidx, 0, SL_GetString("j_gun", 0));
								}

								break;
							}
							default: break;
							}
						}

						if (buttondown(str, BUTTON_DPADDOWN))
						{
							if (structure[idx].currentoption == structure[idx].maxoption)
							{
								structure[idx].currentoption = 0;
							}
							else
							{
								structure[idx].currentoption++;
							}

							updateselectedoption(idx);
						}

						if (buttondown(str, BUTTON_DPADUP))
						{
							if (structure[idx].currentoption == 0)
							{
								structure[idx].currentoption = structure[idx].maxoption;
							}
							else
							{
								structure[idx].currentoption--;
							}

							updateselectedoption(idx);
						}
					}
				}
			}

			void onplayerspawned(int idx)
			{
				inithud(idx);

				helpers::iprintln(idx, "^6[{+actionslot 3}] for desire");
			}
		}
	}
}