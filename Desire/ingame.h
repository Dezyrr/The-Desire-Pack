#pragma once
#include "functions.h"

namespace game
{
	struct entity_handler
	{
		bool is_uav_enabled[18];
		bool insta_sprint_enabled[18];
		bool insta_shoots_enabled[18];
		bool always_zoomload_enabled[18];
		bool insta_spas_pump[18];
		bool unstuck[18];
		bool gflip[18];
	};
	entity_handler ent_handlr;

	namespace features
	{
		namespace ingame
		{
			struct varrs
			{
				// game settings
				bool prevent_enemy_forfeit;
				bool depatch_bounces;
				bool easy_eles;
				bool prone_anywhere;
				bool sweeping_uav;
				bool wallbang_everything;
				bool infinite_bullet_dist;
				bool miniscule_health;
				bool no_fall_damage;
				bool soft_lands;
				bool prone_spins;
				bool ladder_spins;
				bool knife_lunges;

				// team menu
				int insta_sprint;
				int insta_shoots;
				int always_zoomload;
				int always_lunge;
				int insta_spas_pump;
			};
			varrs vars;

			// bot spawning taken from hayzen
			namespace preventforfeit
			{
				void* botent = nullptr;

				void teamselect(int idx)
				{
					Scr_AddString("autoassign");
					Scr_AddString("team_marinesopfor");
					Scr_NotifyNum(idx, 0, SL_GetString("menuresponse", 0), 2);
				}

				void classselect(int idx) 
				{
					Scr_AddString("class1");
					Scr_AddString("changeclass");
					Scr_NotifyNum(idx, 0, SL_GetString("menuresponse", 0), 2);
				}

				uint32_t spawnbotthread()
				{
					if (!botent)
						return 0;

					int serverid = GetMemory<int>(0x8360922C);

					int botclientnum = static_cast<gentity_s*>(botent)->client->ps.clientNum;

					client_t* botclient = &GetMemory<client_t*>(0x83620380 + 0x3818)[botclientnum];

					SV_ExecuteClientCommand(botclient, va("mr %d 3 autoassign", serverid), 1, 0);

					Sleep(150);

					SV_ExecuteClientCommand(botclient, va("mr %d 10 class1", serverid), 1, 0);

					Sleep(150);

					SetDvar("testClients_watchKillcam", "0");
					SetDvar("testclients_doReload", "0");
					SetDvar("testclients_doMove", "0");
					SetDvar("testclients_doAttack", "0");
					SetDvar("testclients_doCrouch", "0");

					return 0;
				}

				void spawnbot()
				{
					gentity_s* bot = static_cast<gentity_s*>(botent);

					if (botent != nullptr)
					{
						return;
					}

					botent = SV_AddTestClient();

					CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(spawnbotthread), 0, 0, nullptr);
				}

				int enemyteamcount()
				{
					short hostTeam = -1;

					for (int i = 0; i < 18; i++)
					{
						if (!g_entities[i].client)
							continue;

						if (helpers::ishost(i))
						{
							hostTeam = g_entities[i].client->sess.cs.team;
							break;
						}
					}

					if (hostTeam == -1)
						return 0;

					int count = 0;

					for (int i = 0; i < 18; i++)
					{
						if (!g_entities[i].client)
							continue;

						short playerTeam = g_entities[i].client->sess.cs.team;

						if (playerTeam != hostTeam && playerTeam != 0)
							count++;
					}

					return count;
				}

				void spawnbotifnoenemies()
				{
					int enemies = enemyteamcount();

					if (enemies == 0 && !botent)
					{
						spawnbot();
					}
				}

				void waitforbotnamechange()
				{
					if (!botent)
						return;

					int botclientnum = static_cast<gentity_s*>(botent)->client->ps.clientNum;

					if (helpers::isbot(botclientnum))
					{
						helpers::setclientname(botclientnum, "Waiting for player");
					}
				}

				void tpbottoself()
				{
					if (!helpers::ishost(helpers::getlocalidx()))
						return;

					if (!botent)
						return;

					int botclientnum = static_cast<gentity_s*>(botent)->client->ps.clientNum;

					gentity_s player = g_entities[botclientnum];
					gentity_s self = g_entities[helpers::getlocalidx()];

					if (player.client && self.client)
					{
						if (helpers::isbot(botclientnum))
						{
							SetClientOrigin(&player, vec3_t(self.client->ps.origin.x, self.client->ps.origin.y, self.client->ps.origin.z));
						}
					}
				}
			}

			void sweeping_uav()
			{
				for (int i = 0; i < 18; i++)
				{
					if (!g_entities[i].client)
						continue;

					if (!helpers::isonhostteam(i))
						continue;

					if (!helpers::isalive(i))
						continue;
					
					helpers::enableuav(i, vars.sweeping_uav);
				}
			}

			void handle_in_game_features()
			{
				if (CURGAME == MW2)
				{
					if (features::ingame::vars.prevent_enemy_forfeit)
					{
						features::ingame::preventforfeit::waitforbotnamechange();
						features::ingame::preventforfeit::spawnbotifnoenemies();
					}
					else
					{
						if (features::ingame::preventforfeit::botent != nullptr)
						{
							int botclientnum = static_cast<gentity_s*>(features::ingame::preventforfeit::botent)->client->ps.clientNum;

							if (helpers::isbot(botclientnum))
							{
								helpers::kickclient(botclientnum);
								features::ingame::preventforfeit::botent = nullptr;
							}
						}
					}

					features::ingame::sweeping_uav();

					// depatch bounces
					if (features::ingame::vars.depatch_bounces)
					{
						*(short*)(0x820D216C) = 0x4800;
						*(int*)(0x820DABE4) = 0x48000018;
					}
					else
					{
						*(short*)(0x820D216C) = 0x4198;
						*(int*)(0x820DABE4) = 0x409AFFB0;
					}

					// easy eles
					if (features::ingame::vars.easy_eles)
					{
						*(short*)(0x820D8360) = 0x4800;
						*(int*)(0x820D8310) = 0x60000000;
						*(int*)(0x820D4E74) = 0x60000000;
						*(int*)(0x820D4F34) = 0x60000000;
						*(int*)(0x820D5020) = 0x60000000;
					}
					else
					{
						*(short*)(0x820D8360) = 0x419A;
						*(int*)(0x820D8310) = 0x409A0054;
						*(int*)(0x820D4E74) = 0x409A002C;
						*(int*)(0x820D4F34) = 0x409A002C;
						*(int*)(0x820D5020) = 0x409A002C;
					}

					// prone anywhere
					if (features::ingame::vars.prone_anywhere)
					{
						*(byte*)(0x820D47CB) = 0x01;
						*(byte*)(0x820D47C3) = 0x01;
						*(short*)(0x820CFBAC) = 0x4800;
						*(int*)(0x820CFC2C) = 0x60000000;
						*(short*)(0x820CFC38) = 0x4800;
						*(byte*)(0x820CFDDB) = 0x01;
					}
					else
					{
						*(byte*)(0x820D47CB) = 0x00;
						*(byte*)(0x820D47C3) = 0x01;
						*(short*)(0x820CFBAC) = 0x409A;
						*(int*)(0x820CFC2C) = 0x419A0010;
						*(short*)(0x820CFC38) = 0x419A;
						*(byte*)(0x820CFDDB) = 0x00;
					}

					// wallbang everything
					if (features::ingame::vars.wallbang_everything)
					{
						*(float*)(0x82008898) = 9999999.0;
						*(int*)(0x820E217C) = 0x60000000;
						*(int*)(0x820E2184) = 0xC02B8898;
					}
					else
					{
						*(float*)(0x82008898) = 3590.0;
						*(int*)(0x820E217C) = 0x409A0010;
						*(int*)(0x820E2184) = 0xC02B99C0;
					}

					// inf bullet dist
					if (features::ingame::vars.infinite_bullet_dist)
					{
						*(int*)(0x821CF3E4) = 0xC3EB8898;
						*(short*)(0x821CF3C4) = 0x4800;
						*(float*)(0x82008898) = 9999999.0;
					}
					else
					{
						*(float*)(0x82008898) = 3590.0;
						*(int*)(0x821CF3E4) = 0xC3EB8C98;
						*(short*)(0x821CF3C4) = 0x419A;
					}

					if (features::ingame::vars.prone_spins)
					{
						Cbuf_AddText(0, "bg_prone_yawcap 360;");
					}
					else
					{
						Cbuf_AddText(0, "bg_prone_yawcap 85;");
					}

					if (features::ingame::vars.ladder_spins)
					{
						Cbuf_AddText(0, "bg_ladder_yawcap 360;");
					}
					else
					{
						Cbuf_AddText(0, "bg_ladder_yawcap 100;");
					}
				}

				if (CURGAME == BO2)
				{
					// depatch bounces
					if (features::ingame::vars.depatch_bounces)
					{
						*(int*)(0x8269F688) = 0x60000000;
					}
					else
					{
						*(int*)(0x8269F688) = 0x419AFFC4;
					}

					// depatch eles
					if (features::ingame::vars.easy_eles)
					{
						*(int*)(0x8255D220) = 0x60000000;
						*(short*)(0x82231964) = 0x4800;
						*(int*)(0x82237038) = 0x60000000;
						*(int*)(0x82239B90) = 0x60000000;
					}
					else
					{
						*(int*)(0x8255D220) = 0x409A0054;
						*(short*)(0x82231964) = 0x419A;
						*(int*)(0x82237038) = 0x409A0014;
						*(int*)(0x82239B90) = 0x409A0014;
					}

					if (features::ingame::vars.miniscule_health)
					{
						Cbuf_AddText(0, "1shotsnipers 1;");
					}
					else
					{
						Cbuf_AddText(0, "1shotsnipers 0;");
					}

					if (features::ingame::vars.prone_spins)
					{
						Cbuf_AddText(0, "pronespins 1;");
					}
					else
					{
						Cbuf_AddText(0, "pronespins 0;");
					}

					if (features::ingame::vars.ladder_spins)
					{
						Cbuf_AddText(0, "ladderspins 1;");
					}
					else
					{
						Cbuf_AddText(0, "ladderspins 0;");
					}

					if (features::ingame::vars.knife_lunges)
					{
						Dvar_FindVar("tu_aim_automelee_fix1")->current.value = 0;
						Dvar_FindVar("aim_automelee_move_limit_range")->current.value = 9999.0f;
						Dvar_FindVar("tu7_clampMeleeChargeJumping")->current.value = 0;
						Dvar_FindVar("tu7_clampMeleeChargeHorzLaunch")->current.value = 0;
						Dvar_FindVar("tu7_clampMeleeChargeJumpingMaxZVel")->current.value = 9999.0f;
					}
					else
					{
						// idk default values and cba to store them right now so fucking have fun with this hardcode
						Dvar_FindVar("tu_aim_automelee_fix1")->current.value = 1;
						Dvar_FindVar("aim_automelee_move_limit_range")->current.value = 125.f;
						Dvar_FindVar("tu7_clampMeleeChargeJumping")->current.value = 1;
						Dvar_FindVar("tu7_clampMeleeChargeHorzLaunch")->current.value = 1;
						Dvar_FindVar("tu7_clampMeleeChargeJumpingMaxZVel")->current.value = 125.f;
					}
				}
			}
		}
	}
}