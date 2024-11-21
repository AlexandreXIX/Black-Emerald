# 1 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 2 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_AIDE, 1
# 3 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BIRCH, 2
# 4 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_RIVAL, 3
# 5 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CYNDAQUIL, 4
# 6 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_TOTODILE, 5
# 7 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CHIKORITA, 6
# 8 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 9 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_MapScripts::
# 10 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_ProfessorBirchsLab_OnTransition
# 11 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_ProfessorBirchsLab_OnWarp
# 12 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_ProfessorBirchsLab_OnFrame
# 13 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 14 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 15 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 16 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 17 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 18 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 19 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Unova mons
# 20 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 21 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 22 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 23 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 24 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Never occurs
# 25 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Chose starter
# 26 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 27 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 3
# 28 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 29 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 30 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_OnTransition:
# 31 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 32 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 33 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 34 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, NuvemaTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 35 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, NuvemaTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 36 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 37 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 38 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 39 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllUnovaMons
# 40 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NuvemaTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 41 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 42 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 43 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 44 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 45 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 46 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 47 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 48 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 49 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 50 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_NUVEMA_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 51 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 52 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 53 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 54 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_NUVEMA_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 55 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 56 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 57 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 58 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 59 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_OnWarp:
# 60 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, NuvemaTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 61 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 62 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 63 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, NuvemaTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 64 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 65 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 66 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 67 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 68 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 69 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 70 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 71 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 72 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 73 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 74 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 75 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCH
# 76 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 77 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_NORTH
# 78 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 79 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 80 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 81 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_AIDE, DIR_EAST
# 82 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_AIDE, 10, 10
# 83 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 84 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 85 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 86 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 87 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 88 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 89 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 90 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CYNDAQUIL
# 91 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_TOTODILE
# 92 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CHIKORITA
# 93 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 94 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
# 95 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
# 96 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
# 97 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
# 98 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
# 99 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
# 100 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 101 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 102 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_EAST
# 103 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 104 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 105 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 106 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_OnFrame:
# 107 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, NuvemaTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 108 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, NuvemaTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 109 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, NuvemaTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 110 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, NuvemaTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 111 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 112 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 113 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
@ The starter is technically given prior to this on Route 1 by special ChooseStarter
# 114 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
@ This is just where the game tells you its yours and lets you nickname it
# 115 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 116 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 117 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 118 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	message NuvemaTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 119 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 120 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 121 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 122 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 123 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NuvemaTown_ProfessorBirchsLab_EventScript_NicknameStarter
# 124 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 125 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 126 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 127 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 128 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_0x8004, 0
# 129 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 130 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 131 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 132 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 133 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 134 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 135 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NuvemaTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 136 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 137 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 138 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 139 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 140 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 141 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_1_BOY
# 142 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 143 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 144 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 145 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 146 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 147 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 148 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NuvemaTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 149 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 150 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 151 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 152 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 153 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 154 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 155 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 156 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_GivePokedex
# 157 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 158 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 159 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 160 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 161 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 162 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 163 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 164 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 165 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 166 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 167 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 168 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 169 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 170 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 171 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 172 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 173 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 174 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, NuvemaTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 175 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 176 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 177 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 178 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 179 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 180 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 181 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 182 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 183 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 184 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 185 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 186 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 187 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 188 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 189 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 190 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertUpgradeComment
# 191 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PC_ON
# 192 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitse
# 193 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 194 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, NuvemaTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 195 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 196 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 197 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 198 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 199 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 200 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 201 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	message NuvemaTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 202 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 203 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 204 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 205 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 206 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 207 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 208 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_BIRCH
# 209 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_RIVAL
# 210 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 211 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 212 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 213 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 214 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 215 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 216 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 217 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 218 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 219 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 220 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 221 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertUpgradeComment::
# 222 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertYouCanThankMe, MSGBOX_DEFAULT
# 223 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 224 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 225 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 226 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 227 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 228 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 229 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 230 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 231 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 232 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 233 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 234 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 235 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 236 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 237 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 238 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 239 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 240 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 241 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 242 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 243 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_up
# 244 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 245 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 246 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 247 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 248 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 249 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 250 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 251 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 252 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 253 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 254 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 255 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 256 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 257 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 258 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 259 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 260 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 261 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 262 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 263 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 264 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 265 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 266 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 267 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 268 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 269 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 270 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 271 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 272 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 273 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 274 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 275 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 276 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 277 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Aide::
# 278 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lock
# 279 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 280 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, NuvemaTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 281 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, NuvemaTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 282 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 283 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 284 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 285 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 286 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 287 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 288 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 289 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 290 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 291 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 292 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 293 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 294 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 295 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 296 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 297 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 298 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 299 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 300 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 301 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 302 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 303 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 304 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 305 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 306 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 307 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 308 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Totodile::
# 309 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 310 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 311 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 312 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 313 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 314 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 315 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 316 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 317 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 318 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 319 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Chikorita::
# 320 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 321 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 322 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 323 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 324 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 325 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 326 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 327 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 328 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 329 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 330 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 331 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 332 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 333 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 334 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 335 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 336 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 337 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 338 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 339 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 340 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 341 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 342 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 343 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 344 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5
# 345 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, NuvemaTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 346 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, NuvemaTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 347 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 348 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 349 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 350 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 351 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 352 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 353 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 354 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 355 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 356 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 357 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 358 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 359 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 360 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 361 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 362 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 363 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 364 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 365 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 366 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 367 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 368 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 369 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 370 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 371 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 372 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 373 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 374 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 375 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 376 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 377 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 378 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 379 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 380 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 381 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 382 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 383 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 384 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 385 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5
# 386 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, NuvemaTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 387 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, NuvemaTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 388 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 389 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 390 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 391 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 392 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 393 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 394 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 395 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 396 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 397 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 398 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 399 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 400 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 401 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 402 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 403 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 404 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 405 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 406 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 407 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 408 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 409 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 410 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 411 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 412 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 413 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 414 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 415 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 416 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 417 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 418 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 419 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 420 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 421 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 422 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 423 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 424 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 425 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 426 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5
# 427 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, NuvemaTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 428 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, NuvemaTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 429 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 430 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 431 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 432 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 433 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 434 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 435 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 436 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 437 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 438 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 439 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 440 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 441 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 442 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 443 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 444 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 445 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 446 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 447 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NuvemaTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 448 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 449 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 450 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 451 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 452 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 453 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 454 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 455 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 456 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 457 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 458 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 459 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 460 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 461 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 462 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 463 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 464 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 465 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 466 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	message NuvemaTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 467 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 468 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 469 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 470 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 471 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Birch::
# 472 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lock
# 473 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 474 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, NuvemaTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 475 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, NuvemaTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 476 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, NuvemaTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 477 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 478 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto NuvemaTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 479 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 480 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 481 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 482 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 483 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 484 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 485 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 486 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 487 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 488 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 489 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 490 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 491 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 492 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_NUVEMA_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 493 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 494 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 495 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, NuvemaTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 496 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 497 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 498 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 499 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 500 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch::
# 501 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 502 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 503 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 504 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 505 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 506 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 507 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 508 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 509 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 510 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 511 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 512 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 513 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 514 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 515 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 516 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call NuvemaTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 517 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 518 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 519 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 520 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 521 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 522 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 523 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 524 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 525 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertGivePokeBalls
# 526 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 527 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 528 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 529 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_NUVEMA_RIVAL_STATE, 4
# 530 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 3
# 531 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 532 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 533 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 534 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 535 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 536 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 537 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, NuvemaTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 538 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 539 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 540 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 541 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 542 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertGivePokeBalls::
# 543 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 544 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 545 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertNoRoomForPokeBalls
# 546 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 547 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 548 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 549 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 550 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 551 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 552 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	message NuvemaTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 553 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 554 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 555 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 556 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 557 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 558 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 559 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 560 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 561 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 562 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 563 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 564 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 565 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 566 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 567 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 568 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 569 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertNoRoomForPokeBalls::
# 570 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 571 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 572 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 573 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 574 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 575 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_left
# 576 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 577 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 578 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Machine::
# 579 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 580 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 581 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 582 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Rival::
# 583 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lock
# 584 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 585 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, NuvemaTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 586 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, NuvemaTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 587 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, NuvemaTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 588 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 589 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 590 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertWhereShouldIGoNext
# 591 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 592 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 593 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 594 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 595 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 596 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 597 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 598 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertWhereShouldIGoNext::
# 599 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertWhereShouldIGoNext, MSGBOX_DEFAULT
# 600 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 601 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 602 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 603 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 604 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 605 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertPreferCollectingSlowly
# 606 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 607 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 608 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 609 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 610 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 611 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 612 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 613 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertPreferCollectingSlowly:
# 614 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertPreferCollectingSlowly, MSGBOX_DEFAULT
# 615 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 616 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 617 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 618 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 619 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 620 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertHaveYouGoneToBattleFrontier
# 621 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 622 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 623 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 624 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 625 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 626 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 627 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 628 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertHaveYouGoneToBattleFrontier::
# 629 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 630 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 631 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 632 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 633 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 634 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NuvemaTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 635 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NuvemaTown_ProfessorBirchsLab_EventScript_HilbertTakeBreakFromFieldwork
# 636 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	release
# 637 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 638 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 639 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 640 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 641 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 642 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 643 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_HilbertTakeBreakFromFieldwork::
# 644 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_HilbertTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 645 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	return
# 646 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 647 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_PC::
# 648 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 649 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 650 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 651 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 652 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 653 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 654 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 655 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_Book::
# 656 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	msgbox NuvemaTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 657 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 658 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 659 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 660 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 661 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall NuvemaTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 662 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 663 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 664 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 665 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	end
# 666 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 667 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 668 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 669 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 670 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 671 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 672 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 673 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 674 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 675 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 676 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 677 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 678 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 679 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 680 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 681 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 682 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 683 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 684 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 685 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 686 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 687 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 688 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 689 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 690 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 691 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 692 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
# 693 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
# 694 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard so much about you from\n"
# 695 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "your father.\p"
# 696 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard that you don't have your\n"
# 697 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "own POKéMON yet.\p"
# 698 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "But the way you battled earlier,\n"
# 699 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "you pulled it off with aplomb!\p"
# 700 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I guess you have your father's blood\n"
# 701 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "in your veins after all!\p"
# 702 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, yes. As thanks for rescuing me,\n"
# 703 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'd like you to have the POKéMON you\l"
# 704 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "used earlier.\p"
# 705 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}!$"
# 706 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 707 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 708 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
# 709 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 710 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 711 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 712 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: If you work at POKéMON\n"
# 713 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you'll make\l"
# 714 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "an extremely good TRAINER.\p"
# 715 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, is also studying\n"
# 716 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON while helping me out.\p"
# 717 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
# 718 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "a good idea to go see {RIVAL}?$"
# 719 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 720 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 721 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Great!\n"
# 722 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} should be happy, too.\p"
# 723 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Get {RIVAL} to teach you what it\n"
# 724 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "means to be a TRAINER.$"
# 725 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 726 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 727 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, don't be that way.\n"
# 728 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You should go meet my kid.$"
# 729 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 730 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 731 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {RIVAL}?\n"
# 732 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Gone home, I think.\p"
# 733 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Or maybe that kid's scrabbling around\n"
# 734 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "in tall grass again somewhere…\p"
# 735 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "If you or your POKéMON get tired,\n"
# 736 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "you should get some rest at home.$"
# 737 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 738 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 739 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 740 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL} on\n"
# 741 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "your first try. That's excellent!\p"
# 742 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}'s been helping with my research\n"
# 743 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "for a long time.\p"
# 744 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} has an extensive history as\n"
# 745 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "a TRAINER already.\p"
# 746 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 747 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 748 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéDEX.$"
# 749 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 750 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 751 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"
# 752 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 753 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 754 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 755 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "tool that automatically makes a record\l"
# 756 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "of any POKéMON you meet or catch.\p"
# 757 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, goes everywhere\n"
# 758 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "with it.\p"
# 759 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Whenever my kid catches a rare POKéMON\n"
# 760 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and records its data in the POKéDEX,\l"
# 761 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "why, {RIVAL} looks for me while I'm out\l"
# 762 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "doing fieldwork, and shows me.$"
# 763 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 764 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 765 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Countless POKéMON\n"
# 766 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 767 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 768 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 769 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 770 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 771 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 772 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a POKéDEX, too!\p"
# 773 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "That's great! Just like me!\n"
# 774 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I've got something for you, too!$"
# 775 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 776 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 777 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: It's fun if you can get a lot of\n"
# 778 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON!\p"
# 779 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to look all over the place\n"
# 780 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "because I want different POKéMON.\p"
# 781 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cute POKéMON, I'll catch\n"
# 782 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "them with POKé BALLS!$"
# 783 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 784 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 785 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your BAG's full.$"
# 786 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 787 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 788 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I wonder where I should go look\n"
# 789 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "for POKéMON next?$"
# 790 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 791 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertGotPokedexTooTakeThese:
# 792 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: Huh…\n"
# 793 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a POKéDEX, too.\p"
# 794 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Well then, here.\n"
# 795 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll give you these.$"
# 796 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 797 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 798 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: You know it's more fun to\n"
# 799 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "have a whole bunch of POKéMON.\p"
# 800 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to explore all over the place\n"
# 801 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "to find different POKéMON.\p"
# 802 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cool POKéMON, you bet\n"
# 803 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll try to get them with POKé BALLS.$"
# 804 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 805 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 806 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your BAG's full.$"
# 807 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 808 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertWhereShouldIGoNext:
# 809 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: Where should I look for\n"
# 810 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON next…$"
# 811 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 812 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 813 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 814 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF must use this for research.$"
# 815 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 816 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 817 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 818 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 819 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 820 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 821 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on POKéMON.$"
# 822 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 823 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 824 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 825 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 826 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 827 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Now…\p"
# 828 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 829 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study POKéMON.\p"
# 830 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 831 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 832 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the UNOVA region,\n"
# 833 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also POKéMON from other\l"
# 834 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "regions.\p"
# 835 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It goes to show how rich and varied\n"
# 836 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the natural environments of UNOVA\l"
# 837 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "happen to be.\p"
# 838 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "That's why I think it's necessary for\n"
# 839 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "me to upgrade your POKéDEX to\l"
# 840 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode.\p"
# 841 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, let me see your POKéDEX units.$"
# 842 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 843 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 844 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Eheheh!\p"
# 845 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cool that even my POKéDEX\n"
# 846 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "is getting updated!\p"
# 847 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's because you went out and caught\n"
# 848 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
# 849 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 850 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertYouCanThankMe:
# 851 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: I went out all over UNOVA\n"
# 852 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and checked out POKéMON.\p"
# 853 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You can thank me for getting\n"
# 854 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode POKéDEX.\p"
# 855 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Yep, you're lucky, {PLAYER}!$"
# 856 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 857 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_OkayAllDone:
# 858 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Okay, all done!$"
# 859 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 860 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 861 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 862 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "to the NATIONAL Mode!$"
# 863 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 864 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 865 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: But listen.\n"
# 866 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the CHAMPION,\l"
# 867 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 868 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 869 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 870 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 871 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 872 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 873 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 874 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I think I'll take a short break\n"
# 875 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "from fieldwork.\p"
# 876 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I think I'll help the PROF here for\n"
# 877 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "a while.$"
# 878 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 879 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertTakeBreakFromFieldwork:
# 880 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: For the time being,\n"
# 881 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm taking a break from fieldwork.\p"
# 882 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll be helping out the PROF here\n"
# 883 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "for a while.$"
# 884 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 885 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 886 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 887 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your POKéDEX.\p"
# 888 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 889 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 890 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 891 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the UNOVA\n"
# 892 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "region's POKéDEX.\p"
# 893 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 894 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 895 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 896 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 897 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare POKéMON only found\n"
# 898 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 899 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 900 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 901 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 902 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 903 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: These are rare POKéMON\n"
# 904 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 905 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 906 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 907 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 908 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 909 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The FIRE POKéMON\n"
# 910 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 911 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 912 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 913 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 914 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 915 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The WATER POKéMON\n"
# 916 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 917 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 918 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 919 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 920 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 921 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The GRASS POKéMON\n"
# 922 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 923 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 924 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 925 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 926 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 927 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Take your time before\n"
# 928 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 929 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable POKéMON.$"
# 930 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 931 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 932 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 933 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: I see!\n"
# 934 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You picked a fine POKéMON!$"
# 935 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 936 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 937 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 938 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "from PROF. BIRCH!$"
# 939 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 940 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 941 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 942 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 943 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 944 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 945 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 946 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 947 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the UNOVA POKéDEX,\l"
# 948 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 949 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 950 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 951 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 952 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 953 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 954 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 955 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised POKéMON.\n"
# 956 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 957 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 958 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 959 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 960 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 961 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéMON.$"
# 962 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 963 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 964 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, after this…\n"
# 965 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 966 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 967 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 968 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 969 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL POKéDEX?\p"
# 970 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the PROF.$"
# 971 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 972 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertPreferCollectingSlowly:
# 973 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: Rather than collecting\n"
# 974 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON, I prefer slowly and \l"
# 975 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 976 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 977 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 978 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 979 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 980 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 981 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 982 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_HilbertHaveYouGoneToBattleFrontier:
# 983 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "HILBERT: Hey, {PLAYER}!\n"
# 984 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 985 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 986 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"

# 987 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
NuvemaTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 988 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 989 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 990 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
# 991 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, SCOTT.\p"
# 992 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. TIDAL now.\n"
# 993 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 994 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 995 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 996 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 997 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 998 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "at either SLATEPORT or LILYCOVE.\p"
# 999 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 1000 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 1001 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1002 "data/maps/NuvemaTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"
