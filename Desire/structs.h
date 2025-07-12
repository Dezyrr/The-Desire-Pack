#include "includes.h"

typedef void PartyData_s;

typedef enum {
	RT = 0x100,
	RS = 0x400,
	X = 0x2000,
	PRONE = 0x10000,
	CROUCH = 0x20000,
	A = 0x40000,
	LS = 0x200200,
	RB = 0x400000,
	LB = 0x800000,
	LT = 0x8080000
}buttons_t;

struct opd_s
{
	int function;
	int toc;
};

struct gsc_function_temp
{
	opd_s* seg;
	int type;
};

struct gsc_method_temp
{
	opd_s* seg;
};
enum UIContextIndex_t
{
	INVALID_UI_CONTEXT = 0xFFFFFFFF,
	UI_CONTEXT_FRONTEND = 0x0,
	UI_CONTEXT_INDEX_0 = 0x0,
	UI_CONTEXT_COUNT = 0x1,
};
enum camolist
{
	CAMO_NONE,
	CAMO_WOODLAND,
	CAMO_DIGITAL,
	CAMO_DESERT,
	CAMO_ARCTIC,
	CAMO_URBAN,
	CAMO_RED_TIGER,
	CAMO_BLUE_TIGER,
	CAMO_FALL,
};
enum dvarType_t
{
	DVAR_TYPE_INVALID = 0x0,
	DVAR_TYPE_BOOL = 0x1,
	DVAR_TYPE_FLOAT = 0x2,
	DVAR_TYPE_FLOAT_2 = 0x3,
	DVAR_TYPE_FLOAT_3 = 0x4,
	DVAR_TYPE_FLOAT_4 = 0x5,
	DVAR_TYPE_INT = 0x6,
	DVAR_TYPE_ENUM = 0x7,
	DVAR_TYPE_STRING = 0x8,
	DVAR_TYPE_COLOR = 0x9,
	DVAR_TYPE_INT64 = 0xA,
	DVAR_TYPE_LINEAR_COLOR_RGB = 0xB,
	DVAR_TYPE_COLOR_XYZ = 0xC,
	DVAR_TYPE_COUNT = 0xD,
};
enum ClassNum
{
	CLASS_NUM_ENTITY = 0x0,
	CLASS_NUM_HUDELEM = 0x1,
	CLASS_NUM_PATHNODE = 0x2,
	CLASS_NUM_VEHICLENODE = 0x3,
	CLASS_NUM_VEHTRACK_SEGMENT = 0x4,
	CLASS_NUM_FXENTITY = 0x5,
	CLASS_NUM_COUNT = 0x6,
};
enum entityType_t
{
	ET_GENERAL = 0x0,
	ET_PLAYER = 0x1,
	ET_PLAYER_CORPSE = 0x2,
	ET_ITEM = 0x3,
	ET_MISSILE = 0x4,
	ET_INVISIBLE = 0x5,
	ET_SCRIPTMOVER = 0x6,
	ET_SOUND_BLEND = 0x7,
	ET_FX = 0x8,
	ET_LOOP_FX = 0x9,
	ET_PRIMARY_LIGHT = 0xA,
	ET_TURRET = 0xB,
	ET_HELICOPTER = 0xC,
	ET_PLANE = 0xD,
	ET_VEHICLE = 0xE,
	ET_VEHICLE_CORPSE = 0xF,
	ET_ACTOR = 0x10,
	ET_ACTOR_SPAWNER = 0x11,
	ET_ACTOR_CORPSE = 0x12,
	ET_STREAMER_HINT = 0x13,
	ET_ZBARRIER = 0x14,
	ET_EVENTS = 0x15,
};
enum usercmdButtonBits
{
	CMD_BUTTON_ATTACK = 1 << 0,
	CMD_BUTTON_SPRINT = 1 << 1,
	CMD_BUTTON_MELEE = 1 << 2,
	CMD_BUTTON_ACTIVATE = 1 << 3,
	CMD_BUTTON_RELOAD = 1 << 4,
	CMD_BUTTON_USE_RELOAD = 1 << 5,
	CMD_BUTTON_LEAN_LEFT = 1 << 6,
	CMD_BUTTON_LEAN_RIGHT = 1 << 7,
	CMD_BUTTON_PRONE = 1 << 8,
	CMD_BUTTON_CROUCH = 1 << 9,
	CMD_BUTTON_UP = 1 << 10,
	CMD_BUTTON_ADS = 1 << 11,
	CMD_BUTTON_DOWN = 1 << 12,
	CMD_BUTTON_BREATH = 1 << 13,
	CMD_BUTTON_FRAG = 1 << 14,
	CMD_BUTTON_OFFHAND_SECONDARY = 1 << 15,
	CMD_BUTTON_THROW = 1 << 19,
};

enum weaponStates
{
	WEAPON_READY = 0x0,
	WEAPON_RAISING = 0x1,
	WEAPON_RAISING_ALTSWITCH = 0x2,
	WEAPON_DROPPING = 0x3,
	WEAPON_DROPPING_QUICK = 0x4,
	WEAPON_DROPPING_ALT = 0x5,
	WEAPON_FIRING = 0x6,
	WEAPON_RECHAMBERING = 0x7,
	WEAPON_RELOADING = 0x8,
	WEAPON_RELOADING_INTERUPT = 0x9,
	WEAPON_RELOAD_START = 0xA,
	WEAPON_RELOAD_START_INTERUPT = 0xB,
	WEAPON_RELOAD_END = 0xC,
	WEAPON_MELEE_INIT = 0xD,
	WEAPON_MELEE_FIRE = 0xE,
	WEAPON_MELEE_END = 0xF,
	WEAPON_OFFHAND_INIT = 0x10,
	WEAPON_OFFHAND_PREPARE = 0x11,
	WEAPON_OFFHAND_HOLD = 0x12,
	WEAPON_OFFHAND_FIRE = 0x13,
	WEAPON_OFFHAND_DETONATE = 0x14,
	WEAPON_OFFHAND_END = 0x15,
	WEAPON_DETONATING = 0x16,
	WEAPON_SPRINT_RAISE = 0x17,
	WEAPON_SPRINT_LOOP = 0x18,
	WEAPON_SPRINT_DROP = 0x19,
	WEAPON_STUNNED_START = 0x1A,
	WEAPON_STUNNED_LOOP = 0x1B,
	WEAPON_STUNNED_END = 0x1C,
	WEAPON_NIGHTVISION_WEAR = 0x1D,
	WEAPON_NIGHTVISION_REMOVE = 0x1E,
	WEAPONSTATES_NUM = 0x1F,
};

enum weaponAnim
{
	WEAP_IDLE = 0x0,
	WEAP_FORCE_IDLE = 0x1,
	WEAP_ATTACK = 0x2,
	WEAP_ATTACK_LASTSHOT = 0x3,
	WEAP_RECHAMBER = 0x4,
	WEAP_ADS_ATTACK = 0x5,
	WEAP_ADS_ATTACK_LASTSHOT = 0x6,
	WEAP_ADS_RECHAMBER = 0x7,
	WEAP_MELEE_ATTACK = 0x8,
	WEAP_MELEE_CHARGE = 0x9,
	WEAP_DROP = 0xA,
	WEAP_RAISE = 0xB,
	WEAP_FIRST_RAISE = 0xC,
	WEAP_RELOAD = 0xD,
	WEAP_RELOAD_EMPTY = 0xE,
	WEAP_RELOAD_START = 0xF,
	WEAP_RELOAD_END = 0x10,
	WEAP_ALTSWITCHFROM = 0x11,
	WEAP_ALTSWITCHTO = 0x12,
	WEAP_QUICK_DROP = 0x13,
	WEAP_QUICK_RAISE = 0x14,
	WEAP_EMPTY_DROP = 0x15,
	WEAP_EMPTY_RAISE = 0x16,
	WEAP_SPRINT_IN = 0x17,
	WEAP_SPRINT_LOOP = 0x18,
	WEAP_SPRINT_OUT = 0x19,
	WEAP_STUNNED_START = 0x1A,
	WEAP_STUNNED_LOOP = 0x1B,
	WEAP_STUNNED_END = 0x1C,
	WEAP_HOLD_FIRE = 0x1D,
	WEAP_DETONATE = 0x1E,
	WEAP_NIGHTVISION_WEAR = 0x1F,
	WEAP_NIGHTVISION_REMOVE = 0x20,
	MAX_WP_ANIMATIONS = 0x21,
};

enum sessionState_t
{
	SESS_STATE_PLAYING = 0x0,
	SESS_STATE_DEAD = 0x1,
	SESS_STATE_SPECTATOR = 0x2,
	SESS_STATE_INTERMISSION = 0x3,
};

enum clientConnected_t
{
	CON_DISCONNECTED = 0x0,
	CON_CONNECTING = 0x1,
	CON_CONNECTED = 0x2,
};

enum team_t
{
	TEAM_FREE,
	TEAM_AXIS,
	TEAM_ALLIES,
	TEAM_SPECTATOR,
	TEAM_NUM_TEAMS
};
enum ffa_team_t
{
	TEAM_FFA_NONE = 0x0,
	TEAM_FFA_AXIS = 0x1,
	TEAM_FFA_ALLIES = 0x2,
	TEAM_FFA_THREE = 0x3,
};

enum VehicleAnimState
{
	VEHICLEANIMSTATE_IDLE = 0x0,
	VEHICLEANIMSTATE_ENTRY = 0x1,
	VEHICLEANIMSTATE_CHANGEPOS = 0x2,
	VEHICLEANIMSTATE_EXIT = 0x3,
	VEHICLEANIMSTATECOUNT = 0x4,
};

enum MissileStage
{
	MISSILESTAGE_SOFTLAUNCH = 0x0,
	MISSILESTAGE_ASCENT = 0x1,
	MISSILESTAGE_DESCENT = 0x2,
};

/* 243 */
enum MissileFlightMode
{
	MISSILEFLIGHTMODE_TOP = 0x0,
	MISSILEFLIGHTMODE_DIRECT = 0x1,
};

enum meansOfDeath_t : __int32
{
	MOD_UNKNOWN = 0x0,
	MOD_PISTOL_BULLET = 0x1,
	MOD_RIFLE_BULLET = 0x2,
	MOD_EXPLOSIVE_BULLET = 0x3,
	MOD_GRENADE = 0x4,
	MOD_GRENADE_SPLASH = 0x5,
	MOD_PROJECTILE = 0x6,
	MOD_PROJECTILE_SPLASH = 0x7,
	MOD_MELEE = 0x8,
	MOD_HEAD_SHOT = 0x9,
	MOD_CRUSH = 0xA,
	MOD_FALLING = 0xB,
	MOD_SUICIDE = 0xC,
	MOD_TRIGGER_HURT = 0xD,
	MOD_EXPLOSIVE = 0xE,
	MOD_IMPACT = 0xF,
	MOD_NUM = 0x10,
};

enum hitLocation_t : __int32
{
	HITLOC_NONE = 0x0,
	HITLOC_HELMET = 0x1,
	HITLOC_HEAD = 0x2,
	HITLOC_NECK = 0x3,
	HITLOC_TORSO_UPR = 0x4,
	HITLOC_TORSO_LWR = 0x5,
	HITLOC_R_ARM_UPR = 0x6,
	HITLOC_L_ARM_UPR = 0x7,
	HITLOC_R_ARM_LWR = 0x8,
	HITLOC_L_ARM_LWR = 0x9,
	HITLOC_R_HAND = 0xA,
	HITLOC_L_HAND = 0xB,
	HITLOC_R_LEG_UPR = 0xC,
	HITLOC_L_LEG_UPR = 0xD,
	HITLOC_R_LEG_LWR = 0xE,
	HITLOC_L_LEG_LWR = 0xF,
	HITLOC_R_FOOT = 0x10,
	HITLOC_L_FOOT = 0x11,
	HITLOC_GUN = 0x12,
	HITLOC_SHIELD = 0x13,
	HITLOC_NUM = 0x14,
};

enum XAssetType
{
	ASSET_TYPE_XMODELPIECES = 0x0,
	ASSET_TYPE_PHYSPRESET = 0x1,
	ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
	ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
	ASSET_TYPE_XANIMPARTS = 0x5,
	ASSET_TYPE_XMODEL = 0x4,
	ASSET_TYPE_MATERIAL = 0x6,
	ASSET_TYPE_TECHNIQUE_SET = 0x7,
	ASSET_TYPE_IMAGE = 0x8,
	ASSET_TYPE_SOUND = 0x9,
	ASSET_TYPE_SOUND_PATCH = 0xA,
	ASSET_TYPE_CLIPMAP = 0xB,
	ASSET_TYPE_CLIPMAP_PVS = 0xC,
	ASSET_TYPE_COMWORLD = 0xD,
	ASSET_TYPE_GAMEWORLD_SP = 0xE,
	ASSET_TYPE_GAMEWORLD_MP = 0xF,
	ASSET_TYPE_MAP_ENTS = 0x10,
	ASSET_TYPE_GFXWORLD = 0x11,
	ASSET_TYPE_LIGHT_DEF = 0x12,
	ASSET_TYPE_UI_MAP = 0x13,
	ASSET_TYPE_FONT = 0x14,
	ASSET_TYPE_FONTICON = 0x15,
	ASSET_TYPE_MENULIST = 0x16,
	ASSET_TYPE_MENU = 0x17,
	ASSET_TYPE_LOCALIZE_ENTRY = 0x18,
	ASSET_TYPE_WEAPON = 0x19,
	ASSET_TYPE_WEAPONDEF = 0x1A,
	ASSET_TYPE_WEAPON_VARIANT = 0x1B,
	ASSET_TYPE_WEAPON_FULL = 0x1C,
	ASSET_TYPE_ATTACHMENT = 0x1D,
	ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1E,
	ASSET_TYPE_WEAPON_CAMO = 0x1F,
	ASSET_TYPE_SNDDRIVER_GLOBALS = 0x20,
	ASSET_TYPE_FX = 0x21,
	ASSET_TYPE_IMPACT_FX = 0x22,
	ASSET_TYPE_AITYPE = 0x23,
	ASSET_TYPE_MPTYPE = 0x24,
	ASSET_TYPE_MPBODY = 0x25,
	ASSET_TYPE_MPHEAD = 0x26,
	ASSET_TYPE_CHARACTER = 0x27,
	ASSET_TYPE_XMODELALIAS = 0x28,
	ASSET_TYPE_RAWFILE = 0x29,
	ASSET_TYPE_STRINGTABLE = 0x2A,
	ASSET_TYPE_LEADERBOARD = 0x2B,
	ASSET_TYPE_XGLOBALS = 0x2C,
	ASSET_TYPE_DDL = 0x2D,
	ASSET_TYPE_GLASSES = 0x2E,
	ASSET_TYPE_EMBLEMSET = 0x2F,
	ASSET_TYPE_SCRIPTPARSETREE = 0x30,
	ASSET_TYPE_KEYVALUEPAIRS = 0x31,
	ASSET_TYPE_VEHICLEDEF = 0x32,
	ASSET_TYPE_MEMORYBLOCK = 0x33,
	ASSET_TYPE_ADDON_MAP_ENTS = 0x34,
	ASSET_TYPE_TRACER = 0x35,
	ASSET_TYPE_SKINNEDVERTS = 0x36,
	ASSET_TYPE_QDB = 0x37,
	ASSET_TYPE_SLUG = 0x38,
	ASSET_TYPE_FOOTSTEP_TABLE = 0x39,
	ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3A,
	ASSET_TYPE_ZBARRIER = 0x3B,
	ASSET_TYPE_COUNT = 0x3C,
	ASSET_TYPE_STRING = 0x3C,
	ASSET_TYPE_ASSETLIST = 0x3D,
	ASSET_TYPE_REPORT = 0x3E,
	ASSET_TYPE_DEPEND = 0x3F,
	ASSET_TYPE_FULL_COUNT = 0x40,
};

enum XAssetTypeBO2
{
	_ASSET_TYPE_XMODELPIECES = 0x0,
	_ASSET_TYPE_PHYSPRESET = 0x1,
	_ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
	_ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
	_ASSET_TYPE_XANIMPARTS = 0x4,
	_ASSET_TYPE_XMODEL = 0x5,
	_ASSET_TYPE_MATERIAL = 0x6,
	_ASSET_TYPE_PIXELSHADER = 0x7,
	_ASSET_TYPE_TECHNIQUE_SET = 0x8,
	_ASSET_TYPE_IMAGE = 0x9,
	_ASSET_TYPE_SOUND = 0xA,
	_ASSET_TYPE_SOUND_PATCH = 0xB,
	_ASSET_TYPE_CLIPMAP = 0xC,
	_ASSET_TYPE_CLIPMAP_PVS = 0xD,
	_ASSET_TYPE_COMWORLD = 0xE,
	_ASSET_TYPE_GAMEWORLD_SP = 0xF,
	_ASSET_TYPE_GAMEWORLD_MP = 0x10,
	_ASSET_TYPE_MAP_ENTS = 0x11,
	_ASSET_TYPE_GFXWORLD = 0x12,
	_ASSET_TYPE_LIGHT_DEF = 0x13,
	_ASSET_TYPE_UI_MAP = 0x14,
	_ASSET_TYPE_FONT = 0x15,
	_ASSET_TYPE_FONTICON = 0x16,
	_ASSET_TYPE_MENULIST = 0x17,
	_ASSET_TYPE_MENU = 0x18,
	_ASSET_TYPE_LOCALIZE_ENTRY = 0x19,
	_ASSET_TYPE_WEAPON = 0x1A,
	_ASSET_TYPE_WEAPONDEF = 0x1B,
	_ASSET_TYPE_WEAPON_VARIANT = 0x1C,
	_ASSET_TYPE_WEAPON_FULL = 0x1D,
	_ASSET_TYPE_ATTACHMENT = 0x1E,
	_ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1F,
	_ASSET_TYPE_WEAPON_CAMO = 0x20,
	_ASSET_TYPE_SNDDRIVER_GLOBALS = 0x21,
	_ASSET_TYPE_FX = 0x22,
	_ASSET_TYPE_IMPACT_FX = 0x23,
	_ASSET_TYPE_AITYPE = 0x24,
	_ASSET_TYPE_MPTYPE = 0x25,
	_ASSET_TYPE_MPBODY = 0x26,
	_ASSET_TYPE_MPHEAD = 0x27,
	_ASSET_TYPE_CHARACTER = 0x28,
	_ASSET_TYPE_XMODELALIAS = 0x29,
	_ASSET_TYPE_RAWFILE = 0x2A,
	_ASSET_TYPE_STRINGTABLE = 0x2B,
	_ASSET_TYPE_LEADERBOARD = 0x2C,
	_ASSET_TYPE_XGLOBALS = 0x2D,
	_ASSET_TYPE_DDL = 0x2E,
	_ASSET_TYPE_GLASSES = 0x2F,
	_ASSET_TYPE_TEXTURELIST = 0x30,
	_ASSET_TYPE_EMBLEMSET = 0x31,
	_ASSET_TYPE_SCRIPTPARSETREE = 0x32,
	_ASSET_TYPE_KEYVALUEPAIRS = 0x33,
	_ASSET_TYPE_VEHICLEDEF = 0x34,
	_ASSET_TYPE_MEMORYBLOCK = 0x35,
	_ASSET_TYPE_ADDON_MAP_ENTS = 0x36,
	_ASSET_TYPE_TRACER = 0x37,
	_ASSET_TYPE_SKINNEDVERTS = 0x38,
	_ASSET_TYPE_QDB = 0x39,
	_ASSET_TYPE_SLUG = 0x3A,
	_ASSET_TYPE_FOOTSTEP_TABLE = 0x3B,
	_ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3C,
	_ASSET_TYPE_ZBARRIER = 0x3D,
	_ASSET_TYPE_COUNT = 0x3E,
	_ASSET_TYPE_STRING = 0x3E,
	_ASSET_TYPE_ASSETLIST = 0x3F,
	_ASSET_TYPE_REPORT = 0x40,
	_ASSET_TYPE_DEPEND = 0x41,
	_ASSET_TYPE_FULL_COUNT = 0x42,
};


enum materialSurfType_t
{
	SURF_TYPE_DEFAULT,
	SURF_TYPE_BARK,
	SURF_TYPE_BRICK,
	SURF_TYPE_CARPET,
	SURF_TYPE_CLOTH,
	SURF_TYPE_CONCRETE,
	SURF_TYPE_DIRT,
	SURF_TYPE_FLESH,
	SURF_TYPE_FOLIAGE,
	SURF_TYPE_GLASS,
	SURF_TYPE_GRASS,
	SURF_TYPE_GRAVEL,
	SURF_TYPE_ICE,
	SURF_TYPE_METAL,
	SURF_TYPE_MUD,
	SURF_TYPE_PAPER,
	SURF_TYPE_PLASTER,
	SURF_TYPE_ROCK,
	SURF_TYPE_SAND,
	SURF_TYPE_SNOW,
	SURF_TYPE_WATER,
	SURF_TYPE_WOOD,
	SURF_TYPE_ASPHALT,
	SURF_TYPE_CERAMIC,
	SURF_TYPE_PLASTIC,
	SURF_TYPE_RUBBER,
	SURF_TYPE_CUSHION,
	SURF_TYPE_FRUIT,
	SURF_TYPE_PAINTED_METAL,
	SURF_TYPE_RIOT_SHIELD,
	SURF_TYPE_SLUSH,

	SURF_TYPE_COUNT
};

enum TraceHitType
{
	TRACE_HITTYPE_NONE = 0x0,
	TRACE_HITTYPE_ENTITY = 0x1,
	TRACE_HITTYPE_DYNENT_MODEL = 0x2,
	TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
	TRACE_HITTYPE_GLASS = 0x4,
};


enum statIndex_t : __int32
{
	STAT_HEALTH = 0x0,
	STAT_DEAD_YAW = 0x1,
	STAT_MAX_HEALTH = 0x2,
	STAT_IDENT_CLIENT_NUM = 0x3,
	STAT_SPAWN_COUNT = 0x4,
	MAX_STATS = 0x5,
};
struct ScreenPlacement
{
	vec2_t scaleVirtualToReal;
	vec2_t scaleVirtualToFull;
	vec2_t scaleRealToVirtual;
	vec2_t virtualViewableMin;
	vec2_t virtualViewableMax;
	vec2_t virtualTweakableMin;
	vec2_t virtualTweakableMax;
	vec2_t realViewportBase;
	vec2_t realViewportSize;
	vec2_t realViewportMid;
	vec2_t realViewableMin;
	vec2_t realViewableMax;
	vec2_t realTweakableMin;
	vec2_t realTweakableMax;
	vec2_t subScreen;
	float hudSplitscreenScale;
};

struct Material
{
	const char* name;
};

struct KerningPairs
{
	unsigned __int16 wFirst;
	unsigned __int16 wSecond;
	int iKernAmount;
};

struct Glyph
{
	unsigned __int16 letter;
	char x0;
	char y0;
	char dx;
	char pixelWidth;
	char pixelHeight;
	float s0;
	float t0;
	float s1;
	float t1;
};

struct Font
{
	const char* fontName;
	int pixelHeight;
	int isScalingAllowed;
	int glyphCount;
	int kerningPairsCount;
	Material* material;
	Material* glowMaterial;
	Glyph* glyphs;
	KerningPairs* kerningPairs;
};
struct Cursor
{
	float x;
	float y;
};
struct UiContext
{
	int localClientNum;
	float bias;
	int realTime;
	int frameTime;
	Cursor cursor;
	int isCursorVisible;
	int paintFull;
	int screenWidth;
	int screenHeight;
	float screenAspect;
	float FPS;
	float blurRadiusOut;
};


enum trType_t {
	TR_STATIONARY,
	TR_INTERPOLATE,
	TR_LINEAR,
	TR_LINEAR_STOP,
	TR_SINE,
	TR_GRAVITY,
	TR_ACCELERATE,
	TR_DECELERATE,
	TR_PHYSICS,
	TR_RAGDOLL
};

struct clientLinkInfo_t
{
	char flags;
	char tagName;
	__int16 parentId;
};

struct trajectory_t
{
	int trType;
	int trTime;
	int trDuration;
	int N0000036C;
	vec3_t trBase;
	char pad_001C[8];
};

struct LerpEntityState
{
	int eFlags;
	int eFlags2;
	struct trajectory_t pos;
	struct trajectory_t apos;
	char pad_0050[32];
};


struct rectDef_s
{
	float x;
	float y;
	float w;
	float h;
	int horzAlign;
	int vertAlign;
};

struct entityState_s
{
	int number;
	int eType;
	char pad_0008[4];
	struct LerpEntityState lerp;
	char pad_007C[8];
	int groundEntityNum;
	int pickup;
	int surfType;
	union
	{
		int brushModel;
		int triggerModel;
		int item;
		int xmodel;
		int primaryLight;
	}index;
	int clientNum;
	int iHeadIcon;
	int iHeadIconTeam;
	int solid;
	unsigned int eventParm;
	int eventSequence;
	int events[4];
	unsigned int eventParms[4];
	struct
	{
		unsigned __int16 weapon;
		unsigned __int16 primaryWeapon;
	}wes;
	int legsAnim;
	int torsoAnim;
	union
	{
		int eventParm2;
		int hintString;
		int fxId;
		int helicopterStage;
	}un1;
	union
	{
		int hintType;
		int vehicleXModel;
		int actorFlags;
		char weaponModel;
	}un2;
	clientLinkInfo_t clientLinkInfo;
	unsigned int partBits[5];
	int clientMask[1];
	unsigned int pad[1];
};


struct Bounds
{
	float midPoint[3];
	float halfSize[3];
};


struct viewClamp {
	vec2_t start; // 0x0
	vec2_t current; // 0x8
	vec2_t goal; // 0x10
};

struct viewClampState {
	viewClamp min; // 0x0
	viewClamp max; // 0x18
	float accelTime; // 0x30
	float decelTime; // 0x34
	float totalTime; // 0x38
	float startTime; // 0x3C
};
struct usercmd_s {
	int serverTime; // 0x0
	int buttons; // 0x4
	int angles[3]; // 0x8
	char forwardmove; // 0x14
	char rightmove; // 0x15
	char undefined2[2]; // 0x16
	float meleeChargeYaw; // 0x18
	char meleeChargeDist; // 0x1C
	char _padding[4]; // 0x1D
	char selectedLoc[2]; // 0x21
	char selectedLocAngle; // 0x3
	int unknown; // 0x24
};
struct playerTeamState_t {
	int location; // 0x0
};

struct clientState_s
{
	int clientIndex;
	team_t team;
	int modelindex;
	int dualWielding;
	int riotShieldNext;
	int attachModelIndex[6];
	int attachTagIndex[6];
	char name[32];
	float maxSprintTimeMultiplier;
	int rank;
	int prestige;
	unsigned int perks[2];
	int diveState;
	int voiceConnectivityBits;
	char clanAbbrev[8];
	unsigned int playerCardIcon;
	unsigned int playerCardTitle;
	unsigned int playerCardNameplate;
};
struct SprintState
{
	int sprintButtonUpRequired; //0x0000
	int sprintDelay; //0x0004
	int lastSprintStart; //0x0008
	int lastSprintEnd; //0x000C
	int sprintStartMaxLength; //0x0010
}; //Size: 0x0014

struct MantleState
{
	float yaw; //0x0000
	int timer; //0x0004
	int transIndex; //0x0008
	int flags; //0x000C
}; //Size: 0x0010

struct PlayerActiveWeaponState
{
	int weapAnim; //0x0000
	int weaponTime; //0x0004
	int weaponDelay; //0x0008
	int weaponRestrictKickTime; //0x000C
	int weaponState; //0x0010
	int weapHandFlags; //0x0014
	unsigned int weaponShotCount; //0x0018
}; //Size: 0x001C

struct GlobalAmmo
{
	int ammoType; //0x0000
	int ammoCount; //0x0004
}; //Size: 0x0008

struct ClipAmmo
{
	int clipIndex; //0x0000
	int ammoCount[2]; //0x0004
}; //Size: 0x000C

struct objective_t
{
	int state; //0x0000
	vec3_t origin; //0x0004
	int entNum; //0x0010
	int teamNum; //0x0014
	int icon; //0x0018
}; //Size: 0x001C

struct WeaponData {
	unsigned int weaponIdx : 8;
	unsigned int weaponVariation : 6;
	unsigned int weaponScopes : 3;
	unsigned int weaponUnderBarrels : 2;
	unsigned int weaponOthers : 7;
	unsigned int scopeVariation : 6;
};

union Weapon {
	WeaponData __s0;
	unsigned int data;
};
enum ActionSlotType
{
	ACTIONSLOTTYPE_DONOTHING = 0x0,
	ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
	ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
	ACTIONSLOTTYPE_NIGHTVISION = 0x3,
	ACTIONSLOTTYPECOUNT = 0x4,
};

struct ActionSlotParam_SpecifyWeapon
{
	unsigned int index;
};

struct ActionSlotParam
{
	ActionSlotParam_SpecifyWeapon specifyWeapon;
};
struct PlayerEquippedWeaponState
{
	bool usedBefore;
	bool dualWielding;
	unsigned __int8 weaponModel;
	bool needsRechamber[2];
};
struct playerState_s
{
	int commandTime; //0x0000
	int pm_type; //0x0004
	int pm_time; //0x0008
	int pm_flags; //0x000C
	int otherFlags; //0x0010
	int linkFlags; //0x0014
	int bobCycle; //0x0018
	vec3_t origin; //0x001C
	vec3_t velocity; //0x0028
	int grenadeTimeLeft; //0x0034
	int throwbackGrenadeOwner; //0x0038
	int throwbackGrenadeTimeLeft; //0x003C
	unsigned int throwbackWeaponIndex; //0x0040
	int remoteEyesEnt; //0x0044
	int remoteEyesTagname; //0x0048
	int remoteControlEnt; //0x004C
	int foliageSoundTime; //0x0050
	int gravity; //0x0054
	float leanf; //0x0058
	int speed; //0x005C
	vec3_t delta_angles; //0x0060
	int groundEntityNum; //0x006C
	vec3_t vLadderVec; //0x0070
	int jumpTime; //0x007C
	float jumpOriginZ; //0x0080
	int legsTimer; //0x0084
	int legsAnim; //0x0088
	int torsoTimer; //0x008C
	int torsoAnim; //0x0090
	int legsAnimDuration; //0x0094
	int torsoAnimDuration; //0x0098
	int damageTimer; //0x009C
	int damageDuration; //0x00A0
	int flinchYawAnim; //0x00A4
	int corpseIndex; //0x00A8
	int movementDir; //0x00AC
	int eFlags; //0x00B0
	int eventSequence; //0x00B4
	int events[4]; //0x00B8
	unsigned int eventParms[4]; //0x00C8
	int oldEventSequence; //0x00D8
	int unpredictableEventSequence; //0x00DC
	int unpredictableEventSequenceOld; //0x00E0
	int unpredictableEvents[4]; //0x00E4
	unsigned int unpredictableEventParms[4]; //0x00F4
	int clientNum; //0x0104
	int viewmodelIndex; //0x0108
	vec3_t viewangles; //0x010C
	int viewHeightTarget; //0x0118
	float viewHeightCurrent; //0x011C
	int viewHeightLerpTime; //0x0120
	int viewHeightLerpTarget; //0x0124
	int viewHeightLerpDown; //0x0128
	vec2_t viewAngleClampBase; //0x012C
	vec2_t viewAngleClampRange; //0x0134
	int damageEvent; //0x013C
	int damageYaw; //0x0140
	int damagePitch; //0x0144
	int damageCount; //0x0148
	int damageFlags; //0x014C
	int stats[4]; //0x0150
	float proneDirection; //0x0160
	float proneDirectionPitch; //0x0164
	float proneTorsoPitch; //0x0168
	int viewlocked; //0x016C
	int viewlocked_entNum; //0x0170
	vec3_t linkAngles; //0x0174
	vec3_t linkWeaponAngles; //0x0180
	int linkWeaponEnt; //0x018C
	int loopSound; //0x0190
	int cursorHint; //0x0194
	int cursorHintString; //0x0198
	int cursorHintEntIndex; //0x019C
	int cursorHintDualWield; //0x01A0
	int iCompassPlayerInfo; //0x01A4
	int radarEnabled; //0x01A8
	int radarBlocked; //0x01AC
	int radarMode; //0x01B0
	int locationSelectionInfo; //0x01B4
	struct SprintState sprintState; //0x01B8
	float holdBreathScale; //0x01CC
	int holdBreathTimer; //0x01D0
	float moveSpeedScaleMultiplier; //0x01D4
	struct MantleState mantleState; //0x01D8
	struct PlayerActiveWeaponState weapState[2]; //0x01E8
	unsigned int weaponsEquipped[15]; //0x0220
	PlayerEquippedWeaponState weapEquippedData[15];
	int offHandIndex; //0x02A8
	int offhandPrimary; //0x02AC
	int offhandSecondary; //0x02B0
	Weapon weapon; //0x02B4
	unsigned int primaryWeaponForAltMode; //0x02B8
	int weapFlags; //0x02BC
	float fWeaponPosFrac; //0x02C0
	float aimSpreadScale; //0x02C4
	int adsDelayTime; //0x02C8
	int spreadOverride; //0x02CC
	int spreadOverrideState; //0x02D0
	int lastWeaponHand; //0x02D4
	struct GlobalAmmo ammoNotInClip[15];
	struct ClipAmmo ammoInClip[15];
	char pad_0404[36];
	unsigned int perks[2]; //0x0428
	unsigned int perkSlots[8]; //0x0430
	ActionSlotType actionSlotType[4]; //0x0450
	ActionSlotParam actionSlotParam[4]; //0x0460
	int weaponHudIconOverrides[6]; //0x0470
	int animScriptedType; //0x0488
	int shellshockIndex; //0x048C
	int shellshockTime; //0x0490
	int shellshockDuration; //0x0494
	float dofNearStart; //0x0498
	float dofNearEnd; //0x049C
	float dofFarStart; //0x04A0
	float dofFarEnd; //0x04A4
	float dofNearBlur; //0x04A8
	float dofFarBlur; //0x04AC
	float dofViewmodelStart; //0x04B0
	float dofViewmodelEnd; //0x04B4
	struct objective_t objective[32]; //0x04B8
	int deltaTime; //0x0838
	int killCamEntity; //0x083C
	int killCamLookAtEntity; //0x0840
	int killCamClientNum; //0x0844
};
struct clientSession_t
{
	int sessionState;
	int forceSpectatorClient;
	int killCamEntity;
	int killCamLookAtEntity;
	int status_icon;
	int archiveTime;
	int score;
	int deaths;
	int kills;
	int assists;
	unsigned short scriptPersId;
	char pad_002A[2];
	int connected;
	usercmd_s cmd;
	usercmd_s oldcmd;
	int localClient;
	int predictItemPickup;
	char newnetname[32];
	int maxHealth;
	int enterTime;
	int location;
	int voteCount;
	int teamVoteCount;
	float moveSpeedScaleMultiplier;
	int viewmodelIndex;
	int noSpectate;
	int teamInfo;
	clientState_s cs;
	int psOffsetTime;
	int hasRadar;
	int isRadarBlocked;
	int radarMode;
	int weaponHudIconOverrides[6];
	unsigned int unusableEntFlags[64];
	vec3_t spectateDefaultPos;
	vec3_t spectateDefaultAngles;
}; //Size: 0x02A0

struct __declspec(align(4)) Turret
{
	bool inuse;
	int flags;
};
struct Vehicle;

typedef struct {
	char _0x0000[2]; //0x0000 
	BYTE Valid; //0x0002
	char _0x0003[21];
	vec3_t mPos; //0x0018 
	vec3_t Angle; //0x0024
	char N0B4867E0[48]; //0x0030
	__int32 Flags; //0x0060  
	char N0B4D8B96[20]; //0x0064 
	vec3_t mPos2; //0x0078 
	char N0B4B45DC[76]; //0x0084 
	__int32 ClientNumber; //0x00D0 
	__int32 EntityType; //0x00D4
	char _0x00D8[4];
	BYTE N0B4B4612; //0x00DC 
	BYTE Zoomed; //0x00DD 
	BYTE Shooting; //0x00DE 
	BYTE PlayerPose; //0x00DF 
	char _0x00E0[20];
	vec3_t mPos3; //0x00F4 
	char _0x0100[88];
	int scavWeaponID; //0x0158 
	char _0x015C[64];
	short WeaponNum; //0x019C 
	char N0B4B4662[50]; //0x01A0 
	__int32 isAlive; //0x01D0
	char _0x01D4[36];
}CEntity, * pCentity_t;; //Size=0x01F8

class CClient
{
public:
	__int32 Valid; //0x0000 
	char _0x0004[4];
	__int32 mNum; //0x0008 
	char mName[32]; //0x000C 
	__int32 mTeam; //0x002C 
	char _0x0030[4];
	__int32 Rank; //0x0034 
	__int32 Prestige; //0x0038 
	char _0x003C[8];
	char clanTag[4];
	char _0x0048[16];
	char szBodyModel[64]; //0x0058 
	char szHeadModel[64]; //0x0098 
	char N0AFB4B1A[64]; //0x00D8 
	char szWeapModel[64]; //0x0118 
	char _0x0158[852];
	__int32 mShooting; //0x04AC 
	char _0x04B0[4];
	__int32 mZooming; //0x04B4 
	char N0AFE4D2B[96]; //0x04B8 
	__int32 Weapon; //0x0518 
	char _0x051C[40];
}; //544

class cRefdef
{
public:
	char _0x0000[8];
	__int32 iWidth; //0x0008 
	__int32 iHeight; //0x000C 
	float fov_X; //0x0010 
	float fov_Y; //0x0014 
	vec3_t EyePos; //0x0018 
	vec3_t ViewAxis[3]; //0x0024 
};

class cg_t
{
public:
	int ServerTime; // 0x00
	char _0x0004[0x18];
	vec3_t Origin; // 0x1C
	char _0x0028[0x88];
	int Stance;
	char _0x00B4[0x50];
	__int32 clientNumber; //0x0104
	char _0x0108[4];
	vec3_t ViewAngle;
	char _0x0118[56];
	__int32 Health; //0x0150 
	char _0x0154[4];
	__int32 Health2; //0x0158 
	char _0x015C[0x168];
	float aimSpreadScale; // 0x2C4
	char _0x02C8[0x36D34];
	playerState_s ps; // 0x36FFC
	char _padding[211720];
	cRefdef refdef; //CG + 6AC28
	char _padding2[573968];
	CClient ClientInfo[18];
};

struct gclient_s
{
	playerState_s ps;
	char _0x00[0x2938];
	clientSession_t sess;
	int flags;
	int spectatorClient;
	int lastCmdTime;
	int buttons;
	int oldbuttons;
	int latched_buttons;
	int buttonsSinceLastFrame;
	vec3_t oldOrigin;
	float fGunPitch;
	float fGunYaw;
	int damage_blood;
	int damage_stun;
	vec3_t damage_from;
	int damage_fromWorld;
	int accurateCount;
	int accuracy_shots;
	int accuracy_hits;
	int inactivityTime;
	int inactivityWarning;
	int lastVoiceTime;
	int switchTeamTime;
	float currentAimSpreadScale;
	vec4_t prevLinkedInvQuat;

	char _3498[0x267];
};

struct EntHandle
{
	unsigned __int16 number;
	unsigned __int16 infoIndex;
};

struct entityShared_t
{
	unsigned __int8 isLinked;
	unsigned __int8 modelType;
	unsigned __int8 svFlags;
	unsigned __int8 isInUse;
	Bounds box;
	int contents;
	Bounds absBox;
	vec3_t currentOrigin;
	vec3_t currentAngles;
	EntHandle ownerNum;
	int eventTime;
};

struct __declspec(align(4)) item_ent_t
{
	int ammoCount;
	int clipAmmoCount[2];
	int index;
	bool dualWieldItem;
};

struct spawner_ent_t
{
	int team;
	int timestamp;
	int index;
};

struct __declspec(align(4)) trigger_ent_t
{
	int threshold;
	int accumulate;
	int timestamp;
	int singleUserEntIndex;
	bool requireLookAt;
};

struct mover_positions_t
{
	float decelTime;
	float speed;
	float midTime;
	float pos1[3];
	float pos2[3];
	float pos3[3];
};

struct mover_slidedata_t
{
	Bounds bounds;
	float velocity[3];
};

union $C1C90AD4BC14CEA439959099C52B89B6
{
	mover_positions_t pos;
	mover_slidedata_t slide;
};

struct mover_ent_t
{
	$C1C90AD4BC14CEA439959099C52B89B6 ___u0;
	mover_positions_t angle;
};

struct corpse_ent_t
{
	int deathAnimStartTime;
};

struct missile_fields_grenade
{
	float wobbleCycle;
	float curve;
};

struct missile_fields_nonGrenade
{
	float curvature[3];
	float targetEntOffset[3];
	float targetPos[3];
	float launchOrigin[3];
	MissileStage stage;
};

union $14DD1F7D2DED82293D032526413216B8
{
	missile_fields_grenade grenade;
	missile_fields_nonGrenade nonGrenade;
};

struct missile_ent_t
{
	float time;
	int timeOfBirth;
	float travelDist;
	float surfaceNormal[3];
	int team;
	int flags;
	int antilagTimeOffset;
	$14DD1F7D2DED82293D032526413216B8 ___u7;
};

struct blend_ent_t
{
	float pos[3];
	float vel[3];
	float viewQuat[4];
	bool changed;
	float accelTime;
	float decelTime;
	float startTime;
	float totalTime;
};

union $D2BF0D160AB9D3B25830A1EBD7297F50
{
	item_ent_t item[2];
	spawner_ent_t spawner;
	trigger_ent_t trigger;
	mover_ent_t mover;
	corpse_ent_t corpse;
	missile_ent_t missile;
	blend_ent_t blend;
};

struct gentity_s
{
	entityState_s s;
	entityShared_t r;
	gclient_s* client;
	struct Turret* turret;
	struct Vehicle* vehicle;
	int physObjId;
	unsigned __int16 model;
	char physicsObject;
	char takedamage;
	char active;
	char handler;
	char team;
	bool freeAfterEvent;
	__int16 padding_short;
	unsigned __int16 classname;
	unsigned __int16 script_classname;
	unsigned __int16 script_linkName;
	unsigned __int16 target;
	unsigned __int16 targetname;
	unsigned int attachIgnoreCollision;
	int spawnflags;
	int flags;
	int eventTime;
	int clipmask;
	int processedFrame;
	EntHandle parent;
	int nextthink;
	int health;
	int maxHealth;
	int damage;
	int count;
	$D2BF0D160AB9D3B25830A1EBD7297F50 ___u31;
	EntHandle missileTargetEnt;
	EntHandle remoteControlledOwner;
	struct tagInfo_s* tagInfo;
	gentity_s* tagChildren;
	unsigned __int16 attachModelNames[19];
	unsigned __int16 attachTagNames[19];
	int useCount;
	gentity_s* nextFree;
	int birthTime;
	int padding[3];
};

struct client_niggas_t
{
	char padding1[0x21294];
	gentity_s* entity;
	char padding2[0x76CE8];
};

struct VariableStackBuffer
{
	const char* pos;
	unsigned __int16 size;
	unsigned __int16 bufLen;
	unsigned __int16 localId;
	unsigned __int8 time;
	char buf[1];
};

/* 9453 */
union VariableUnion
{
	int intValue;
	float floatValue;
	unsigned int stringValue;
	const float* vectorValue;
	const char* codePosValue;
	unsigned int pointerValue;
	VariableStackBuffer* stackValue;
	unsigned int entityOffset;
};

/* 9454 */
struct VariableValue
{
	VariableUnion u;
	int type;
};
enum svscmd_type : __int32
{
	SV_CMD_CAN_IGNORE = 0x0,
	SV_CMD_RELIABLE = 0x1,
};

struct CardMemory
{
	int platform;
};
struct GfxImageStreamData
{
	short Width;
	short Height;
	int pixelSize;
};
struct GfxImage
{
	char pad_0000[52]; //0x00
	_D3DFORMAT Format; //0x34
	char mapType; //0x38
	char semantic; //0x39
	char category; //0x3A
	char _padding_003B; //0x3B
	CardMemory cardMemory; //0x3C
	short width; //0x40
	short height; //0x42
	short depth; //0x44
	char levelCount; //0x46
	bool cached; //0x47
	void* pixels; //0x48
	GfxImageStreamData streams[4]; //0x4C
	char* name; //0x6C
};//Size: 0x70

struct scr_entref_t
{
	unsigned __int16 entnum;
	unsigned __int16 classnum;
};

struct scrVmPub_t
{
	unsigned int* localVars;
	VariableValue* maxstack;
	int function_count;
	void* function_frame;
	VariableValue* top;
	unsigned int inparamcount;
	unsigned int outparamcount;
	unsigned int breakpointOutparamcount;
	bool showError;
	int function_frame_start[32];
	VariableValue stack[2048];
};
struct SessionData
{

};
struct cachedSnapshot_t
{
	int archivedFrame;
	int time;
	int num_entities;
	int first_entity;
	int num_clients;
	int first_client;
	int usesDelta;
};

struct archivedEntityShared_t
{
	int svFlags;
	Bounds absBox;
};

struct archivedEntity_s
{
	entityState_s s;
	archivedEntityShared_t r;
};

enum clientStateStatus_t {
	CS_FREE = 0x0,
	CS_ZOMBIE = 0x1,
	CS_RECONNECTING = 0x2,
	CS_CONNECTED = 0x3,
	CS_CLIENTLOADING = 0x4,
	CS_ACTIVE = 0x5,
};

struct client_t
{
	char padding1[0x21294];
	gentity_s* gentity;
	char padding2[0x76CE8];
};

enum testClientType_t {
	TC_NONE = 0x0,
	TC_TEST_CLIENT = 0x1,
	TC_BOT = 0x2,
	TC_COUNT = 0x3,
};
struct client_s {
	clientStateStatus_t state;
	char unk0[0x20E90];
	int lastClientCommand;
	char lastClientCommandString[1024];
	char unk1[0x4];
	char name[32];
	char unk2[0x10844];
	testClientType_t testClient;
	int serverId;
	char unk3[0x66478];
};

struct serverStatic_t
{
	cachedSnapshot_t cachedSnapshotFrames[512];
	archivedEntity_s* cachedSnapshotEntities;
	entityState_s* snapshotEntities;
	int initialized;
	int time;
	int snapFlagServerBit;
	int clientCount;
	client_s* clients;
	char padding[0x381C];
};
struct CmdArgs
{
	int nesting;
	int localClientNum[8];
	int controllerIndex[8];
	int argc[8];
	const char** argv[8];
};
struct msg_t
{
	int overflowed;
	int readOnly;
	__int8* data;
	__int8* splitData;
	int maxsize;
	int cursize;
	int splitSize;
	int readcount;
	int bit;
	int lastEntityRef;
};
struct svscmd_info_t
{
	char cmd[1024];
	int time;
	int type;
};
struct clientSnapshot_t
{
	playerState_s ps;
	int num_entities;
	int num_clients;
	int first_entity;
	int first_client;
	int messageSent;
	int messageAcked;
	int messageSize;
	int serverTime;
	int timeDelta;
	unsigned __int8 padding[92];
};

struct ucmd_t
{
	char* name;
	void(__cdecl* func)(client_s*);
	int allowFromOldServer;
};

enum clc_ops_e {
	clc_move = 0x0,
	clc_moveNoDelta = 0x1,
	clc_clientCommand = 0x2,
	clc_EOF = 0x3,
};
enum netadrtype_t : __int32
{
	NA_BOT = 0x0,
	NA_BAD = 0x1,
	NA_LOOPBACK = 0x2,
	NA_BROADCAST = 0x3,
	NA_IP = 0x4,
};
struct netadr_t {
	int type;
	char padding[0x97F7C];
};
struct Bots
{
	int clientNum;
};

struct trace_t
{
	float fraction;
	float normal[3];
	int surfaceFlags;
	int contents;
	const char* material;
	TraceHitType hitType;
	unsigned __int16 hitId;
	float fractionForHitType;
	unsigned __int16 modelIndex;
	unsigned __int16 partName;
	unsigned __int16 partGroup;
	bool allsolid;
	bool startsolid;
	bool walkable;
};
struct pml_t
{
	float forward[3];
	float right[3];
	float up[3];
	float frametime;
	int msec;
	int walking;
	int groundPlane;
	int almostGroundPlane;
	trace_t groundTrace;
	float impactSpeed;
	float previous_origin[3];
	float previous_velocity[3];
	unsigned int holdrand;
};


enum PlayerHandIndex : __int32
{
	WEAPON_HAND_RIGHT = 0x0,
	WEAPON_HAND_LEFT = 0x1,
	NUM_WEAPON_HANDS = 0x2,
	WEAPON_HAND_DEFAULT = 0x0,
};





union $C8D87EB0090687D323381DFB7A82089C
{
	float slavePercentage;
	float masterPercentage;
};

struct __declspec(align(4)) XMALOOPREGION
{
	unsigned int LoopStart;
	unsigned int LoopEnd;
	uint8_t LoopSubframeEnd;
	uint8_t LoopSubframeSkip;
};

struct XAUDIOPACKET_ALIGNED
{
	char* pBuffer;
	unsigned int BufferSize;
	unsigned int LoopCount;
	XMALOOPREGION XMALoop[6];
	char* pContext;
};

/* 8586 */
struct XaIwXmaDataInfo
{
	int totalMsec;
};

/* 8587 */
struct XaSeekTable
{
	int size;
	unsigned int* data;
};

union $A914CD29B804E77ACE08D070A31DB5AB
{
	uint8_t NumStreams;
	uint8_t ChannelCount;
};

struct __declspec(align(4)) XAUDIOXMAFORMAT
{
	unsigned int SampleRate;
	uint8_t ChannelCount;
	uint8_t DecodeBufferSize;
};

/* 1254 */
union $31D46FFCBE40996F457570C2842907C6
{
	XAUDIOXMAFORMAT Stream[6];
	unsigned int SampleRate;
};

/* 1255 */
struct XAUDIOSOURCEFORMAT
{
	uint8_t SampleType;
	__declspec(align(4)) $A914CD29B804E77ACE08D070A31DB5AB ___u1;
	$31D46FFCBE40996F457570C2842907C6 ___u2;
};

/* 8588 */
struct XaSound
{
	XAUDIOPACKET_ALIGNED packet;
	XAUDIOSOURCEFORMAT format;
	XaIwXmaDataInfo xaIwXmaDataInfo;
	XaSeekTable seekTable;
};

/* 8589 */
struct LoadedSound
{
	const char* name;
	XaSound sound;
};

/* 8590 */
struct StreamFileNameRaw
{
	const char* dir;
	const char* name;
};

/* 8591 */
struct StreamFileNamePacked
{
	unsigned int offset;
	unsigned int length;
};

/* 8592 */
union StreamFileInfo
{
	StreamFileNameRaw raw;
	StreamFileNamePacked packed;
};

/* 8593 */
struct StreamFileName
{
	unsigned int fileIndex;
	StreamFileInfo info;
};

struct StreamedSound
{
	StreamFileName filename;
};

/* 8595 */
union SoundFileRef
{
	LoadedSound* loadSnd;
	StreamedSound streamSnd;
};

/* 8596 */
struct SoundFile
{
	uint8_t type;
	uint8_t exists;
	SoundFileRef u;
};

/* 8597 */
struct SndCurve
{
	const char* filename;
	uint16_t knotCount;
	float knots[16][2];
};

struct XAUDIOCHANNELMAPENTRY
{
	uint8_t InputChannel;
	uint8_t OutputChannel;
	float Volume;
};

/* 1739 */
struct XAUDIOCHANNELMAP
{
	uint8_t EntryCount;
	XAUDIOCHANNELMAPENTRY* paEntries;
};

struct SpeakerMap
{
	bool isDefault;
	const char* name;
	XAUDIOCHANNELMAP channelMaps[2][2];
};


struct snd_alias_t
{
	const char* aliasName;
	const char* subtitle;
	const char* secondaryAliasName;
	const char* chainAliasName;
	const char* mixerGroup;
	SoundFile* soundFile;
	int sequence;
	float volMin;
	float volMax;
	float pitchMin;
	float pitchMax;
	float distMin;
	float distMax;
	float velocityMin;
	int flags;
	$C8D87EB0090687D323381DFB7A82089C ___u15;
	float probability;
	float lfePercentage;
	float centerPercentage;
	int startDelay;
	SndCurve* volumeFalloffCurve;
	float envelopMin;
	float envelopMax;
	float envelopPercentage;
	SpeakerMap* speakerMap;
};

struct snd_alias_list_t
{
	const char* aliasName;
	snd_alias_t* head;
	int count;
};

enum ammoCounterClipType_t
{
	AMMO_COUNTER_CLIP_NONE,
	AMMO_COUNTER_CLIP_MAGAZINE,
	AMMO_COUNTER_CLIP_SHORTMAGAZINE,
	AMMO_COUNTER_CLIP_SHOTGUN,
	AMMO_COUNTER_CLIP_ROCKET,
	AMMO_COUNTER_CLIP_BELTFED,
	AMMO_COUNTER_CLIP_ALTWEAPON,
	AMMO_COUNTER_CLIP_COUNT
};



enum weapInventoryType_t
{
	WEAPINVENTORY_PRIMARY = 0x0,
	WEAPINVENTORY_OFFHAND = 0x1,
	WEAPINVENTORY_ITEM = 0x2,
	WEAPINVENTORY_ALTMODE = 0x3,
	WEAPINVENTORY_EXCLUSIVE = 0x4,
	WEAPINVENTORY_SCAVENGER = 0x5,
	WEAPINVENTORYCOUNT = 0x6,
};

enum weapFireType_t
{
	WEAPON_FIRETYPE_FULLAUTO = 0x0,
	WEAPON_FIRETYPE_SINGLESHOT = 0x1,
	WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
	WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
	WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
	WEAPON_FIRETYPE_DOUBLEBARREL = 0x5,
	WEAPON_FIRETYPECOUNT = 0x6,
	WEAPON_FIRETYPE_BURSTFIRE_FIRST = 0x2,
	WEAPON_FIRETYPE_BURSTFIRE_LAST = 0x4,
};

enum OffhandClass
{
	OFFHAND_CLASS_NONE = 0x0,
	OFFHAND_CLASS_FRAG_GRENADE = 0x1,
	OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
	OFFHAND_CLASS_FLASH_GRENADE = 0x3,
	OFFHAND_CLASS_THROWINGKNIFE = 0x4,
	OFFHAND_CLASS_OTHER = 0x5,
	OFFHAND_CLASS_COUNT = 0x6,
};

enum weapStance_t
{
	WEAPSTANCE_STAND = 0x0,
	WEAPSTANCE_DUCK = 0x1,
	WEAPSTANCE_PRONE = 0x2,
	WEAPSTANCE_NUM = 0x3,
};



struct XModel
{
	char* name;
	char numBones;
	char numRootBones;
	char numsurfs;
	char undefined;
	char unknownData1[0x1C];
	unsigned short* boneNames;				//count = numBones
	unsigned char* parentList;				//size = numBones - numRootBones
	unsigned short* quats;					//size = (numBones - numRootBones) << 3
	float* trans;							//size = (((numBones - numRootBones) << 1) + (numBones - numRootBones)) << 2
	unsigned char* partClassification;		//size = numBones
};

struct handModelTest
{
	char* test;

};

struct weapModelTest
{
	char** weaponCamo1; //0x0000
	char** weaponCamo2; //0x0004
	char pad_0008[56]; //0x0008
	char viewmodelName[16]; //0x0040
};

struct textureListDirty
{
	char pad_0000[95];
	char weaponTextureName[16];
}; //Size: 0x006F

struct weaponVarientList
{
	int baseWeapon; //0x0000
	int weaponCamo1; //0x0004
}; //Size: 0x0008
enum WeapOverlayInteface_t
{
	WEAPOVERLAYINTERFACE_NONE = 0x0,
	WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
	WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
	WEAPOVERLAYINTERFACECOUNT = 0x3,
};

enum weapProjExposion_t
{
	WEAPPROJEXP_GRENADE = 0x0,
	WEAPPROJEXP_ROCKET = 0x1,
	WEAPPROJEXP_FLASHBANG = 0x2,
	WEAPPROJEXP_NONE = 0x3,
	WEAPPROJEXP_DUD = 0x4,
	WEAPPROJEXP_SMOKE = 0x5,
	WEAPPROJEXP_HEAVY = 0x6,
	WEAPPROJEXP_NUM = 0x7,
};

enum WeapStickinessType
{
	WEAPSTICKINESS_NONE = 0x0,
	WEAPSTICKINESS_ALL = 0x1,
	WEAPSTICKINESS_ALL_ORIENT = 0x2,
	WEAPSTICKINESS_GROUND = 0x3,
	WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
	WEAPSTICKINESS_KNIFE = 0x5,
	WEAPSTICKINESS_COUNT = 0x6,
};

enum guidedMissileType_t
{
	MISSILE_GUIDANCE_NONE = 0x0,
	MISSILE_GUIDANCE_SIDEWINDER = 0x1,
	MISSILE_GUIDANCE_HELLFIRE = 0x2,
	MISSILE_GUIDANCE_JAVELIN = 0x3,
	MISSILE_GUIDANCE_COUNT = 0x4,
};

enum weapOverlayReticle_t
{
	WEAPOVERLAYRETICLE_NONE = 0x0,
	WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
	WEAPOVERLAYRETICLE_NUM = 0x2,
};
enum activeReticleType_t
{
	VEH_ACTIVE_RETICLE_NONE = 0x0,
	VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
	VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
	VEH_ACTIVE_RETICLE_COUNT = 0x3,
};

struct FxEffectDef
{
	const char* name;
	int flags;
	int totalSize;
	int msecLoopingLife;
	int elemDefCountLooping;
	int elemDefCountOneShot;
	int elemDefCountEmission;
	int elemDefs;
};


enum PenetrateType : __int32
{
	PENETRATE_TYPE_NONE = 0x0,
	PENETRATE_TYPE_SMALL = 0x1,
	PENETRATE_TYPE_MEDIUM = 0x2,
	PENETRATE_TYPE_LARGE = 0x3,
	PENETRATE_TYPE_COUNT = 0x4,
};


enum weapClass_t
{
	WEAPCLASS_RIFLE,
	WEAPCLASS_SNIPER,
	WEAPCLASS_MG,
	WEAPCLASS_SMG,
	WEAPCLASS_SPREAD,
	WEAPCLASS_PISTOL,
	WEAPCLASS_GRENADE,
	WEAPCLASS_ROCKETLAUNCHER,
	WEAPCLASS_TURRET,
	WEAPCLASS_THROWINGKNIFE,
	WEAPONCLASS_NON_PLAYER,
	WEAPCLASS_ITEM
};

enum weaponIconRatioType_t : __int32
{
	WEAPON_ICON_RATIO_1TO1 = 0x0,
	WEAPON_ICON_RATIO_2TO1 = 0x1,
	WEAPON_ICON_RATIO_4TO1 = 0x2,
	WEAPON_ICON_RATIO_COUNT = 0x3,
};
enum weapType_t : __int32
{
	WEAPTYPE_BULLET = 0x0,
	WEAPTYPE_GRENADE = 0x1,
	WEAPTYPE_PROJECTILE = 0x2,
	WEAPTYPE_RIOTSHIELD = 0x3,
	WEAPTYPE_NUM = 0x4,
};
union snd_alias_list_name
{
	char* name;
	snd_alias_list_t* asset;
};

enum playerAnimType_t : int
{
	none = 0x0,
	other = 0x1,
	pistol = 0x2,
	smg = 0x3,
	autorifle = 0x4,
	mg = 0x5,
	sniper = 0x6,
	rocketlauncher = 0x7,
	plosive = 0x8,
	grenade = 0x9,
	turret = 0xA,
	c4 = 0xB,
	m203 = 0xC,
	hold = 0xD,
	briefcase = 0xE,
	riotshield = 0xF,
	laptop = 0x10,
	throwingknife = 0x11
};

struct Tracer
{
	const char* name;
	Material* material;
	unsigned int drawInterval;
	float speed;
	float beamLength;
	float beamWidth;
	float screwRadius;
	float screwDist;
	float colors[5][4];
};

struct weaponDef
{
	char* szInternalName;
	XModel** gunXModel;
	XModel* handXModel;
	const char** szXAnimsR;
	const char** szXAnimsL;
	char* szModeName;
	int noteTrackSoundMap[2];
	int noteTrackRumbleMap[2];
	playerAnimType_t playerAnimType;
	weapType_t weaponType;
	weapClass_t weaponClass;
	PenetrateType penetrateType;
	weapInventoryType_t inventoryType;
	weapFireType_t fireType;
	OffhandClass offhandClass;
	weapStance_t stance;
	void* viewFlashEffect;
	void* worldFlashEffect;
	snd_alias_list_name pickUpSound;
	snd_alias_list_name pickUpSoundPlayer;
	snd_alias_list_name ammoPickupSound;
	snd_alias_list_name ammoPickupSoundPlayer;
	snd_alias_list_name projectileSound;
	snd_alias_list_name pullbackSound;
	snd_alias_list_name pullbackSoundPlayer;
	snd_alias_list_name fireSound;
	snd_alias_list_name fireSoundPlayer;
	snd_alias_list_name fireSoundPlayerAkimbo;
	snd_alias_list_name loopFireSound;
	snd_alias_list_name loopFireSoundPlayer;
	snd_alias_list_name stopFireSound;
	snd_alias_list_name stopFireSoundPlayer;
	snd_alias_list_name lastShotSound;
	snd_alias_list_name lastShotSoundPlayer;
	snd_alias_list_name emptyFireSound;
	snd_alias_list_name emptyFireSoundPlayer;
	snd_alias_list_name meleeSwipeSound;
	snd_alias_list_name meleeSwipeSoundPlayer;
	snd_alias_list_name meleeHitSound;
	snd_alias_list_name meleeMissSound;
	snd_alias_list_name rechamberSound;
	snd_alias_list_name rechamberSoundPlayer;
	snd_alias_list_name reloadSound;
	snd_alias_list_name reloadSoundPlayer;
	snd_alias_list_name reloadEmptySound;
	snd_alias_list_name reloadEmptySoundPlayer;
	snd_alias_list_name reloadStartSound;
	snd_alias_list_name reloadStartSoundPlayer;
	snd_alias_list_name reloadEndSound;
	snd_alias_list_name reloadEndSoundPlayer;
	snd_alias_list_name detonateSound;
	snd_alias_list_name detonateSoundPlayer;
	snd_alias_list_name nightVisionWearSound;
	snd_alias_list_name nightVisionWearSoundPlayer;
	snd_alias_list_name nightVisionRemoveSound;
	snd_alias_list_name nightVisionRemoveSoundPlayer;
	snd_alias_list_name altSwitchSound;
	snd_alias_list_name altSwitchSoundPlayer;
	snd_alias_list_name raiseSound;
	snd_alias_list_name raiseSoundPlayer;
	snd_alias_list_name firstRaiseSound;
	snd_alias_list_name firstRaiseSoundPlayer;
	snd_alias_list_name putawaySound;
	snd_alias_list_name putawaySoundPlayer;
	snd_alias_list_name scanSound;
	snd_alias_list_name* bounceSound;
	void* viewShellEjectEffect;
	void* worldShellEjectEffect;
	void* viewLastShotEjectEffect;
	void* worldLastShotEjectEffect;
	Material* reticleCenter;
	Material* reticleSide;
	int iReticleCenterSize;
	int iReticleSideSize;
	int iReticleMinOfs;
	activeReticleType_t activeReticleType;
	float vStandMove[3];
	float vStandRot[3];
	float vStrafeMove[3];
	float vStrafeRot[3];
	float vDuckedOfs[3];
	float vDuckedMove[3];
	float vDuckedRot[3];
	float vProneOfs[3];
	float vProneMove[3];
	float vProneRot[3];
	float fPosMoveRate;
	float fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	float fPosRotRate;
	float fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	XModel** worldModel;
	XModel* worldClipModel;
	XModel* rocketModel;
	XModel* knifeModel;
	XModel* worldKnifeModel;
	Material* hudIcon;
	weaponIconRatioType_t hudIconRatio;
	Material* pickupIcon;
	weaponIconRatioType_t pickupIconRatio;
	Material* ammoCounterIcon;
	weaponIconRatioType_t ammoCounterIconRatio;
	ammoCounterClipType_t ammoCounterClip;
	int iStartAmmo;
	const char* szAmmoName;
	int iAmmoIndex;
	const char* szClipName;
	int iClipIndex;
	int iMaxAmmo;
	int shotCount;
	const char* szSharedAmmoCapName;
	int iSharedAmmoCapIndex;
	int iSharedAmmoCap;
	int damage;
	int playerDamage;
	int iMeleeDamage;
	int iDamageType;
	int iFireDelay;
	int iMeleeDelay;
	int meleeChargeDelay;
	int iDetonateDelay;
	int iRechamberTime;
	int iRechamberOneHanded;
	int iRechamberBoltTime;
	int iHoldFireTime;
	int iDetonateTime;
	int iMeleeTime;
	int meleeChargeTime;
	int iReloadTime;
	int reloadShowRocketTime;
	int iReloadEmptyTime;
	int iReloadAddTime;
	int iReloadStartTime;
	int iReloadStartAddTime;
	int iReloadEndTime;
	int iDropTime;
	int iRaiseTime;
	int iAltDropTime;
	int quickDropTime;
	int quickRaiseTime;
	int iFirstRaiseTime;
	int iEmptyRaiseTime;
	int iEmptyDropTime;
	int sprintInTime;
	int sprintLoopTime;
	int sprintOutTime;
	int stunnedTimeBegin;
	int stunnedTimeLoop;
	int stunnedTimeEnd;
	int nightVisionWearTime;
	int nightVisionWearTimeFadeOutEnd;
	int nightVisionWearTimePowerUp;
	int nightVisionRemoveTime;
	int nightVisionRemoveTimePowerDown;
	int nightVisionRemoveTimeFadeInStart;
	int fuseTime;
	int aifuseTime;
	float autoAimRange;
	float aimAssistRange;
	float aimAssistRangeAds;
	float aimPadding;
	float enemyCrosshairRange;
	float moveSpeedScale;
	float adsMoveSpeedScale;
	float sprintDurationScale;
	float adsZoomInFrac;
	float adsZoomOutFrac;
	Material* AdsOverlayShader;
	Material* AdsOverlayShaderLowRes;
	Material* AdsOverlayShaderEMP;
	Material* AdsOverlayShaderEMPLowRes;
	weapOverlayReticle_t adsOverlayReticle;
	WeapOverlayInteface_t adsOverlayInterface;
	float adsOverlayWidth;
	float adsOverlayHeight;
	float adsOverlayWidthSplitscreen;
	float adsOverlayHeightSplitscreen;
	float fAdsBobFactor;
	float fAdsViewBobMult;
	float fHipSpreadStandMin;
	float fHipSpreadDuckedMin;
	float fHipSpreadProneMin;
	float hipSpreadStandMax;
	float hipSpreadDuckedMax;
	float hipSpreadProneMax;
	float fHipSpreadDecayRate;
	float fHipSpreadFireAdd;
	float fHipSpreadTurnAdd;
	float fHipSpreadMoveAdd;
	float fHipSpreadDuckedDecay;
	float fHipSpreadProneDecay;
	float fHipReticleSidePos;
	float fAdsIdleAmount;
	float fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	float fGunMaxPitch;
	float fGunMaxYaw;
	float swayMaxAngle;
	float swayLerpSpeed;
	float swayPitchScale;
	float swayYawScale;
	float swayHorizScale;
	float swayVertScale;
	float swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	float adsSwayPitchScale;
	float adsSwayYawScale;
	float adsSwayHorizScale;
	float adsSwayVertScale;
	float adsViewErrorMin;
	float adsViewErrorMax;
	void* collisions;
	float dualWieldViewModelOffset;
	weaponIconRatioType_t killIconRatio;
	int iReloadAmmoAdd;
	int iReloadStartAdd;
	int iDropAmmoMin;
	int ammoDropClipPercentMin;
	int ammoDropClipPercentMax;
	int iExplosionRadius;
	int iExplosionRadiusMin;
	int iExplosionInnerDamage;
	int iExplosionOuterDamage;
	float damageConeAngle;
	float bulletExplDmgMult;
	float bulletExplRadiusMult;
	int iProjectileSpeed;
	int iProjectileSpeedUp;
	int iProjectileSpeedForward;
	int iProjectileActivateDist;
	float projLifetime;
	float timeToAccelerate;
	float projectileCurvature;
	XModel* projectileModel;
	weapProjExposion_t projExplosiveType;
	void* projExplosionEffect;
	void* projDudEffect;
	snd_alias_list_name projExplosionSound;
	snd_alias_list_name projDudSound;
	WeapStickinessType stickiness;
	float lowAmmoWarningThreshold;
	float ricochetChance;
	float* parallelBounce;
	float* perpendicularBounce;
	void* projTrailEffect;
	void* projBeaconEffect;
	float vProjectileColor[3];
	guidedMissileType_t guidedMissileType;
	float maxSteeringAccel;
	float projIgnitionDelay;
	void* projIgnitionEffect;
	snd_alias_list_name projIgnitionSound;
	float fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int adsGunKickReducedKickBullets;
	float adsGunKickReducedKickPercent;
	float fAdsGunKickPitchMin;
	float fAdsGunKickPitchMax;
	float fAdsGunKickYawMin;
	float fAdsGunKickYawMax;
	float fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	float fAdsGunKickStaticDecay;
	float fAdsViewKickPitchMin;
	float fAdsViewKickPitchMax;
	float fAdsViewKickYawMin;
	float fAdsViewKickYawMax;
	float fAdsViewScatterMin;
	float fAdsViewScatterMax;
	float fAdsSpread;
	int hipGunKickReducedKickBullets;
	float hipGunKickReducedKickPercent;
	float fHipGunKickPitchMin;
	float fHipGunKickPitchMax;
	float fHipGunKickYawMin;
	float fHipGunKickYawMax;
	float fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	float fHipGunKickStaticDecay;
	float fHipViewKickPitchMin;
	float fHipViewKickPitchMax;
	float fHipViewKickYawMin;
	float fHipViewKickYawMax;
	float fHipViewScatterMin;
	float fHipViewScatterMax;
	float fightDist;
	float maxDist;
	const char* accuracyGraphName[2];
	vec2_t* accuracyGraphKnots;
	vec2_t* originalAccuracyGraphKnots;
	short accuracyGraphKnotCount;
	short originalAccuracyGraphKnotCount;
	int iPositionReloadTransTime;
	float leftArc;
	float rightArc;
	float topArc;
	float bottomArc;
	float accuracy;
	float aiSpread;
	float playerSpread;
	float minVertTurnSpeed;
	float minHorTurnSpeed;
	float maxVertTurnSpeed;
	float maxHorTurnSpeed;
	float pitchConvergenceTime;
	float yawConvergenceTime;
	float suppressTime;
	float maxRange;
	float fAnimHorRotateInc;
	float fPlayerPositionDist;
	const char* szUseHintString;
	const char* dropHintString;
	int iUseHintStringIndex;
	int dropHintStringIndex;
	float horizViewJitter;
	float vertViewJitter;
	float scanSpeed;
	float scanAccel;
	int scanPauseTime;
	const char* szScript;
	float fOOPosAnimLength[2];
	int minDamage;
	int minPlayerDamage;
	float maxDamageRange;
	float minDamageRange;
	float destabilizationRateTime;
	float destabilizationCurvatureMax;
	int destabilizeDistance;
	float* locationDamageMultipliers;
	const char* fireRumble;
	const char* meleeImpactRumble;
	Tracer* tracer;
	int turretScopeZoomRate;
	int turretScopeZoomMin;
	int turretScopeZoomMax;
	int turretOverheatUpRate;
	int turretOverheatDownRate;
	int turretOverheatPenalty;
	snd_alias_list_name turretOverheatSound;
	void* turretOverheatEffect;
	char* turretBarrelSpinRumble;
	int turretBarrelSpinUpTime;
	int turretBarrelSpinDownTime;
	int turretBarrelSpinSpeed;
	snd_alias_list_name turretBarrelSpinMaxSnd;
	snd_alias_list_name turretBarrelSpinUpSnds[4];
	snd_alias_list_name turretBarrelSpinDownSnds[4];
	snd_alias_list_name missileConeSoundAlias;
	snd_alias_list_name missileConeSoundAliasAtBase;
	float missileConeSoundRadiusAtTop;
	float missileConeSoundRadiusAtBase;
	float missileConeSoundHeight;
	float missileConeSoundOriginOffset;
	float missileConeSoundVolumescaleAtCore;
	float missileConeSoundVolumescaleAtEdge;
	float missileConeSoundVolumescaleCoreSize;
	float missileConeSoundPitchAtTop;
	float missileConeSoundPitchAtBottom;
	float missileConeSoundPitchTopSize;
	float missileConeSoundPitchBottomSize;
	float missileConeSoundCrossfadeTopSize;
	float missileConeSoundCrossfadeBottomSize;
	bool shareAmmo;
	bool lockonSupported;
	bool requireLockonToFire;
	bool bigExplosion;
	bool noAdsWhenMagEmpty;
	bool avoidDropCleanup;
	bool inheritsPerks;
	bool crosshairColorChange;
	bool rifleBullet;
	bool armorPiercing;
	bool boltAction;
	bool aimDownSight;
	bool rechamberWhileAds;
	bool bBulletExplosiveDamage;
	bool cookOffHold;
	bool clipOnly;
	bool noAmmoPickup;
	bool adsFire;
	bool cancelAutoHolsterWhenEmpty;
	bool disableSwitchToWhenEmpty;
	bool suppressAmmoReserveDisplay;
	bool laserSightDuringNightvision;
	bool markableViewmodel;
	bool noDualWield;
	bool flipKillIcon;
	bool noPartialReload;
	bool segmentedReload;
	bool blocksProne;
	bool silenced;
	bool isRollingGrenade;
	bool projExplosionEffectForceNormalUp;
	bool projImpactExplode;
	bool stickToPlayers;
	bool hasDetonator;
	bool disableFiring;
	bool timedDetonation;
	bool rotate;
	bool holdButtonToThrow;
	bool freezeMovementWhenFiring;
	bool thermalScope;
	bool altModeSameWeapon;
	bool turretBarrelSpinEnabled;
	bool missileConeSoundEnabled;
	bool missileConeSoundPitchshiftEnabled;
	bool missileConeSoundCrossfadeEnabled;
	bool offhandHoldIsCancelable;
}; //Size: 0x050C


enum ImpactType
{
	IMPACT_TYPE_NONE = 0,
	IMPACT_TYPE_BULLET_SMALL = 1,
	IMPACT_TYPE_BULLET_LARGE = 2,
	IMPACT_TYPE_BULLET_AP = 3,
	IMPACT_TYPE_SHOTGUN_FMJ = 4,
	IMPACT_TYPE_SHOTGUN = 5,
	IMPACT_TYPE_GRENADE_BOUNCE = 7,
	IMPACT_TYPE_GRENADE_EXPLODE = 8,
	IMPACT_TYPE_ROCKET_EXPLODE = 9,
	IMPACT_TYPE_PROJECTILE_DUD = 10,
	IMPACT_TYPE_MAX
};

struct WeaponCompleteDef
{
	const char* szInternalName;
	weaponDef* weapDef;
	const char* szDisplayName;
	unsigned short* hideTags;
	const char** szXAnims;
	float fAdsZoomFov;
	int iAdsTransInTime;
	int iAdsTransOutTime;
	int iClipSize;
	ImpactType impactType;
	int iFireTime;
	weaponIconRatioType_t dpadIconRatio;
	float penetrateMultiplier;
	float fAdsViewKickCenterSpeed;
	float fHipViewKickCenterSpeed;
	const char* szAltWeaponName;
	unsigned int altWeaponIndex;
	int iAltRaiseTime;
	Material* killIcon;
	Material* dpadIcon;
	int fireAnimLength;
	int iFirstRaiseTime;
	int ammoDropStockMax;
	float adsDofStart;
	float adsDofEnd;
	unsigned __int16 accuracyGraphKnotCount[2];
	float(*accuracyGraphKnots[2])[2];
	bool motionTracker;
	bool enhanced;
	bool dpadIconShowsAmmo;
}; //Size: 0x0140

enum perksEnum : __int32
{
	PERK_JAMRADAR = 0x0,
	PERK_ACCURACY = 0x1,
	PERK_FASTRELOAD = 0x2,
	PERK_RATEOFFIRE = 0x3,
	PERK_EXTRABREATH = 0x4,
	PERK_EXTRABP = 0x5,
	PERK_GRENADEDEATH = 0x6,
	PERK_PISTOLDEATH = 0x7,
	PERK_QUIETMOVE = 0x8,
	PERK_PARABOLIC = 0x9,
	PERK_LONGERSPRINT = 0xA,
	PERK_DETECTEXPLOSIVE = 0xB,
	PERK_EXPOSEENEMY = 0xC,
	PERK_BULLETDMG = 0xD,
	PERK_EXTRAAMMO = 0xE,
	PERK_TWOPRIMARIES = 0xF,
	PERK_ARMORVEST = 0x10,
	PERK_FRAGGRENADE = 0x11,
	PERK_SPECIALGRENADE = 0x12,
	PERK_FASTMANTLE = 0x13,
	PERK_JUMPDIVE = 0x14,
	PERK_EXPLOSIVEBULLETS = 0x15,
	PERK_SCAVENGER = 0x16,
	PERK_EXTENDEDMAGS = 0x17,
	PERK_LIGHTWEIGHT = 0x18,
	PERK_MARATHON = 0x19,
	PERK_QUICKDRAW = 0x1A,
	PERK_COLDBLOODED = 0x1B,
	PERK_HEARTBREAKER = 0x1C,
	PERK_SELECTIVEHEARING = 0x1D,
	PERK_FASTSNIPE = 0x1E,
	PERK_IMPROVEDEXTRABREATH = 0x1F,
	PERK_SPYGAME = 0x20,
	PERK_AUTOMANTLE = 0x21,
	PERK_FASTSPRINTRECOVERY = 0x22,
	PERK_EXTENDEDMELEE = 0x23,
	PERK_COUNT = 0x24,
	PERK_UNKNOWN = 0x24,
};

struct StringTableEntry
{
	char* value;
	int hash;
};

struct StringTable
{
	char* name;
	int columnCount;
	int rowCount;
	StringTableEntry* values;
};

enum MigrationClientState : __int32
{
	CSTATE_INACTIVE = 0x0,
	CSTATE_WAITFORRATING = 0x1,
	CSTATE_MIGRATING = 0x2,
};

struct MigrationClient
{
	MigrationClientState state;
	int attempts;
	int msgTimeout;
	int rating;
};

struct windowDef_t
{
	const char* name;
	rectDef_s rect;
	rectDef_s rectClient;
	const char* group;
	int style;
	int border;
	int ownerDraw;
	int ownerDrawFlags;
	float borderSize;
	int staticFlags;
	int dynamicFlags[4];
	int nextTime;
	float foreColor[4];
	float backColor[4];
	float borderColor[4];
	float outlineColor[4];
	float disableColor[4];
	Material* background;
};

struct menuDef_t
{
	windowDef_t window;
	const char* font;
	int fullScreen;
	int itemCount;
	int fontIndex;
	int cursorItem[4];
	int fadeCycle;
	float fadeClamp;
	float fadeAmount;
	float fadeInAmount;
	float blurRadius;
	void* onOpen;
	void* onCloseRequest;
	void* onClose;
	void* onESC;
	void* onKey;
	void* visibleExp;
	const char* allowedBinding;
	const char* soundName;
	int imageTrack;
	float focusColor[4];
};

enum Menus 
{
	main,
	matchmaking,
	gamee,
	trickshot,
	customization,
	players
};

struct hudelem_color_t
{
	byte r;
	byte g;
	byte b;
	byte a;
};

enum hetype_t 
{
	HE_TYPE_FREE,
	HE_TYPE_TEXT,
	HE_TYPE_VALUE,
	HE_TYPE_PLAYERNAME,
	HE_TYPE_MATERIAL,
	HE_TYPE_TIMER_DOWN,
	HE_TYPE_TIMER_UP,
	HE_TYPE_TIMER_STATIC,
	HE_TYPE_TENTHS_TIMER_DOWN,
	HE_TYPE_TENTHS_TIMER_UP,
	HE_TYPE_TENTHS_TIMER_STATIC,
	HE_TYPE_CLOCK_DOWN,
	HE_TYPE_CLOCK_UP,
	HE_TYPE_WAYPOINT,
	HE_TYPE_MAPNAME,
	HE_TYPE_GAMETYPE
};

struct hudelem_s
{
	int type;                     // 0x00-0x04
	float y;                      // 0x04-0x08
	float x;                      // 0x08-0x0C
	float z;                      // 0x0C-0x10
	int targetEntNum;             // 0x10-0x14
	float fontScale;              // 0x14-0x18
	float fromFontScale;          // 0x18-0x1C
	int fontScaleStartTime;       // 0x1C-0x20
	int fontScaleTime;            // 0x20-0x24
	int label;                    // 0x24-0x28
	int font;                     // 0x28-0x2C
	int alignOrg;                 // 0x2C-0x30
	int alignScreen;              // 0x30-0x34
	hudelem_color_t color;        // 0x34-0x38
	hudelem_color_t fromColor;    // 0x38-0x3C
	int fadeStartTime;            // 0x3C-0x40
	int fadeTime;                 // 0x40-0x44
	int height;                   // 0x44-0x48
	int width;                    // 0x48-0x4C
	int materialIndex;            // 0x4C-0x50
	int fromHeight;               // 0x50-0x54
	int fromWidth;                // 0x54-0x58
	int scaleStartTime;           // 0x58-0x5C
	int scaleTime;                // 0x5C-0x60
	float fromY;                  // 0x60-0x64
	float fromX;                  // 0x64-0x68
	int fromAlignOrg;             // 0x68-0x6C
	int fromAlignScreen;          // 0x6C-0x70
	int moveStartTime;            // 0x70-0x74
	int moveTime;                 // 0x74-0x78
	float value;                  // 0x78-0x7C
	int time;                     // 0x7C-0x80
	int duration;                 // 0x80-0x84
	int text;                     // 0x84-0x88
	float sort;                   // 0x88-0x8C
	hudelem_color_t glowColor;    // 0x8C-0x90
	int fxBirthTime;              // 0x90-0x94
	int fxLetterTime;             // 0x94-0x98
	int fxDecayStartTime;         // 0x98-0x9C
	int fxDecayDuration;          // 0x9C-0xA0
	int soundID;                  // 0xA0-0xA4
	int flags;                    // 0xA4-0xA8
};

struct game_hudelem_s
{
	hudelem_s elem;               // 0x00-0xA8
	int clientNum;                // 0xA8-0xAC
	int teamNum;                  // 0xAC-0xB0
	int archived;                 // 0xB0-0xB4
};

struct cgs_t
{
	char pad_0000[32]; //0x0000
	char gametype[32]; //0x0020
	char szHostName[256]; //0x0040
	char pad_0140[4]; //0x0140
	int32_t maxclients; //0x0144
	char pad_0148[84]; //0x0148
};

struct pmove_t
{
	playerState_s* ps;
	usercmd_s cmd;
};

struct cmd_function_s
{
	cmd_function_s* next;
	const char* name;
	const char* autoCompleteDir;
	const char* autoCompleteExt;
	void(__cdecl* function)();
};

enum DvarSetSource : __int32
{
	DVAR_SOURCE_INTERNAL = 0x0,
	DVAR_SOURCE_EXTERNAL = 0x1,
	DVAR_SOURCE_SCRIPT = 0x2,
	DVAR_SOURCE_DEVGUI = 0x3,
};

union DvarLimits
{
	struct enumeration
	{
		int stringCount;
		char** strings;
	};

	struct integer
	{
		int min;
		int max;
	};

	struct decimal
	{
		float min;
		float max;
	};
};

union DvarValue
{
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	float value;
	float vec[4];
	char* string;
	char color[4];
};

struct dvar_s
{
	char* dvarName; //0x0000
	uint16_t flags; //0x0004
	uint8_t type; //0x0006
	bool modified; //0x0007
	DvarValue current; //0x0008
	DvarValue latched; //0x000C
	DvarValue reset; //0x0010
	DvarLimits domain;
	dvar_s* next;
};

struct dvar_t
{
	const char* name;
	const char* description;
	int hash;
	unsigned int flags;
	int type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	DvarLimits domain;
	dvar_t* hashNext;
};

struct XAnimNotifyInfo
{
	short name;
	float time;
};

union XAnimIndices
{
	char* _1;
	unsigned __int16* _2;
	void* data;
};

union XAnimDynamicFrames
{
	char(*_1)[3];
	unsigned __int16(*_2)[3];
};

union XAnimDynamicIndices
{
	char _1[1];
	unsigned __int16 _2[1];
};

struct XAnimPartTransFrames
{
	float mins[3];
	float size[3];
	XAnimDynamicFrames frames;
	XAnimDynamicIndices indices;
};

union XAnimPartTransData
{
	XAnimPartTransFrames frames;
	float frame0[3];
};

struct XAnimPartTrans
{
	unsigned __int16 size;
	char smallTrans;
	__declspec(align(2)) XAnimPartTransData u;
};

struct XAnimDeltaPartQuatDataFrames2
{
	__int16* frames;
	char indices[1];
};

union XAnimDeltaPartQuatData2
{
	XAnimDeltaPartQuatDataFrames2 frames;
	__int16 frame0[2];
};

struct XAnimDeltaPartQuat2
{
	unsigned __int16 size;
	XAnimDeltaPartQuatData2 u;
};

struct XAnimDeltaPartQuatDataFrames
{
	__int16(*frames)[2];
	XAnimDynamicIndices indices;
};

union XAnimDeltaPartQuatData
{
	XAnimDeltaPartQuatDataFrames frames;
	__int16 frame0[2];
};

struct XAnimDeltaPartQuat
{
	unsigned __int16 size;
	__declspec(align(4)) XAnimDeltaPartQuatData u;
};

struct XAnimDeltaPart
{
	XAnimPartTrans* trans;
	XAnimDeltaPartQuat2* quat2;
	XAnimDeltaPartQuat* quat;
};

struct XAnimParts
{
	char* name; // 0
	unsigned short dataByteCount; // 4
	unsigned short dataShortCount; // 6
	unsigned short dataIntCount; // 8
	unsigned short randomDataByteCount; // 10 - 0xA
	unsigned short randomDataIntCount; // 12 - 0xC
	unsigned short framecount; // 14 - 0xE
	char flags; // 16
	unsigned char boneCount[10]; // 17
	char notifyCount; // 27
	char assetType; // 30
	bool isDefault; // 31
	unsigned int randomDataShortCount; // 32 - 0x20
	unsigned int indexcount; // 36 - 0x24
	float framerate; // 40 - 0x28
	float frequency; // 44 - 0x2C
	unsigned short* tagnames; // 48 - 0x30
	char* dataByte; // 52 - 0x34
	short* dataShort; // 56 - 0x38
	int* dataInt; // 60 - 0x3C
	short* randomDataShort; // 64 - 0x40
	char* randomDataByte; // 68 - 0x44
	int* randomDataInt; // 72 - 0x48
	XAnimIndices indices; // 76 - 0x4C
	XAnimNotifyInfo* notify; // 80 - 0x50
	XAnimDeltaPart* delta; // 84 - 0x54
};

union XAssetHeader
{
	void* PHYSPRESET;
	void* phys_collmap;
	XAnimParts* xanim;
	void* xmodelsurfs;
	XModel* xmodel;
	Material* material;
	void* pixelshader;
	void* techset;
	GfxImage* image;
	snd_alias_list_t* sound;
	void* sndcurve;
	void* loaded_sound;
	void* col_map_sp;
	void* col_map_mp;
	void* com_map;
	void* game_map_sp;
	void* game_map_mp;
	void* map_ents;
	void* fx_map;
	void* gfx_map;
	void* lightdef;
	void* ui_map;
	Font* font;
	void* menufile;
	void* menu;
	void* localize;
	WeaponCompleteDef* weapon;
	void* snddriverglobals;
	void* fx;
	void* impactfx;
	void* aitype;
	void* mptype;
	void* character;
	void* xmodelalias;
	void* rawfile;
	void* stringtable;
	void* leaderboarddef;
	void* structureddatadef;
	Tracer* tracer;
	void* vehicle;
	void* addon_map_ents;
};

struct GfxImageBO2
{
	D3DBaseTexture basemap;
	char unknown2;
	char unknown3;
	char unknown4;
	char unknown5;
	__declspec(align(4)) CardMemory cardMemory; //defines the size
	unsigned __int16 width;
	unsigned __int16 height;
	unsigned __int16 depth;
	char levelCount;
	char streaming;
	unsigned int baseSize;
	char* pixels;
	char unknownData2[0x80];
	const char* name;
	unsigned int hash;

	int dumpGfxImageAsset();
};

union XAssetHeaderBO2
{
	//XModelPieces *xmodelPieces;
	void* physPreset;
	void* physConstraints;
	void* destructibleDef;
	/* XAnimParts *parts;
	 XModel *model;
	 Material *material;
	 MaterialPixelShader *pixelShader;
	 MaterialVertexShader *vertexShader;
	 MaterialTechniqueSet *techniqueSet;*/
	GfxImageBO2* image;
	/*SndBank *sound;
	SndPatch *soundPatch;
	clipMap_t *clipMap;
	ComWorld *comWorld;
	GameWorldSp *gameWorldSp;
	GameWorldMp *gameWorldMp;*/
	void* mapEnts;
	/*GfxWorld *gfxWorld;*/
	void* lightDef;
	/*Font_s *font;
	FontIcon *fontIcon;
	MenuList *menuList;
	menuDef_t *menu;*/
	void* localize;
	void* weapon;
	void* attachment;
	void* attachmentUnique;
	/*WeaponCamo *weaponCamo;
	SndDriverGlobals *sndDriverGlobals;*/
	FxEffectDef* fx;
	/*FxImpactTable *impactFx;*/
	void* rawfile;
	StringTable* stringTable;
	/*LeaderboardDef *leaderboardDef;
	XGlobals *xGlobals;*/
	void* ddlRoot;
	/*Glasses *glasses;
	TextureList *textureList;
	EmblemSet *emblemSet;*/
	void* scriptParseTree;
	/*KeyValuePairs *keyValuePairs;*/
	void* vehicleDef;
	/*MemoryBlock *memoryBlock;
	AddonMapEnts *addonMapEnts;*/
	void* tracerDef;
	/*SkinnedVertsDef *skinnedVertsDef;*/
	void* qdb;
	void* slug;
	void* footstepTableDef;
	void* footstepFXTableDef;
	void* zbarrierDef;
	void* data;
};

struct XAsset
{
	XAssetType type;
	XAssetHeader header;
};

struct XAssetEntry
{
	XAsset asset;
	unsigned __int8 zoneIndex;
	volatile unsigned __int8 inuseMask;
	bool printedMissingAsset;
	unsigned __int16 nextHash;
	unsigned __int16 nextOverride;
};

/* 10130 */
union XAssetEntryPoolEntry
{
	XAssetEntry entry;
	XAssetEntryPoolEntry* next;
};

class UiContext_t
{
public:
	char _0x0000[28];
	__int32 width; //0x001C 
	__int32 height; //0x0020 
	char _0x0024[4];
	float FPS; //0x0028 
	char _0x002C[28];
};

struct clientInfo_s 
{
	int infoValid; //0x0000 
	int nextValid; //0x0004 
	int clientNumber; //0x0008 
	char clientName[32]; //0x000C
	int Team; //0x002C
	char _0x002C[48];
	int Rank; //0x0060 
	int Prestige; //0x0064 
	char _0x0068[0x10];
	char xuid[8];
	char clanAbbrev[8]; //0x0080 
	int Ping; //0x0088 
	int status_icon; //0x008C 
	int Place; //0x0090 
	int Score; //0x0094 
	int Kills; //0x0098 
	int Assists; //0x009C 
	int Deaths; //0x00A0 
	char _0x00A4[32];
	int Headshots; //0x00C4 
	char _0x00C8[4];
	int currentStreak; //0x00CC 
	char _0x00D0[80];
	char SecondaryWeapon[32]; //0x0120 
	char _0x0140[900];
	vec3_t viewAngles; //0x04C4 
	char _0x04D0[192];
	int aimingIn; //0x0590 
	char _0x0594[628];
};
struct refDef_s {

	int Width; //0x0000 
	int Height; //0x0004 
	char _0x0008[20];
	vec2_t tanHalfFov; //0x001C 
	char _0x0024[12];
	vec3_t viewOrigin; //0x0030 
	char _0x003C[4];
	vec3_t viewAxis[3]; //0x0040 
	char _0x0064[8];
};

struct compassData_s 
{
	char _0x0000[0x24];
};

struct cgs_tBO2 {
	int clientNumber; //0x0000
	int localClientNum; //0x0004
	char _0x0008[0x20];
	void* snap; //0x0028
	char _0x002C[0x8C];
	vec3_t Origin; //0x00B8
	char _0x00C4[0x1AC];
	float ZoomState; //0x270
	char _0x0274[0x54];
	int Health; //0x02C8
	char _0x02CC[0x4];
	int maxHealth; //0x02D0
	char _0x02D4[0x47DC8];
	BYTE bThirdPerson; //0x4809C
	char _0x4809D[0xB];
	playerState_s playerState; //0x480A8
	char _0x48638[0x5250];
	refDef_s refDef; //0x4D888
	char _0x4D8F4[0x1BF74];
	compassData_s compassData; //0x69868
	char _0x6988C[0x204];
	clientInfo_s clientInfo[18]; //0x69A90
	char _0x72B20[0xE060];
	float SpreadScale; //0x80B80
	char _0x80B84[0x6B7C];
};

struct button_bits
{
	int buttons[2];
};

struct PlayerHeldWeapon
{
	int weapon;
	int renderOptions;
	float heatPercent;
	int fuelTankTime;
	int adsZoomSelect;
	bool overHeating;
	bool needsRechamber;
	bool heldBefore;
	bool quickReload;
	bool blockWeaponPickup;
	char model;
};

struct gclient_sBO2
{
	char _0x0[0xC];
	int pm_flags;
	int weapFlags;
	char _0x14[0x4];
	int otherFlags;
	char _0x1C[0xC];
	vec3_t origin;
	char _0x34[0x50];
	bool bThirdPerson;
	char _0x85[0x77];
	int eFlags; //0xFC
	char _0x100[0xA4];
	int offHand; //0x1A4
	char _0x1A8[0x10];
	int weapon;
	char _0x1BC[0x2C];
	int spreadOverride;
	int spreadOverrideState;
	char _0x1F0[0x8];
	vec3_t viewangles;
	char _0x204[0x44];
	PlayerHeldWeapon weapons[15];
	char _0x3EC[0x4C];
	int lethalAmmo; //0x438
	int tacticalAmmo; //0x43C
	char _0x440[0x70];
	int locationSelectionInfo;
	int locationSelectionType;
	char _0x4B8[0x4F74];
	usercmd_s cmd;
	char _0x5448[0x78];
	float moveSpeedScale;
	char _0x54E4[0x10];
	int team;
	char _0x54F8[0x3C];
	char name[0x20];
	char _0x5554[0x4];
	int rank;
	int prestige;
	char _0x5560[0x40];
	char clantag[4];
	char _0x55A4[0x60];
	int clientUIVisibilityFlag;
	char _0x5608[0x7C];
	int flags;
	char _0x5688[0x4];
	button_bits buttons;
	button_bits oldbuttons;
	button_bits latchedbuttons;
	button_bits buttonsSinceLastFrame;
	char _0x56AC[0x14C];
};

#define scrPlace ((ScreenPlacement*)0x82690F40)

#define uiContext ((UiContext*)0x83647860)
#define uiContextBO2 ((UiContext_t*)0x83BA29F0)

#define cgsBO2 (*(cgs_tBO2**)0x82BBAE68)
#define g_clientsBO2 ((gclient_sBO2*)0x83551A10)

#define scrVmPub ((scrVmPub_t*)0x835C49D8)
#define cgs (*(cg_t**)0x825B8638)
#define g_entities ((gentity_s*)0x82F03600)
#define g_clients ((gclient_s*)0x830CBF80)
#define globals (*(cgs_t**)0x825B861C)
#define svs ((serverStatic_t*)0x83620380)
#define g_lobbyData ((PartyData_s*)0x8268EE78)