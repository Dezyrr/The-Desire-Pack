#pragma once
#include "functions.h"

#define normalfont					"fonts/normalFont"
#define consolefont					"fonts/consoleFont"
#define hudBigfont					"fonts/hudBigFont"
#define hudSmallfont				"fonts/hudSmallFont"
#define extraBigfont				"fonts/extraBigFont"
#define smallfont					"fonts/smallFont"
#define bigfont						"fonts/bigFont"
#define objectivefont				"fonts/objectiveFont"
#define boldfont					"fonts/boldFont"
#define smallDevfont				"fonts/smallDevFont"
#define bigDevfont					"fonts/bigDevFont"

#define FONT_italicFontBO2			"fonts/720/italicFont"
#define FONT_BIG_DEVBO2				"fonts/bigDevFont"
#define FONT_CONSOLEBO2				"fonts/720/consoleFont"
#define FONT_BIGBO2					"fonts/720/bigFont"
#define FONT_SMALLBO2				"fonts/720/smallFont"
#define FONT_BOLDBO2				"fonts/720/boldFont"
#define FONT_NORMALBO2				"fonts/720/normalFont"
#define FONT_EXTRA_BIGBO2			"fonts/720/extraBigFont"
#define FONT_OBJECTIVEBO2			"fonts/720/objectiveFont"


enum render_alignment
{
	def = 0,
	right,
	center
};

namespace game
{
	namespace render
	{
		namespace buttons
		{
			const char* a = "\x01";
			const char* b = "\x02";
			const char* x = "\x03";
			const char* y = "\x04";
			const char* ls = "\x10";
			const char* rs = "\x011";
			const char* lb = "\x05";
			const char* rb = "\x06";
			const char* lt = "\x012";
			const char* rt = "\x011";
			const char* dpadup = "\x014";
			const char* dpaddown = "\x015";
			const char* dpadleft = "\x017";
			const char* dpadright = "\x016";
		}

		namespace colors
		{
			float accent[4] = { 255 / 255.f, 169 / 255.f, 215 / 255.f, 1 };
			float accentnoalpha[4] = { 255 / 255.f, 169 / 255.f, 215 / 255.f, 0 };
			float accenthalfalpha[4] = { 255 / 255.f, 169 / 255.f, 215 / 255.f, 0.5 };

			float darkblue[4] = { 47 / 255.f, 99 / 255.f, 219 / 255.f, 1 };
			float darkbluenoalpha[4] = { 255 / 255.f, 169 / 255.f, 215 / 255.f, 0 };
			float darkbluehalfalpha[4] = { 255 / 255.f, 169 / 255.f, 215 / 255.f, 0.5 };

			float green[4] = { 0, 1, 0, 1 };
			float greennoalpha[4] = { 0, 1, 0, 0 };
			float greenhalfalpha[4] = { 0, 1, 0, 0.5 };

			float white[4] = { 1, 1, 1, 1 };
			float whitenoalpha[4] = { 1, 1, 1, 0 };
			float whitehalfalpha[4] = { 1, 1, 1, 0.5 };

			float black[4] = { 0, 0, 0, 1 };
			float blacknoalpha[4] = { 0, 0, 0, 0 };
			float blackhalfalpha[4] = { 0, 0, 0, 0.5 };

			float grey[4] = { 0.12, 0.12, 0.12, 1 };
			float greynoalpha[4] = { 0.1, 0.1, 0.1, 0};
			float greyhalfalpha[4] = { 0.1, 0.1, 0.1, 0.5 };

			float* fromrgb(int r, int g, int b, int a)
			{
				float temp[4] = { r / 255.f, g / 255.f, b / 255.f, a / 255.f };
				return temp;
			}
		}

		int textwidth(const char* text, const char* font)
		{
			return R_TextWidth(text, 0x7FFFFFFF, R_RegisterFont(font, 0));
		}

		int textheight(const char* font)
		{
			return R_TextHeight(R_RegisterFont(font, 0));
		}

		int textwidthbo2(const char* text, const char* font)
		{
			return R_TextWidthBO2(0, text, 0x7FFFFFFF, R_RegisterFont(font, 0));
		}

		int textheightbo2(const char* font, float yScale)
		{
			return (int)(R_TextHeight(R_RegisterFont(font, 0)) * yScale);
		}

		void shader(float x, float y, float w, float h, float* col, char* material)
		{
			R_AddCmdDrawStretchPic(x, y, w, h, 0, 0, 1, 1, col, static_cast<void*>(Material_RegisterHandle(material, 0)));
		}

		void text(const char* text, float x, float y, char* font, float fontsize, float* col, bool dropshadow, render_alignment alignment)
		{
			if (dropshadow)
			{
				switch (alignment)
				{
					case render_alignment::def: 
					{
						R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), x + 2, y + 1, fontsize, fontsize, 0, colors::blackhalfalpha, 0);
						break;
					}
					case render_alignment::right: 
					{
						if (CURGAME == MW2)
						{
							R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidth(text, font) / 1) * fontsize) + 1, y + 1, fontsize, fontsize, 0, colors::blackhalfalpha, 0);
						}

						if (CURGAME == BO2)
						{
							R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidthbo2(text, font) / 1) * fontsize) + 1, y + 1, fontsize, fontsize, 0, colors::blackhalfalpha, 0);
						}

						break;
					}		
					case render_alignment::center: 
					{
						if (CURGAME == MW2)
						{
							R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidth(text, font) / 2) * fontsize) + 1, y + 1, fontsize, fontsize, 0, colors::blackhalfalpha, 0);
						}

						if (CURGAME == BO2)
						{
							R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidthbo2(text, font) / 2) * fontsize) + 1, y + 1, fontsize, fontsize, 0, colors::blackhalfalpha, 0);
						}

						break;
					}
				}
			}

			switch (alignment)
			{
				case render_alignment::def: 
				{
					R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), x, y, fontsize, fontsize, 0, col, 0); 
					break;
				}
				case render_alignment::right:
				{
					if (CURGAME == MW2)
					{
						R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidth(text, font) / 1) * fontsize), y, fontsize, fontsize, 0, col, 0); 
					}

					if (CURGAME == BO2)
					{
						R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidthbo2(text, font) / 1) * fontsize), y, fontsize, fontsize, 0, col, 0);
					}

					break;
				}
				case render_alignment::center: 
				{
					if (CURGAME == MW2)
					{
						R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidth(text, font) / 2) * fontsize), y, fontsize, fontsize, 0, col, 0); 
					}

					if (CURGAME == BO2)
					{
						R_AddCmdDrawText(text, 0x7FFFFFFF, static_cast<void*>(R_RegisterFont(font, 0)), (x - (textwidthbo2(text, font) / 2) * fontsize), y, fontsize, fontsize, 0, col, 0);
					}

					break;
				}
			}
		}
	}
}