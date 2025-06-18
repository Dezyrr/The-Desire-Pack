#pragma once
#include "includes.h"
#include "functions.h"

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

			const char* __fastcall mw2lobbysize(const char* result)
			{
				std::strcpy((char*)0x836BC2DB, result);
				std::strcpy((char*)0x836BED1B, result);
				std::strcpy((char*)0x836C175B, result);
				std::strcpy((char*)0x836C419B, result);
				std::strcpy((char*)0x836C6BDC, result);
				std::strcpy((char*)0x836C961B, result);
				std::strcpy((char*)0x836CC05B, result);
				std::strcpy((char*)0x836CEA9B, result);
				std::strcpy((char*)0x836D14DB, result);
				std::strcpy((char*)0x836D3F1B, result);
				std::strcpy((char*)0x836D695B, result);
				std::strcpy((char*)0x836D939B, result);
				std::strcpy((char*)0x836E125B, result);
				std::strcpy((char*)0x836E3C9B, result);
				std::strcpy((char*)0x836E66DB, result);
				std::strcpy((char*)0x836E911B, result);
				std::strcpy((char*)0x836EBB5B, result);
				return result;
			}

			void doforcehost()
			{
				if (features::pregame::vars.forcehost)
				{
					if (CURGAME == MW2)
					{
						if (*(DWORD*)(0x8231ECE4) == 0x40990120)
							*(DWORD*)(0x8231ECE4) = 0x48000120;

						if (*(DWORD*)(0x8215FC64) == 0x419A0050)
							*(DWORD*)(0x8215FC64) = 0x48000050;

						SetDvar("party_minPlayers", va("%i", features::pregame::vars.minplayerstostart));

						SetDvar("party_maxPlayers", va("%i", features::pregame::vars.maxplayersinlobby));
						SetDvar("party_matchedplayercount", va("%i", features::pregame::vars.maxplayersinlobby));
						mw2lobbysize(va("%i", features::pregame::vars.maxplayersinlobby));
					}

					if (CURGAME == BO2)
					{
						Cbuf_AddText(0, "party_connectToOthers 0;partyMigrate_disabled 1;party_mergingEnabled 0;");

						// min players
						*(BYTE*)(0x83C6AC7B) = features::pregame::vars.minplayerstostart;
						*(BYTE*)(0x83C6AC8B) = features::pregame::vars.minplayerstostart;
						Cbuf_AddText(0, va("set party_minplayers %d;", features::pregame::vars.minplayerstostart));

						// max players
						*(BYTE*)(0x83C6A61B) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C6A62B) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C4B7DB) = features::pregame::vars.maxplayersinlobby;
						*(BYTE*)(0x83C4B7EB) = features::pregame::vars.maxplayersinlobby;
						Cbuf_AddText(0, va("set party_maxplayers %d; ", features::pregame::vars.maxplayersinlobby));
					}
				}
				else
				{
					if (CURGAME == MW2)
					{
						if (*(DWORD*)(0x8231ECE4) == 0x48000120)
							*(DWORD*)(0x8231ECE4) = 0x40990120;

						if (*(DWORD*)(0x8215FC64) == 0x48000050)
							*(DWORD*)(0x8215FC64) = 0x419A0050;
					}

					if (CURGAME == BO2)
					{
						Cbuf_AddText(0, "party_connectToOthers 1;partyMigrate_disabled 0;party_mergingEnabled 1;");
					}
				}

				if (CURGAME == BO2)
				{
					if (features::pregame::vars.disabledlc)
					{
						*(char*)(0x8297702F) = 0x00;
						*(char*)(0x829770BF) = 0x00;
						*(char*)(0x8297714F) = 0x00;
						*(char*)(0x829771DF) = 0x00;
					}
					else
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
			}
		}
	}
}