#pragma once
#include "includes.h"
#include "structs.h"

namespace game
{
	void(_cdecl* SV)(int clientNum, int type, const char* text);
	int(__cdecl* R_TextHeight)(void* font);
	int(__cdecl* R_TextWidth)(const char* text, int maxchars, void* font);
	int(__cdecl* R_TextWidthBO2)(int unk, const char* text, int maxchars, void* font);

	Material* (*Material_RegisterHandle)(const char* r3, int r4);
	void* (*R_RegisterFont)(const char* r3, int r4);
	void* (*R_AddCmdDrawText)(const char* r3, int r4, void* r5, float f1, float f2, float f3, float f4, float f5, const float* color, int something);
	void* (*R_AddCmdDrawStretchPic)(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, const float* color, void* material);
	bool(*Dvar_GetBool)(const char* dvarName);

	int(__cdecl* SL_GetString)(char*, int) = reinterpret_cast<int(__cdecl*)(char*, int)>(0x82242250);
	const char* (*SL_ConvertToString)(uint32_t stringValue) = reinterpret_cast<const char* (*)(uint32_t)>(0x82241898);
	void(*Cbuf_AddText)(int localClientNum, const char* text);
	int(__cdecl* BG_GetWeaponDef)(unsigned int weaponIndex) = reinterpret_cast<int(__cdecl*)(unsigned int)>(0x820E22C0);
	int(*Com_GetClientDObj)(int r3, int r4) = reinterpret_cast<int(*)(int, int)>(0x8222FCC0);
	char* (__cdecl* UI_GetMapDisplayName)(const char* mapname) = reinterpret_cast<char* (*)(const char*)>(0x822729A0);
	PCHAR(*fmt)(PCHAR format, ...) = reinterpret_cast<PCHAR(*)(PCHAR, ...)>(0x822A7028);
	int(*Dvar_GetInt)(const char* dvarName) = reinterpret_cast<int(*)(const char*)>(0x8229EF50);
	void(*CG_GameMessage)(int localClientNum, const char* msg) = reinterpret_cast<void(*)(int, const char*)>(0x821071D0);
	void(*CG_GameMessageBold)(int localClientNum, const char* msg) = reinterpret_cast<void(*)(int, const char*)>(0x821071F0);
	int(*Material_RegisterHandleInt)(const char* r3, int r4) = reinterpret_cast<int(*)(const char*, int)>(0x8234E510);
	dvar_t*(*Dvar_FindVar)(const char* name) = (dvar_t*(*)(const char*))0x82496430;
	int(*Key_isDown)(int ClientNum, int ButtonEnum) = reinterpret_cast<int(*)(int, int)>(0x82141300);
	float(__cdecl* CG_GoodRandomFloat)(int* seed) = reinterpret_cast<float(__cdecl*)(int*)>(0x820D76F0);
	const char* (*Dvar_GetString)(const char* dvarName) = reinterpret_cast<const char* (*)(const char*)>(0x8229F0A8);
	void(__cdecl* CG_DrawRotatedPicPhysical)(int, float, float, float, float, float, float*, void*) = reinterpret_cast<void(__cdecl*)(int, float, float, float, float, float, float*, void*)>(0x820F7900);
	void(__cdecl* CG_DrawRotatedPicPhysicalInt)(int, float, float, float, float, float, float*, int) = reinterpret_cast<void(__cdecl*)(int, float, float, float, float, float, float*, int)>(0x820F7900);
	void(__cdecl* CG_DrawRotatedPic)(int scrPlaces, float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const float* color, void* material) = reinterpret_cast<void(__cdecl*)(int, float, float, float, float, int, int, float, const float*, void*)>(0x820F7AB0);
	void(__cdecl* CG_DrawRotatedPicInt)(int scrPlaces, float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const float* color, int material) = reinterpret_cast<void(__cdecl*)(int, float, float, float, float, int, int, float, const float*, int)>(0x820F7AB0);
	int(__cdecl* SND_PlayLocalSoundAliasByName)(int localClientNum, const char* aliasname, int system) = reinterpret_cast<int(*)(int, const char*, int)>(0x8232B660);
	char* (__cdecl* UI_GetGameTypeDisplayName)(const char* gametype) = reinterpret_cast<char* (*)(const char*)>(0x82272BD0);
	void(__cdecl* R_DrawXModelSkinnedCached)(int context, int xsurf, int skinnedCachedOffset) = reinterpret_cast<void(*)(int, int, int)>(0x823982E0);
	int(__cdecl* MSG_ReadBitsCompress)(const char* from, char* to, int size) = reinterpret_cast<int(*)(const char*, char*, int)>(0x822348E8);
	void(__cdecl* CL_DrawStretchPicPhysical)(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const float* color, Material* material) = reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, const float*, Material*)>(0x821384D8);
	void(__cdecl* Menu_OpenByName)(int fuck, char* name) = reinterpret_cast<void(*)(int, char*)>(0x82281FA0);
	int(__cdecl* Menu_OpenName)(int fuck) = reinterpret_cast<int(*)(int)>(0x8226C438);

	XAssetHeader(__cdecl* DB_FindXAssetHeader)(XAssetType type, const char* name) = (XAssetHeader(*)(XAssetType, const char*))0x8219BBC8;
	XAssetHeaderBO2(__cdecl* DB_FindXAssetHeaderBO2)(XAssetTypeBO2 type, const char* name, bool errorIfMissing, int waitTime) = (XAssetHeaderBO2(*)(XAssetTypeBO2, const char*, bool, int))0x822CAE50;


	game_hudelem_s* (__cdecl* HudElem_Alloc)(int clientIndex, int TeamNum) = (game_hudelem_s * (*)(int, int))0x821DF928;
	void(__cdecl* HudElem_Free)(game_hudelem_s*) = reinterpret_cast<void(*)(game_hudelem_s*)>(0x821DF9C0);
	int(__cdecl* G_LocalizedStringIndex)(const char* String) = (int(*)(const char*))0x8220C7A0;
	int(__cdecl* G_MaterialIndex)(const char* Name) = (int(*)(const char*))0x8220C960;
	void(_cdecl* SV_Cmd_TokenizeString)(const char* text_in) = (void(*)(const char*))0x822252B0;
	void(_cdecl* ClientCommand)(unsigned long clientIndex) = (void(*)(unsigned long))0x821DC5A0;
	void(_cdecl* SV_Cmd_EndTokenizedString)() = (void(*)())0x822252D0;
	void(_cdecl* Dvar_SetInt)(const char* dvarName, int val, int idk) = reinterpret_cast<void(*)(const char*, int, int)>(0x822A04B0);
	void(_cdecl* Dvar_SetIntByName)(const char* dvarName, int val) = reinterpret_cast<void(*)(const char*, int)>(0x822A0BA8);
	void(_cdecl* SetDvar)(const char* dvarName, const char* val) = reinterpret_cast<void(*)(const char*, const char*)>(0x822A1100);
	bool (*Session_IsHost)(uintptr_t sessionDataPtr, int clientNum) = reinterpret_cast<bool (*)(uintptr_t, int)>(0x82320138);
	void (*SetClientOrigin)(gentity_s* ent, const float* origin) = reinterpret_cast<void (*)(gentity_s*, const float*)>(0x821D3798);
	void (*SetClientViewAngle)(gentity_s* ent, const float* angle) = reinterpret_cast<void (*)(gentity_s*, const float*)>(0x821D3550);
	gentity_s* (*SV_AddTestClient)() = reinterpret_cast<gentity_s * (*)()>(0x82254690);
	void (*G_SetModel)(gentity_s* ent, const char* modelName) = reinterpret_cast<void (*)(gentity_s*, const char*)>(0x8220D278);
	void (*SV_LinkEntity)(gentity_s* gEnt) = reinterpret_cast<void (*)(gentity_s*)>(0x8225F518);
	void (*SV_UnlinkEntity)(gentity_s* gEnt) = reinterpret_cast<void (*)(gentity_s*)>(0x8225F430);
	int(_cdecl* NotifyOnButton)(int idx, const char* button, const char* button_name) = reinterpret_cast<int(*)(int, const char*, const char*)>(0x82225858);
	int (*Scr_GetSelf)(int var) = reinterpret_cast<int(*)(int)>(0x82243758);
	int (*CG_GetClientNum)(int var) = reinterpret_cast<int(*)(int)>(0x82253948);
	int (*G_GetWeaponIndexForName)(const char* weaponname) = reinterpret_cast<int(*)(const char*)>(0x822105A8);
	int (*G_GivePlayerWeapon)(playerState_s* playerstate, int weaponidx, char altmodelidx, int akimbo) = reinterpret_cast<int(*)(playerState_s*, int, char, int)>(0x82210B30);
	int (*Add_Ammo)(gentity_s* ent, int weaponidx, char weaponmodel, int count, int fillclip) = reinterpret_cast<int(*)(gentity_s*, int, char, int, int)>(0x821E1EF8);
	int (*Drop_Weapon)(gentity_s* ent, int weaponidx, char weaponmodel, unsigned int tag) = reinterpret_cast<int(*)(gentity_s*, int, char, unsigned int)>(0x821E36A8);
	bool(__cdecl* SV_IsClientBot)(int clientNum) = (bool(*)(int))0x822597F0;

	void UI_OpenToastPopup(const char* title, const char* description, const char* material, int displayTime)  {
		((void(*)(...))0x82454800)(0, material, title, description, displayTime);
	}

	void initgamefunctions()
	{
		switch (CURGAME)
		{
			case MW2:
			{
				SV = (void(*)(int, int, const char*))0x822548D8;
				R_TextHeight = reinterpret_cast<int(__cdecl*)(void*)>(0x8234DDF0);
				R_TextWidth = reinterpret_cast<int(__cdecl*)(const char*, int, void*)>(0x8234DD20);
				Dvar_GetBool = reinterpret_cast<bool(*)(const char*)>(0x8229EEE8);
				R_AddCmdDrawText = reinterpret_cast<void* (*)(const char* r3, int r4, void* r5, float f1, float f2, float f3, float f4, float f5, const float* color, int something)>(0x82350278);
				R_AddCmdDrawStretchPic = reinterpret_cast<void* (*)(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, const float* color, void* material)>(0x8234F9B8);
				R_RegisterFont = reinterpret_cast<void* (*)(const char*, int)>(0x8234DCB0);
				Material_RegisterHandle = reinterpret_cast<Material * (*)(const char*, int)>(0x8234E510);
				Cbuf_AddText = reinterpret_cast<void(*)(int, const char*)>(0x82224990);

				//printf("setup mw2 funcs\n");

				break;
			}

			case BO2:
			{
				SV = (void(*)(int, int, const char*))0x822548D8;
				R_TextHeight = reinterpret_cast<int(__cdecl*)(void*)>(0x82490390);
				R_TextWidthBO2 = reinterpret_cast<int(__cdecl*)(int, const char*, int, void*)>(0x828B6FD8);
				Dvar_GetBool = reinterpret_cast<bool(*)(const char*)>(0x824964C0);
				R_AddCmdDrawText = reinterpret_cast<void* (*)(const char* r3, int r4, void* r5, float f1, float f2, float f3, float f4, float f5, const float* color, int something)>(0x828B8BA0);
				R_AddCmdDrawStretchPic = reinterpret_cast<void* (*)(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, const float* color, void* material)>(0x828B86C0);
				R_RegisterFont = reinterpret_cast<void* (*)(const char*, int)>(0x82275F78);
				Material_RegisterHandle = reinterpret_cast<Material * (*)(const char*, int)>(0x828B78F0);
				Cbuf_AddText = reinterpret_cast<void(*)(int, const char*)>(0x824015E0);

				//printf("setup bo2 funcs\n");

				break;
			}

			default: break;
		}
	}

	namespace helpers
	{
		bool isingame()
		{
			if (CURGAME == MW2)
				return Dvar_GetBool(_("cl_ingame"));

			else if (CURGAME == BO2)
				return Dvar_FindVar(_("cl_ingame"))->current.enabled;

			return false;
		}

		bool isonlinegame()
		{
			if (CURGAME == MW2)
				return Dvar_GetBool(_("onlinegame"));

			else if (CURGAME == BO2)
				return Dvar_FindVar(_("onlinegame"))->current.enabled;

			return false;
		}

		bool ispublicmatch()
		{
			if (CURGAME == MW2)
				return Dvar_GetBool(_("xblive_privatematch"));

			else if (CURGAME == BO2)
				return Dvar_FindVar(_("xblive_privatematch"))->current.enabled;

			return false;
		}

		void printimageinfo(XAssetHeaderBO2 img)
		{
			printf(_("%s: [%d, %d, %d, %d]\n"), img.image->name, img.image->width, img.image->height, img.image->depth, img.image->levelCount);
		}

		Material* getmaterial(const char* shader)
		{
			return Material_RegisterHandle(shader, 0);
		}

		void injectimage(int Address, const char* FilePath)
		{
			if (FileExists((PCHAR)FilePath))
			{
				FILE* Image;
				fopen_s(&Image, FilePath, ("rb"));

				fseek(Image, 0, SEEK_END);
				long lsize = ftell(Image);
				fseek(Image, 0, SEEK_SET);
				fread((char*)Address, sizeof(char), lsize, Image);

				fclose(Image);
			}
		}

		void replacematerial(const char* materialname, const char* imagetoreplacewith)
		{
			if (FileExists((PCHAR)imagetoreplacewith))
			{
				auto temp = DB_FindXAssetHeaderBO2(XAssetTypeBO2::_ASSET_TYPE_IMAGE, materialname, false, 0);
				helpers::injectimage((int)temp.image->pixels, imagetoreplacewith);
				helpers::printimageinfo(temp);
			}
		}

		void setclientdvar(int idx, const char* dvar, const char* value)
		{
			SV(idx, 0, va(("s %s \"%s\""), dvar, value));
		}

		bool isbot(int idx)
		{
			return SV_IsClientBot(idx);
		}

		bool ishost(int idx)
		{
			if (idx < 0 || idx > 17)
				return false;

			return Session_IsHost(0x83AC3DB0, idx);
		}

		bool isonhostteam(int idx)
		{
			if (!isingame())
				return false;

			if (!cgs || !cgameGlob[idx].ClientInfo)
				return false;

			short hostteam = -1;

			for (int i = 0; i < 18; i++)
			{
				if (!g_entities[i].client)
					continue;

				if (ishost(i))
				{
					hostteam = g_entities[i].client->sess.cs.team;
					break;
				}
			}

			if (hostteam == -1)
			{
				return false;
			}

			short playerteam = g_entities[idx].client->sess.cs.team;

			return playerteam == hostteam;
		}

		void iprintln(int idx, const char* text)
		{
			SV(idx, 0, va(("f \"%s\""), text));
		}

		void notifyclient(int idx, const char* text)
		{
			iprintln(idx, std::string(_("^7[^6desire^7]: ")).append(text).c_str());
		}
	}

	namespace hudelems
	{
		void set_text(game_hudelem_s* elem, const char* text, int font, float fontScale, float x, float y, int alignOrg, float sort, byte r = 255, byte g = 255, byte b = 255, byte a = 255)
		{
			elem->elem.type = 0x01;
			elem->elem.alignOrg = alignOrg;
			elem->elem.alignScreen = 0x01;
			elem->elem.font = font;
			elem->elem.fontScale = fontScale;
			elem->elem.x = x;
			elem->elem.y = y;
			elem->elem.color.r = r;
			elem->elem.color.g = g;
			elem->elem.color.b = b;
			elem->elem.color.a = a;
			elem->elem.sort = sort;
			elem->elem.text = G_LocalizedStringIndex(text);
		}

		void set_shader(game_hudelem_s* elem, const char* materialName, float x, float y, int width, int height, int alignOrg, float sort, byte r = 255, byte g = 255, byte b = 255, byte a = 255)
		{
			elem->elem.type = 0x04;
			elem->elem.alignOrg = alignOrg;
			elem->elem.alignScreen = 0x01;
			elem->elem.x = x;
			elem->elem.y = y;
			elem->elem.color.r = r;
			elem->elem.color.g = g;
			elem->elem.color.b = b;
			elem->elem.color.a = a;
			elem->elem.width = width;
			elem->elem.height = height;
			elem->elem.sort = sort;
			elem->elem.materialIndex = G_MaterialIndex(materialName);
		}

		void move_over_time(game_hudelem_s* elem, int Time, float X, float Y, int delay = 0)
		{
			elem->elem.fromX = elem->elem.x;
			elem->elem.fromY = elem->elem.y;
			elem->elem.fromAlignOrg = elem->elem.alignOrg;
			elem->elem.fromAlignScreen = elem->elem.alignScreen;
			elem->elem.moveStartTime = *(int*)0x8310A12C + delay;
			elem->elem.moveTime = Time;
			elem->elem.x = X;
			elem->elem.y = Y;
		}
	}
}