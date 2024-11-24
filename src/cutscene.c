#include "global.h"
#include "bg.h"
#include "cutscene.h"
#include "menu_helpers.h"
#include "palette.h"
#include "constants/rgb.h"
#include "constants/vars.h"
#include "sprite.h"

static const u8 sDefaultCallTilemap[] = INCBIN_U8("graphics/xtransceiver_call/default_tilemap.bin");

static const u8 sHilbertCallTiles[] = INCBIN_U8("graphics/xtransceiver_call/hilbert/tiles.4bpp");
static const u8 sHilbertCallMap[] = INCBIN_U8("graphics/xtransceiver_call/hilbert/map.bin");
static const u8 sHilbertCallPalette[] = INCBIN_U8("graphics/xtransceiver_call/hilbert/palette.gbapal");

static const u8 sHildaCallTiles[] = INCBIN_U8("graphics/xtransceiver_call/hilda/tiles.4bpp");
static const u8 sHildaCallMap[] = INCBIN_U8("graphics/xtransceiver_call/hilda/map.bin");
static const u8 sHildaCallPalette[] = INCBIN_U8("graphics/xtransceiver_call/hilda/palette.gbapal");


static const struct CutsceneBG gCutsceneBgTable[] =
{
    [SCENEHILBERT] = 
    {
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sHilbertCallTiles,
		.tileSize = sizeof(sHilbertCallTiles),
        .map = sHilbertCallMap,
		.mapSize = sizeof(sHilbertCallMap),
        .palette = sHilbertCallPalette,
		.palIdxCnt = 240
    },
	    [SCENEHILDA] = 
    {
		.mode = CUTSCENE_4BPP_NO_SCROLL,
		.scrollMode = CUTSCENE_SCROLL_NONE,
        .tiles = sHildaCallTiles,
		.tileSize = sizeof(sHildaCallTiles),
        .map = sHildaCallMap,
		.mapSize = sizeof(sHildaCallMap),
        .palette = sHildaCallPalette,
		.palIdxCnt = 240
    },
};

//spritescenes defined here

static const struct BgTemplate sCutsceneBackground8bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 26,
	.screenSize = 0,
	.paletteMode = 1,
	.priority = 0,
	.baseTile = 0
};

static const struct BgTemplate sCutsceneBackground4bpp = {
	.bg = 1,
	.charBaseIndex = 0,
	.mapBaseIndex = 26,
	.screenSize = 0,
	.paletteMode = 0,
	.priority = 0,
	.baseTile = 0
};


EWRAM_DATA struct BGPanState gBgPanState = {0};

ALIGNED(4) EWRAM_DATA u16 gUnfadedPalette[0x100] = {0};
ALIGNED(4) EWRAM_DATA u16 gFadedPalette[0x100] = {0};
EWRAM_DATA struct PidgeyPaletteFade gPPlttFade = {0};
//ALIGNED(4) EWRAM_DATA u8 gCutsceneSpriteIDs[4] = {0};

//static void DrawCutsceneSpriteArrangement(u8 xStart, u8 yStart, u8 mugshotId)
//mugshot id here would be MUGSHOTLUCY for example, which has already been included.

//remove the mugshot arrangement
//(void)RyuRemoveCutsceneSpriteArrangement(void)
//{}

static void BlendPaletteDevPidgey(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor)
{
    u16 i;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gUnfadedPalette[index];
        s8 r1 = data1->r;
        s8 g1 = data1->g;
        s8 b1 = data1->b;
        struct PlttData *data2 = (struct PlttData *)&blendColor;
		s8 r2 = data2->r;
        s8 g2 = data2->g;
        s8 b2 = data2->b;
        gFadedPalette[index] = ((r1 + (((r2 - r1) * coeff) >> 4)) << 0)
                                | ((g1 + (((g2 - g1) * coeff) >> 4)) << 5)
                                | ((b1 + (((b2 - b1) * coeff) >> 4)) << 10);
    }
}

void UpdatePidgeyPaletteFade(void)
{
	if(gPPlttFade.active)
	{
		BlendPaletteDevPidgey(gPPlttFade.palOffset, gPPlttFade.numEntries, gPPlttFade.currentCoeff, RGB_BLACK);
		CpuCopy16(gFadedPalette, (u16 *)PLTT, gPPlttFade.numEntries * sizeof(u16));
		if(gPPlttFade.currentCoeff == gPPlttFade.endCoeff)
		{
			gPPlttFade.active = FALSE;
			return;
		}
		if(gPPlttFade.startCoeff > gPPlttFade.endCoeff)
		{
			gPPlttFade.currentCoeff--;
		}
		else if(gPPlttFade.startCoeff < gPPlttFade.endCoeff)
		{
			gPPlttFade.currentCoeff++;
		}
	} 
}

void StartPaletteFadePidgey(u16 offset, u8 numEntries, u8 startCoeff, u8 endCoeff, u16 color)
{
	if(!gPPlttFade.active)
	{
		gPPlttFade.startCoeff = startCoeff;
		gPPlttFade.endCoeff = endCoeff;
		gPPlttFade.currentCoeff = startCoeff;
		gPPlttFade.numEntries = numEntries;
		gPPlttFade.palOffset = offset;
		gPPlttFade.color = color;
		gPPlttFade.active = TRUE;
	}
	CpuCopy16(&gPlttBufferUnfaded[0x1E0/2], (u16 *)(PLTT + 0x1E0), 0x20); // HACK!! due to changing the VBlankCallback for cutscenes the normal palettes 
																		  // that have been loaded won't get sent to palette ram so we do for the msgbox ourselves
}

void LoadPalettePidgey(const void * pal, u8 numEntries)
{
	CpuCopy16(pal, gUnfadedPalette, numEntries * sizeof(u16));
}

static void InitDefaultTilemap(void)
{
	LoadBgTilemap(1, sDefaultCallTilemap, sizeof(sDefaultCallTilemap), 0);
}

static void StartBackgroundPan(const u8 * ptr, u8 bpp, u8 mode)
{
	gBgPanState.bgLineOfs = 0;
	gBgPanState.ptr = ptr;
	gBgPanState.bpp = bpp;
	gBgPanState.mode = mode;
	gBgPanState.bgLineOfs = 19; // expects a '{width} x 40' image
	gBgPanState.active = TRUE;
}

void UpdateBgPan(void)
{
	if(gBgPanState.active)
	{
		if(gBgPanState.bgLineOfs != 0 && gBgPanState.vofsVal == 0)
		{
			if(gBgPanState.mode == 0)
				LoadBgTilemap(1, &gBgPanState.ptr[gBgPanState.bgLineOfs * 0x2 * 32], 0x2 * 32 * 21, 0);
			else
				LoadBgTiles(1, &gBgPanState.ptr[gBgPanState.bgLineOfs * gBgPanState.bpp * 0x8 * 30], gBgPanState.bpp * 0x8 * 30 * 21, 0);
			gBgPanState.bgLineOfs--;
			gBgPanState.vofsVal = 8;
		}
		if(gBgPanState.vofsVal > 0)
		{
			gBgPanState.vofsVal--;
			REG_BG1VOFS = gBgPanState.vofsVal;
		}
		else if(gBgPanState.bgLineOfs == 0)
		{
			gBgPanState.active = FALSE;
		}
	}
}

void StartBGCutscene(u8 id)
{
	if(gCutsceneBgTable[id].mode & CUTSCENE_8BPP_MODE_MASK)
		InitBgFromTemplate(&sCutsceneBackground8bpp);
	else
		InitBgFromTemplate(&sCutsceneBackground4bpp);
	ResetAllBgsCoordinates();
    ShowBg(0);
    ShowBg(1);
	switch(gCutsceneBgTable[id].mode)
	{
		case CUTSCENE_4BPP_NO_SCROLL:
		case CUTSCENE_8BPP_NO_SCROLL:
			if(gCutsceneBgTable[id].map == NULL)
				InitDefaultTilemap();
			else
				LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
			LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
			break;
		case CUTSCENE_4BPP_SCROLL:
			switch(gCutsceneBgTable[id].scrollMode)
			{
				case CUTSCENE_SCROLL_MAP:
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					StartBackgroundPan(gCutsceneBgTable[id].map, 4, gCutsceneBgTable[id].scrollMode);
					break;
				case CUTSCENE_SCROLL_TILE:
					InitDefaultTilemap();
					StartBackgroundPan(gCutsceneBgTable[id].tiles, 4, gCutsceneBgTable[id].scrollMode);
					break;
				default:
					if(gCutsceneBgTable[id].map == NULL)
						InitDefaultTilemap();
					else
						LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					break;
			}
			break;
		case CUTSCENE_8BPP_SCROLL:
			switch(gCutsceneBgTable[id].scrollMode)
			{
				case CUTSCENE_SCROLL_MAP:
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					StartBackgroundPan(gCutsceneBgTable[id].map, 8, gCutsceneBgTable[id].scrollMode);
					break;
				case CUTSCENE_SCROLL_TILE:
					InitDefaultTilemap();
					StartBackgroundPan(gCutsceneBgTable[id].tiles, 8, gCutsceneBgTable[id].scrollMode);
					break;
				default:
					if(gCutsceneBgTable[id].map == NULL)
						InitDefaultTilemap();
					else
						LoadBgTilemap(1, gCutsceneBgTable[id].map, gCutsceneBgTable[id].mapSize, 0);
					LoadBgTiles(1, gCutsceneBgTable[id].tiles, gCutsceneBgTable[id].tileSize, 0);
					break;
			}
			break; 
		default:
			break;
	}
	//Unused_LoadBgPalette(1, gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt * 2, 0);
	LoadPalettePidgey(gCutsceneBgTable[id].palette, gCutsceneBgTable[id].palIdxCnt);
	StartPaletteFadePidgey(0, gCutsceneBgTable[id].palIdxCnt, 16, 0, RGB_BLACK);
}
