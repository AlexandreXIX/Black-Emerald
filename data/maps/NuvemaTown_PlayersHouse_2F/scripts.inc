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
	map_script_2 VAR_NUVEMA_TOWN_STATE, 1, NuvemaTown_PlayersHouse_2F_EventScript_IntroCutscene
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
# 125 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 126 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Approaches
# 127 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 128 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_Intro, MSGBOX_NPC
# 129 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Sees_Starters
# 130 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 131 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_Waiting, MSGBOX_NPC
# 132 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Looks_at_Player
# 133 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 134 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_Time, MSGBOX_NPC
# 135 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 136 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 2
# 137 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	addobject LOCALID_BIANCA
# 138 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Climbs_Stairs
# 139 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Notices_Bianca
# 141 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 142 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Notices_Bianca
# 143 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 144 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Bianca_Arrives, MSGBOX_NPC
# 145 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Meets_Bianca
# 146 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 147 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_Berating, MSGBOX_NPC
# 148 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Enters
# 149 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 150 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Faces_Group
# 151 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Group
# 152 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 153 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Bianca_Apology, MSGBOX_NPC
# 154 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Approaches_Starters
# 155 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 156 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Bianca
# 157 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 158 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Bianca_TimeToPick, MSGBOX_NPC
# 159 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_Response, MSGBOX_NPC
# 160 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Approaches_Starters
# 161 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 162 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Starters
# 163 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 164 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Faces_Starters
# 165 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitmovement 0
# 166 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	msgbox Cheren_TimeToPick, MSGBOX_NPC
# 167 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


NuvemaTown_PlayersHouse_2F_EventScript_StarterBag::
# 171 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	lockall
# 172 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 173 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 174 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special ChooseStarter
# 175 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 176 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special SetUnlockedPokedexFlags
# 177 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 178 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


PlayersHouse_2F_EventScript_CheckWallClock::
# 182 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 183 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 184 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special Special_ViewWallClock
# 185 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 186 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	releaseall
	end


PlayersHouse_2F_EventScript_SetWallClock::
# 192 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 193 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	special StartWallClock
# 194 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 195 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_SET_WALL_CLOCK
	return


# 200 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Approaches:
# 201 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 202 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 209 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Sees_Starters:
# 210 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 217 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Looks_at_Player:
# 218 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 221 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Player_Looks_at_Cheren:
# 222 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_right
	step_end

# 229 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Bianca_Climbs_Stairs:
# 230 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 233 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Player_Notices_Bianca:
# 234 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_up
	step_end

# 237 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Notices_Bianca:
# 238 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_up
	step_end

# 245 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Meets_Bianca:
# 246 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_right
# 247 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_up
	step_end

# 254 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Bianca_Enters:
# 255 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 256 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 257 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
	step_end

# 260 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Faces_Group:
# 261 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 264 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Player_Faces_Group:
# 265 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_up
	step_end

# 272 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Bianca_Approaches_Starters:
# 273 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 274 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 275 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_player
	step_end

# 278 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Player_Faces_Bianca:
# 279 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_left
	step_end

# 290 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Cheren_Approaches_Starters:
# 291 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_down
# 292 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	walk_left
# 293 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 296 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Player_Faces_Starters:
# 297 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

# 300 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
Bianca_Faces_Starters:
# 301 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	face_down
	step_end

Cheren_Intro::
# 205 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: {PLAYER}! I heard from\n"
	.string "Professor Juniper. We can have a\l"
	.string "Pokémon?$"

Cheren_Waiting::
# 213 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "...\l"
	.string "...\n"
	.string "What's keeping Bianca?$"

Cheren_Time::
# 225 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "What time is it anyways?$"

Bianca_Arrives::
# 241 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: Am I a little late again?\n"
	.string "So-oooo-orry!$"

Cheren_Berating::
# 250 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Bianca...\n"
	.string "I've known for ten years that you have\l"
	.string "no sense of time, but...seriously...\l"
	.string "Today's the day we can get a Pokémon\l"
	.string "from Professor Juniper!$"

Bianca_Apology::
# 268 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: I know. Sorry, {PLAYER}. Sorry,\n"
	.string "Cheren.$"

Bianca_TimeToPick::
# 282 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Bianca: So, where are the Pokémon?\n"
	.string "They were delivered to {PLAYER}'s\l"
	.string "house, so {PLAYER} gets first pick.$"

Cheren_Response::
# 286 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "Cheren: Naturally.$"

Cheren_TimeToPick::
# 304 "data/maps/NuvemaTown_PlayersHouse_2F/scripts.pory"
	.string "The Pokémon are waiting for us inside\n"
	.string "that gift box.\n"
	.string "Ok, {PLAYER}, you go first and take a\l"
	.string "peek at the gift box.\n"
	.string "I want to meet the Pokémon right now!$"
