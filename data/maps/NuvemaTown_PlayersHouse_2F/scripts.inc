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


PlayersHouse_2F_EventScript_DontLeave::
# 185 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 186 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 187 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 188 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_EventScript_DontLeave_Text_0
# 189 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_4
# 190 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 191 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 192 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end


NuvemaTown_PlayersHouse_2F_EventScript_StarterBag::
# 197 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 198 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0
# 199 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 200 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special ChooseStarter
# 201 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 202 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_HIDE_STARTER_INTRO
# 203 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 204 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SetUnlockedPokedexFlags
# 205 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 206 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 207 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 208 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 209 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3
# 211 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4
# 213 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1:
# 218 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitfanfare
# 219 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 3
# 220 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter
# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_3:
# 210 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_4:
# 212 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_5:
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3
	goto NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_1


NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter::
# 225 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0
# 227 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 228 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0
# 229 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_0
# 230 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 231 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1
# 232 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 233 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3
# 234 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4
# 235 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5
# 236 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1:
# 238 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 239 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 3, 6
# 240 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 241 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SpawnCameraObject
# 242 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy OBJ_EVENT_ID_CAMERA, 3, 6
# 243 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_BIANCA, 5, 7
# 244 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 246 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setobjectxy LOCALID_CHEREN, 4, 4
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 248 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 249 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles
# 250 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_3:
# 233 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_4:
# 234 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_5:
# 235 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4
	goto NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_1


NuvemaTown_PlayersHouse_2F_Rival_Battles::
# 254 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 255 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setrespawn HEAL_LOCATION_NUVEMA_TOWN_PLAYERS_HOUSE_2F
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0
# 258 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 259 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0
# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2
# 262 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3
# 263 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4
# 264 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5
# 265 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 267 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rival_Battles_3
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rival_Battles_4
# 269 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rival_Battles_5
NuvemaTown_PlayersHouse_2F_Rival_Battles_1:
# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6
# 273 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 275 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 276 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 277 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 279 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 280 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 281 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 282 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 283 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8
# 284 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 285 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9
# 287 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1
# 289 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 290 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11
# 291 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12
# 292 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call Common_EventScript_AllyHeal
# 293 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 294 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 295 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13
# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14
# 297 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call Common_EventScript_AllyHeal
# 298 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_2
# 299 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_3
# 301 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 302 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_1
# 303 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 304 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_5
# 305 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 306 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_15
# 308 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_16
# 311 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_4
# 312 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 313 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_2
# 314 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene_Movement_3
# 315 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 316 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_17
# 317 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	switch VAR_STARTER_MON
# 318 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 0, NuvemaTown_PlayersHouse_2F_Rival_Battles_8
# 321 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 1, NuvemaTown_PlayersHouse_2F_Rival_Battles_9
# 324 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	case 2, NuvemaTown_PlayersHouse_2F_Rival_Battles_10
NuvemaTown_PlayersHouse_2F_Rival_Battles_6:
# 328 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_21
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_5
# 332 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_22
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_6
# 334 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement LOCALID_BIANCA
# 335 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	removeobject LOCALID_CHEREN
# 336 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	removeobject LOCALID_BIANCA
# 337 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 4
# 338 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end

NuvemaTown_PlayersHouse_2F_Rival_Battles_3:
# 267 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_SNIVY, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_4:
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_TEPIG, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_5:
# 269 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_BIANCA_INTRO_OSHAWOTT, NuvemaTown_PlayersHouse_2F_Bianca_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_1

NuvemaTown_PlayersHouse_2F_Rival_Battles_8:
# 319 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_18
# 320 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_SNIVY, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_6

NuvemaTown_PlayersHouse_2F_Rival_Battles_9:
# 322 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_19
# 323 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_TEPIG, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_6

NuvemaTown_PlayersHouse_2F_Rival_Battles_10:
# 325 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_20
# 326 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_CHEREN_INTRO_OSHAWOTT, NuvemaTown_PlayersHouse_2F_Cheren_Lost
	goto NuvemaTown_PlayersHouse_2F_Rival_Battles_6


PlayersHouse_2F_EventScript_CheckWallClock::
# 343 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 344 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 345 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 346 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special Special_ViewWallClock
# 347 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 348 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end


PlayersHouse_2F_EventScript_SetWallClock::
# 353 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 354 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 355 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special StartWallClock
# 356 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 357 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SET_WALL_CLOCK
# 358 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
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

# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Movement_0:
# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 226 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_0:
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_1:
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 288 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 298 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_2:
# 298 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	emote_exclamation_mark
	step_end

# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_3:
# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
	step_end

# 311 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_4:
# 311 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
	step_end

# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_5:
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 331 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	set_invisible
	step_end

# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
NuvemaTown_PlayersHouse_2F_Rival_Battles_Movement_6:
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
# 333 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
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

PlayersHouse_2F_EventScript_DontLeave_Text_0:
# 188 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Aren't you going to check out\n"
	.string "the gift box? Where are you going?$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_0:
# 198 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} opened the gift box!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_1:
# 210 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Snivy!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_2:
# 212 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Tepig!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_3:
# 214 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} chose\n"
	.string "Oshawott!$"

NuvemaTown_PlayersHouse_2F_EventScript_StarterBag_Text_4:
# 216 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Error getting starter!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_0:
# 228 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: OK, I'll take this Pokémon!\n"
	.string "Cheren, that one's yours!$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_1:
# 231 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Hey, how come you get to pick\n"
	.string "out my Pokémon?$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_2:
# 233 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Tepig from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_3:
# 234 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Oshawott from\n"
	.string "the start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rivals_Pick_Starter_Text_4:
# 235 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Oh, never mind. I wanted Snivy from the\n"
	.string "start, anyway.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_0:
# 259 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Everyone has chosen a Pokémon!\n"
	.string "...So that's that!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_1:
# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Hey, I know!\n"
	.string "Let's have a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_2:
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Honestly, Bianca...$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_3:
# 262 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Even though they're still weak Pokémon,\n"
	.string "you shouldn't have Pokémon battles\l"
	.string "inside a house.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_4:
# 263 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Don't be a worrywart!\n"
	.string "These little ones are weak, like you\l"
	.string "said.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_5:
# 264 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "We have to let them battle so they'll\n"
	.string "get stronger. It's settled, {PLAYER}!\l"
	.string "Get ready for a Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_6:
# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wow...\n"
	.string "{PLAYER}, you're gonna be an awesome\l"
	.string "Trainer someday, I can tell!\p"
	.string "No doubt!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_7:
# 273 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Uh...\n"
	.string "...\p"
	.string "Bianca, would you take a look around?$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_8:
# 283 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Wh-whoa!\l"
	.string "What ahppened?!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_9:
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Wow! Pokémon are amaaaaazing!! So\n"
	.string "little, but so strong!\p"
	.string "I'm so glad that I get to have a\n"
	.string "Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_10:
# 287 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...Oh.\n"
	.string "Um, sorry about your room, {PLAYER}.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_11:
# 290 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: You...are completely hopeless.\p"
	.string "Here!\l"
	.string "I'll restore your Pokémon for you.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_12:
# 291 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed Bianca's Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_13:
# 295 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER}'s Pokémon needs to be fixed\n"
	.string "up, too.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_14:
# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren healed {PLAYER}'s Pokémon!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_15:
# 306 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Hey Cheren!\l"
	.string "How about you battle, too?\p"
	.string "With all you know, I'm sure you can\n"
	.string "battle without turning the room into a\l"
	.string "disaster area like I did!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_16:
# 308 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: I believe you're right!\p"
	.string "It'll be no problem for me to keep the\n"
	.string "room from getting any messier.\p"
	.string "Besides, it's not fair if you two are the\n"
	.string "only ones who get to have fun battling!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_17:
# 316 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "It's decided. You'll be my opponent... in\n"
	.string "our first Pokémon battle!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_18:
# 319 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Tepig!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_19:
# 322 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Oshawott!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_20:
# 325 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Let's see what you can do, Snivy!$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_21:
# 328 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: I made a strange blunder in my\n"
	.string "first battle, but this feeling I have...\p"
	.string "...I'm finally a Trainer.\p"
	.string "But first, we'd better go apologize to\n"
	.string "your mother about this messed-up room.$"

NuvemaTown_PlayersHouse_2F_Rival_Battles_Text_22:
# 332 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Oh!\n"
	.string "I'd better come, too!$"

NuvemaTown_PlayersHouse_2F_Bianca_Lost::
# 362 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon on both sides did their\n"
	.string "best!$"

NuvemaTown_PlayersHouse_2F_Cheren_Lost::
# 366 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Ah! So that's a Pokémon battle!$"
