#pragma once
#include "functions.h"
#include "notifications.h"

namespace game
{
	namespace features
	{
		namespace customisation
		{
			struct varrs
			{
				bool custom_callingcards_enabled;
				bool wasingame;

				bool give_secondary_camo;
				int secondary_camo;

				bool custom_hud_color;
				int hudcolor_r;
				int hudcolor_g;
				int hudcolor_b;

				bool custom_camo_color;
				int camocolor_r;
				int camocolor_g;
				int camocolor_b;

				int custom_camo_select;
				int custom_camo_replace;
				bool has_camo_selected;

				void init()
				{
					hudcolor_r = 255;
					hudcolor_g = 255;
					hudcolor_b = 255;

					camocolor_r = 255;
					camocolor_g = 255;
					camocolor_b = 255;
				}
			};
			varrs vars;

			void customcamos()
			{
				if (!helpers::isingame())
					return;

				if (CURGAME == MW2)
				{
					/*
						name: [width, height, format, depth, levelCount]
						weapon_camo_woodland: [64, 64, 438305106, 1, 7]
						weapon_camo_desert : [64, 64, 438305106, 1, 7]
						weapon_camo_arctic : [128, 128, 671089019, 1, 8]
						weapon_camo_digital : [64, 64, 671089019, 1, 7]
						weapon_camo_red_urban : [64, 64, 438305106, 1, 7]
						weapon_camo_red_tiger : [64, 64, 438305106, 1, 7]
						weapon_camo_blue_tiger : [64, 64, 438305106, 1, 7]
						weapon_camo_orange_fall : [64, 64, 438305106, 1, 7]
					*/

					const char* camo_to_replace = "";

					switch (features::customisation::vars.custom_camo_replace)
					{
						case 0: camo_to_replace = "weapon_camo_woodland"; break;
						case 1: camo_to_replace = "weapon_camo_desert"; break;
						case 2: camo_to_replace = "weapon_camo_arctic"; break;
						case 3: camo_to_replace = "weapon_camo_digital"; break;
						case 4: camo_to_replace = "weapon_camo_red_urban"; break;
						case 5: camo_to_replace = "weapon_camo_red_tiger"; break;
						case 6: camo_to_replace = "weapon_camo_blue_tiger"; break;
						case 7: camo_to_replace = "weapon_camo_orange_fall"; break;
					}

					if (camo_to_replace != "")
					{
						switch (features::customisation::vars.custom_camo_select)
						{
							case 0: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\white.bin"); break;
							case 1: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\pink.bin"); break;
							case 2: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\green.bin"); break;
							case 3: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\blue.bin"); break;
							case 4: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\red.bin"); break;
							case 5: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\orange.bin"); break;
							case 6: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\purple.bin"); break;
							case 7: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\arcade_carpet.bin"); break;
							case 8: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\party_rock.bin"); break;
							case 9: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\cherry_blossom.bin"); break;
							case 10: helpers::replacematerial(camo_to_replace, "hdd:\\desire\\camos\\mw2\\royalty_tiger.bin"); break;
						}
					}
				}

				if (CURGAME == BO2)
				{
					//helpers::replacematerial(_("t6_camo_mango_pattern"), _("hdd:\\desire\\camos\\bo2\\camo_bo2.bin"));

					//auto t6_camo_mango_pattern = DB_FindXAssetHeaderBO2(XAssetTypeBO2::_ASSET_TYPE_IMAGE, "t6_camo_mango_pattern", false, 0);

					//helpers::printimageinfobo2(t6_camo_mango_pattern);
				}
			}

			void camothread()
			{
				while (!game::moduleunloading())
				{
					if (features::customisation::vars.has_camo_selected)
						customcamos();

					Sleep(1000);
				}
			}

			void customprestiges()
			{
				if (CURGAME == BO2)
				{

				}
			}

			void customemblems()
			{
				if (CURGAME == MW2)
				{
					helpers::replacematerial(_("cardicon_prestige10_02"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige10_02.bin"));
					helpers::replacematerial(_("cardicon_prestige10_01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige10_01.bin"));
					helpers::replacematerial(_("cardicon_8_bit_price"), _("hdd:\\desire\\emblems\\mw2\\cardicon_8_bit_price.bin"));
					helpers::replacematerial(_("cardicon_8ball"), _("hdd:\\desire\\emblems\\mw2\\cardicon_8ball.bin"));
					helpers::replacematerial(_("cardicon_abduction"), _("hdd:\\desire\\emblems\\mw2\\cardicon_abduction.bin"));
					helpers::replacematerial(_("cardicon_abrams"), _("hdd:\\desire\\emblems\\mw2\\cardicon_abrams.bin"));
					helpers::replacematerial(_("cardicon_ac130_angelflare"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ac130_angelflare.bin"));
					helpers::replacematerial(_("cardicon_aircraft_01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_aircraft_01.bin"));
					helpers::replacematerial(_("cardicon_animal"), _("hdd:\\desire\\emblems\\mw2\\cardicon_animal.bin"));
					helpers::replacematerial(_("cardicon_assad"), _("hdd:\\desire\\emblems\\mw2\\cardicon_assad.bin"));
					helpers::replacematerial(_("cardicon_award_jets"), _("hdd:\\desire\\emblems\\mw2\\cardicon_award_jets.bin"));
					helpers::replacematerial(_("cardicon_b2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_b2.bin"));
					helpers::replacematerial(_("cardicon_ball_baseball_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ball_baseball_1.bin"));
					helpers::replacematerial(_("cardicon_ball_volleyball_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ball_volleyball_1.bin"));
					helpers::replacematerial(_("cardicon_bear"), _("hdd:\\desire\\emblems\\mw2\\cardicon_bear.bin"));
					helpers::replacematerial(_("cardicon_binoculars_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_binoculars_1.bin"));
					helpers::replacematerial(_("cardicon_biohazard"), _("hdd:\\desire\\emblems\\mw2\\cardicon_biohazard.bin"));
					helpers::replacematerial(_("cardicon_birdbrain"), _("hdd:\\desire\\emblems\\mw2\\cardicon_birdbrain.bin"));
					helpers::replacematerial(_("cardicon_blast_shield"), _("hdd:\\desire\\emblems\\mw2\\cardicon_blast_shield.bin"));
					helpers::replacematerial(_("cardicon_booniehat"), _("hdd:\\desire\\emblems\\mw2\\cardicon_booniehat.bin"));
					helpers::replacematerial(_("cardicon_boot"), _("hdd:\\desire\\emblems\\mw2\\cardicon_boot.bin"));
					helpers::replacematerial(_("cardicon_boots_01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_boots_01.bin"));
					helpers::replacematerial(_("cardicon_boots_02"), _("hdd:\\desire\\emblems\\mw2\\cardicon_boots_02.bin"));
					helpers::replacematerial(_("cardicon_brassknuckles"), _("hdd:\\desire\\emblems\\mw2\\cardicon_brassknuckles.bin"));
					helpers::replacematerial(_("cardicon_brit_beret"), _("hdd:\\desire\\emblems\\mw2\\cardicon_brit_beret.bin"));
					helpers::replacematerial(_("cardicon_bulb"), _("hdd:\\desire\\emblems\\mw2\\cardicon_bulb.bin"));
					helpers::replacematerial(_("cardicon_bullet_case"), _("hdd:\\desire\\emblems\\mw2\\cardicon_bullet_case.bin"));
					helpers::replacematerial(_("cardicon_bullets_50cal"), _("hdd:\\desire\\emblems\\mw2\\cardicon_bullets_50cal.bin"));
					helpers::replacematerial(_("cardicon_burgertown"), _("hdd:\\desire\\emblems\\mw2\\cardicon_burgertown.bin"));
					helpers::replacematerial(_("cardicon_c4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_c4.bin"));
					helpers::replacematerial(_("cardicon_car"), _("hdd:\\desire\\emblems\\mw2\\cardicon_car.bin"));
					helpers::replacematerial(_("cardicon_chicken"), _("hdd:\\desire\\emblems\\mw2\\cardicon_chicken.bin"));
					helpers::replacematerial(_("cardicon_circuit"), _("hdd:\\desire\\emblems\\mw2\\cardicon_circuit.bin"));
					helpers::replacematerial(_("cardicon_claw"), _("hdd:\\desire\\emblems\\mw2\\cardicon_claw.bin"));
					helpers::replacematerial(_("cardicon_claymore"), _("hdd:\\desire\\emblems\\mw2\\cardicon_claymore.bin"));
					helpers::replacematerial(_("cardicon_cod4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_cod4.bin"));
					helpers::replacematerial(_("cardicon_comic_price"), _("hdd:\\desire\\emblems\\mw2\\cardicon_comic_price.bin"));
					helpers::replacematerial(_("cardicon_comic_shepherd"), _("hdd:\\desire\\emblems\\mw2\\cardicon_comic_shepherd.bin"));
					helpers::replacematerial(_("cardicon_compass"), _("hdd:\\desire\\emblems\\mw2\\cardicon_compass.bin"));
					helpers::replacematerial(_("cardicon_copycat"), _("hdd:\\desire\\emblems\\mw2\\cardicon_copycat.bin"));
					helpers::replacematerial(_("cardicon_default"), _("hdd:\\desire\\emblems\\mw2\\cardicon_default.bin"));
					helpers::replacematerial(_("cardicon_devilfinger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_devilfinger.bin"));
					helpers::replacematerial(_("cardicon_dogtags_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_dogtags_1.bin"));
					helpers::replacematerial(_("cardicon_doubletap"), _("hdd:\\desire\\emblems\\mw2\\cardicon_doubletap.bin"));
					helpers::replacematerial(_("cardicon_eagle"), _("hdd:\\desire\\emblems\\mw2\\cardicon_eagle.bin"));
					helpers::replacematerial(_("cardicon_electro"), _("hdd:\\desire\\emblems\\mw2\\cardicon_electro.bin"));
					helpers::replacematerial(_("cardicon_expert_aa12"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_aa12.bin"));
					helpers::replacematerial(_("cardicon_expert_ak47"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_ak47.bin"));
					helpers::replacematerial(_("cardicon_expert_aug"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_aug.bin"));
					helpers::replacematerial(_("cardicon_expert_barrett"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_barrett.bin"));
					helpers::replacematerial(_("cardicon_expert_beretta"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_beretta.bin"));
					helpers::replacematerial(_("cardicon_expert_beretta393"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_beretta393.bin"));
					helpers::replacematerial(_("cardicon_expert_cheytac"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_cheytac.bin"));
					helpers::replacematerial(_("cardicon_expert_coltanaconda"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_coltanaconda.bin"));
					helpers::replacematerial(_("cardicon_expert_deserteagle"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_deserteagle.bin"));
					helpers::replacematerial(_("cardicon_expert_fal"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_fal.bin"));
					helpers::replacematerial(_("cardicon_expert_famas"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_famas.bin"));
					helpers::replacematerial(_("cardicon_expert_fn2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_fn2000.bin"));
					helpers::replacematerial(_("cardicon_expert_glock"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_glock.bin"));
					helpers::replacematerial(_("cardicon_expert_kriss"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_kriss.bin"));
					helpers::replacematerial(_("cardicon_expert_m1014"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_m1014.bin"));
					helpers::replacematerial(_("cardicon_expert_m16"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_m16.bin"));
					helpers::replacematerial(_("cardicon_expert_m21"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_m21.bin"));
					helpers::replacematerial(_("cardicon_expert_m240"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_m240.bin"));
					helpers::replacematerial(_("cardicon_expert_m4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_m4.bin"));
					helpers::replacematerial(_("cardicon_expert_masada"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_masada.bin"));
					helpers::replacematerial(_("cardicon_expert_mg4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_mg4.bin"));
					helpers::replacematerial(_("cardicon_expert_model1887"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_model1887.bin"));
					helpers::replacematerial(_("cardicon_expert_mp5k"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_mp5k.bin"));
					helpers::replacematerial(_("cardicon_expert_p90"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_p90.bin"));
					helpers::replacematerial(_("cardicon_expert_pp2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_pp2000.bin"));
					helpers::replacematerial(_("cardicon_expert_ranger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_ranger.bin"));
					helpers::replacematerial(_("cardicon_expert_rpd"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_rpd.bin"));
					helpers::replacematerial(_("cardicon_expert_sa80"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_sa80.bin"));
					helpers::replacematerial(_("cardicon_expert_scar"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_scar.bin"));
					helpers::replacematerial(_("cardicon_expert_spas12"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_spas12.bin"));
					helpers::replacematerial(_("cardicon_expert_striker"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_striker.bin"));
					helpers::replacematerial(_("cardicon_expert_tavor"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_tavor.bin"));
					helpers::replacematerial(_("cardicon_expert_tmp"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_tmp.bin"));
					helpers::replacematerial(_("cardicon_expert_ump45"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_ump45.bin"));
					helpers::replacematerial(_("cardicon_expert_usp"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_usp.bin"));
					helpers::replacematerial(_("cardicon_expert_uzi"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_uzi.bin"));
					helpers::replacematerial(_("cardicon_expert_wa2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_expert_wa2000.bin"));
					helpers::replacematerial(_("cardicon_f15"), _("hdd:\\desire\\emblems\\mw2\\cardicon_f15.bin"));
					helpers::replacematerial(_("cardicon_final_stand"), _("hdd:\\desire\\emblems\\mw2\\cardicon_final_stand.bin"));
					helpers::replacematerial(_("cardicon_flare"), _("hdd:\\desire\\emblems\\mw2\\cardicon_flare.bin"));
					helpers::replacematerial(_("cardicon_fmj"), _("hdd:\\desire\\emblems\\mw2\\cardicon_fmj.bin"));
					helpers::replacematerial(_("cardicon_frag_grenade"), _("hdd:\\desire\\emblems\\mw2\\cardicon_frag_grenade.bin"));
					helpers::replacematerial(_("cardicon_gasmask"), _("hdd:\\desire\\emblems\\mw2\\cardicon_gasmask.bin"));
					helpers::replacematerial(_("cardicon_gears"), _("hdd:\\desire\\emblems\\mw2\\cardicon_gears.bin"));
					helpers::replacematerial(_("cardicon_ghillie"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ghillie.bin"));
					helpers::replacematerial(_("cardicon_ghost"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ghost.bin"));
					helpers::replacematerial(_("cardicon_ghost_bust"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ghost_bust.bin"));
					helpers::replacematerial(_("cardicon_ghost_mic"), _("hdd:\\desire\\emblems\\mw2\\cardicon_ghost_mic.bin"));
					helpers::replacematerial(_("cardicon_girlskull"), _("hdd:\\desire\\emblems\\mw2\\cardicon_girlskull.bin"));
					helpers::replacematerial(_("cardicon_gloss_grenade"), _("hdd:\\desire\\emblems\\mw2\\cardicon_gloss_grenade.bin"));
					helpers::replacematerial(_("cardicon_gold"), _("hdd:\\desire\\emblems\\mw2\\cardicon_gold.bin"));
					helpers::replacematerial(_("cardicon_grenadepulldeath"), _("hdd:\\desire\\emblems\\mw2\\cardicon_grenadepulldeath.bin"));
					helpers::replacematerial(_("cardicon_grigsby"), _("hdd:\\desire\\emblems\\mw2\\cardicon_grigsby.bin"));
					helpers::replacematerial(_("cardicon_gumby"), _("hdd:\\desire\\emblems\\mw2\\cardicon_gumby.bin"));
					helpers::replacematerial(_("cardicon_harrier"), _("hdd:\\desire\\emblems\\mw2\\cardicon_harrier.bin"));
					helpers::replacematerial(_("cardicon_hat_n_knife"), _("hdd:\\desire\\emblems\\mw2\\cardicon_hat_n_knife.bin"));
					helpers::replacematerial(_("cardicon_hazard"), _("hdd:\\desire\\emblems\\mw2\\cardicon_hazard.bin"));
					helpers::replacematerial(_("cardicon_headshot"), _("hdd:\\desire\\emblems\\mw2\\cardicon_headshot.bin"));
					helpers::replacematerial(_("cardicon_heartbeatsensor"), _("hdd:\\desire\\emblems\\mw2\\cardicon_heartbeatsensor.bin"));
					helpers::replacematerial(_("cardicon_helmet_army"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_army.bin"));
					helpers::replacematerial(_("cardicon_helmet_brit_ww2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_brit_ww2.bin"));
					helpers::replacematerial(_("cardicon_helmet_medic"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_medic.bin"));
					helpers::replacematerial(_("cardicon_helmet_pilot"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_pilot.bin"));
					helpers::replacematerial(_("cardicon_helmet_ranger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_ranger.bin"));
					helpers::replacematerial(_("cardicon_helmet_samurai"), _("hdd:\\desire\\emblems\\mw2\\cardicon_helmet_samurai.bin"));
					helpers::replacematerial(_("cardicon_hipflask"), _("hdd:\\desire\\emblems\\mw2\\cardicon_hipflask.bin"));
					helpers::replacematerial(_("cardicon_honeybadger01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_honeybadger01.bin"));
					helpers::replacematerial(_("cardicon_humantrophy"), _("hdd:\\desire\\emblems\\mw2\\cardicon_humantrophy.bin"));
					helpers::replacematerial(_("cardicon_hummer"), _("hdd:\\desire\\emblems\\mw2\\cardicon_hummer.bin"));
					helpers::replacematerial(_("cardicon_hyena"), _("hdd:\\desire\\emblems\\mw2\\cardicon_hyena.bin"));
					helpers::replacematerial(_("cardicon_illuminati"), _("hdd:\\desire\\emblems\\mw2\\cardicon_illuminati.bin"));
					helpers::replacematerial(_("cardicon_iss"), _("hdd:\\desire\\emblems\\mw2\\cardicon_iss.bin"));
					helpers::replacematerial(_("cardicon_joystick"), _("hdd:\\desire\\emblems\\mw2\\cardicon_joystick.bin"));
					helpers::replacematerial(_("cardicon_juggernaut_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_juggernaut_1.bin"));
					helpers::replacematerial(_("cardicon_juggernaut_2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_juggernaut_2.bin"));
					helpers::replacematerial(_("cardicon_kinggorilla"), _("hdd:\\desire\\emblems\\mw2\\cardicon_kinggorilla.bin"));
					helpers::replacematerial(_("cardicon_launcher"), _("hdd:\\desire\\emblems\\mw2\\cardicon_launcher.bin"));
					helpers::replacematerial(_("cardicon_league_grenade"), _("hdd:\\desire\\emblems\\mw2\\cardicon_league_grenade.bin"));
					helpers::replacematerial(_("cardicon_loadedfinger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_loadedfinger.bin"));
					helpers::replacematerial(_("cardicon_locked"), _("hdd:\\desire\\emblems\\mw2\\cardicon_locked.bin"));
					helpers::replacematerial(_("cardicon_makarov"), _("hdd:\\desire\\emblems\\mw2\\cardicon_makarov.bin"));
					helpers::replacematerial(_("cardicon_marksman_aa12"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_aa12.bin"));
					helpers::replacematerial(_("cardicon_marksman_ak47"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_ak47.bin"));
					helpers::replacematerial(_("cardicon_marksman_aug"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_aug.bin"));
					helpers::replacematerial(_("cardicon_marksman_barrett"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_barrett.bin"));
					helpers::replacematerial(_("cardicon_marksman_beretta"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_beretta.bin"));
					helpers::replacematerial(_("cardicon_marksman_beretta393"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_beretta393.bin"));
					helpers::replacematerial(_("cardicon_marksman_cheytac"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_cheytac.bin"));
					helpers::replacematerial(_("cardicon_marksman_coltanaconda"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_coltanaconda.bin"));
					helpers::replacematerial(_("cardicon_marksman_deserteagle"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_deserteagle.bin"));
					helpers::replacematerial(_("cardicon_marksman_fal"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_fal.bin"));
					helpers::replacematerial(_("cardicon_marksman_famas"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_famas.bin"));
					helpers::replacematerial(_("cardicon_marksman_fn2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_fn2000.bin"));
					helpers::replacematerial(_("cardicon_marksman_glock"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_glock.bin"));
					helpers::replacematerial(_("cardicon_marksman_kriss"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_kriss.bin"));
					helpers::replacematerial(_("cardicon_marksman_m1014"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_m1014.bin"));
					helpers::replacematerial(_("cardicon_marksman_m16"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_m16.bin"));
					helpers::replacematerial(_("cardicon_marksman_m21"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_m21.bin"));
					helpers::replacematerial(_("cardicon_marksman_m240"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_m240.bin"));
					helpers::replacematerial(_("cardicon_marksman_m4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_m4.bin"));
					helpers::replacematerial(_("cardicon_marksman_masada"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_masada.bin"));
					helpers::replacematerial(_("cardicon_marksman_mg4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_mg4.bin"));
					helpers::replacematerial(_("cardicon_marksman_model1887"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_model1887.bin"));
					helpers::replacematerial(_("cardicon_marksman_mp5k"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_mp5k.bin"));
					helpers::replacematerial(_("cardicon_marksman_p90"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_p90.bin"));
					helpers::replacematerial(_("cardicon_marksman_pp2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_pp2000.bin"));
					helpers::replacematerial(_("cardicon_marksman_ranger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_ranger.bin"));
					helpers::replacematerial(_("cardicon_marksman_rpd"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_rpd.bin"));
					helpers::replacematerial(_("cardicon_marksman_sa80"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_sa80.bin"));
					helpers::replacematerial(_("cardicon_marksman_scar"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_scar.bin"));
					helpers::replacematerial(_("cardicon_marksman_spas12"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_spas12.bin"));
					helpers::replacematerial(_("cardicon_marksman_striker"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_striker.bin"));
					helpers::replacematerial(_("cardicon_marksman_tavor"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_tavor.bin"));
					helpers::replacematerial(_("cardicon_marksman_tmp"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_tmp.bin"));
					helpers::replacematerial(_("cardicon_marksman_ump45"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_ump45.bin"));
					helpers::replacematerial(_("cardicon_marksman_usp"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_usp.bin"));
					helpers::replacematerial(_("cardicon_marksman_uzi"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_uzi.bin"));
					helpers::replacematerial(_("cardicon_marksman_wa2000"), _("hdd:\\desire\\emblems\\mw2\\cardicon_marksman_wa2000.bin"));
					helpers::replacematerial(_("cardicon_mexican_blue"), _("hdd:\\desire\\emblems\\mw2\\cardicon_mexican_blue.bin"));
					helpers::replacematerial(_("cardicon_mexican_red"), _("hdd:\\desire\\emblems\\mw2\\cardicon_mexican_red.bin"));
					helpers::replacematerial(_("cardicon_mig"), _("hdd:\\desire\\emblems\\mw2\\cardicon_mig.bin"));
					helpers::replacematerial(_("cardicon_minigun"), _("hdd:\\desire\\emblems\\mw2\\cardicon_minigun.bin"));
					helpers::replacematerial(_("cardicon_missile_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_missile_1.bin"));
					helpers::replacematerial(_("cardicon_moon"), _("hdd:\\desire\\emblems\\mw2\\cardicon_moon.bin"));
					helpers::replacematerial(_("cardicon_motorcycle"), _("hdd:\\desire\\emblems\\mw2\\cardicon_motorcycle.bin"));
					helpers::replacematerial(_("cardicon_nightvision_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_nightvision_1.bin"));
					helpers::replacematerial(_("cardicon_nightvision_2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_nightvision_2.bin"));
					helpers::replacematerial(_("cardicon_noseart1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_noseart1.bin"));
					helpers::replacematerial(_("cardicon_nvg_star"), _("hdd:\\desire\\emblems\\mw2\\cardicon_nvg_star.bin"));
					helpers::replacematerial(_("cardicon_pacifier_blue"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pacifier_blue.bin"));
					helpers::replacematerial(_("cardicon_pacifier_pink"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pacifier_pink.bin"));
					helpers::replacematerial(_("cardicon_painkiller"), _("hdd:\\desire\\emblems\\mw2\\cardicon_painkiller.bin"));
					helpers::replacematerial(_("cardicon_paratrooper"), _("hdd:\\desire\\emblems\\mw2\\cardicon_paratrooper.bin"));
					helpers::replacematerial(_("cardicon_patch"), _("hdd:\\desire\\emblems\\mw2\\cardicon_patch.bin"));
					helpers::replacematerial(_("cardicon_pavelow"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pavelow.bin"));
					helpers::replacematerial(_("cardicon_pirate_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pirate_1.bin"));
					helpers::replacematerial(_("cardicon_pirateflag_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pirateflag_1.bin"));
					helpers::replacematerial(_("cardicon_porterjustice"), _("hdd:\\desire\\emblems\\mw2\\cardicon_porterjustice.bin"));
					helpers::replacematerial(_("cardicon_prestige10anim"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige10anim.bin"));
					helpers::replacematerial(_("cardicon_prestige10anim_02"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige10anim_02.bin"));
					helpers::replacematerial(_("cardicon_prestige_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_1.bin"));
					helpers::replacematerial(_("cardicon_prestige_10"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_10.bin"));
					helpers::replacematerial(_("cardicon_prestige_2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_2.bin"));
					helpers::replacematerial(_("cardicon_prestige_3"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_3.bin"));
					helpers::replacematerial(_("cardicon_prestige_4"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_4.bin"));
					helpers::replacematerial(_("cardicon_prestige_5"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_5.bin"));
					helpers::replacematerial(_("cardicon_prestige_6"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_6.bin"));
					helpers::replacematerial(_("cardicon_prestige_7"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_7.bin"));
					helpers::replacematerial(_("cardicon_prestige_8"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_8.bin"));
					helpers::replacematerial(_("cardicon_prestige_9"), _("hdd:\\desire\\emblems\\mw2\\cardicon_prestige_9.bin"));
					helpers::replacematerial(_("cardicon_price_ww2"), _("hdd:\\desire\\emblems\\mw2\\cardicon_price_ww2.bin"));
					helpers::replacematerial(_("cardicon_pricearctic"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pricearctic.bin"));
					helpers::replacematerial(_("cardicon_pricewoodland"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pricewoodland.bin"));
					helpers::replacematerial(_("cardicon_pushindaisies"), _("hdd:\\desire\\emblems\\mw2\\cardicon_pushindaisies.bin"));
					helpers::replacematerial(_("cardicon_radiation"), _("hdd:\\desire\\emblems\\mw2\\cardicon_radiation.bin"));
					helpers::replacematerial(_("cardicon_rank_1stlt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_1stlt1.bin"));
					helpers::replacematerial(_("cardicon_rank_2ndlt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_2ndlt1.bin"));
					helpers::replacematerial(_("cardicon_rank_bgen1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_bgen1.bin"));
					helpers::replacematerial(_("cardicon_rank_capt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_capt1.bin"));
					helpers::replacematerial(_("cardicon_rank_cmdsgtmaj1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_cmdsgtmaj1.bin"));
					helpers::replacematerial(_("cardicon_rank_col1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_col1.bin"));
					helpers::replacematerial(_("cardicon_rank_comm"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_comm.bin"));
					helpers::replacematerial(_("cardicon_rank_cpl1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_cpl1.bin"));
					helpers::replacematerial(_("cardicon_rank_fsgt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_fsgt1.bin"));
					helpers::replacematerial(_("cardicon_rank_gen1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_gen1.bin"));
					helpers::replacematerial(_("cardicon_rank_ltcol1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_ltcol1.bin"));
					helpers::replacematerial(_("cardicon_rank_ltgen1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_ltgen1.bin"));
					helpers::replacematerial(_("cardicon_rank_maj1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_maj1.bin"));
					helpers::replacematerial(_("cardicon_rank_majgen1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_majgen1.bin"));
					helpers::replacematerial(_("cardicon_rank_msgt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_msgt1.bin"));
					helpers::replacematerial(_("cardicon_rank_pfc1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_pfc1.bin"));
					helpers::replacematerial(_("cardicon_rank_pvt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_pvt1.bin"));
					helpers::replacematerial(_("cardicon_rank_sgt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_sgt1.bin"));
					helpers::replacematerial(_("cardicon_rank_sgtfc1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_sgtfc1.bin"));
					helpers::replacematerial(_("cardicon_rank_sgtmaj1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_sgtmaj1.bin"));
					helpers::replacematerial(_("cardicon_rank_spc1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_spc1.bin"));
					helpers::replacematerial(_("cardicon_rank_ssgt1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rank_ssgt1.bin"));
					helpers::replacematerial(_("cardicon_red_devil"), _("hdd:\\desire\\emblems\\mw2\\cardicon_red_devil.bin"));
					helpers::replacematerial(_("cardicon_redhand"), _("hdd:\\desire\\emblems\\mw2\\cardicon_redhand.bin"));
					helpers::replacematerial(_("cardicon_redhead"), _("hdd:\\desire\\emblems\\mw2\\cardicon_redhead.bin"));
					helpers::replacematerial(_("cardicon_rhino"), _("hdd:\\desire\\emblems\\mw2\\cardicon_rhino.bin"));
					helpers::replacematerial(_("cardicon_riot_shield"), _("hdd:\\desire\\emblems\\mw2\\cardicon_riot_shield.bin"));
					helpers::replacematerial(_("cardicon_russian_beret"), _("hdd:\\desire\\emblems\\mw2\\cardicon_russian_beret.bin"));
					helpers::replacematerial(_("cardicon_sami"), _("hdd:\\desire\\emblems\\mw2\\cardicon_sami.bin"));
					helpers::replacematerial(_("cardicon_seasnipers"), _("hdd:\\desire\\emblems\\mw2\\cardicon_seasnipers.bin"));
					helpers::replacematerial(_("cardicon_semtex"), _("hdd:\\desire\\emblems\\mw2\\cardicon_semtex.bin"));
					helpers::replacematerial(_("cardicon_shotgun_shells"), _("hdd:\\desire\\emblems\\mw2\\cardicon_shotgun_shells.bin"));
					helpers::replacematerial(_("cardicon_shuriken"), _("hdd:\\desire\\emblems\\mw2\\cardicon_shuriken.bin"));
					helpers::replacematerial(_("cardicon_simplegun"), _("hdd:\\desire\\emblems\\mw2\\cardicon_simplegun.bin"));
					helpers::replacematerial(_("cardicon_skull"), _("hdd:\\desire\\emblems\\mw2\\cardicon_skull.bin"));
					helpers::replacematerial(_("cardicon_skull_black"), _("hdd:\\desire\\emblems\\mw2\\cardicon_skull_black.bin"));
					helpers::replacematerial(_("cardicon_skullaward"), _("hdd:\\desire\\emblems\\mw2\\cardicon_skullaward.bin"));
					helpers::replacematerial(_("cardicon_skullnbones"), _("hdd:\\desire\\emblems\\mw2\\cardicon_skullnbones.bin"));
					helpers::replacematerial(_("cardicon_snakeeyes"), _("hdd:\\desire\\emblems\\mw2\\cardicon_snakeeyes.bin"));
					helpers::replacematerial(_("cardicon_sniper"), _("hdd:\\desire\\emblems\\mw2\\cardicon_sniper.bin"));
					helpers::replacematerial(_("cardicon_sniperscope"), _("hdd:\\desire\\emblems\\mw2\\cardicon_sniperscope.bin"));
					helpers::replacematerial(_("cardicon_snowmobile"), _("hdd:\\desire\\emblems\\mw2\\cardicon_snowmobile.bin"));
					helpers::replacematerial(_("cardicon_soap_bar"), _("hdd:\\desire\\emblems\\mw2\\cardicon_soap_bar.bin"));
					helpers::replacematerial(_("cardicon_stop"), _("hdd:\\desire\\emblems\\mw2\\cardicon_stop.bin"));
					helpers::replacematerial(_("cardicon_stryker"), _("hdd:\\desire\\emblems\\mw2\\cardicon_stryker.bin"));
					helpers::replacematerial(_("cardicon_sugarglider"), _("hdd:\\desire\\emblems\\mw2\\cardicon_sugarglider.bin"));
					helpers::replacematerial(_("cardicon_tank_01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tank_01.bin"));
					helpers::replacematerial(_("cardicon_taskforcearmy01"), _("hdd:\\desire\\emblems\\mw2\\cardicon_taskforcearmy01.bin"));
					helpers::replacematerial(_("cardicon_tf141"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tf141.bin"));
					helpers::replacematerial(_("cardicon_thebomb"), _("hdd:\\desire\\emblems\\mw2\\cardicon_thebomb.bin"));
					helpers::replacematerial(_("cardicon_thecow"), _("hdd:\\desire\\emblems\\mw2\\cardicon_thecow.bin"));
					helpers::replacematerial(_("cardicon_throwing_knife_soda"), _("hdd:\\desire\\emblems\\mw2\\cardicon_throwing_knife_soda.bin"));
					helpers::replacematerial(_("cardicon_throwing_knive"), _("hdd:\\desire\\emblems\\mw2\\cardicon_throwing_knive.bin"));
					helpers::replacematerial(_("cardicon_tictacboom"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tictacboom.bin"));
					helpers::replacematerial(_("cardicon_tiger"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tiger.bin"));
					helpers::replacematerial(_("cardicon_tire"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tire.bin"));
					helpers::replacematerial(_("cardicon_toon_price_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_toon_price_1.bin"));
					helpers::replacematerial(_("cardicon_treasurechest_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_treasurechest_1.bin"));
					helpers::replacematerial(_("cardicon_treasuremap_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_treasuremap_1.bin"));
					helpers::replacematerial(_("cardicon_tsunami"), _("hdd:\\desire\\emblems\\mw2\\cardicon_tsunami.bin"));
					helpers::replacematerial(_("cardicon_umbracatervae"), _("hdd:\\desire\\emblems\\mw2\\cardicon_umbracatervae.bin"));
					helpers::replacematerial(_("cardicon_vest_1"), _("hdd:\\desire\\emblems\\mw2\\cardicon_vest_1.bin"));
					helpers::replacematerial(_("cardicon_veteran"), _("hdd:\\desire\\emblems\\mw2\\cardicon_veteran.bin"));
					helpers::replacematerial(_("cardicon_warpig"), _("hdd:\\desire\\emblems\\mw2\\cardicon_warpig.bin"));
					helpers::replacematerial(_("cardicon_weed"), _("hdd:\\desire\\emblems\\mw2\\cardicon_weed.bin"));
					helpers::replacematerial(_("cardicon_xray"), _("hdd:\\desire\\emblems\\mw2\\cardicon_xray.bin"));
				}
			}

			void customcallingcards()
			{
				if (CURGAME == MW2)
				{
					helpers::replacematerial(_("cardtitle_140x32"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_140x32.bin"));
					helpers::replacematerial(_("cardtitle_208x48"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_208x48.bin"));
					helpers::replacematerial(_("cardtitle_248x20"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_248x20.bin"));
					helpers::replacematerial(_("cardtitle_248x48"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_248x48.bin"));
					helpers::replacematerial(_("cardtitle_4thofjuly_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_4thofjuly_1.bin"));
					helpers::replacematerial(_("cardtitle_abstract3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_abstract3.bin"));
					helpers::replacematerial(_("cardtitle_ac130_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_ac130_1.bin"));
					helpers::replacematerial(_("cardtitle_aircraft_carriers"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_aircraft_carriers.bin"));
					helpers::replacematerial(_("cardtitle_angry_dragon"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_angry_dragon.bin"));
					helpers::replacematerial(_("cardtitle_apocalypse"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_apocalypse.bin"));
					helpers::replacematerial(_("cardtitle_assault_expert"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_assault_expert.bin"));
					helpers::replacematerial(_("cardtitle_assault_marksman"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_assault_marksman.bin"));
					helpers::replacematerial(_("cardtitle_assault_master"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_assault_master.bin"));
					helpers::replacematerial(_("cardtitle_assault_sharpshooter"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_assault_sharpshooter.bin"));
					helpers::replacematerial(_("cardtitle_assault_veteran"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_assault_veteran.bin"));
					helpers::replacematerial(_("cardtitle_at4_rocket"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_at4_rocket.bin"));
					helpers::replacematerial(_("cardtitle_bandaid"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bandaid.bin"));
					helpers::replacematerial(_("cardtitle_benjamins"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_benjamins.bin"));
					helpers::replacematerial(_("cardtitle_blackcat"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_blackcat.bin"));
					helpers::replacematerial(_("cardtitle_blimp_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_blimp_1.bin"));
					helpers::replacematerial(_("cardtitle_bloodsplat"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bloodsplat.bin"));
					helpers::replacematerial(_("cardtitle_bloodysword"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bloodysword.bin"));
					helpers::replacematerial(_("cardtitle_bomber_pinup_girl"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bomber_pinup_girl.bin"));
					helpers::replacematerial(_("cardtitle_bombs2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bombs2.bin"));
					helpers::replacematerial(_("cardtitle_buckshot"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_buckshot.bin"));
					helpers::replacematerial(_("cardtitle_buggy"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_buggy.bin"));
					helpers::replacematerial(_("cardtitle_bullet"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_bullet.bin"));
					helpers::replacematerial(_("cardtitle_butterfly_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_butterfly_1.bin"));
					helpers::replacematerial(_("cardtitle_butterfly_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_butterfly_2.bin"));
					helpers::replacematerial(_("cardtitle_camo_arctic"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_arctic.bin"));
					helpers::replacematerial(_("cardtitle_camo_bluetiger"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_bluetiger.bin"));
					helpers::replacematerial(_("cardtitle_camo_desert"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_desert.bin"));
					helpers::replacematerial(_("cardtitle_camo_digital"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_digital.bin"));
					helpers::replacematerial(_("cardtitle_camo_fall"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_fall.bin"));
					helpers::replacematerial(_("cardtitle_camo_redtiger"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_redtiger.bin"));
					helpers::replacematerial(_("cardtitle_camo_urban"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_urban.bin"));
					helpers::replacematerial(_("cardtitle_camo_woodland"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_camo_woodland.bin"));
					helpers::replacematerial(_("cardtitle_cemetary"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cemetary.bin"));
					helpers::replacematerial(_("cardtitle_cheese"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cheese.bin"));
					helpers::replacematerial(_("cardtitle_chicken"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_chicken.bin"));
					helpers::replacematerial(_("cardtitle_cobra"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cobra.bin"));
					helpers::replacematerial(_("cardtitle_cowboy"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cowboy.bin"));
					helpers::replacematerial(_("cardtitle_cripple"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cripple.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v1_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v1_1.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v1_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v1_2.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v1_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v1_3.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v2_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v2_1.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v2_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v2_2.bin"));
					helpers::replacematerial(_("cardtitle_cutegirl_v2_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_cutegirl_v2_3.bin"));
					helpers::replacematerial(_("cardtitle_dragon_kick"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_dragon_kick.bin"));
					helpers::replacematerial(_("cardtitle_drifting"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_drifting.bin"));
					helpers::replacematerial(_("cardtitle_dynamite"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_dynamite.bin"));
					helpers::replacematerial(_("cardtitle_endofline_red"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_endofline_red.bin"));
					helpers::replacematerial(_("cardtitle_explosion"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_explosion.bin"));
					helpers::replacematerial(_("cardtitle_eyeball_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_eyeball_3.bin"));
					helpers::replacematerial(_("cardtitle_flag_australia"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_australia.bin"));
					helpers::replacematerial(_("cardtitle_flag_austria"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_austria.bin"));
					helpers::replacematerial(_("cardtitle_flag_belgium"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_belgium.bin"));
					helpers::replacematerial(_("cardtitle_flag_brazil"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_brazil.bin"));
					helpers::replacematerial(_("cardtitle_flag_canada"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_canada.bin"));
					helpers::replacematerial(_("cardtitle_flag_china"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_china.bin"));
					helpers::replacematerial(_("cardtitle_flag_czech"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_czech.bin"));
					helpers::replacematerial(_("cardtitle_flag_denmark"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_denmark.bin"));
					helpers::replacematerial(_("cardtitle_flag_elsalvador"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_elsalvador.bin"));
					helpers::replacematerial(_("cardtitle_flag_finland"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_finland.bin"));
					helpers::replacematerial(_("cardtitle_flag_france"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_france.bin"));
					helpers::replacematerial(_("cardtitle_flag_germany"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_germany.bin"));
					helpers::replacematerial(_("cardtitle_flag_greece"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_greece.bin"));
					helpers::replacematerial(_("cardtitle_flag_hongkong"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_hongkong.bin"));
					helpers::replacematerial(_("cardtitle_flag_india"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_india.bin"));
					helpers::replacematerial(_("cardtitle_flag_iran"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_iran.bin"));
					helpers::replacematerial(_("cardtitle_flag_ireland"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_ireland.bin"));
					helpers::replacematerial(_("cardtitle_flag_italy"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_italy.bin"));
					helpers::replacematerial(_("cardtitle_flag_japan"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_japan.bin"));
					helpers::replacematerial(_("cardtitle_flag_luxemburg"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_luxemburg.bin"));
					helpers::replacematerial(_("cardtitle_flag_mexico"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_mexico.bin"));
					helpers::replacematerial(_("cardtitle_flag_netherlands"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_netherlands.bin"));
					helpers::replacematerial(_("cardtitle_flag_newzealand"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_newzealand.bin"));
					helpers::replacematerial(_("cardtitle_flag_norway"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_norway.bin"));
					helpers::replacematerial(_("cardtitle_flag_philippines"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_philippines.bin"));
					helpers::replacematerial(_("cardtitle_flag_poland"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_poland.bin"));
					helpers::replacematerial(_("cardtitle_flag_portugal"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_portugal.bin"));
					helpers::replacematerial(_("cardtitle_flag_russia"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_russia.bin"));
					helpers::replacematerial(_("cardtitle_flag_saudiarabia"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_saudiarabia.bin"));
					helpers::replacematerial(_("cardtitle_flag_singapore"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_singapore.bin"));
					helpers::replacematerial(_("cardtitle_flag_southafrica"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_southafrica.bin"));
					helpers::replacematerial(_("cardtitle_flag_southkorea"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_southkorea.bin"));
					helpers::replacematerial(_("cardtitle_flag_spain"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_spain.bin"));
					helpers::replacematerial(_("cardtitle_flag_sweden"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_sweden.bin"));
					helpers::replacematerial(_("cardtitle_flag_swiss"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_swiss.bin"));
					helpers::replacematerial(_("cardtitle_flag_taiwan"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_taiwan.bin"));
					helpers::replacematerial(_("cardtitle_flag_turkey"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_turkey.bin"));
					helpers::replacematerial(_("cardtitle_flag_uk"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_uk.bin"));
					helpers::replacematerial(_("cardtitle_flag_united_arab_emirates"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_united_arab_emirates.bin"));
					helpers::replacematerial(_("cardtitle_flag_unitedstates"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flag_unitedstates.bin"));
					helpers::replacematerial(_("cardtitle_flames_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flames_1.bin"));
					helpers::replacematerial(_("cardtitle_flower_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_flower_3.bin"));
					helpers::replacematerial(_("cardtitle_gears_03"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_gears_03.bin"));
					helpers::replacematerial(_("cardtitle_general"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_general.bin"));
					helpers::replacematerial(_("cardtitle_ghillie"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_ghillie.bin"));
					helpers::replacematerial(_("cardtitle_glass_hispeed"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_glass_hispeed.bin"));
					helpers::replacematerial(_("cardtitle_graff"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_graff.bin"));
					helpers::replacematerial(_("cardtitle_graffiti_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_graffiti_1.bin"));
					helpers::replacematerial(_("cardtitle_graffiti_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_graffiti_2.bin"));
					helpers::replacematerial(_("cardtitle_harrier"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_harrier.bin"));
					helpers::replacematerial(_("cardtitle_hazard_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_hazard_3.bin"));
					helpers::replacematerial(_("cardtitle_heartbeatsensor"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_heartbeatsensor.bin"));
					helpers::replacematerial(_("cardtitle_helicopters_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_helicopters_1.bin"));
					helpers::replacematerial(_("cardtitle_hello_sticker"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_hello_sticker.bin"));
					helpers::replacematerial(_("cardtitle_horsemen"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_horsemen.bin"));
					helpers::replacematerial(_("cardtitle_horsemen_death"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_horsemen_death.bin"));
					helpers::replacematerial(_("cardtitle_horsemen_famine"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_horsemen_famine.bin"));
					helpers::replacematerial(_("cardtitle_horsemen_war"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_horsemen_war.bin"));
					helpers::replacematerial(_("cardtitle_hotdog_high"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_hotdog_high.bin"));
					helpers::replacematerial(_("cardtitle_iss01"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_iss01.bin"));
					helpers::replacematerial(_("cardtitle_jason_nvg"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_jason_nvg.bin"));
					helpers::replacematerial(_("cardtitle_joint"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_joint.bin"));
					helpers::replacematerial(_("cardtitle_kingsnake"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_kingsnake.bin"));
					helpers::replacematerial(_("cardtitle_lingerie_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_lingerie_1.bin"));
					helpers::replacematerial(_("cardtitle_lingerie_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_lingerie_2.bin"));
					helpers::replacematerial(_("cardtitle_locked"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_locked.bin"));
					helpers::replacematerial(_("cardtitle_machinegun"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_machinegun.bin"));
					helpers::replacematerial(_("cardtitle_magic"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_magic.bin"));
					helpers::replacematerial(_("cardtitle_make_it_rain"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_make_it_rain.bin"));
					helpers::replacematerial(_("cardtitle_mig15"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_mig15.bin"));
					helpers::replacematerial(_("cardtitle_moab"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_moab.bin"));
					helpers::replacematerial(_("cardtitle_mw2_black"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_mw2_black.bin"));
					helpers::replacematerial(_("cardtitle_night_vision_hi"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_night_vision_hi.bin"));
					helpers::replacematerial(_("cardtitle_operations"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_operations.bin"));
					helpers::replacematerial(_("cardtitle_pavelow"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_pavelow.bin"));
					helpers::replacematerial(_("cardtitle_pavelow_side"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_pavelow_side.bin"));
					helpers::replacematerial(_("cardtitle_pinkscar"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_pinkscar.bin"));
					helpers::replacematerial(_("cardtitle_pushindaisies"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_pushindaisies.bin"));
					helpers::replacematerial(_("cardtitle_rainbows_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_rainbows_3.bin"));
					helpers::replacematerial(_("cardtitle_rice_rocket"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_rice_rocket.bin"));
					helpers::replacematerial(_("cardtitle_roll_hard_six"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_roll_hard_six.bin"));
					helpers::replacematerial(_("cardtitle_rpg"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_rpg.bin"));
					helpers::replacematerial(_("cardtitle_samurai_lv3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_samurai_lv3.bin"));
					helpers::replacematerial(_("cardtitle_satellite"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_satellite.bin"));
					helpers::replacematerial(_("cardtitle_schooled"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_schooled.bin"));
					helpers::replacematerial(_("cardtitle_shark"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_shark.bin"));
					helpers::replacematerial(_("cardtitle_silencer"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_silencer.bin"));
					helpers::replacematerial(_("cardtitle_skateboard"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_skateboard.bin"));
					helpers::replacematerial(_("cardtitle_smoke_em"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_smoke_em.bin"));
					helpers::replacematerial(_("cardtitle_sniper_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_sniper_1.bin"));
					helpers::replacematerial(_("cardtitle_sniper_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_sniper_2.bin"));
					helpers::replacematerial(_("cardtitle_sniper_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_sniper_3.bin"));
					helpers::replacematerial(_("cardtitle_sniper_4"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_sniper_4.bin"));
					helpers::replacematerial(_("cardtitle_snowmobile"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_snowmobile.bin"));
					helpers::replacematerial(_("cardtitle_snubnose"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_snubnose.bin"));
					helpers::replacematerial(_("cardtitle_spankpaddle"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_spankpaddle.bin"));
					helpers::replacematerial(_("cardtitle_spider"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_spider.bin"));
					helpers::replacematerial(_("cardtitle_spy_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_spy_1.bin"));
					helpers::replacematerial(_("cardtitle_stpatricks_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_stpatricks_3.bin"));
					helpers::replacematerial(_("cardtitle_straight_blast"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_straight_blast.bin"));
					helpers::replacematerial(_("cardtitle_sunbather"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_sunbather.bin"));
					helpers::replacematerial(_("cardtitle_swordmaster_1"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_swordmaster_1.bin"));
					helpers::replacematerial(_("cardtitle_swordmaster_2"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_swordmaster_2.bin"));
					helpers::replacematerial(_("cardtitle_swordmaster_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_swordmaster_3.bin"));
					helpers::replacematerial(_("cardtitle_tank"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_tank.bin"));
					helpers::replacematerial(_("cardtitle_thebomb"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_thebomb.bin"));
					helpers::replacematerial(_("cardtitle_tiger"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_tiger.bin"));
					helpers::replacematerial(_("cardtitle_tomahawk"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_tomahawk.bin"));
					helpers::replacematerial(_("cardtitle_tsunami"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_tsunami.bin"));
					helpers::replacematerial(_("cardtitle_weed_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_weed_3.bin"));
					helpers::replacematerial(_("cardtitle_zero"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_zero.bin"));
					helpers::replacematerial(_("cardtitle_zombie_3"), _("hdd:\\desire\\cardtitles\\mw2\\cardtitle_zombie_3.bin"));
				}

				if (CURGAME == BO2)
				{
					helpers::replacematerial(_("emblem_bg_default"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_default.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_kap40"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_kap40.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_kap40"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_kap40.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_kap40"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_kap40.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_tac45"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_tac45.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_tac40"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_tac40.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_tac45"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_tac45.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_b23"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_b23.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_b23"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_b23.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_b23"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_b23.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_judge"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_judge.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_judge"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_judge.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_judge"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_judge.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_five_seven"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_five_seven.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_five_seven"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_five_seven.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_five_seven"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_five_seven.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_mp7"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_mp7.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_mp7"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_mp7.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_mp7"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_mp7.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_skorpion"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_skorpion.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_skorpion"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_skorpion.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_skorpion"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_skorpion.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_pdw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_pdw.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_pdw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_pdw.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_pdw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_pdw.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_chicom"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_chicom.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_chicom"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_chicom.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_chicom"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_chicom.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_msmc"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_msmc.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_msmc"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_msmc.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_msmc"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_msmc.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_vector"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_vector.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_vector"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_vector.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_vector"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_vector.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_m8a1"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_m8a1.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_m8a1"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_m8a1.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_m8a1"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_m8a1.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_scar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_scar.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_scar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_scar.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_scar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_scar.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_an94"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_an94.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_an94"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_an94.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_an94"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_an94.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_sig"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_sig.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_sig"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_sig.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_sig"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_sig.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_type25"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_type25.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_type25"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_type25.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_type25"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_type25.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_fal"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_fal.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_fal"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_fal.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_fal"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_fal.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_smr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_smr.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_smr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_smr.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_smr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_smr.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_m27"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_m27.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_m27"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_m27.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_m27"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_m27.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_mtar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_mtar.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_mtar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_mtar.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_mtar"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_mtar.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_mk48"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_mk48.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_mk48"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_mk48.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_mk48"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_mk48.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_qbb"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_qbb.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_qbb"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_qbb.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_qbb"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_qbb.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_lsat"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_lsat.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_lsat"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_lsat.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_lsat"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_lsat.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_hamr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_hamr.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_hamr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_hamr.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_hamr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_hamr.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_ballista"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_ballista.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_ballista"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_ballista.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_ballista"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_ballista.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_svu"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_svu.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_svu"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_svu.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_svu"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_svu.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_dsr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_dsr.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_dsr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_dsr.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_dsr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_dsr.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_xpr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_xpr.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_xpr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_xpr.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_xpr"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_xpr.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_mcs"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_mcs.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_mcs"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_mcs.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_mcs"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_mcs.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_m1216"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_m1216.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_m1216"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_m1216.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_m1216"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_m1216.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_saiga"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_saiga.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_saiga"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_saiga.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_saiga"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_saiga.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_ksg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_ksg.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_ksg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_ksg.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_ksg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_ksg.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_smaw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_smaw.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_smaw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_smaw.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_fhj"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_fhj.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_fhj"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_fhj.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_rpg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_rpg.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_rpg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_rpg.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_shield"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_shield.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_shield"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_shield.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_crossbow"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_crossbow.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_crossbow"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_crossbow.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_crossbow"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_crossbow.bin"));
					helpers::replacematerial(_("em_bg_wpn_camo_ballistic"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_camo_ballistic.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_ballistic"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_ballistic.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_griz_vet"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_griz_vet.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_career_wins"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_career_wins.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_top_3_player"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_top_3_player.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_hc_vet"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_hc_vet.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_hc_vanquish"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_hc_vanquish.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_hc_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_hc_superior.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_mt_vet"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_mt_vet.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_mt_vanquish"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_mt_vanquish.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_mt_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_mt_superior.bin"));
					helpers::replacematerial(_("emblem_bg_combat_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_combat_master.bin"));
					helpers::replacematerial(_("emblem_bg_ffa_hydra"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ffa_hydra.bin"));
					helpers::replacematerial(_("emblem_bg_ffa_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ffa_superior.bin"));
					helpers::replacematerial(_("emblem_bg_return_to_sender"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_return_to_sender.bin"));
					helpers::replacematerial(_("emblem_bg_movie_star"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_movie_star.bin"));
					helpers::replacematerial(_("emblem_bg_sit_aware"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_sit_aware.bin"));
					helpers::replacematerial(_("emblem_bg_precision_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_precision_master.bin"));
					helpers::replacematerial(_("emblem_bg_masterchef"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_masterchef.bin"));
					helpers::replacematerial(_("emblem_bg_backfire"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_backfire.bin"));
					helpers::replacematerial(_("emblem_bg_buzzkill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_buzzkill.bin"));
					helpers::replacematerial(_("emblem_bg_from_grave"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_from_grave.bin"));
					helpers::replacematerial(_("emblem_bg_backstabber"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_backstabber.bin"));
					helpers::replacematerial(_("emblem_bg_unforgiving"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_unforgiving.bin"));
					helpers::replacematerial(_("emblem_bg_sticky"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_sticky.bin"));
					helpers::replacematerial(_("emblem_bg_bloodthirsty"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bloodthirsty.bin"));
					helpers::replacematerial(_("emblem_bg_merciless"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_merciless.bin"));
					helpers::replacematerial(_("emblem_bg_ruthless"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ruthless.bin"));
					helpers::replacematerial(_("emblem_bg_relentless"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_relentless.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_nuclear_killer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_nuclear_killer.bin"));
					helpers::replacematerial(_("emblem_bg_double_kill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_double_kill.bin"));
					helpers::replacematerial(_("emblem_bg_triple_killer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_triple_killer.bin"));
					helpers::replacematerial(_("emblem_bg_chain_killer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_chain_killer.bin"));
					helpers::replacematerial(_("emblem_bg_mega_killer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_mega_killer.bin"));
					helpers::replacematerial(_("emblem_bg_ultra_killer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ultra_killer.bin"));
					helpers::replacematerial(_("emblem_bg_four_piece"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_four_piece.bin"));
					helpers::replacematerial(_("emblem_bg_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_master.bin"));
					helpers::replacematerial(_("emblem_bg_xray"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_xray.bin"));
					helpers::replacematerial(_("emblem_bg_spotter"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_spotter.bin"));
					helpers::replacematerial(_("emblem_bg_laid_to_rest"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_laid_to_rest.bin"));
					helpers::replacematerial(_("emblem_bg_stalking_prey"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_stalking_prey.bin"));
					helpers::replacematerial(_("emblem_bg_streak_vsat"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_vsat.bin"));
					helpers::replacematerial(_("emblem_bg_streak_emp_kill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_emp_kill.bin"));
					helpers::replacematerial(_("emblem_bg_streak_uav"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_uav.bin"));
					helpers::replacematerial(_("emblem_bg_streak_emp"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_emp.bin"));
					helpers::replacematerial(_("emblem_bg_ovsat_support"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ovsat_support.bin"));
					helpers::replacematerial(_("emblem_bg_streak_hk"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_hk.bin"));
					helpers::replacematerial(_("emblem_bg_streak_missle"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_missle.bin"));
					helpers::replacematerial(_("emblem_bg_streak_light_strike"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_light_strike.bin"));
					helpers::replacematerial(_("emblem_bg_streak_dragonfire"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_dragonfire.bin"));
					helpers::replacematerial(_("emblem_bg_streak_stealth_heli"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_stealth_heli.bin"));
					helpers::replacematerial(_("emblem_bg_streak_escort"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_escort.bin"));
					helpers::replacematerial(_("emblem_bg_streak_warthog"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_warthog.bin"));
					helpers::replacematerial(_("emblem_bg_streak_lodestar"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_lodestar.bin"));
					helpers::replacematerial(_("emblem_bg_streak_vtol"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_vtol.bin"));
					helpers::replacematerial(_("emblem_bg_streak_swarm"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_swarm.bin"));
					helpers::replacematerial(_("emblem_bg_streak_rcxd"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_rcxd.bin"));
					helpers::replacematerial(_("emblem_bg_streak_sentry"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_sentry.bin"));
					helpers::replacematerial(_("emblem_bg_streak_deathmachine"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_deathmachine.bin"));
					helpers::replacematerial(_("emblem_bg_streak_warmachine"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_warmachine.bin"));
					helpers::replacematerial(_("emblem_bg_streak_agr"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_agr.bin"));
					helpers::replacematerial(_("emblem_bg_streak_dogs"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_dogs.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_primary"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_primary.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_secondary"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_secondary.bin"));
					helpers::replacematerial(_("emblem_bg_weapons_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_weapons_master.bin"));
					helpers::replacematerial(_("emblem_bg_kills_ar"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_ar.bin"));
					helpers::replacematerial(_("emblem_bg_kills_smg"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_smg.bin"));
					helpers::replacematerial(_("emblem_bg_kills_lmg"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_lmg.bin"));
					helpers::replacematerial(_("emblem_bg_kills_shotgun"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_shotgun.bin"));
					helpers::replacematerial(_("emblem_bg_kills_sniper"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_sniper.bin"));
					helpers::replacematerial(_("emblem_bg_kills_pistol"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_pistol.bin"));
					helpers::replacematerial(_("emblem_bg_kills_score_streaks"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_score_streaks.bin"));
					helpers::replacematerial(_("emblem_bg_kills_assists"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kills_assists.bin"));
					helpers::replacematerial(_("emblem_bg_streak_uav_kill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_uav_kill.bin"));
					helpers::replacematerial(_("emblem_bg_streak_hpm_kill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_hpm_kill.bin"));
					helpers::replacematerial(_("emblem_bg_streak_cuav_kill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_cuav_kill.bin"));
					helpers::replacematerial(_("emblem_bg_streak_hpm"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_hpm.bin"));
					helpers::replacematerial(_("emblem_bg_streak_cuav"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_streak_cuav.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_reflex"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_reflex.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_acog"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_acog.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_holo"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_holo.bin"));
					helpers::replacematerial(_("em_bg_wpn_complete_hybrid"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_complete_hybrid.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_reflex"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_reflex.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_mms"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_mms.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_ironsites"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_ironsites.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_sniper"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_sniper.bin"));
					helpers::replacematerial(_("emblem_bg_att_ext_clip"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_ext_clip.bin"));
					helpers::replacematerial(_("emblem_bg_att_rapid_fire"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_rapid_fire.bin"));
					helpers::replacematerial(_("emblem_bg_att_silencer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_silencer.bin"));
					helpers::replacematerial(_("emblem_bg_att_long_barrel"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_long_barrel.bin"));
					helpers::replacematerial(_("emblem_bg_att_las_sight"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_las_sight.bin"));
					helpers::replacematerial(_("emblem_bg_att_dual_wield"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_dual_wield.bin"));
					helpers::replacematerial(_("emblem_bg_att_v_zoom"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_v_zoom.bin"));
					helpers::replacematerial(_("emblem_bg_att_fore_grip"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_fore_grip.bin"));
					helpers::replacematerial(_("emblem_bg_att_quick_draw"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_quick_draw.bin"));
					helpers::replacematerial(_("emblem_bg_att_adj_stock"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_adj_stock.bin"));
					helpers::replacematerial(_("emblem_bg_att_bal_cpu"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_bal_cpu.bin"));
					helpers::replacematerial(_("emblem_bg_att_grenade_launcher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_grenade_launcher.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_frag"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_frag.bin"));
					helpers::replacematerial(_("emblem_bg_equip_ax"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_equip_ax.bin"));
					helpers::replacematerial(_("emblem_bg_equip_stuck"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_equip_stuck.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_c4"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_c4.bin"));
					helpers::replacematerial(_("emblem_bg_bouncing_betty"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bouncing_betty.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_claymore"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_claymore.bin"));
					helpers::replacematerial(_("emblem_bg_att_select_fire"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_select_fire.bin"));
					helpers::replacematerial(_("emblem_bg_att_fmj"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_fmj.bin"));
					helpers::replacematerial(_("emblem_bg_att_fast_mag"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_fast_mag.bin"));
					helpers::replacematerial(_("emblem_bg_att_tac_knife"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_tac_knife.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_tazer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_tazer.bin"));
					helpers::replacematerial(_("emblem_bg_emp_v"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_emp_v.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_concussion"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_concussion.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_flash"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_flash.bin"));
					helpers::replacematerial(_("emblem_bg_equip_smoke"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_equip_smoke.bin"));
					helpers::replacematerial(_("emblem_bg_tacinsert_v"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_tacinsert_v.bin"));
					helpers::replacematerial(_("emblem_bg_sensor_v"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_sensor_v.bin"));
					helpers::replacematerial(_("emblem_bg_trophy_v"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_trophy_v.bin"));
					helpers::replacematerial(_("emblem_bg_pda_v"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_pda_v.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_flak"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_flak.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_ghost"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_ghost.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_blindeye"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_blindeye.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_hline"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_hline.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_lweight"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_lweight.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk2_coldblooded"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk2_coldblooded.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk1_hline2"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk1_hline2.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk2_scavenger"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk2_scavenger.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk2_fasthands"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk2_fasthands.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk2_toughness"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk2_toughness.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk3_engineer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk3_engineer.bin"));
					helpers::replacematerial(_("emblem_bg_tdm_vanquisher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_tdm_vanquisher.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk3_extreme"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk3_extreme.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk3_tacmask"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk3_tacmask.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk3_dexterity"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk3_dexterity.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_perk3_awareness"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_perk3_awareness.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_pfighter"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_pfighter.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_sfighter"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_sfighter.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_overkill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_overkill.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_dclose"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_dclose.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_tactician"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_tactician.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_p1"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_p1.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_p2"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_p2.bin"));
					helpers::replacematerial(_("emblem_bg_prestige_p3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_prestige_p3.bin"));
					helpers::replacematerial(_("emblem_bg_tdm_veteran"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_tdm_veteran.bin"));
					helpers::replacematerial(_("emblem_bg_tdm_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_tdm_superior.bin"));
					helpers::replacematerial(_("emblem_bg_snd_veteran"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_veteran.bin"));
					helpers::replacematerial(_("emblem_bg_dom_vet"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_vet.bin"));
					helpers::replacematerial(_("emblem_bg_hq_veteran3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hq_veteran3.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_veteran"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_veteran.bin"));
					helpers::replacematerial(_("emblem_bg_dem_veteran3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dem_veteran3.bin"));
					helpers::replacematerial(_("emblem_bg_kcon_vet"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kcon_vet.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_ffa"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_ffa.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_tdm"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_tdm.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_sd"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_sd.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_dom"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_dom.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_hq"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_hq.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_ctf"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_ctf.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_dem"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_dem.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_hardpoint"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_hardpoint.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_kc"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_kc.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_sharpshooter"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_sharpshooter.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_oic"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_oic.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_gungame"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_gungame.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sup_stick_stone"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sup_stick_stone.bin"));
					helpers::replacematerial(_("emblem_bg_ffa_vanquisher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ffa_vanquisher.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_ffa"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_ffa.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_tdm"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_tdm.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_s_and_d"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_s_and_d.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_dom"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_dom.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_hq"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_hq.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_ctf"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_ctf.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_demo"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_demo.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_hardpoint"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_hardpoint.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_kc"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_kc.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sharpshooter"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sharpshooter.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_sticks_stones"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_sticks_stones.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_gungame"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_gungame.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_pl_oic"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_pl_oic.bin"));
					helpers::replacematerial(_("emblem_bg_dem_destroyer3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dem_destroyer3.bin"));
					helpers::replacematerial(_("emblem_bg_snd_destroyer"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_destroyer.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_aggression"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_aggression.bin"));
					helpers::replacematerial(_("emblem_bg_dom_aggression"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_aggression.bin"));
					helpers::replacematerial(_("emblem_bg_hq_vanquisher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hq_vanquisher.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_flag_warden"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_flag_warden.bin"));
					helpers::replacematerial(_("emblem_bg_dom_vanquisher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_vanquisher.bin"));
					helpers::replacematerial(_("emblem_bg_dom_assault"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_assault.bin"));
					helpers::replacematerial(_("emblem_bg_hq_assault"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hq_assault.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_bandolier"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_bandolier.bin"));
					helpers::replacematerial(_("emblem_bg_snd_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_superior.bin"));
					helpers::replacematerial(_("emblem_bg_dom_defender"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_defender.bin"));
					helpers::replacematerial(_("emblem_bg_hq_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hq_superior.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_defender"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_defender.bin"));
					helpers::replacematerial(_("emblem_bg_dem_bomb_defuser3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dem_bomb_defuser3.bin"));
					helpers::replacematerial(_("emblem_bg_snd_bomb_defuser"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_bomb_defuser.bin"));
					helpers::replacematerial(_("emblem_bg_anti_air_iv"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_anti_air_iv.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_nuked_out"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_nuked_out.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_assassination3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_assassination3.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_escort3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_escort3.bin"));
					helpers::replacematerial(_("emblem_bg_dom_superior"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_superior.bin"));
					helpers::replacematerial(_("emblem_bg_ffa_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ffa_master.bin"));
					helpers::replacematerial(_("emblem_bg_tdm_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_tdm_master.bin"));
					helpers::replacematerial(_("emblem_bg_snd_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_master.bin"));
					helpers::replacematerial(_("emblem_bg_dom_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dom_master.bin"));
					helpers::replacematerial(_("emblem_bg_hq_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hq_master.bin"));
					helpers::replacematerial(_("emblem_bg_ctf_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_ctf_master.bin"));
					helpers::replacematerial(_("emblem_bg_dem_master3"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_dem_master3.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_ar"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_ar.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_smg"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_smg.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_shotgun"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_shotgun.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_sniper"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_sniper.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_lmg"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_lmg.bin"));
					helpers::replacematerial(_("emblem_bg_att_tritip"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_att_tritip.bin"));
					helpers::replacematerial(_("emblem_bg_hp_defenderl"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_hp_defenderl.bin"));
					helpers::replacematerial(_("emblem_bg_kcon_con"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kcon_con.bin"));
					helpers::replacematerial(_("emblem_bg_kcon_den"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kcon_den.bin"));
					helpers::replacematerial(_("emblem_bg_kcon_masterl"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kcon_masterl.bin"));
					helpers::replacematerial(_("emblem_bg_kingofhill"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_kingofhill.bin"));
					helpers::replacematerial(_("emblem_bg_pg_game_master"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_pg_game_master.bin"));
					helpers::replacematerial(_("emblem_bg_pg_gun_game"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_pg_gun_game.bin"));
					helpers::replacematerial(_("emblem_bg_pg_oic"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_pg_oic.bin"));
					helpers::replacematerial(_("emblem_bg_pg_sticks_stones"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_pg_sticks_stones.bin"));
					helpers::replacematerial(_("emblem_bg_score_master_air"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_score_master_air.bin"));
					helpers::replacematerial(_("emblem_bg_score_master_ground"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_score_master_ground.bin"));
					helpers::replacematerial(_("emblem_bg_score_master_return"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_score_master_return.bin"));
					helpers::replacematerial(_("emblem_bg_score_master_support"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_score_master_support.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_blue01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_blue01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_brown"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_brown.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_green01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_green01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_green02"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_green02.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_green03"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_green03.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_grey01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_grey01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_red01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_red01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_rust01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_rust01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_rust02"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_rust02.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_camo_yellow01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_camo_yellow01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_debris"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_debris.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_dogtags01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_dogtags01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_green_camo01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_green_camo01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_green_camo02"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_green_camo02.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_green_digital01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_green_digital01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_honeycomb01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_honeycomb01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_knife01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_knife01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_metal_camo01"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_metal_camo01.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_screens"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_screens.bin"));
					helpers::replacematerial(_("emblem_bg_junkyard"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_junkyard.bin"));
					helpers::replacematerial(_("emblem_bg_master_humiliation"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_master_humiliation.bin"));
					helpers::replacematerial(_("emblem_bg_snd_vanquisher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_snd_vanquisher.bin"));
					helpers::replacematerial(_("emblem_bg_bo2_scope"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_bo2_scope.bin"));
					helpers::replacematerial(_("emblem_bg_weapon_bootcamp"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_weapon_bootcamp.bin"));
					helpers::replacematerial(_("emblem_bg_weapon_flasher"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_weapon_flasher.bin"));
					helpers::replacematerial(_("emblem_player_1_bg"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_player_1_bg.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_gametype"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_gametype.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_scorestreak"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_scorestreak.bin"));
					helpers::replacematerial(_("emblem_bg_career_mastery_assignment"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_career_mastery_assignment.bin"));
					helpers::replacematerial(_("emblem_bg_diamond_club"), _("hdd:\\desire\\cardtitles\\bo2\\emblem_bg_diamond_club.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_smaw"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_smaw.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_fhj"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_fhj.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_rpg"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_rpg.bin"));
					helpers::replacematerial(_("em_bg_wpn_attach_shield"), _("hdd:\\desire\\cardtitles\\bo2\\em_bg_wpn_attach_shield.bin"));
				}
			}

			void applycamosonsecondaryweapon()
			{
				if (!helpers::isingame())
					return;

				auto weapidx = helpers::getsecondaryweaponidx(helpers::getlocalidx());
				auto weapstr = G_GetWeaponNameForIndex(weapidx);

				if (!weapidx || weapidx == -1)
					return;

				// shit doesn't work on models
				if (strstr(weapstr, "1887"))
					return;

				// fuck all akimbo weapons
				if (strstr(weapstr, "akimbo"))
					return;

				// fuck the pistols
				if (strstr(weapstr, "eagle") ||
					strstr(weapstr, "anaconda") ||
					strstr(weapstr, "usp") ||
					strstr(weapstr, "beretta"))
					return;

				// fuck the launchers
				if (strstr(weapstr, "m79_") ||
					strstr(weapstr, "gl_") ||
					strstr(weapstr, "at4_") ||
					strstr(weapstr, "stinger_") ||
					strstr(weapstr, "javelin_"))
					return;

				// fuck these too
				if (strstr(weapstr, "beretta393_"))
					return;

				switch (features::customisation::vars.secondary_camo)
				{
					case 0: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_WOODLAND); break;
					case 1: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_DIGITAL); break;
					case 2: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_DESERT); break;
					case 3: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_ARCTIC); break;
					case 4: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_URBAN); break;
					case 5: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_RED_TIGER); break;
					case 6: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_BLUE_TIGER); break;
					case 7: helpers::givesecondaryweaponcamo(helpers::getlocalidx(), CAMO_FALL); break;
				}
			}
		}
	}
}