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
# 137 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0
# 139 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_0
# 141 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 142 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 143 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_1
# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 145 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 146 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 147 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 148 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_2
# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 150 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	addobject LOCALID_BIANCA
# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_4
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 153 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 154 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 155 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 156 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 157 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_3
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_6
# 159 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 160 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_4
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_7
# 162 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 163 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 165 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 166 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_5
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_8
# 168 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 169 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 170 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 171 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_6
# 172 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_7
# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_9
# 174 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 175 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 176 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 177 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 178 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 179 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_8
# 180 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 2
# 181 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


NuvemaTown_PlayersHouse_2F_EventScript_StarterBag::
# 185 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 186 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0
# 187 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 188 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special ChooseStarter
# 189 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 190 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_HIDE_STARTER_INTRO
# 191 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 192 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SetUnlockedPokedexFlags
# 193 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 194 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 195 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 196 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 197 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3
# 199 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4
# 201 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1:
# 206 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitfanfare
# 207 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 3
# 208 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter
# 209 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3:
# 198 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4:
# 200 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5:
# 202 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1


NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter::
# 213 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0
# 215 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0
# 217 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0
# 218 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 219 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1
# 220 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3
# 222 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4
# 223 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5
# 224 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1:
# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 227 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 3, 6
# 228 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 229 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SpawnCameraObject
# 230 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy OBJ_EVENT_ID_CAMERA, 4, 5
# 231 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_BIANCA, 5, 7
# 232 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 233 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 234 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_CHEREN, 4, 4
# 235 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 236 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles
# 238 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3:
# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4:
# 222 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5:
# 223 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1


NuvemaTown_PlayersHouse_2F_Rival_Battles::
# 242 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 243 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setrespawn HEAL_LOCATION_NUVEMA_TOWN_PLAYERS_HOUSE_2F
# 244 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0
# 246 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0
# 248 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1
# 249 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2
# 250 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3
# 251 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4
# 252 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5
# 253 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 255 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rival_Battles_3
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rival_Battles_4
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rival_Battles_5
NuvemaTown_PlayersHouse_2F_Rival_Battles_1:
# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7
# 262 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 263 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 264 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 265 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 266 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 267 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 269 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 270 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 271 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8
# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 273 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9
# 275 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1
# 277 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11
# 279 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12
# 280 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call Common_EventScript_AllyHeal
# 281 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 282 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 283 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13
# 284 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14
# 285 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call Common_EventScript_AllyHeal
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_2
# 287 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_3
# 289 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 290 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 291 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 292 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 293 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 294 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_15
# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_16
# 299 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_4
# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 301 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 302 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 303 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 304 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_17
# 305 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 306 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rival_Battles_7
# 309 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rival_Battles_8
# 312 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rival_Battles_9
	return

NuvemaTown_PlayersHouse_2F_Rival_Battles_3:
# 255 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_SNIVY, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_4:
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_TEPIG, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_5:
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_OSHAWOTT, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_7:
# 307 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_18
# 308 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_SNIVY, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	return

NuvemaTown_PlayersHouse_2F_Rival_Battles_8:
# 310 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_19
# 311 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_TEPIG, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	return

NuvemaTown_PlayersHouse_2F_Rival_Battles_9:
# 313 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_20
# 314 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_OSHAWOTT, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	return


PlayersHouse_2F_EventScript_CheckWallClock::
# 319 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 320 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 321 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 322 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special Special_ViewWallClock
# 323 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 324 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end


PlayersHouse_2F_EventScript_SetWallClock::
# 329 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 330 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special StartWallClock
# 332 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SET_WALL_CLOCK
# 334 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0:
# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 141 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1:
# 141 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2:
# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 146 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3:
# 146 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_4:
# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 153 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5:
# 153 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_up
	step_end

# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_6:
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
	step_end

# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_7:
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_8:
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_player
	step_end

# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_9:
# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0:
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0:
# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1:
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_2:
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	emote_exclamation_mark
	step_end

# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_3:
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
	step_end

# 299 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_4:
# 299 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
	step_end

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_0:
# 140 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: {PLAYER}!\p"
	.string "I heard from Professor Juniper. We can\n"
	.string "have a Pokémon?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_1:
# 143 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...\n"
	.string "...\p"
	.string "What's keeping Bianca?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_2:
# 148 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "What time is it anyways?$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_3:
# 157 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Am I a little late again?\n"
	.string "So-oooo-orry!$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_4:
# 160 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Bianca...\p"
	.string "I've known for ten years that you have\n"
	.string "no sense of time, but...seriously...\p"
	.string "Today's the day we can get a Pokémon\n"
	.string "from Professor Juniper!$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_5:
# 166 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: I know. Sorry, {PLAYER}.\n"
	.string "Sorry, Cheren.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_6:
# 171 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: So, where are the Pokémon?\p"
	.string "They were delivered to {PLAYER}'s\n"
	.string "house, so {PLAYER} gets first pick.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_7:
# 172 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Naturally.$"

NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Text_8:
# 179 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon are waiting for us inside\n"
	.string "that gift box.\p"
	.string "Ok, {PLAYER}, you go first and take a\n"
	.string "peek at the gift box.\p"
	.string "I want to meet the Pokémon right now!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0:
# 186 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} opened the gift box!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1:
# 198 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Snivy!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2:
# 200 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Tepig!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3:
# 202 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Oshawott!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4:
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Error getting starter!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0:
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: OK, I'll take this Pokémon!\n"
	.string "Cheren, that one's yours!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1:
# 219 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Hey, how come you get to pick\n"
	.string "out my Pokémon?$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2:
# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Tepig from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3:
# 222 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Oshawott from\n"
	.string "the start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4:
# 223 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Snivy from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0:
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Everyone has chosen a Pokémon!\n"
	.string "...So that's that!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1:
# 248 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Hey, I know!\n"
	.string "Let's have a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2:
# 249 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Honestly, Bianca...$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3:
# 250 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Even though they're still weak Pokémon,\n"
	.string "you shouldn't have Pokémon battles\l"
	.string "inside a house.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4:
# 251 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Don't be a worrywart!\n"
	.string "These little ones are weak, like you\l"
	.string "said.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5:
# 252 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "We have to let them battle so they'll\n"
	.string "get stronger. It's settled, {PLAYER}!\l"
	.string "Get ready for a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6:
# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wow...\n"
	.string "{PLAYER}, you're gonna be an awesome\l"
	.string "Trainer someday, I can tell!\p"
	.string "No doubt!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7:
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Uh...\n"
	.string "...\p"
	.string "Bianca, would you take a look around?$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8:
# 271 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wh-whoa!\l"
	.string "What ahppened?!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9:
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Wow! Pokémon are amaaaaazing!! So\n"
	.string "little, but so strong!\p"
	.string "I'm so glad that I get to have a\n"
	.string "Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10:
# 275 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...Oh.\n"
	.string "Um, sorry about your room, {PLAYER}.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11:
# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: You...are completely hopeless.\p"
	.string "Here!\l"
	.string "I'll restore your Pokémon for you.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12:
# 279 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed Bianca's Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13:
# 283 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER}'s Pokémon needs to be fixed\n"
	.string "up, too.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14:
# 284 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed {PLAYER}'s Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_15:
# 294 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Hey Cheren!\l"
	.string "How about you battle, too?\p"
	.string "With all you know, I'm sure you can\n"
	.string "battle without turning the room into a\l"
	.string "disaster area like I did!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_16:
# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: I believe you're right!\p"
	.string "It'll be no problem for me to keep the\n"
	.string "room from getting any messier.\p"
	.string "Besides, it's not fair if you two are the\n"
	.string "only ones who get to have fun battling!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_17:
# 304 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "It's decided. You'll be my opponent... in\n"
	.string "our first Pokémon battle!\p"
	.string "$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_18:
# 307 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Tepig!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_19:
# 310 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Oshawott!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_20:
# 313 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Snivy!$"

NuvemaTown_PlayersHouse_2F_Bianca_Lost::
# 338 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon on both sides did their\n"
	.string "best!$"

NuvemaTown_PlayersHouse_2F_Cheren_Lost::
# 342 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Ah! So that's a Pokémon battle!$"
