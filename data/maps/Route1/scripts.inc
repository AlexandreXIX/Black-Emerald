# 1 "data/maps/Route1/scripts.pory"

# 2 "data/maps/Route1/scripts.pory"
.set LOCALID_BIRCH, 2
# 3 "data/maps/Route1/scripts.pory"
.set LOCALID_ZIGZAGOON, 4
# 4 "data/maps/Route1/scripts.pory"

# 5 "data/maps/Route1/scripts.pory"
Route1_MapScripts::
# 6 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
# 7 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_OnFrame
# 8 "data/maps/Route1/scripts.pory"
	.byte 0
# 9 "data/maps/Route1/scripts.pory"

# 10 "data/maps/Route1/scripts.pory"
Route1_OnTransition:
# 11 "data/maps/Route1/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data/maps/Route1/scripts.pory"
	end
# 13 "data/maps/Route1/scripts.pory"

# 14 "data/maps/Route1/scripts.pory"
Route1_OnFrame:
# 15 "data/maps/Route1/scripts.pory"
	.2byte 0
# 16 "data/maps/Route1/scripts.pory"

# 17 "data/maps/Route1/scripts.pory"
Route1_EventScript_StartBirchRescue::
# 18 "data/maps/Route1/scripts.pory"
	lockall
# 19 "data/maps/Route1/scripts.pory"
	playbgm MUS_HELP, TRUE
# 20 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_HelpMe, MSGBOX_DEFAULT
# 21 "data/maps/Route1/scripts.pory"
	closemessage
# 22 "data/maps/Route1/scripts.pory"
	setobjectxy LOCALID_BIRCH, 0, 15
# 23 "data/maps/Route1/scripts.pory"
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
# 24 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route1_Movement_EnterScene
# 25 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_BIRCH, Route1_Movement_BirchRunAway1
# 26 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route1_Movement_ZigzagoonChase1
# 27 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route1_Movement_ZigzagoonChaseInCircles
# 29 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_BIRCH, Route1_Movement_BirchRunInCircles
# 30 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 32 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 33 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route1_Movement_ZigzagoonFaceBirch
# 34 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_BIRCH, Route1_Movement_BirchFaceZigzagoon
# 35 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_PleaseHelp, MSGBOX_DEFAULT
# 37 "data/maps/Route1/scripts.pory"
	closemessage
# 38 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 2
# 39 "data/maps/Route1/scripts.pory"
	releaseall
# 40 "data/maps/Route1/scripts.pory"
	end
# 41 "data/maps/Route1/scripts.pory"

# 42 "data/maps/Route1/scripts.pory"
Route1_EventScript_PreventExitSouth::
# 43 "data/maps/Route1/scripts.pory"
	lockall
# 44 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_DontLeaveMe, MSGBOX_DEFAULT
# 45 "data/maps/Route1/scripts.pory"
	closemessage
# 46 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route1_Movement_PreventExitSouth
# 47 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 48 "data/maps/Route1/scripts.pory"
	releaseall
# 49 "data/maps/Route1/scripts.pory"
	end
# 50 "data/maps/Route1/scripts.pory"

# 51 "data/maps/Route1/scripts.pory"
Route1_EventScript_PreventExitWest::
# 52 "data/maps/Route1/scripts.pory"
	lockall
# 53 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_DontLeaveMe, MSGBOX_DEFAULT
# 54 "data/maps/Route1/scripts.pory"
	closemessage
# 55 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route1_Movement_PreventExitWest
# 56 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route1/scripts.pory"
	releaseall
# 58 "data/maps/Route1/scripts.pory"
	end
# 59 "data/maps/Route1/scripts.pory"

# 60 "data/maps/Route1/scripts.pory"
Route1_EventScript_PreventExitNorth::
# 61 "data/maps/Route1/scripts.pory"
	lockall
# 62 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_DontLeaveMe, MSGBOX_DEFAULT
# 63 "data/maps/Route1/scripts.pory"
	closemessage
# 64 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route1_Movement_PreventExitNorth
# 65 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route1/scripts.pory"
	releaseall
# 67 "data/maps/Route1/scripts.pory"
	end
# 68 "data/maps/Route1/scripts.pory"

# 69 "data/maps/Route1/scripts.pory"
Route1_Movement_PreventExitSouth:
# 70 "data/maps/Route1/scripts.pory"
	walk_up
# 71 "data/maps/Route1/scripts.pory"
	step_end
# 72 "data/maps/Route1/scripts.pory"

# 73 "data/maps/Route1/scripts.pory"
Route1_Movement_PreventExitWest:
# 74 "data/maps/Route1/scripts.pory"
	walk_right
# 75 "data/maps/Route1/scripts.pory"
	step_end
# 76 "data/maps/Route1/scripts.pory"

# 77 "data/maps/Route1/scripts.pory"
Route1_Movement_PreventExitNorth:
# 78 "data/maps/Route1/scripts.pory"
	walk_down
# 79 "data/maps/Route1/scripts.pory"
	step_end
# 80 "data/maps/Route1/scripts.pory"

# 81 "data/maps/Route1/scripts.pory"
Route1_Movement_ZigzagoonChaseInCircles:
# 82 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 83 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 84 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 85 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 86 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 87 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 88 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 89 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 90 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 91 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 92 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 93 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 94 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 95 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 96 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 97 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 98 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 99 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 100 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 101 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 102 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 103 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 104 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 105 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 106 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 107 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 108 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 109 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 110 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 111 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route1/scripts.pory"
	step_end
# 113 "data/maps/Route1/scripts.pory"

# 114 "data/maps/Route1/scripts.pory"
Route1_Movement_ZigzagoonChase1:
# 115 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 116 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 117 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 118 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 119 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 120 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 121 "data/maps/Route1/scripts.pory"
	step_end
# 122 "data/maps/Route1/scripts.pory"

# 123 "data/maps/Route1/scripts.pory"
@ Leftover data? This command is unused.
# 124 "data/maps/Route1/scripts.pory"
	step_end
# 125 "data/maps/Route1/scripts.pory"

# 126 "data/maps/Route1/scripts.pory"
Route1_Movement_ZigzagoonFaceBirch:
# 127 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_left
# 128 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_left
# 129 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_left
# 130 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_left
# 131 "data/maps/Route1/scripts.pory"
	step_end
# 132 "data/maps/Route1/scripts.pory"

# 133 "data/maps/Route1/scripts.pory"
Route1_Movement_EnterScene:
# 134 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 135 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 136 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 137 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 138 "data/maps/Route1/scripts.pory"
	walk_in_place_faster_left
# 139 "data/maps/Route1/scripts.pory"
	step_end
# 140 "data/maps/Route1/scripts.pory"

# 141 "data/maps/Route1/scripts.pory"
Route1_Movement_BirchRunInCircles:
# 142 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 143 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 146 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 147 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 148 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 149 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 150 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 151 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 153 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 154 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 155 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 156 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 157 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 158 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 159 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 160 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 161 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 162 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 163 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 164 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 166 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 167 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 168 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 169 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 170 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 171 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 172 "data/maps/Route1/scripts.pory"
	step_end
# 173 "data/maps/Route1/scripts.pory"

# 174 "data/maps/Route1/scripts.pory"
Route1_Movement_BirchRunAway1:
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 177 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 178 "data/maps/Route1/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 180 "data/maps/Route1/scripts.pory"
	walk_fast_up
# 181 "data/maps/Route1/scripts.pory"
	step_end
# 182 "data/maps/Route1/scripts.pory"

# 183 "data/maps/Route1/scripts.pory"
@ Leftover data? This command is unused.
# 184 "data/maps/Route1/scripts.pory"
	step_end
# 185 "data/maps/Route1/scripts.pory"

# 186 "data/maps/Route1/scripts.pory"
Route1_Movement_BirchFaceZigzagoon:
# 187 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_right
# 188 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_right
# 189 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_right
# 190 "data/maps/Route1/scripts.pory"
	walk_in_place_fast_right
# 191 "data/maps/Route1/scripts.pory"
	step_end
# 192 "data/maps/Route1/scripts.pory"

# 193 "data/maps/Route1/scripts.pory"
Route1_Movement_Unused1:
# 194 "data/maps/Route1/scripts.pory"
	walk_up
# 195 "data/maps/Route1/scripts.pory"
	walk_up
# 196 "data/maps/Route1/scripts.pory"
	step_end
# 197 "data/maps/Route1/scripts.pory"

# 198 "data/maps/Route1/scripts.pory"
Route1_Movement_Unused2:
# 199 "data/maps/Route1/scripts.pory"
	walk_up
# 200 "data/maps/Route1/scripts.pory"
	walk_left
# 201 "data/maps/Route1/scripts.pory"
	walk_up
# 202 "data/maps/Route1/scripts.pory"
	step_end
# 203 "data/maps/Route1/scripts.pory"

# 204 "data/maps/Route1/scripts.pory"
Route1_EventScript_Youngster::
# 205 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 206 "data/maps/Route1/scripts.pory"
	end
# 207 "data/maps/Route1/scripts.pory"

# 208 "data/maps/Route1/scripts.pory"
Route1_EventScript_Boy::
# 209 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 210 "data/maps/Route1/scripts.pory"
	end
# 211 "data/maps/Route1/scripts.pory"

# 212 "data/maps/Route1/scripts.pory"
Route1_EventScript_RouteSign::
# 213 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
# 214 "data/maps/Route1/scripts.pory"
	end
# 215 "data/maps/Route1/scripts.pory"

# 216 "data/maps/Route1/scripts.pory"
Route1_EventScript_BirchsBag::
# 217 "data/maps/Route1/scripts.pory"
	lock
# 218 "data/maps/Route1/scripts.pory"
	faceplayer
# 219 "data/maps/Route1/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 220 "data/maps/Route1/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 221 "data/maps/Route1/scripts.pory"
	fadescreen FADE_TO_BLACK
# 222 "data/maps/Route1/scripts.pory"
	removeobject LOCALID_ZIGZAGOON
# 223 "data/maps/Route1/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
# 224 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 225 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 226 "data/maps/Route1/scripts.pory"
	special ChooseStarter
# 227 "data/maps/Route1/scripts.pory"
	waitstate
# 228 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_BIRCH, Route1_Movement_BirchApproachPlayer
# 229 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_YouSavedMe, MSGBOX_DEFAULT
# 231 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 232 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE_1_BIRCH_ZIGZAGOON_BATTLE
# 233 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_NUVEMA_TOWN_BIRCHS_LAB_BIRCH
# 234 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE_1_BIRCH_STARTERS_BAG
# 235 "data/maps/Route1/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 236 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 3
# 237 "data/maps/Route1/scripts.pory"
	checkplayergender
# 238 "data/maps/Route1/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route1_EventScript_HideMayInBedroom
# 239 "data/maps/Route1/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route1_EventScript_HideHilbertInBedroom
# 240 "data/maps/Route1/scripts.pory"
	warp MAP_NUVEMA_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 241 "data/maps/Route1/scripts.pory"
	waitstate
# 242 "data/maps/Route1/scripts.pory"
	release
# 243 "data/maps/Route1/scripts.pory"
	end
# 244 "data/maps/Route1/scripts.pory"

# 245 "data/maps/Route1/scripts.pory"
Route1_EventScript_HideMayInBedroom::
# 246 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 247 "data/maps/Route1/scripts.pory"
	return
# 248 "data/maps/Route1/scripts.pory"

# 249 "data/maps/Route1/scripts.pory"
Route1_EventScript_HideHilbertInBedroom::
# 250 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_PLAYERS_HOUSE_RIVAL_BEDROOM
# 251 "data/maps/Route1/scripts.pory"
	return
# 252 "data/maps/Route1/scripts.pory"

# 253 "data/maps/Route1/scripts.pory"
Route1_Movement_BirchApproachPlayer:
# 254 "data/maps/Route1/scripts.pory"
	walk_right
# 255 "data/maps/Route1/scripts.pory"
	step_end
# 256 "data/maps/Route1/scripts.pory"

# 257 "data/maps/Route1/scripts.pory"
Route1_Text_HelpMe:
# 258 "data/maps/Route1/scripts.pory"
	.string "H-help me!$"
# 259 "data/maps/Route1/scripts.pory"

# 260 "data/maps/Route1/scripts.pory"
Route1_Text_PleaseHelp:
# 261 "data/maps/Route1/scripts.pory"
	.string "Hello! You over there!\n"
# 262 "data/maps/Route1/scripts.pory"
	.string "Please! Help!\p"
# 263 "data/maps/Route1/scripts.pory"
	.string "In my BAG!\n"
# 264 "data/maps/Route1/scripts.pory"
	.string "There's a POKé BALL!$"
# 265 "data/maps/Route1/scripts.pory"

# 266 "data/maps/Route1/scripts.pory"
Route1_Text_DontLeaveMe:
# 267 "data/maps/Route1/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 268 "data/maps/Route1/scripts.pory"
	.string "Don't leave me like this!$"
# 269 "data/maps/Route1/scripts.pory"

# 270 "data/maps/Route1/scripts.pory"
Route1_Text_YouSavedMe:
# 271 "data/maps/Route1/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 272 "data/maps/Route1/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 273 "data/maps/Route1/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 274 "data/maps/Route1/scripts.pory"
	.string "You saved me.\n"
# 275 "data/maps/Route1/scripts.pory"
	.string "Thanks a lot!\p"
# 276 "data/maps/Route1/scripts.pory"
	.string "Oh?\p"
# 277 "data/maps/Route1/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 278 "data/maps/Route1/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 279 "data/maps/Route1/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 280 "data/maps/Route1/scripts.pory"

# 281 "data/maps/Route1/scripts.pory"
Route1_Text_TakeTiredPokemonToPokeCenter:
# 282 "data/maps/Route1/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 283 "data/maps/Route1/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 284 "data/maps/Route1/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 285 "data/maps/Route1/scripts.pory"
	.string "TOWN right close by.$"
# 286 "data/maps/Route1/scripts.pory"

# 287 "data/maps/Route1/scripts.pory"
Route1_Text_WildPokemonInTallGrass:
# 288 "data/maps/Route1/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 289 "data/maps/Route1/scripts.pory"
	.string "tall grass.\p"
# 290 "data/maps/Route1/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 291 "data/maps/Route1/scripts.pory"
	.string "to go into the tall grass and search.$"
# 292 "data/maps/Route1/scripts.pory"

# 293 "data/maps/Route1/scripts.pory"
Route1_Text_RouteSign:
# 294 "data/maps/Route1/scripts.pory"
	.string "ROUTE 1\n"
# 295 "data/maps/Route1/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"

Route1_HideTransition::
# 302 "data/maps/Route1/scripts.pory"
	lockall
# 303 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 304 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 1
# 305 "data/maps/Route1/scripts.pory"
	releaseall
	end


Route1_ShowTransition::
# 310 "data/maps/Route1/scripts.pory"
	lockall
# 311 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 312 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 0
# 313 "data/maps/Route1/scripts.pory"
	releaseall
	end

