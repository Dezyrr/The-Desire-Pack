#pragma once
#include "functions.h"

namespace game
{
	namespace features
	{
		namespace ingame
		{
			namespace players
			{
				void kick(int i)
				{
					helpers::kickclient(i, "Player Kicked.");
				}
			}
		}
	}
}