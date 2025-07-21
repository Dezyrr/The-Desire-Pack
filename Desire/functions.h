#pragma once
#include "structs.h"

namespace game
{
	// shit ive found in ida
	// 0x820E2EC8 GetWeaponModel
	// 0x820E22C0 BG_GetWeaponDef
	// 0x820E22D8 BG_GetWeaponCompleteDef
	// 0x821E2E18 Item_SetDefaultVelocity
	// 0x821E2188 CurrentPrimaryWeapon
	// 0x821E4360 G_EntEnablePhysics
	// 0x820E2EC8 BG_GetWeaponModel
	// 0x821D53F0 Player_SwitchToWeapon
	// 0x821D9E30 PlayerCmd_DropItem
	// 0x821D9288 GScr_notifyOnPlayerCommand
	// 0x82249DF0 Scr_ClearOutParams
	// 0x821D4AD0 PlayerCmd_giveWeapon
	// 0x821D4C80 PlayerCmd_takeWeapon
	// 0x8224C2C8 Scr_AddBool
	// 0x8224C348 Scr_AddInt
	// 0x8224C3C8 Scr_AddFloat

	void(_cdecl* SV)(int clientNum, int type, const char* text);
	void (*SV_ExecuteClientCommand)(client_t* client, const char* s, int clientOK, int fromOldServer) = reinterpret_cast<void (*)(client_t*, const char*, int, int)>(0x82253140);

	void (*SV_DropClient)(client_t* client, const char* reason, bool tellThem) = reinterpret_cast<void (*)(client_t*, const char*, bool)>(0x822523A8);

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
	int(_cdecl* Cmd_RegisterNotification)(int idx, const char* button, const char* button_name) = reinterpret_cast<int(*)(int, const char*, const char*)>(0x82225858);
	int (*Scr_GetSelf)(int var) = reinterpret_cast<int(*)(int)>(0x82243758);
	int (*CG_GetClientNum)(int var) = reinterpret_cast<int(*)(int)>(0x82253948);
	int (*G_GetWeaponIndexForName)(const char* weaponname) = reinterpret_cast<int(*)(const char*)>(0x822105A8);
	int (*G_GivePlayerWeapon)(playerState_s* playerstate, int weaponidx, int camo, int akimbo) = reinterpret_cast<int(*)(playerState_s*, int, int, int)>(0x82210B30);
	int (*Add_Ammo)(gentity_s* ent, int weaponidx, char weaponmodel, int count, int fillclip) = reinterpret_cast<int(*)(gentity_s*, int, char, int, int)>(0x821E1EF8);
	gentity_s*(*Drop_Weapon)(gentity_s* ent, int weaponidx, char weaponmodel, int yep) = reinterpret_cast<gentity_s*(*)(gentity_s*, int, char, int)>(0x821E36A8);
	bool(__cdecl* SV_IsClientBot)(int clientNum) = (bool(*)(int))0x822597F0;
	const char* (__cdecl* G_GetWeaponNameForIndex)(int weaponIndex) = (const char* (*)(int))0x820E22F0;

	void (*Scr_AddString)(const char* s) = reinterpret_cast<void(*)(const char*)>(0x8224C620);
	void (*Scr_AddBool)(bool b) = reinterpret_cast<void(*)(bool)>(0x8224C2C8);
	void (*Scr_AddInt)(int i) = reinterpret_cast<void(*)(int)>(0x8224C348);
	void (*Scr_AddFloat)(float f) = reinterpret_cast<void(*)(float)>(0x8224C3C8);

	void (*Scr_Notify)(int* ent, short stringValue, unsigned int paramcount) = reinterpret_cast<void(*)(int*, short, unsigned int)>(0x82209710);
	void (*Scr_NotifyNum)(int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount) = reinterpret_cast<void(*)(int, unsigned int, unsigned int, unsigned int)>(0x8224AF10);
	void (*Item_SetDefaultVelocity)(gentity_s* ent, gentity_s* weaponidx) = reinterpret_cast<void(*)(gentity_s*, gentity_s*)>(0x821E2E18);
	void (*G_EntEnablePhysics)(gentity_s* ent, int physcollmap) = reinterpret_cast<void(*)(gentity_s*, int)>(0x821E4360);
	int (*BG_GetWeaponModel)(playerState_s* playerstate, int weaponidx) = reinterpret_cast<int(*)(playerState_s*, int)>(0x820E2EC8);
	int (*G_TakePlayerWeapon)(playerState_s* playerstate, unsigned int weaponidx) = reinterpret_cast<int(*)(playerState_s*, unsigned int)>(0x82210990);
	weaponDef* (*BG_GetWeaponDef)(int weaponidx) = reinterpret_cast<weaponDef * (*)(int)>(0x820E22C0);
	void (*GScr_LoadGameTypeScript)() = reinterpret_cast<void(*)()>(0x821FFCF0);

	void UI_OpenToastPopup(const char* title, const char* description, const char* material, int displayTime)  {
		((void(*)(...))0x82454800)(0, material, title, description, displayTime);
	}

	void (*PlayerCmd_DropItem)(scr_entref_t entref) = reinterpret_cast<void(*)(scr_entref_t)>(0x821D9E30);
	void (*PlayerCmd_giveWeapon)(scr_entref_t entref) = reinterpret_cast<void(*)(scr_entref_t)>(0x821D4AD0);
	void (*PlayerCmd_takeWeapon)(scr_entref_t entref) = reinterpret_cast<void(*)(scr_entref_t)>(0x821D4C80);

	void(*GScr_notifyOnPlayerCommand)(scr_entref_t entref) = (void(*)(scr_entref_t))0x821D9288;
	void(*Scr_ClearOutParams)() = reinterpret_cast<void(*)()>(0x82249DF0);

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

		bool isbot(int clientIndex)
		{
			return SV_IsClientBot(clientIndex);
		}

		bool isalive(int idx)
		{
			gentity_s* player = &g_entities[idx];
			
			if (player->health > 0)
				return true;

			return false;
		}

		void printimageinfomw2(XAssetHeader img)
		{
			printf(_("%s: [%d, %d, %d, %d, %d]\n"), img.image->name, img.image->width, img.image->height, img.image->depth, img.image->levelCount, img.image->Format);
		}

		void printimageinfobo2(XAssetHeaderBO2 img)
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
				if (CURGAME == MW2)
				{
					auto temp = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_IMAGE, materialname);
					helpers::injectimage((int)temp.image->pixels, imagetoreplacewith);
				}

				if (CURGAME == BO2)
				{
					auto temp = DB_FindXAssetHeaderBO2(XAssetTypeBO2::_ASSET_TYPE_IMAGE, materialname, false, 0);
					helpers::injectimage((int)temp.image->pixels, imagetoreplacewith);
				}
			}
		}

		static unsigned short rgbTo565(unsigned char r, unsigned char g, unsigned char b) {
			return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
		}


		void RecolorDXT1_128x128_7Levels(void* pixels, unsigned char r, unsigned char g, unsigned char b) {
			if (!pixels) return;

			unsigned char* data = static_cast<unsigned char*>(pixels);
			unsigned short color565 = rgbTo565(r, g, b);

			int baseWidth = 210;
			int baseHeight = 210;
			int mipLevels = 7;

			size_t offset = 0;

			for (int level = 0; level < mipLevels; ++level) {
				int mipWidth = baseWidth >> level;
				int mipHeight = baseHeight >> level;

				if (mipWidth < 1) mipWidth = 1;
				if (mipHeight < 1) mipHeight = 1;

				int blocksWide = (mipWidth + 3) / 4;
				int blocksHigh = (mipHeight + 3) / 4;
				size_t numBlocks = blocksWide * blocksHigh;

				// Each DXT1 block = 8 bytes
				for (size_t i = 0; i < numBlocks; ++i) {
					size_t blockOffset = offset + i * 8;

					// Set both base colors to the same color (solid color block)
					data[blockOffset + 0] = color565 & 0xFF;
					data[blockOffset + 1] = (color565 >> 8) & 0xFF;
					data[blockOffset + 2] = color565 & 0xFF;
					data[blockOffset + 3] = (color565 >> 8) & 0xFF;

					// Clear pixel indices so the block uses the first color everywhere
					data[blockOffset + 4] = 0x00;
					data[blockOffset + 5] = 0x00;
					data[blockOffset + 6] = 0x00;
					data[blockOffset + 7] = 0x00;
				}

				offset += numBlocks * 8;
			}
		}

		const char* getweaponname(char weapon)
		{
			return G_GetWeaponNameForIndex(weapon);
		}

		void printmodelinfomw2(const char* weapon)
		{
			auto gunXModel = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->gunXModel[0];
			auto worldModel = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->worldModel[0];
			auto handXModel = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->handXModel;
			auto szXAnims = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->szXAnims[0];
			auto szXAnimsL = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->szXAnimsL[0];
			auto szXAnimsR = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->szXAnimsR[0];
			auto xmodel = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XMODEL, weapon).xmodel;
			//auto xanim = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XANIMPARTS, weapon).xanim;

			printf(_("------------------------------------------------------------------------------------------------------------------------\n"));
			printf(_("gunXModel: %s: [%d]\n"), gunXModel->name, gunXModel->numBones);
			printf(_("worldModel: %s: [%d]\n"), worldModel->name, worldModel->numBones);
			printf(_("handXModel: %s: [%d]\n"), handXModel->name, handXModel->numBones);
			printf(_("szXAnims: %s\n"), szXAnims);
			printf(_("szXAnimsL: %s\n"), szXAnimsL);
			printf(_("szXAnimsR: %s\n"), szXAnimsR);
			printf(_("xmodel: %s: [%d]\n"), xmodel->name, xmodel->numBones);
			//printf(_("xanim: %s\n"), xanim->name);
			printf(_("------------------------------------------------------------------------------------------------------------------------\n"));
			printf(_("\n"));
		}

		void replaceweaponmodel(const char* weapon, const char* model)
		{
			DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->gunXModel[0] = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, model).weapon->weapDef->gunXModel[0];
			DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->worldModel[0] = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, model).weapon->weapDef->worldModel[0];
		}

		void replaceweaponmodelwithxmodel(const char* weapon, const char* model)
		{
			DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->gunXModel[0] = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XMODEL, model).xmodel;
			DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPONDEF, weapon).weapon->weapDef->worldModel[0] = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XMODEL, model).xmodel;
		}

		void replaceweaponanimation(const char* weapon, const char* anim)
		{
			//DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XANIMPARTS, weapon).xanim = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_XANIMPARTS, weapon).xanim;
		}

		bool isholdingsniper(int idx)
		{
			if (!g_entities[idx].client)
				return false;

			auto weapidx = g_entities[idx].client->ps.weapon.data;
			auto weapstr = G_GetWeaponNameForIndex(weapidx);

			if (strstr(weapstr, "cheytac") || 
				strstr(weapstr, "m21") || 
				strstr(weapstr, "wa2000") ||
				strstr(weapstr, "barrett"))
				return true;

			return false;
		}

		bool isholdingthrowingknife(int idx)
		{
			if (!g_entities[idx].client)
				return false;

			auto weapidx = g_entities[idx].client->ps.weapon.data;
			auto weapstr = G_GetWeaponNameForIndex(weapidx);

			if (weapstr == "throwingknife_mp")
				return true;

			return false;
		}

		bool isholdingakimboweapon(int idx)
		{
			if (!g_entities[idx].client)
				return false;

			auto weapidx = g_entities[idx].client->ps.weapon.data;
			auto weapstr = G_GetWeaponNameForIndex(weapidx);

			if (strstr(weapstr, "akimbo"))
				return true;

			return false;
		}

		bool isholdingpumpshotgun(int idx)
		{
			if (!g_entities[idx].client)
				return false;

			auto weapidx = g_entities[idx].client->ps.weapon.data;
			auto weapstr = G_GetWeaponNameForIndex(weapidx);

			if (strstr(weapstr, "spas") || 
				strstr(weapstr, "1887"))
				return true;

			return false;
		}

		void setclientdvar(int idx, const char* dvar, const char* value)
		{
			SV(idx, 0, va(("s %s \"%s\""), dvar, value));
		}

		void setclientname(int idx, const char* name)
		{
			strcpy(g_clients[idx].sess.cs.name, name);
		}

		bool SV_IsClientActive(int clientNum) 
		{
			return svs->clients[clientNum].state == CS_ACTIVE;
		}

		bool SV_IsTestClient(int clientNum) 
		{
			return svs->clients[clientNum].testClient == TC_TEST_CLIENT;
		}

		int getbotidx() 
		{
			for (int i = 0; i < 18; i++) 
			{
				if (SV_IsTestClient(i))
					return i;
			}

			return -1;
		}

		bool ishost(int idx)
		{
			if (idx < 0 || idx > 17)
				return false;

			return Session_IsHost(0x83AC3DB0, idx);
		}

		int gethostidx()
		{
			for (int i = 0; i < 18; i++)
			{
				if (ishost(i))
					return i;
			}

			return -1;
		}

		int getlocalidx()
		{
			if (cgs)
			{
				return cgs->clientNumber;
			}

			return -1;
		}

		bool islocalplayerhost()
		{
			return getlocalidx() == gethostidx();
		}

		void kickclient(int idx)
		{
			if (!ishost(getlocalidx()))
				return;

			if (!isingame())
				return;

			if (!g_entities[idx].client)
				return;

			client_t* client = &GetMemory<client_t*>(0x83620380 + 0x3818)[idx];

			SV_DropClient(client, "Player Kicked.", true);
		}

		void enableuav(int idx, bool on)
		{
			int radar = on ? 0x1 : 0x0;

			memset(&g_clients[idx].sess.hasRadar, radar, sizeof(int));
		}

		const char* getstance(int idx) {
			gclient_s* client = &g_clients[idx];

			if ((client->ps.pm_flags & 1))
				return "prone";

			if ((client->ps.pm_flags & 2))
				return "crouch";

			return "stand";
		}

		void switchtoweapon(int idx, const char* name)
		{
			char buffer[100];
			sprintf(buffer, "a %i", G_GetWeaponIndexForName(name));
			SV(idx, 1, buffer);
		}

		void giveweapon(int idx, const char* name, int camo, int akimbo)
		{
			gentity_s* player = &g_entities[idx];
			playerState_s* playerstate = &player->client->ps;

			int weaponidx = G_GetWeaponIndexForName(name);

			G_GivePlayerWeapon(playerstate, weaponidx, camo, akimbo);
			Add_Ammo(player, weaponidx, 0, 9999, 1);
		}

		void refillammo(int idx)
		{
			gentity_s* player = &g_entities[idx];

			Weapon* weapons = (Weapon*)player->client->ps.weaponsEquipped;
			int weaponsEquipped = 15;
			do
			{
				if (weapons->data)
					Add_Ammo(player, weapons->data, 0, 9999, 1);

				++weapons;
				--weaponsEquipped;
			} while (weaponsEquipped);
		}

		int getsecondaryweaponidx(int idx)
		{
			gentity_s* player = &g_entities[idx];

			Weapon* weapons = (Weapon*)player->client->ps.weaponsEquipped;

			if (weapons[0].data)
				return weapons[0].data;

			return -1;
		}

		int getprimaryweaponidx(int idx)
		{
			gentity_s* player = &g_entities[idx];

			Weapon* weapons = (Weapon*)player->client->ps.weaponsEquipped;

			if (weapons[2].data)
				return weapons[2].data;

			return -1;
		}

		void givesecondaryweaponcamo(int idx, int camo)
		{
			gentity_s* player = &g_entities[idx];
			playerState_s* playerstate = &player->client->ps;

			int weaponidx1 = getprimaryweaponidx(idx);
			int weaponidx = getsecondaryweaponidx(idx);

			// fuck off
			if (weaponidx && weaponidx1)
			{
				G_TakePlayerWeapon(playerstate, weaponidx);
			}

			G_GivePlayerWeapon(playerstate, weaponidx, camo, 0);
			Add_Ammo(player, weaponidx, 0, 9999, 1);
		}

		bool isonhostteam(int idx)
		{
			if (!isingame())
				return false;

			return g_entities[idx].client->sess.cs.team == g_entities[getlocalidx()].client->sess.cs.team;
		}

		void iprintln(int idx, const char* text)
		{
			SV(idx, 0, va(("f \"%s\""), text));
		}

		void notifyclient(int idx, const char* text)
		{
			iprintln(idx, std::string(_("^7[^6desire^7]: ")).append(text).c_str());
		}

		bool shouldrunonteamorself(int feature_value, int clientidx)
		{
			return (feature_value == 1 && clientidx == helpers::getlocalidx()) || (feature_value == 2 && helpers::isonhostteam(clientidx));
		}

		namespace gsc
		{
			void wait(int seconds)
			{
				time_t curtime = time(NULL);

				time_t endtime = curtime + seconds;

				while (endtime > curtime)
				{
					time(&curtime);
				}
			}

			void notifyonplayercommand(int idx, const char* command, const char* string)
			{
				scr_entref_t ent;
				ent.classnum = CLASS_NUM_ENTITY;
				ent.entnum = idx;

				Scr_AddString(command);
				Scr_AddString(string);
				scrVmPub->outparamcount = 2;
				GScr_notifyOnPlayerCommand(ent);
				scrVmPub->outparamcount = 0;

				Scr_ClearOutParams();
			}

			void takeweapon(int idx, const char* name)
			{
				scr_entref_t entref;
				entref.classnum = CLASS_NUM_ENTITY;
				entref.entnum = idx;

				Scr_AddString(name);
				scrVmPub->outparamcount = 1;
				PlayerCmd_takeWeapon(entref);
				scrVmPub->outparamcount = 0;

				Scr_ClearOutParams();
			}

			void giveweapon(int idx, const char* name)
			{
				scr_entref_t entref;
				entref.classnum = CLASS_NUM_ENTITY;
				entref.entnum = idx;

				Scr_AddString(name);
				scrVmPub->outparamcount = 1;
				PlayerCmd_giveWeapon(entref);
				scrVmPub->outparamcount = 0;

				Scr_ClearOutParams();
			}

			void dropitem(int idx, const char* name)
			{
				scr_entref_t entref;
				entref.classnum = CLASS_NUM_ENTITY;
				entref.entnum = idx;

				Scr_AddString(name);
				scrVmPub->outparamcount = 2;
				PlayerCmd_DropItem(entref);
				scrVmPub->outparamcount = 0;

				Scr_ClearOutParams();
			}
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