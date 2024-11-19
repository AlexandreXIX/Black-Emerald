# 1 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 2 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
.set LOCALID_STARTERS, 1
# 3 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
.set LOCALID_CHEREN, 2
# 4 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
.set LOCALID_BIANCA, 3
# 5 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 6 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_MapScripts::
# 7 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_PlayersHouse_2F_OnTransition
# 8 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_PlayersHouse_2F_OnFrame
# 9 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_PlayersHouse_2F_OnWarp
# 10 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.byte 0
# 11 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 12 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_OnTransition:
# 13 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 14 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 15 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 16 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 17 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_OnFrame:
# 18 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 1, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene
# 19 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.2byte 0
# 20 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 21 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_OnWarp:
# 22 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, NuvemaTown_PlayersHouse_2F_EventScript_CheckInitDecor
# 23 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.2byte 0
# 24 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 25 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_CheckInitDecor::
# 26 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	checkplayergender
# 27 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 28 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 29 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 30 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_CheckPlayersPC::
# 31 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
# 32 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 33 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_ON
# 34 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 35 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special BedroomPC
# 36 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 37 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
# 38 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 39 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 40 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
# 41 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
# 42 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 43 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 44 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
# 45 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 46 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 47 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 48 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 49 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 50 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 51 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 52 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 53 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	end
# 54 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 55 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 56 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 57 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 58 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 59 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 60 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 61 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 62 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 63 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 64 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 65 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "UNOVA region map.$"
# 66 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"

# 67 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 68 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 69 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 70 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene::
# 128 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 129 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0
# 130 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 131 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_0
# 132 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 133 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 134 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_1
# 135 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 136 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 137 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 139 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_2
# 140 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 141 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	addobject LOCALID_BIANCA
# 142 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_4
# 143 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 145 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 146 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 147 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 148 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_3
# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_6
# 150 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_4
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_7
# 153 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 154 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 155 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 156 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 157 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_5
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_8
# 159 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 160 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 162 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_6
# 163 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_7
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_9
# 165 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 166 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 168 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 169 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 170 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_8
# 171 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 2
# 172 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


NuvemaTown_PlayersHouse_2F_EventScript_StarterBag::
# 176 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 177 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0
# 178 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 179 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 180 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special ChooseStarter
# 181 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 182 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SetUnlockedPokedexFlags
# 183 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 184 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 185 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 186 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 187 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3
# 189 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4
# 191 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5
# 194 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1:
# 196 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitfanfare
# 197 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 3
# 198 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter
# 199 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3:
# 188 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4:
# 190 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5:
# 192 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1


NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter::
# 203 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0
# 205 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 206 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0
# 207 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0
# 208 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 209 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1
# 210 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 211 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3
# 213 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4
# 215 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5
# 218 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1:
# 220 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 3, 6
# 222 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 223 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 224 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_BIANCA, 5, 7
# 225 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 227 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_CHEREN, 4, 4
# 228 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 229 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 230 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles
# 231 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3:
# 212 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4:
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5:
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1


NuvemaTown_PlayersHouse_2F_Rival_Battles::
# 235 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 236 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0
# 238 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 239 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0
# 240 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1
# 241 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2
# 242 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3
# 243 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4
# 244 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5
# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rival_Battles_3
# 248 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rival_Battles_4
# 249 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rival_Battles_5
NuvemaTown_PlayersHouse_2F_Rival_Battles_1:
# 252 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6
# 253 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7
# 254 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 255 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 258 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 259 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 262 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 263 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8
# 264 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 265 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 266 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9
# 267 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1
# 269 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 270 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11
# 271 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playfanfare SE_USE_ITEM
# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12
# 273 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitfanfare
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 275 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13
# 277 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playfanfare SE_USE_ITEM
# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14
# 279 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitfanfare
# 280 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_Rival_Battles_3:
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_SNIVY, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_4:
# 248 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_TEPIG, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_5:
# 249 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_OSHAWOTT, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1


PlayersHouse_2F_EventScript_CheckWallClock::
# 284 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 285 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 287 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special Special_ViewWallClock
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 289 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end


PlayersHouse_2F_EventScript_SetWallClock::
# 294 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 295 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special StartWallClock
# 297 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 298 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SET_WALL_CLOCK
# 299 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


# 129 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0:
# 129 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 129 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 132 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1:
# 132 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 135 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2:
# 135 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 137 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3:
# 137 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 142 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_4:
# 142 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5:
# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_up
	step_end

# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_6:
# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
	step_end

# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_7:
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_8:
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_player
	step_end

# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_9:
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0:
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0:
# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1:
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_0:
# 131 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: {PLAYER}!\p"
	.string "I heard from Professor Juniper. We can\n"
	.string "have a Pokémon?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_1:
# 134 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...\n"
	.string "...\p"
	.string "What's keeping Bianca?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_2:
# 139 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "What time is it anyways?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_3:
# 148 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Am I a little late again?\n"
	.string "So-oooo-orry!$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_4:
# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Bianca...\p"
	.string "I've known for ten years that you have\n"
	.string "no sense of time, but...seriously...\p"
	.string "Today's the day we can get a Pokémon\n"
	.string "from Professor Juniper!$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_5:
# 157 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: I know. Sorry, {PLAYER}.\n"
	.string "Sorry, Cheren.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_6:
# 162 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: So, where are the Pokémon?\p"
	.string "They were delivered to {PLAYER}'s\n"
	.string "house, so {PLAYER} gets first pick.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_7:
# 163 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Naturally.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_8:
# 170 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon are waiting for us inside\n"
	.string "that gift box.\p"
	.string "Ok, {PLAYER}, you go first and take a\n"
	.string "peek at the gift box.\p"
	.string "I want to meet the Pokémon right now!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0:
# 177 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} opened the gift box!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1:
# 188 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Snivy!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2:
# 190 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Tepig!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3:
# 192 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Oshawott!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4:
# 194 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Error getting starter!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0:
# 206 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: OK, I'll take this Pokémon!\n"
	.string "Cheren, that one's yours!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1:
# 209 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Hey, how come you get to pick\n"
	.string "out my Pokémon?$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2:
# 212 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Tepig from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3:
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Oshawott from\n"
	.string "the start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4:
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Snivy from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0:
# 239 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Everyone has chosen a Pokémon!\n"
	.string "...So that's that!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1:
# 240 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Hey, I know!\n"
	.string "Let's have a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2:
# 241 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Honestly, Bianca...$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3:
# 242 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Even though they're still weak Pokémon,\n"
	.string "you shouldn't have Pokémon battles\l"
	.string "inside a house.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4:
# 243 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Don't be a worrywart!\n"
	.string "These little ones are weak, like you\l"
	.string "said.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5:
# 244 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "We have to let them battle so they'll\n"
	.string "get stronger. It's settled, {PLAYER}!\l"
	.string "Get ready for a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6:
# 252 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wow...\n"
	.string "{PLAYER}, you're gonna be an awesome\l"
	.string "Trainer someday, I can tell!\p"
	.string "No doubt!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7:
# 253 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Uh...\n"
	.string "...\p"
	.string "Bianca, would you take a look around?$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8:
# 263 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wh-whoa!\l"
	.string "What ahppened?!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9:
# 266 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Wow! Pokémon are amaaaaazing!! So\n"
	.string "little, but so strong!\p"
	.string "I'm so glad that I get to have a\n"
	.string "Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10:
# 267 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...Oh.\n"
	.string "Um, sorry about your room, {PLAYER}.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11:
# 270 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: You...are completely hopeless.\p"
	.string "Here!\l"
	.string "I'll restore your Pokémon for you.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12:
# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed Bianca's Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13:
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER}'s Pokémon needs to be fixed\n"
	.string "up, too.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14:
# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed {PLAYER}'s Pokémon!$"

NuvemaTown_PlayersHouse_2F_Bianca_Lost::
# 303 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon on both sides did their\n"
	.string "best!$"
