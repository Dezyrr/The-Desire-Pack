#pragma once
#include "functions.h"
#include "account.h"

namespace game
{
	namespace features
	{
		namespace pregame
		{
			struct varrs
			{
				bool forcehost;
				int minplayerstostart;
				int maxplayersinlobby;
				int gamemode;
				bool disabledlc;
			};
			varrs vars;

			// taken from isotope, the return must be used for something else, never fully looked
			// fixed by looking at how ascension did it, changing (char*) casting to reinterpret_cast<char*> casting does nothing, but it looks nice anyway
			void setlobbysize(const char* size)
			{
				std::strcpy(reinterpret_cast<char*>(0x836BC2DB), size);
				std::strcpy(reinterpret_cast<char*>(0x836BED1B), size);
				std::strcpy(reinterpret_cast<char*>(0x836C175B), size);
				std::strcpy(reinterpret_cast<char*>(0x836C419B), size);
				std::strcpy(reinterpret_cast<char*>(0x836C6BDC), size);
				std::strcpy(reinterpret_cast<char*>(0x836C961B), size);
				std::strcpy(reinterpret_cast<char*>(0x836CC05B), size);
				std::strcpy(reinterpret_cast<char*>(0x836CEA9B), size);
				std::strcpy(reinterpret_cast<char*>(0x836D14DB), size);
				std::strcpy(reinterpret_cast<char*>(0x836D3F1B), size);
				std::strcpy(reinterpret_cast<char*>(0x836D695B), size);
				std::strcpy(reinterpret_cast<char*>(0x836D939B), size);
				std::strcpy(reinterpret_cast<char*>(0x836E125B), size);
				std::strcpy(reinterpret_cast<char*>(0x836E3C9B), size);
				std::strcpy(reinterpret_cast<char*>(0x836E66DB), size);
				std::strcpy(reinterpret_cast<char*>(0x836E911B), size);
				std::strcpy(reinterpret_cast<char*>(0x836EBB5B), size);
			}

			void doforcehost()
			{
				if (features::pregame::vars.forcehost)
				{
					if (CURGAME == MW2)
					{
						//*(DWORD*)(0x82690E38 + 8) = features::pregame::vars.minplayerstostart;
						//*(DWORD*)(0x8268DC6C + 8) = 0x12;

						SetDvar("party_matchedPlayerCount", "2");
						SetDvar("party_minPlayers", va("%i", features::pregame::vars.minplayerstostart));

						char maxplayers[255];
						sprintf(maxplayers, "; party_maxPlayers %i", features::pregame::vars.maxplayersinlobby);
						setlobbysize(va("%i", features::pregame::vars.maxplayersinlobby));
						SetDvar("party_maxPlayers", va("%i", features::pregame::vars.maxplayersinlobby));
					}

					if (CURGAME == BO2)
					{
						// min players (from tonypack)
						*(BYTE*)(0x83C6AC7B) = features::pregame::vars.minplayerstostart;
						*(BYTE*)(0x83C6AC8B) = features::pregame::vars.minplayerstostart;

						Cbuf_AddText(0, va("set party_minplayers %d;", features::pregame::vars.minplayerstostart));

						// max players (from tonypack)
						*(BYTE*)(0x83C6A61B) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C6A62B) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C4B7DB) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C4B7EB) = features::pregame::vars.maxplayersinlobby;

						Cbuf_AddText(0, va("set party_maxplayers %d; ", features::pregame::vars.maxplayersinlobby));
					}
				}

				if (features::pregame::vars.disabledlc)
				{
					if (CURGAME == MW2)
					{
						*(DWORD*)(0x83749568) = 0x1;
					}

					if (CURGAME == BO2)
					{
						*(char*)(0x8297702F) = 0x00;
						*(char*)(0x829770BF) = 0x00;
						*(char*)(0x8297714F) = 0x00;
						*(char*)(0x829771DF) = 0x00;
					}
				}
				else
				{
					if (CURGAME == MW2)
					{
						*(DWORD*)(0x83749568) = 0x3;
					}

					if (CURGAME == BO2)
					{
						*(char*)(0x8297702F) = 0x10;
						*(char*)(0x829770BF) = 0x20;
						*(char*)(0x8297714F) = 0x40;
						*(char*)(0x829771DF) = 0x80;
					}
				}
			}

			void handle_pre_game_features()
			{
				features::pregame::doforcehost();

				features::account::setprestige();
			}
		}
	}
}