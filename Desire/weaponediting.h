#pragma once
#include "functions.h"

namespace game
{
	namespace features
	{
		namespace weapon_editing
		{
			struct varrs
			{
				bool deagle_flips;
				bool barrett_canswap_anim;
			};
			varrs vars;

			void replaceakwithcod4ak()
			{
				helpers::replaceweaponmodelwithxmodel("ak47_mp", "viewmodel_ak47");
			}

			void replacedeaglewithcod4goldone()
			{
				helpers::replaceweaponmodel("deserteagle_akimbo_mp", "deserteaglegold_mp");
				helpers::replaceweaponmodel("deserteagle_mp", "deserteaglegold_mp");

				//helpers::replaceweaponmodelwithxmodel("deserteagle_akimbo_mp", "viewmodel_desert_eagle_gold_mp");
				//helpers::replaceweaponmodelwithxmodel("deserteagle_mp", "viewmodel_desert_eagle_gold_mp");
			}
		}
	}
}