#pragma once
#include "ingame.h"
#include "notifications.h"

namespace game
{
	namespace menu
	{
		namespace ingame
		{
			struct structure_s
			{
				bool isopen;
				int currentoption;
				int maxoption;
				int wait;

				void reset()
				{
					isopen = false;
					currentoption = 0;
					maxoption = 0;
					wait = 0;
				}

			} structure[18];

			struct hud_s
			{
				game_hudelem_s* background;
				game_hudelem_s* titlebar;
				game_hudelem_s* title;
				game_hudelem_s* option[64];
				bool inited;

				void free()
				{
					if (background)
					{
						HudElem_Free(background);
						background = nullptr;
					}

					if (titlebar)
					{
						HudElem_Free(titlebar);
						titlebar = nullptr;
					}

					if (title)
					{
						HudElem_Free(title);
						title = nullptr;
					}

					for (int i = 0; i < 64; i++)
					{
						if (option[i])
						{
							HudElem_Free(option[i]);
							option[i] = nullptr;
						}
					}

					inited = false;
				}

				void init(int idx)
				{
					structure[idx].reset();

					if (inited)
						free();

					background = HudElem_Alloc(idx, 0);
					titlebar = HudElem_Alloc(idx, 0);
					title = HudElem_Alloc(idx, 0);

					for (int i = 0; i < 64; i++)
					{
						option[i] = HudElem_Alloc(idx, 0);
					}

					inited = true;
				}
			} hud[18];

			int height = 190;

			void addoption(int i, const char* text, int idx)
			{
				hudelems::set_text(hud[idx].option[i], text, 0, 1.3, -300, height / 2 + 90 - 60 + (i * 15), 1, 3 + i, 255, 255, 255, 100);
				hudelems::move_over_time(hud[idx].option[i], 300, 255, height / 2 + 90 - 60 + (i * 15), 0);
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

			void setelemcolor(int idx, int i, int r, int g, int b)
			{
				hud[idx].option[i]->elem.color.r = r;
				hud[idx].option[i]->elem.color.g = g;
				hud[idx].option[i]->elem.color.b = b;
			}

			// literally kill yourself
			void updateenabledoption(int idx)
			{
				if (ent_handlr.altswap[idx])
					setelemcolor(idx, 3, 0, 255, 0);
				else					
					setelemcolor(idx, 3, 255, 0, 0);

				if (ent_handlr.smooth_actions[idx])
					setelemcolor(idx, 4, 0, 255, 0);
				else
					setelemcolor(idx, 4, 255, 0, 0);

				if (ent_handlr.insta_shoots[idx])
					setelemcolor(idx, 5, 0, 255, 0);
				else
					setelemcolor(idx, 5, 255, 0, 0);

				if (ent_handlr.insta_sprint[idx])
					setelemcolor(idx, 6, 0, 255, 0);
				else
					setelemcolor(idx, 6, 255, 0, 0);

				if (ent_handlr.insta_spas_pump[idx])
					setelemcolor(idx, 7, 0, 255, 0);
				else
					setelemcolor(idx, 7, 255, 0, 0);

				if (ent_handlr.always_zoomload[idx])
					setelemcolor(idx, 8, 0, 255, 0);
				else
					setelemcolor(idx, 8, 255, 0, 0);

				if (ent_handlr.always_lunge[idx])
					setelemcolor(idx, 9, 0, 255, 0);
				else
					setelemcolor(idx, 9, 255, 0, 0);

				if (ent_handlr.inf_canswap[idx])
					setelemcolor(idx, 10, 0, 255, 0);
				else
					setelemcolor(idx, 10, 255, 0, 0);
			}

			void openmenu(int idx)
			{
				structure[idx].isopen = true;

				hudelems::set_shader(hud[idx].background, "black", -300, 200, 140, height, 1, 0, 20, 20, 20, 255);
				hudelems::set_shader(hud[idx].titlebar, "white", -300, 140 / 2 + 70 - 60, 140, 20, 1, 1, 255, 169, 215, 255);
				hudelems::set_text(hud[idx].title, "desire team menu", 0, 1.4, -300, height / 2 + 70 - 60, 1, 2, 255, 255, 255, 255);

				hudelems::move_over_time(hud[idx].background, 300, 250, height, 0);
				hudelems::move_over_time(hud[idx].titlebar, 300, 250, height / 2 + 70 - 60, 0);
				hudelems::move_over_time(hud[idx].title, 300, 255, height / 2 + 70 - 60, 0);

				addoption(0, "unstuck", idx);
				addoption(1, "drop canswap", idx);
				addoption(2, "refill ammo", idx);
				addoption(3, "altswap", idx);
				addoption(4, "smooth actions [{+actionslot 2}]", idx);
				addoption(5, "insta shoots", idx);
				addoption(6, "insta sprint", idx);
				addoption(7, "insta pump", idx);
				addoption(8, "always zoomload", idx);
				addoption(9, "always lunge", idx);
				addoption(10, "inf canswap", idx);
			}

			void closemenu(int idx)
			{
				structure[idx].isopen = false;

				hudelems::move_over_time(hud[idx].background, 400, 1200, 200, 0);
				hudelems::move_over_time(hud[idx].titlebar, 400, 1200, height / 2 + 70 - 60, 0);
				hudelems::move_over_time(hud[idx].title, 400, 1200, height / 2 + 70 - 60, 0);

				for (int i = 0; i < 64; i++)
				{
					hudelems::move_over_time(hud[idx].option[i], 400, 1200, height / 2 + 90 - 60 + (i * 15), 0);
				}
			}

			void monitorplayers(int idx, const char* str)
			{
				static bool isalive[18];

				if (!helpers::isonhostteam(idx))
					return;

				if (game::moduleunloading())
				{
					for (int i = 0; i < 18; i++)
					{
						if (structure[i].isopen)
							closemenu(i);

						if (hud[i].inited)
						{
							structure[i].reset();
							hud[i].free();
						}
					}
				}

				structure[idx].wait++;

				if (isalive[idx] != helpers::isalive(idx))
				{
					helpers::setclientdvar(idx, _("loc_warnings"), _("0"));

					if (helpers::isalive(idx))
					{
						helpers::notifyclient(idx, "^2[{+actionslot 1}] for menu");
					}

					else
					{
						if (structure[idx].isopen)
							closemenu(idx);

						if (hud[idx].inited)
						{
							structure[idx].reset();
							hud[idx].free();
						}
					}

					isalive[idx] = helpers::isalive(idx);
				}
			}

			void onplayerbegin(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (structure[idx].isopen)
					closemenu(idx);

				if (hud[idx].inited)
				{
					structure[idx].reset();
					hud[idx].free();
				}
			}

			void onplayerspawned(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;
				
				if (!game::ent_handlr.spawned_once[idx])
				{
					helpers::setclientdvar(idx, _("loc_warnings"), _("0"));
					ent_handlr.spawned_once[idx] = true;
				}

				if (ent_handlr.altswap[idx])
				{
					ent_handlr.altswap[idx] = false;
				}

				// gotta set this every round apparently, fuh dih gaym
				Cmd_RegisterNotification(idx, "+actionslot 1", "DPAD_UP");
				Cmd_RegisterNotification(idx, "+actionslot 2", "DPAD_DOWN");
				Cmd_RegisterNotification(idx, "+actionslot 3", "DPAD_LEFT");
				Cmd_RegisterNotification(idx, "+actionslot 4", "DPAD_RIGHT");
				Cmd_RegisterNotification(idx, "+usereload", "MENU_SELECT");
				Cmd_RegisterNotification(idx, "+melee", "MENU_CLOSE");
			}

			void ongameended(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (structure[idx].isopen)
					closemenu(idx);

				if (hud[idx].inited)
				{
					structure[idx].reset();
					hud[idx].free();
				}
			}

			void ondpadup(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;

				if (!helpers::isalive(idx))
					return;

				if (!hud[idx].inited)
					hud[idx].init(idx);

				if (!structure[idx].isopen)
				{
					openmenu(idx);
					updateselectedoption(idx);
					updateenabledoption(idx);
					structure[idx].wait = 0;
				}
				else
				{
					if (structure[idx].wait > 1)
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

						structure[idx].wait = 0;
					}
				}
			}

			void ondpaddown(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;

				if (!helpers::isalive(idx))
					return;

				if (structure[idx].isopen)
				{
					if (structure[idx].wait > 1)
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

						structure[idx].wait = 0;
					}
				}

				else
				{
					if (ent_handlr.smooth_actions[idx])
					{
						ent_handlr.pressed_smooth_actions_bind[idx] = true;
					}
				}
			}

			void ondpadleft(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;

				if (!helpers::isalive(idx))
					return;
			}

			void ondpadright(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;

				if (!helpers::isalive(idx))
					return;
			}

			void onx(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (!helpers::isonhostteam(idx))
					return;

				if (!helpers::isalive(idx))
					return;

				if (structure[idx].isopen)
				{
					if (structure[idx].wait > 1)
					{
						switch (structure[idx].currentoption)
						{
							case 0:
							{
								SetClientOrigin(entity, vec3_t(entity->client->ps.origin.x, entity->client->ps.origin.y, entity->client->ps.origin.z + 10));
								break;
							}

							case 1:
							{
								helpers::gsc::giveweapon(idx, "usp_mp");
								helpers::gsc::dropitem(idx, "usp_mp");
								break;
							}

							case 2:
							{
								helpers::refillammo(idx);
								break;
							}

							case 3:
							{
								if (!ent_handlr.altswap[idx])
								{
									const char* secondarystr = G_GetWeaponNameForIndex(helpers::getsecondaryweaponidx(idx));

									// give usp
									helpers::giveweapon(idx, "usp_mp", 0, 0);

									// take secondary
									helpers::gsc::takeweapon(idx, secondarystr);

									// give secondary back
									helpers::giveweapon(idx, secondarystr, 0, strstr(secondarystr, "akimbo") ? 1 : 0);

									ent_handlr.altswap[idx] = true;
								}

								break;
							}

							case 4:
							{
								ent_handlr.smooth_actions[idx] = !ent_handlr.smooth_actions[idx];

								break;
							}

							case 5:
							{
								ent_handlr.insta_shoots[idx] = !ent_handlr.insta_shoots[idx];

								break;
							}

							case 6:
							{
								ent_handlr.insta_sprint[idx] = !ent_handlr.insta_sprint[idx];

								break;
							}

							case 7:
							{
								ent_handlr.insta_spas_pump[idx] = !ent_handlr.insta_spas_pump[idx];

								break;
							}

							case 8:
							{
								ent_handlr.always_zoomload[idx] = !ent_handlr.always_zoomload[idx];

								break;
							}

							case 9:
							{
								ent_handlr.always_lunge[idx] = !ent_handlr.always_lunge[idx];

								break;
							}

							case 10:
							{
								ent_handlr.inf_canswap[idx] = !ent_handlr.inf_canswap[idx];

								break;
							}

							default: break;
						}

						updateenabledoption(idx);
						structure[idx].wait = 0;
					}
				}
			}

			void onrs(gentity_s* entity)
			{
				int idx = entity->client->ps.clientNum;

				if (helpers::isonhostteam(idx))
				{
					if (helpers::isalive(idx))
					{
						if (structure[idx].isopen)
						{
							if (structure[idx].wait > 1)
							{
								closemenu(idx);

								structure[idx].wait = 0;
							}
						}
					}
				}
			}
		}
	}
}