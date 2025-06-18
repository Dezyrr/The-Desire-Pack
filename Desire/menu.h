#pragma once
#include "render.h"
#include "includes.h"
#include "functions.h"
#include "pregame.h"
#include "ingame.h"
#include "hooks.h"
#include "account.h"

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
				sm_ingame,
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
										features::pregame::vars.minplayerstostart = 1;
								}
								else
								{
									features::pregame::vars.minplayerstostart++;
									if (features::pregame::vars.minplayerstostart > 12)
										features::pregame::vars.minplayerstostart = 12;
								}
								break;
							}
							case 2:
							{
								if (left)
								{
									features::pregame::vars.maxplayersinlobby--;
									if (features::pregame::vars.maxplayersinlobby < 1)
										features::pregame::vars.maxplayersinlobby = 1;
								}
								else
								{
									features::pregame::vars.maxplayersinlobby++;
									if (features::pregame::vars.maxplayersinlobby > 18)
										features::pregame::vars.maxplayersinlobby = 18;
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

					case sm_account:
					{
						switch (controls.currentoption)
						{
							case 0: break;
							case 1:
							{
								if (left)
								{
									features::account::vars.prestige--;
									if (features::account::vars.prestige < 0)
										features::account::vars.prestige = 0;
								}
								else
								{
									features::account::vars.prestige++;
									if (features::account::vars.prestige > 15)
										features::account::vars.prestige = 15;
								}
								break;
							}
							case 2: break;
							case 3: break;
							case 4: break;
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
								menuvars.current_submenu = sm_ingame;
								controls.currentoption = 0;

								break;
							}

							case 2:
							{
								menuvars.current_submenu = sm_account;
								controls.currentoption = 0;

								break;
							}

							case 3:
							{
								menuvars.current_submenu = sm_misc;
								controls.currentoption = 0;

								break;
							}
						}
						break;
					}

					case sm_matchmaking:
					{
						switch (controls.currentoption)
						{
							// forcehost
							case 0:
							{
								features::pregame::vars.forcehost = !features::pregame::vars.forcehost;
								break;
							}

							// min players to start
							case 1: break;

							// max players in lobby
							case 2: break;

							// change map
							case 3:
							{
								if (CURGAME == MW2)
								{
									if (!helpers::isingame())
									{
										Menu_OpenByName(Menu_OpenName(0), "settings_map");
										menu::handler::controls.isopen = false;
									}
								}

								if (CURGAME == BO2)
								{
									if (!helpers::isingame())
									{
										Cbuf_AddText(0, "set party_minplayers 1; xpartygo;");
									}
								}

								break;
							}

							// change mode
							case 4:
							{
								if (CURGAME == MW2)
								{
									if (!helpers::isingame())
									{
										Menu_OpenByName(Menu_OpenName(0), "settings_gametype");
										menu::handler::controls.isopen = false;
									}
								}

								if (CURGAME == BO2)
								{
									switch (features::pregame::vars.gamemode)
									{
										case 0: Cbuf_AddText(0, "set ui_gametype \"sd\"; set_gametype \"sd\";"); break;
										case 1: Cbuf_AddText(0, "set ui_gametype \"dm\"; set_gametype \"dm\";"); break;
										case 2: Cbuf_AddText(0, "set ui_gametype \"tdm\"; set_gametype \"tdm\";"); break;
										default: break;
									}
								}

								break;
							}

							// disable dlc
							case 5:
							{
								if (CURGAME == MW2)
								{
									
								}

								if (CURGAME == BO2)
								{
									if (!helpers::isingame())
									{
										features::pregame::vars.disabledlc = !features::pregame::vars.disabledlc;
									}
								}

								break;
							}

						}

						break;
					}

					case sm_ingame:
					{
						switch (controls.currentoption)
						{
							// depatch bounces
							case 0:
							{
								features::ingame::vars.depatch_bounces = !features::ingame::vars.depatch_bounces;
								break;
							}

							// easy eles
							case 1:
							{
								features::ingame::vars.easy_eles = !features::ingame::vars.easy_eles;
								break;
							}

							// prone anywhere
							case 2:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.prone_anywhere = !features::ingame::vars.prone_anywhere;
								}

								if (CURGAME == BO2)
								{
									features::ingame::vars.miniscule_health = !features::ingame::vars.miniscule_health;
								}
								break;
							}

							// sweeping uav
							case 3:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.sweeping_uav = !features::ingame::vars.sweeping_uav;
								}

								if (CURGAME == BO2)
								{
									features::ingame::vars.prone_spins = !features::ingame::vars.prone_spins;
								}

								break;
							}

							// wallbang everything
							case 4:
							{
								if (CURGAME == MW2)
								{
									features::ingame::vars.wallbang_everything = !features::ingame::vars.wallbang_everything;
								}


								if (CURGAME == BO2)
								{
									features::ingame::vars.ladder_spins = !features::ingame::vars.ladder_spins;
								}

								break;
							}

							// infinite bullet dist
							case 5:
							{
								features::ingame::vars.infinite_bullet_dist = !features::ingame::vars.infinite_bullet_dist;
								break;
							}

							// miniscule health
							case 6:
							{
								features::ingame::vars.miniscule_health = !features::ingame::vars.miniscule_health;
								break;
							}

							// no fall damage
							case 7:
							{								
								features::ingame::vars.no_fall_damage = !features::ingame::vars.no_fall_damage;
								break;
							}

							// soft lands
							case 8:
							{
								features::ingame::vars.soft_lands = !features::ingame::vars.soft_lands;
								break;
							}

							// prone spins
							case 9:
							{
								features::ingame::vars.prone_spins = !features::ingame::vars.prone_spins;
								break;
							}

							// ladder spins
							case 10:
							{
								features::ingame::vars.ladder_spins = !features::ingame::vars.ladder_spins;
								break;
							}

							default: break;
						}

						break;
					}

					case sm_account:
					{
						switch (controls.currentoption)
						{
							// unlockall
							case 0: game::features::account::unlockall(); break;

							// set prestige
							case 1: game::features::account::setprestige(); break;

							// gamertag
							case 2: game::features::account::docustomgamertag(); break;
							case 3: game::features::account::resetgamertag(); break;
						}
						break;
					}

					case sm_misc:
					{
						switch (controls.currentoption)
						{
							// watermark
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
							controls.wait = 0;
						}

						else if (input.Gamepad.wButtons == (XINPUT_GAMEPAD_DPAD_LEFT))
						{
							doslidercrement(true);
							controls.wait = 0;
						}
					}
				}
			}

			int calcmenuheight()
			{
				return (controls.lastoption * 16) + 32;
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
					titleposy = titlebackgroundposy + 17;

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
						render::shader(bounds.optionposx - 4, bounds.optionposy + (i * 16) - 14, bounds.backgroundsizex, 14, render::colors::accent, "white");

					render::text(text, bounds.optionposx, bounds.optionposy + (i * 16), CURGAME == MW2 ? hudSmallfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.6 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::def);

					handler::controls.lastoption = i;
				}

				void addsubtab(int i, const char* text)
				{
					addoption(i, text);
					render::shader(bounds.optionposx + bounds.backgroundsizex - 8-8, bounds.optionposy + (i * 16) - 13, 14, 12, render::colors::white, "ui_arrow_right");
					handler::controls.lastoption = i;
				}

				void addslider(int i, const char* text, int var, int min, int max)
				{
					addoption(i, text);
					render::text(va("%i", var), bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 16), CURGAME == MW2 ? hudSmallfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.6 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
					handler::controls.lastoption = i;
				}

				void addcombo(int i, const char* text, const char** items, int selected)
				{
					addoption(i, text);
					const char* selecteditem = items[selected];
					render::text(selecteditem, bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 16), CURGAME == MW2 ? hudSmallfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.6 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
					handler::controls.lastoption = i;
				}

				void addcheckbox(int i, const char* text, bool var)
				{
					addoption(i, text);
					render::text(va("%s", var ? "on" : "off"), bounds.optionposx + bounds.backgroundsizex - 8, bounds.optionposy + (i * 16), CURGAME == MW2 ? hudSmallfont : CURGAME == BO2 ? FONT_SMALLBO2 : "", CURGAME == MW2 ? 0.6 : CURGAME == BO2 ? 0.6 : 0, render::colors::white, false, render_alignment::right);
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
					title = "desire mw2";
					font = hudSmallfont;
					fontscale = 0.6;
					break;
				}

				case BO2:
				{
					title = "desire bo2";
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

				render::shader(handler::bounds.backgroundposx, handler::bounds.backgroundposy, handler::bounds.backgroundsizex, handler::bounds.backgroundsizey, render::colors::black, "white");
				render::shader(handler::bounds.titlebackgroundposx, handler::bounds.titlebackgroundposy, handler::bounds.titlebackgroundsizex, handler::bounds.titlebackgroundsizey, render::colors::accent, "white");
				render::text(title.c_str(), handler::bounds.backgroundposx + handler::bounds.backgroundsizex / 2, handler::bounds.titleposy, font, fontscale, render::colors::white, false, render_alignment::center);

				//render::shader(handler::bounds.backgroundposx, handler::bounds.backgroundposy + handler::bounds.backgroundsizey - 3, handler::bounds.backgroundsizex, 4, render::colors::accent, "white");

				switch (CURGAME)
				{
					case MW2:
					{
						switch (handler::menuvars.current_submenu)
						{
							case handler::sm_main:
							{
								handler::widgets::addsubtab(0, "matchmaking");
								handler::widgets::addsubtab(1, "ingame");
								handler::widgets::addsubtab(2, "account");
								handler::widgets::addsubtab(3, "misc");

								break;
							}

							case handler::sm_matchmaking:
							{
								handler::widgets::addcheckbox(0, "forcehost", features::pregame::vars.forcehost);
								handler::widgets::addslider(1, "min players to start", features::pregame::vars.minplayerstostart, 1, 12);
								handler::widgets::addslider(2, "max players in lobby", features::pregame::vars.maxplayersinlobby, 1, 18);
								handler::widgets::addoption(3, "change map");
								handler::widgets::addoption(4, "change mode");
								//handler::widgets::addcheckbox(5, "disable dlc", features::pregame::vars.disabledlc);

								break;
							}

							case handler::sm_ingame:
							{
								handler::widgets::addcheckbox(0, "depatch bounces", features::ingame::vars.depatch_bounces);
								handler::widgets::addcheckbox(1, "easy eles", features::ingame::vars.easy_eles);
								handler::widgets::addcheckbox(2, "prone anywhere", features::ingame::vars.prone_anywhere);
								handler::widgets::addcheckbox(3, "sweeping uav", features::ingame::vars.sweeping_uav);
								handler::widgets::addcheckbox(4, "wallbang everything", features::ingame::vars.wallbang_everything);
								handler::widgets::addcheckbox(5, "infinite bullet dist", features::ingame::vars.infinite_bullet_dist);
								handler::widgets::addcheckbox(6, "miniscule health", features::ingame::vars.miniscule_health);
								handler::widgets::addcheckbox(7, "no fall damage", features::ingame::vars.no_fall_damage);
								handler::widgets::addcheckbox(8, "soft lands", features::ingame::vars.soft_lands);
								handler::widgets::addcheckbox(9, "prone spins", features::ingame::vars.prone_spins);
								handler::widgets::addcheckbox(10, "ladder spins", features::ingame::vars.ladder_spins);

								break;
							}

							case handler::sm_account:
							{
								handler::widgets::addoption(0, "unlockall");
								handler::widgets::addslider(1, "prestige", features::account::vars.prestige, 0, 15);
								handler::widgets::addoption(2, "change gamertag");
								handler::widgets::addoption(3, "reset gamertag");

								break;
							}

							case handler::sm_misc:
							{
								handler::widgets::addcheckbox(0, "watermark", handler::menuvars.watermark);
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
								handler::widgets::addsubtab(0, "matchmaking");
								handler::widgets::addsubtab(1, "ingame");
								handler::widgets::addsubtab(2, "account");
								handler::widgets::addsubtab(3, "misc");

								break;
							}

							case handler::sm_matchmaking:
							{
								handler::widgets::addcheckbox(0, "forcehost", features::pregame::vars.forcehost);
								handler::widgets::addslider(1, "min players to start", features::pregame::vars.minplayerstostart, 1, 12);
								handler::widgets::addslider(2, "max players in lobby", features::pregame::vars.maxplayersinlobby, 1, 18);
								handler::widgets::addoption(3, "force start game");

								const char* modes[] = { "snd", "ffa", "tdm" };
								handler::widgets::addcombo(4, "change mode", modes, features::pregame::vars.gamemode);

								handler::widgets::addcheckbox(5, "disable dlc", features::pregame::vars.disabledlc);

								break;
							}

							case handler::sm_ingame:
							{
								handler::widgets::addcheckbox(0, "depatch bounces", features::ingame::vars.depatch_bounces);
								handler::widgets::addcheckbox(1, "depatch eles", features::ingame::vars.easy_eles);
								handler::widgets::addcheckbox(2, "one shot snipers", features::ingame::vars.miniscule_health);
								handler::widgets::addcheckbox(3, "prone spins", features::ingame::vars.prone_spins);
								handler::widgets::addcheckbox(4, "ladder spins", features::ingame::vars.ladder_spins);

								break;
							}

							case handler::sm_account:
							{
								handler::widgets::addoption(0, "unlock all");
								handler::widgets::addslider(1, "prestige", features::account::vars.prestige, 0, 15);
								handler::widgets::addoption(2, "change gamertag");
								handler::widgets::addoption(3, "reset gamertag");

								break;
							}

							case handler::sm_misc:
							{
								handler::widgets::addcheckbox(0, "watermark", handler::menuvars.watermark);
								break;
							}

							default: break;
						}

						break;
					}

					default: break;
				}

				switch (CURGAME)
				{
					case MW2:
					{
						render::text(fmt("%s close | %s select | %s up %s down | %s decrease %s increase",
							render::buttons::rs, render::buttons::x,
							render::buttons::dpadup, render::buttons::dpaddown,
							render::buttons::dpadright, render::buttons::dpadleft),
							handler::bounds.backgroundposx + handler::bounds.backgroundsizex / 2,
							handler::bounds.backgroundposy + handler::bounds.backgroundsizey + 26,
							font, fontscale,
							render::colors::white,
							false,
							render_alignment::center
						);
						break;
					}

					case BO2:
					{
						render::text("^BXENONButtonStickAnimatedR^ close | ^BXENONButtonX^ select | ^BXENONButtondpadU^ up ^BXENONButtondpadD^ down | ^BXENONButtondpadL^ decrease ^BXENONButtondpadR^ increase",
							handler::bounds.backgroundposx + handler::bounds.backgroundsizex / 2,
							handler::bounds.backgroundposy + handler::bounds.backgroundsizey + 24,
							font, fontscale,
							render::colors::white,
							false,
							render_alignment::center
						);
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
						render::text(fmt("%s and %s for desire",
							render::buttons::lt, render::buttons::dpadup),
							10,
							uiContext->screenHeight - 10,
							normalfont, 0.5,
							render::colors::white,
							false, render_alignment::def
						);
						break;
					}

					case BO2:
					{
						render::text("^BXENONButtontrigL^ and ^BXENONButtondpadU^ for desire",
							10,
							uiContextBO2->height - 10,
							font, fontscale,
							render::colors::white,
							false, render_alignment::def
						);

						if (helpers::isingame())
						{
							render::text("^BXENONButtontrigL^ and ^BXENONButtondpadU^ for desire",
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