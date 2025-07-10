#pragma once
#include "render.h"
#include "includes.h"
#include "functions.h"
#include "pregame.h"
#include "ingame.h"
#include "hooks.h"
#include "account.h"
#include "gsc.h"
#include "players.h"
#include "customisation.h"

namespace game
{
	namespace menu
	{
		namespace handler
		{
			enum submenus
			{
				sm_main,
				sm_matchmaking,
				sm_gamesettings,
				sm_trickshotting,
				sm_customisation,
				sm_players,
				sm_playeroptions,
				sm_account,
				sm_misc
			};

			struct menuvarrs
			{
				bool watermark;
				int current_submenu;

				void init()
				{
					watermark = true;
					current_submenu = sm_main;
				}
			};
			menuvarrs menuvars;

			struct control 
			{
				bool isopen;
				int currentoption;
				int lastoption;
				int wait;
			};
			control controls;

			void doslidercrement(bool left)
			{
				switch (menuvars.current_submenu)
				{
					case sm_matchmaking:
					{
						switch (controls.currentoption)
						{
							case 0: break;
							case 1:
							{
								if (left)
								{
									features::pregame::vars.minplayerstostart--;
									if (features::pregame::vars.minplayerstostart < 1)
										features::pregame::vars.minplayerstostart = 12;
								}
								else
								{
									features::pregame::vars.minplayerstostart++;
									if (features::pregame::vars.minplayerstostart > 12)
										features::pregame::vars.minplayerstostart = 1;
								}
								break;
							}
							case 2:
							{
								if (left)
								{
									features::pregame::vars.maxplayersinlobby--;
									if (features::pregame::vars.maxplayersinlobby < 1)
										features::pregame::vars.maxplayersinlobby = 18;
								}
								else
								{
									features::pregame::vars.maxplayersinlobby++;
									if (features::pregame::vars.maxplayersinlobby > 18)
										features::pregame::vars.maxplayersinlobby = 1;
								}
								break;
							}
							case 3: break;
							case 4: 
							{
								if (CURGAME == BO2)
								{
									if (left)
									{
										features::pregame::vars.gamemode--;
										if (features::pregame::vars.gamemode < 0)
											features::pregame::vars.gamemode = 2;
									}
									else
									{
										features::pregame::vars.gamemode++;
										if (features::pregame::vars.gamemode > 2)
											features::pregame::vars.gamemode = 0;
									}
								}
								break;
							}
						}

						break;
					}

					case sm_trickshotting:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								if (left)
								{
									features::ingame::vars.insta_shoots--;
									if (features::ingame::vars.insta_shoots < 0)
										features::ingame::vars.insta_shoots = 2;
								}
								else
								{
									features::ingame::vars.insta_shoots++;
									if (features::ingame::vars.insta_shoots > 2)
										features::ingame::vars.insta_shoots = 0;
								}
								break;
							}

							case 1:
							{
								if (left)
								{
									features::ingame::vars.insta_sprint--;
									if (features::ingame::vars.insta_sprint < 0)
										features::ingame::vars.insta_sprint = 2;
								}
								else
								{
									features::ingame::vars.insta_sprint++;
									if (features::ingame::vars.insta_sprint > 2)
										features::ingame::vars.insta_sprint = 0;
								}
								break;
							}

							case 2:
							{
								if (left)
								{
									features::ingame::vars.insta_spas_pump--;
									if (features::ingame::vars.insta_spas_pump < 0)
										features::ingame::vars.insta_spas_pump = 2;
								}
								else
								{
									features::ingame::vars.insta_spas_pump++;
									if (features::ingame::vars.insta_spas_pump > 2)
										features::ingame::vars.insta_spas_pump = 0;
								}
								break;
							}

							case 3:
							{
								if (left)
								{
									features::ingame::vars.always_zoomload--;
									if (features::ingame::vars.always_zoomload < 0)
										features::ingame::vars.always_zoomload = 2;
								}
								else
								{
									features::ingame::vars.always_zoomload++;
									if (features::ingame::vars.always_zoomload > 2)
										features::ingame::vars.always_zoomload = 0;
								}
								break;
							}

							case 4:
							{
								if (left)
								{
									features::ingame::vars.always_lunge--;
									if (features::ingame::vars.always_lunge < 0)
										features::ingame::vars.always_lunge = 2;
								}
								else
								{
									features::ingame::vars.always_lunge++;
									if (features::ingame::vars.always_lunge > 2)
										features::ingame::vars.always_lunge = 0;
								}
								break;
							}

							case 6:
							{

								break;
							}

							case 7:
							{

								break;
							}
						}

						break;
					}

					case sm_customisation:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								if (left)
								{
									features::customisation::vars.camo_select--;
									if (features::customisation::vars.camo_select < 0)
										features::customisation::vars.camo_select = 3;
								}
								else
								{
									features::customisation::vars.camo_select++;
									if (features::customisation::vars.camo_select > 3)
										features::customisation::vars.camo_select = 0;
								}

								break;
							}

							case 3:
							{								
								if (left)
								{
									features::customisation::vars.hudcolor_r--;
									if (features::customisation::vars.hudcolor_r < 0)
										features::customisation::vars.hudcolor_r = 255;
								}
								else
								{
									features::customisation::vars.hudcolor_r++;
									if (features::customisation::vars.hudcolor_r > 255)
										features::customisation::vars.hudcolor_r = 0;
								}
								break;
							}

							case 4:
							{								
								if (left)
								{
									features::customisation::vars.hudcolor_g--;
									if (features::customisation::vars.hudcolor_g < 0)
										features::customisation::vars.hudcolor_g = 255;
								}
								else
								{
									features::customisation::vars.hudcolor_g++;
									if (features::customisation::vars.hudcolor_g > 255)
										features::customisation::vars.hudcolor_g = 0;
								}
								break;
							}

							case 5:
							{
								if (left)
								{
									features::customisation::vars.hudcolor_b--;
									if (features::customisation::vars.hudcolor_b < 0)
										features::customisation::vars.hudcolor_b = 255;
								}
								else
								{
									features::customisation::vars.hudcolor_b++;
									if (features::customisation::vars.hudcolor_b > 255)
										features::customisation::vars.hudcolor_b = 0;
								}
								break;
							}
						}

						break;
					}

					case sm_account:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								if (left)
								{
									if (CURGAME == MW2)
									{
										features::account::vars.prestige--;
										if (features::account::vars.prestige < 0)
											features::account::vars.prestige = 11;
									}

									if (CURGAME == BO2)
									{
										features::account::vars.prestige--;
										if (features::account::vars.prestige < 0)
											features::account::vars.prestige = 15;
									}
								}
								else
								{
									if (CURGAME == MW2)
									{
										features::account::vars.prestige++;
										if (features::account::vars.prestige > 11)
											features::account::vars.prestige = 0;
									}

									if (CURGAME == BO2)
									{
										features::account::vars.prestige++;
										if (features::account::vars.prestige > 15)
											features::account::vars.prestige = 0;
									}
								}
								break;
							}
							case 1: break;
							case 2: break;
							case 3: break;
						}

						break;
					}
				}
			}

			void dofunctions()
			{
				switch (menuvars.current_submenu)
				{
					case sm_main:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								menuvars.current_submenu = sm_matchmaking;
								controls.currentoption = 0;

								break;
							}

							case 1:
							{
								menuvars.current_submenu = sm_gamesettings;
								controls.currentoption = 0;

								break;
							}

							case 2:
							{
								menuvars.current_submenu = sm_trickshotting;
								controls.currentoption = 0;

								break;
							}

							case 3:
							{
								menuvars.current_submenu = sm_customisation;
								controls.currentoption = 0;

								break;
							}

							case 4:
							{
								menuvars.current_submenu = sm_players;
								controls.currentoption = 0;

								break;
							}

							case 5:
							{
								menuvars.current_submenu = sm_account;
								controls.currentoption = 0;

								break;
							}

							case 6:
							{
								menuvars.current_submenu = sm_misc;
								controls.currentoption = 0;

								break;
							}

							case 7:
							{
								if (CURGAME == MW2)
								{
									//auto weap = g_entities[cgs->clientNumber].client->ps.weapon.data;

									//auto text = fmt("info: [num: %d, weapid: %d, weapname: %s]\n", 
									//	cgs->clientNumber,
									//	weap,
									//	G_GetWeaponNameForIndex(weap)
									//);

									//printf(text);

									helpers::replacematerial("weapon_camo_blue_tiger", "hdd:\\desire\\camos\\mw2\\camo_mw2.bin");
								}

								if (CURGAME == BO2)
								{
									features::injectgsc();
								}

								break;
							}
						}
						break;
					}

					case sm_matchmaking:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								features::pregame::vars.forcehost = !features::pregame::vars.forcehost;

								if (features::pregame::vars.forcehost)
								{
									if (CURGAME == MW2)
									{
										*(int*)(0x8231ECE4) = 0x48000120;
										*(int*)(0x8215FC64) = 0x48000050;
									}

									if (CURGAME == BO2)
									{
										Cbuf_AddText(0, _("party_connectToOthers 0;partyMigrate_disabled 1;party_mergingEnabled 0;"));
									}
								}
								else
								{
									if (CURGAME == MW2)
									{
										*(int*)(0x8231ECE4) = 0x40990120;
										*(int*)(0x8215FC64) = 0x419A0050;
									}

									if (CURGAME == BO2)
									{
										Cbuf_AddText(0, _("party_connectToOthers 1;partyMigrate_disabled 0;party_mergingEnabled 1;"));
									}
								}
								break;
							}

							case 1: break;
							case 2: break;

							case 3:
							{
								if (CURGAME == MW2)
								{
									if (!helpers::isingame())
									{
										Menu_OpenByName(Menu_OpenName(0), _("settings_map"));
										menu::handler::controls.isopen = false;
									}
								}

								if (CURGAME == BO2)
								{
									if (!helpers::isingame())
									{
										Cbuf_AddText(0, _("set party_minplayers 1; xpartygo"));
									}
								}

								break;
							}

							case 4:
							{
								if (CURGAME == MW2)
								{
									if (!helpers::isingame())
									{
										Menu_OpenByName(Menu_OpenName(0), _("settings_gametype"));
										menu::handler::controls.isopen = false;
									}
								}

								if (CURGAME == BO2)
								{
									// doesn't work really
									switch (features::pregame::vars.gamemode)
									{
										case 0: Cbuf_AddText(0, _("set ui_gametype sd;")); break;
										case 1: Cbuf_AddText(0, _("set ui_gametype dm;")); break;
										case 2: Cbuf_AddText(0, _("set ui_gametype tdm;")); break;
										default: break;
									}
								}

								break;
							}

							case 5:
							{
								features::pregame::vars.disabledlc = !features::pregame::vars.disabledlc;

								break;
							}
						}

						break;
					}

					case sm_gamesettings:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								features::ingame::vars.prevent_enemy_forfeit = !features::ingame::vars.prevent_enemy_forfeit;
								break;
							}

							case 1:
							{
								features::ingame::vars.depatch_bounces = !features::ingame::vars.depatch_bounces;
								break;
							}

							case 2:
							{
								features::ingame::vars.easy_eles = !features::ingame::vars.easy_eles;
								break;
							}

							case 3:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.prone_anywhere = !features::ingame::vars.prone_anywhere;
								}

								if (CURGAME == BO2)
								{
									features::ingame::vars.knife_lunges = !features::ingame::vars.knife_lunges;
								}

								break;
							}

							case 4:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.sweeping_uav = !features::ingame::vars.sweeping_uav;
								}

								if (CURGAME == BO2)
								{
									features::ingame::vars.miniscule_health = !features::ingame::vars.miniscule_health;
								}

								break;
							}

							case 5:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.wallbang_everything = !features::ingame::vars.wallbang_everything;
								}


								if (CURGAME == BO2)
								{
									features::ingame::vars.prone_spins = !features::ingame::vars.prone_spins;
								}

								break;
							}

							case 6:
							{
								features::ingame::vars.infinite_bullet_dist = !features::ingame::vars.infinite_bullet_dist;

								if (CURGAME == BO2)
								{
									features::ingame::vars.ladder_spins = !features::ingame::vars.ladder_spins;
								}

								break;
							}

							case 7:
							{
								features::ingame::vars.miniscule_health = !features::ingame::vars.miniscule_health;
								break;
							}

							case 8:
							{		
								features::ingame::vars.no_fall_damage = !features::ingame::vars.no_fall_damage;
								break;
							}

							case 9:
							{
								//features::ingame::vars.soft_lands = !features::ingame::vars.soft_lands;
								features::ingame::vars.prone_spins = !features::ingame::vars.prone_spins;

								break;
							}

							case 10:
							{
								//features::ingame::vars.prone_spins = !features::ingame::vars.prone_spins;
								features::ingame::vars.ladder_spins = !features::ingame::vars.ladder_spins;

								break;
							}

							case 11:
							{
								features::ingame::vars.ladder_spins = !features::ingame::vars.ladder_spins;
								break;
							}

							default: break;
						}

						break;
					}

					case sm_trickshotting:
					{
						switch (controls.currentoption)
						{
							case 5:
							{
								features::ingame::dropweapon("cheytac_mp", CAMO_URBAN);
								break;
							}

							default: break;
						}
						break;
					}

					case sm_customisation:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								features::customisation::customcamos();
								break;
							}

							case 1:
							{									
								if (!features::customisation::vars.custom_callingcards_enabled)
								{
									if (CURGAME == MW2)
									{
										features::customisation::vars.wasingame = true;

										if (!helpers::isingame() && features::customisation::vars.wasingame)
										{
											// thread this so that we can keep a constant check wether we are in game or not
											ExCreateThread(game::callingcard_thread, 0, 0, 0, (LPTHREAD_START_ROUTINE)features::customisation::customcallingcardsthread, 0, 0);
											features::customisation::vars.custom_callingcards_enabled = true;
										}
									}

									if (CURGAME == BO2)
									{
										features::customisation::customcallingcards();
										UI_OpenToastPopup(_("Desire"), _("Successfully loaded custom calling cards!"), _("ui_host"), 6000);
									}
								}
								else
								{
									if (game::callingcard_thread)
									{
										CloseHandle(game::callingcard_thread);
									}

									features::customisation::vars.wasingame = true;
									features::customisation::vars.custom_callingcards_enabled = false;
								}

								break;
							}

							case 2:
							{
								features::customisation::vars.custom_hud_color = !features::customisation::vars.custom_hud_color;
								break;
							}
						}

						break;
					}

					case sm_players:
					{
						game::features::ingame::players::kick(controls.currentoption);
						break;
					}

					case sm_account:
					{
						switch (controls.currentoption)
						{
							// set prestige
							case 0: game::features::account::setprestige(); break;

							// gamertag
							case 1: game::features::account::docustomgamertag(); break;
							case 2: game::features::account::resetgamertag(); break;
						}
						break;
					}

					case sm_misc:
					{
						switch (controls.currentoption)
						{
							case 0:
							{
								handler::menuvars.watermark = !handler::menuvars.watermark;
								break;
							}
						}
						break;
					}

					default: break;
				}
			}

			XINPUT_STATE input;
			void handlemenuinputs()
			{
				ZeroMemory(&input, sizeof(XINPUT_STATE));
				XInputGetState(0, &input);

				controls.wait++;
				if (controls.wait > 10)
				{
					if (!controls.isopen)
					{
						if (input.Gamepad.bLeftTrigger && input.Gamepad.wButtons & (XINPUT_GAMEPAD_DPAD_UP))
						{
							controls.isopen = true;
							controls.currentoption = 0;
							controls.wait = 0;
						}
					}
					else
					{
						if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_RIGHT_THUMB))
						{
							if (menuvars.current_submenu != sm_main)
							{
								menuvars.current_submenu = sm_main;
							}
							else
							{
								controls.isopen = false;
							}

							controls.currentoption = 0;
							controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_X))
						{
							dofunctions();
							controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_DPAD_UP))
						{
							controls.currentoption--;

							if (controls.currentoption < 0)
								controls.currentoption = controls.lastoption;

							controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_DPAD_DOWN))
						{
							controls.currentoption++;

							if (controls.currentoption > controls.lastoption)
								controls.currentoption = 0;

							controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_DPAD_RIGHT))
						{
							doslidercrement(false);

							if (handler::menuvars.current_submenu == sm_customisation)
							{
								// only make rgb sliders fast
								if (controls.currentoption == 3 || controls.currentoption == 4 || controls.currentoption == 5)
									controls.wait = 6;
								else
									controls.wait = 0;
							}
							else
								controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_DPAD_LEFT))
						{
							doslidercrement(true);

							if (handler::menuvars.current_submenu == sm_customisation)
								controls.wait = 6;
							else
								controls.wait = 0;
						}
					}
				}
			}

			int calcmenuheight()
			{
				return (controls.lastoption * 18) + 30;
			}

			struct bound
			{
				float backgroundsizex;
				float backgroundsizey;

				float backgroundposx;
				float backgroundposy;

				float titlebackgroundsizex;
				float titlebackgroundsizey;

				float titlebackgroundposx;
				float titlebackgroundposy;

				float titleposx;
				float titleposy;

				float optionposx;
				float optionposy;

				void updatebounds()
				{
					backgroundsizex = 240;
					backgroundsizey = 4 + handler::calcmenuheight() + 4;

					if (CURGAME == MW2)
					{
						backgroundposx = uiContext->screenWidth / 2 - backgroundsizex / 2;
						backgroundposy = uiContext->screenHeight / 2 - backgroundsizey / 2;
					}
					if (CURGAME == BO2)
					{
						backgroundposx = uiContextBO2->width / 2 - backgroundsizex / 2;
						backgroundposy = uiContextBO2->height / 2 - backgroundsizey / 2;
					}

					titlebackgroundsizex = backgroundsizex;
					titlebackgroundsizey = 20;

					titlebackgroundposx = backgroundposx;
					titlebackgroundposy = backgroundposy;

					titleposx = titlebackgroundposx + 24;
					titleposy = titlebackgroundposy + 19;

					optionposx = backgroundposx + 4;
					optionposy = backgroundposy + titlebackgroundsizey + 17;
				}
			};
			bound bounds;

			bool optionhovered(int i)
			{
				return i == controls.currentoption;
			}

			namespace widgets
			{
				void addoption(int i, const char* text)
				{
					if (i == handler::controls.currentoption)
						render::shader(bounds.optionposx - 4, bounds.optionposy + (i * 18) - 16, bounds.backgroundsizex, 16, render::colors::accent, "white");

					render::text(text, bounds.optionposx, bounds.optionposy + (i * 18), CURGAME == MW2 ? normalfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.5 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::def);

					handler::controls.lastoption = i;
				}

				void addsubtab(int i, const char* text)
				{
					addoption(i, text);
					render::shader(bounds.optionposx + bounds.backgroundsizex - 8-8, bounds.optionposy + (i * 18) - 13, 14, 12, render::colors::white, "ui_arrow_right");
					handler::controls.lastoption = i;
				}

				void addslider(int i, const char* text, int var, int min, int max)
				{
					addoption(i, text);
					render::text(va("%i", var), bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 18), CURGAME == MW2 ? normalfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.5 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
					handler::controls.lastoption = i;
				}

				void addcombo(int i, const char* text, const char** items, int selected)
				{
					addoption(i, text);
					const char* selecteditem = items[selected];
					render::text(selecteditem, bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 18), CURGAME == MW2 ? normalfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.5 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
					handler::controls.lastoption = i;
				}

				void addcheckbox(int i, const char* text, bool var)
				{
					addoption(i, text);

					render::shader(bounds.optionposx + bounds.backgroundsizex - 12 - 8, bounds.optionposy + (i * 18) - 14, 12, 12, render::colors::blackhalfalpha, "white");

					if (var)
					{
						render::shader(bounds.optionposx + bounds.backgroundsizex - 11 - 8, bounds.optionposy + (i * 18) - 13, 10, 10, render::colors::accent, "white");
					}

					//render::text(va("%s", var ? "on" : "off"), bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 18), CURGAME == MW2 ? normalfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.5 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
					handler::controls.lastoption = i;
				}
			}
		}

		void init()
		{
			//printf("call from menuinit\n");

			static bool set_vars = false;
			if (!set_vars)
			{
				handler::menuvars.init();
				features::pregame::vars.minplayerstostart = 7;
				features::pregame::vars.maxplayersinlobby = 12;
				set_vars = true;
			}

			handler::handlemenuinputs();

			std::string title = "";
			char* font = "";
			float fontscale = 0;

			switch (CURGAME)
			{
				case MW2:
				{
					title = _("desire mw2");
					font = normalfont;
					fontscale = 0.6;
					break;
				}

				case BO2:
				{
					title = _("desire bo2");
					font = FONT_SMALLBO2;
					fontscale = 0.6;
					break;
				}

				default: break;
			}

			if (handler::controls.isopen)
			{
				handler::bounds.updatebounds();

				render::shader(handler::bounds.backgroundposx - 1, handler::bounds.backgroundposy - 1, handler::bounds.backgroundsizex + 2, handler::bounds.backgroundsizey + 2, render::colors::accent, "white");
				render::shader(handler::bounds.backgroundposx, handler::bounds.backgroundposy, handler::bounds.backgroundsizex, handler::bounds.backgroundsizey, render::colors::grey, "white");
				render::shader(handler::bounds.titlebackgroundposx, handler::bounds.titlebackgroundposy, handler::bounds.titlebackgroundsizex, handler::bounds.titlebackgroundsizey, render::colors::accent, "white");
				render::text(title.c_str(), handler::bounds.backgroundposx + handler::bounds.backgroundsizex / 2, handler::bounds.titleposy, font, fontscale, render::colors::white, false, render_alignment::center);

				switch (CURGAME)
				{
					case MW2:
					{
						switch (handler::menuvars.current_submenu)
						{
							case handler::sm_main:
							{
								handler::widgets::addsubtab(0, _("matchmaking"));
								handler::widgets::addsubtab(1, _("game settings"));
								handler::widgets::addsubtab(2, _("trickshotting"));
								handler::widgets::addsubtab(3, _("customisation"));
								handler::widgets::addsubtab(4, _("kick players"));
								handler::widgets::addsubtab(5, _("account"));
								handler::widgets::addsubtab(6, _("misc"));
								handler::widgets::addsubtab(7, _("testing"));


								break;
							}

							case handler::sm_matchmaking:
							{
								handler::widgets::addcheckbox(0, _("forcehost"), features::pregame::vars.forcehost);
								handler::widgets::addslider(1, _("min players to start"), features::pregame::vars.minplayerstostart, 1, 12);
								handler::widgets::addslider(2, _("max players in lobby"), features::pregame::vars.maxplayersinlobby, 1, 18);
								handler::widgets::addoption(3, _("change map"));
								handler::widgets::addoption(4, _("change mode"));
								handler::widgets::addcheckbox(5, _("disable dlc"), features::pregame::vars.disabledlc);

								break;
							}

							case handler::sm_gamesettings:
							{
								handler::widgets::addcheckbox(0, _("prevent enemy forfeit"), features::ingame::vars.prevent_enemy_forfeit);
								handler::widgets::addcheckbox(1, _("depatch bounces"), features::ingame::vars.depatch_bounces);
								handler::widgets::addcheckbox(2, _("easy eles"), features::ingame::vars.easy_eles);
								handler::widgets::addcheckbox(3, _("prone anywhere"), features::ingame::vars.prone_anywhere);
								handler::widgets::addcheckbox(4, _("sweeping uav"), features::ingame::vars.sweeping_uav);
								handler::widgets::addcheckbox(5, _("wallbang everything"), features::ingame::vars.wallbang_everything);
								handler::widgets::addcheckbox(6, _("infinite bullet dist"), features::ingame::vars.infinite_bullet_dist);
								handler::widgets::addcheckbox(7, _("miniscule health"), features::ingame::vars.miniscule_health);
								handler::widgets::addcheckbox(8, _("no fall damage"), features::ingame::vars.no_fall_damage);
								//handler::widgets::addcheckbox(9, _("soft lands"), features::ingame::vars.soft_lands);
								handler::widgets::addcheckbox(9, _("prone spins"), features::ingame::vars.prone_spins);
								handler::widgets::addcheckbox(10, _("ladder spins"), features::ingame::vars.ladder_spins);

								break;
							}

							case handler::sm_trickshotting:
							{
								const char* modes[] = { "off", "self", "team" };
								handler::widgets::addcombo(0, "insta shoots", modes, features::ingame::vars.insta_shoots);
								handler::widgets::addcombo(1, "insta sprint", modes, features::ingame::vars.insta_sprint);
								handler::widgets::addcombo(2, "insta spas pump", modes, features::ingame::vars.insta_spas_pump);
								handler::widgets::addcombo(3, "always zoomload", modes, features::ingame::vars.always_zoomload);
								handler::widgets::addcombo(4, "always lunge", modes, features::ingame::vars.always_lunge);
								handler::widgets::addoption(5, "drop canswap");
								break;
							}

							case handler::sm_customisation:
							{
								const char* camos[] = { "white", "pink", "green", "blue" };
								handler::widgets::addcombo(0, _("custom bluetiger preset"), camos, features::customisation::vars.camo_select);
								handler::widgets::addcheckbox(1, _("custom calling cards"), features::customisation::vars.custom_callingcards_enabled);
								handler::widgets::addcheckbox(2, _("custom hud color"), features::customisation::vars.custom_hud_color);
								handler::widgets::addslider(3, _("hud r"), features::customisation::vars.hudcolor_r, 0, 255);
								handler::widgets::addslider(4, _("hud g"), features::customisation::vars.hudcolor_g, 0, 255);
								handler::widgets::addslider(5, _("hud b"), features::customisation::vars.hudcolor_b, 0, 255);
								//handler::widgets::addcheckbox(4, _("custom camo color"), features::customisation::vars.custom_camo_color);
								//handler::widgets::addslider(5, _("camo r"), features::customisation::vars.camocolor_r, 0, 255);
								//handler::widgets::addslider(6, _("camo g"), features::customisation::vars.camocolor_g, 0, 255);
								//handler::widgets::addslider(7, _("camo b"), features::customisation::vars.camocolor_b, 0, 255);
								break;
							}

							case handler::sm_players:
							{
								if (helpers::isingame())
								{
									for (int i = 0; i < 18; i++)
									{
										if (!g_entities[i].client)
										{
											handler::widgets::addoption(i, "-");
											continue;
										}

										handler::widgets::addoption(i, g_entities[i].client->sess.cs.name);
									}
								}
								else
								{
									handler::widgets::addoption(0, _("go in-game to see players"));
								}

								break;
							}

							case handler::sm_account:
							{
								//handler::widgets::addoption(0, "unlockall");
								handler::widgets::addslider(0, _("prestige"), features::account::vars.prestige, 0, 15);
								handler::widgets::addoption(1, _("change gamertag"));
								handler::widgets::addoption(2, _("reset gamertag"));

								break;
							}

							case handler::sm_misc:
							{
								handler::widgets::addcheckbox(0, _("controls"), handler::menuvars.watermark);
								break;
							}

							default: break;
						}

						break;
					}

					case BO2:
					{
						switch (handler::menuvars.current_submenu)
						{
							case handler::sm_main:
							{
								handler::widgets::addsubtab(0, _("matchmaking"));
								handler::widgets::addsubtab(1, _("game settings"));
								handler::widgets::addsubtab(2, _("team settings"));
								handler::widgets::addsubtab(3, _("customisation"));
								handler::widgets::addsubtab(4, _("kick players"));
								handler::widgets::addsubtab(5, _("account"));
								handler::widgets::addsubtab(6, _("misc"));
								handler::widgets::addoption(7, _("load team menu"));

								break;
							}

							case handler::sm_matchmaking:
							{
								handler::widgets::addcheckbox(0, _("forcehost"), features::pregame::vars.forcehost);
								handler::widgets::addslider(1, _("min players to start"), features::pregame::vars.minplayerstostart, 1, 12);
								handler::widgets::addslider(2, _("max players in lobby"), features::pregame::vars.maxplayersinlobby, 1, 18);
								handler::widgets::addoption(3, _("force start game"));

								//const char* modes[] = { "snd", "ffa", "tdm" };
								//handler::widgets::addcombo(4, "change mode", modes, features::pregame::vars.gamemode);

								handler::widgets::addcheckbox(4, _("disable dlc"), features::pregame::vars.disabledlc);

								break;
							}

							case handler::sm_trickshotting:
							{
								break;
							}

							case handler::sm_gamesettings:
							{
								handler::widgets::addcheckbox(0, _("depatch bounces"), features::ingame::vars.depatch_bounces);
								handler::widgets::addcheckbox(1, _("depatch eles"), features::ingame::vars.easy_eles);
								handler::widgets::addcheckbox(2, _("depatch knife lunges"), features::ingame::vars.knife_lunges);
								handler::widgets::addcheckbox(3, _("one shot snipers"), features::ingame::vars.miniscule_health);
								handler::widgets::addcheckbox(4, _("prone spins"), features::ingame::vars.prone_spins);
								handler::widgets::addcheckbox(5, _("ladder spins"), features::ingame::vars.ladder_spins);

								break;
							}

							case handler::sm_customisation:
							{
								handler::widgets::addoption(0, _("custom calling cards"));
								//handler::widgets::addoption(1, _("custom camos"));
								break;
							}

							case handler::sm_players:
							{
								handler::widgets::addoption(0, _("not working yet, too lazy"));

								break;
							}

							case handler::sm_account:
							{
								//handler::widgets::addoption(0, "unlock all");
								handler::widgets::addslider(0, _("prestige"), features::account::vars.prestige, 0, 15);
								handler::widgets::addoption(1, _("change gamertag"));
								handler::widgets::addoption(2, _("reset gamertag"));

								break;
							}

							case handler::sm_misc:
							{
								handler::widgets::addcheckbox(0, _("controls"), handler::menuvars.watermark);
								break;
							}

							default: break;
						}

						break;
					}

					default: break;
				}
			}

			if (handler::menuvars.watermark)
			{
				switch (CURGAME)
				{
					case MW2:
					{
						if (handler::controls.isopen)
						{
							render::text(fmt(_("%s close | %s select | %s up %s down | %s decrease %s increase"),
								render::buttons::rs, render::buttons::x,
								render::buttons::dpadup, render::buttons::dpaddown,
								render::buttons::dpadright, render::buttons::dpadleft),
								10,
								uiContext->screenHeight - 10,
								normalfont, 0.5,
								render::colors::white,
								false, render_alignment::def
							);
						}
						else
						{
							render::text(fmt(_("%s and %s for desire"),
								render::buttons::lt, render::buttons::dpadup),
								10,
								uiContext->screenHeight - 10,
								normalfont, 0.5,
								render::colors::white,
								false, render_alignment::def
							);
						}
						break;
					}

					case BO2:
					{
						if (handler::controls.isopen)
						{
							render::text(_("^BXENONButtonStickAnimatedR^ close | ^BXENONButtonX^ select | ^BXENONButtondpadU^ up ^BXENONButtondpadD^ down | ^BXENONButtondpadL^ decrease ^BXENONButtondpadR^ increase"),
								10,
								uiContextBO2->height - 10,
								font, fontscale,
								render::colors::white,
								false, render_alignment::def
							);
						}
						else
						{
							render::text(_("^BXENONButtontrigL^ and ^BXENONButtondpadU^ for desire"),
								10,
								uiContextBO2->height - 10,
								font, fontscale,
								render::colors::white,
								false, render_alignment::def
							);
						}

						break;
					}

					default: break;
				}
			}
		}
	}
}