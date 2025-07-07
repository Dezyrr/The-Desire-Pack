#pragma once
#include "includes.h"
#include "functions.h"

namespace game
{
	namespace features
	{
		namespace customisation
		{
			struct varrs
			{
				bool custom_hud_color;
				int hudcolor_r;
				int hudcolor_g;
				int hudcolor_b;

				bool custom_camo_color;
				int camocolor_r;
				int camocolor_g;
				int camocolor_b;

				void set()
				{
					hudcolor_r = hudcolor_g = hudcolor_b = 255;
					camocolor_r = camocolor_g = camocolor_b = 255;
				}
			};
			varrs vars;
		}
	}
}