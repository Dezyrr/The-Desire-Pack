#pragma once
#include "includes.h"
#include "functions.h"

namespace game
{
	struct entity_handler
	{
		bool is_uav_enabled[18];
		bool insta_sprint_enabled[18];
		bool insta_shoots_enabled[18];
		bool has_inited_menu[18];
	};
	entity_handler ent_handlr;

	namespace features
	{
		namespace ingame
		{
			struct varrs
			{
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
			};
			varrs vars;

			void sweeping_uav()
			{
				for (int i = 0; i < 18; i++)
				{
					if (!g_entities[i].client)
						continue;

					gentity_s player = g_entities[i];

					if (!helpers::isonhostteam(i))
						continue;

					if (player.health < 1)
						continue;

					if (features::ingame::vars.sweeping_uav && !ent_handlr.is_uav_enabled[i])
					{
						*(byte*)(0x830CF264 + (player.client->ps.clientNum * 0x3700)) = 0x01;
						ent_handlr.is_uav_enabled[i] = true;
					}

					if (!features::ingame::vars.sweeping_uav && ent_handlr.is_uav_enabled[i])
					{
						*(byte*)(0x830CF264 + (player.client->ps.clientNum * 0x3700)) = 0x00;
						ent_handlr.is_uav_enabled[i] = false;
					}
				}
			}

			void handle_in_game_features()
			{
				if (CURGAME == MW2)
				{
					Cbuf_AddText(0, "sv_cheats 1;");

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
						if (*(int*)(0x821CF3E4) != 0xC3EB8898)
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
						if (*(int*)(0x820E2184) != 0xC02B8898)
							*(float*)(0x82008898) = 3590.0;

						*(int*)(0x821CF3E4) = 0xC3EB8C98;
						*(short*)(0x821CF3C4) = 0x419A;
					}

					if (features::ingame::vars.miniscule_health)
					{
						Cbuf_AddText(0, "scr_player_maxhealth 30;");
					}
					else
					{
						Cbuf_AddText(0, "scr_player_maxhealth 100;");
					}

					if (features::ingame::vars.no_fall_damage)
					{
						Cbuf_AddText(0, "bg_fallDamageMinHeight 9999;");
					}
					else
					{
						Cbuf_AddText(0, "bg_fallDamageMinHeight 128;");
					}

					if (features::ingame::vars.soft_lands)
					{
						Cbuf_AddText(0, "bg_softLandingMinHeight 0;bg_softLandingMaxHeight 0;bg_softlandingmaxdamage 0.1;");
					}
					else
					{
						Cbuf_AddText(0, "bg_softLandingMinHeight 128;bg_softLandingMaxHeight 300;bg_softlandingmaxdamage 0.1;");
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

					features::ingame::sweeping_uav();
				}
				else
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
				}
			}
		}
	}
}