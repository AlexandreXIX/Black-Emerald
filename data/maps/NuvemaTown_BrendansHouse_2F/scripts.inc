# 1 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
.set LOCALID_STARTERS, 1
# 3 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
.set LOCALID_CHEREN, 2
# 4 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
.set LOCALID_BIANCA, 3
# 5 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 6 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_MapScripts::
# 7 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_BrendansHouse_2F_OnTransition
# 8 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_BrendansHouse_2F_OnFrame
# 9 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_BrendansHouse_2F_OnWarp
# 10 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 11 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 12 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_OnTransition:
# 13 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_lt VAR_NUVEMA_RIVAL_STATE, 2, NuvemaTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 14 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_ge VAR_NUVEMA_RIVAL_STATE, 3, NuvemaTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 15 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_NUVEMA_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 16 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 17 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 18 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 19 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 20 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
# 21 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, NuvemaTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 22 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, NuvemaTown_BrendansHouse_2F_EventScript_Ret
# 23 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto NuvemaTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 24 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 25 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 26 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 27 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, NuvemaTown_BrendansHouse_2F_EventScript_Ret
# 28 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	@ Odd that the MaysHouse equivalent was used below instead
# 29 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, NuvemaTown_MaysHouse_2F_EventScript_Ret
# 30 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 0, 2
# 31 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 32 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 33 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 34 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_Ret::
# 35 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 36 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 37 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
# 38 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 39 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, NuvemaTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 40 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 41 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 42 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
# 43 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_RIVAL_STATE, 2
# 44 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 45 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 46 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_OnFrame:
# 47 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_NUVEMA_TOWN_STATE, 1, NuvemaTown_BrendansHouse_2F_EventScript_IntroCutscene
# 48 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 49 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 50 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_OnWarp:
# 51 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
    call NuvemaTown_BrendansHouse_2F_EventScript_IntroCutscene
# 52 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, NuvemaTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 53 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 54 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 55 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 56 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 57 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 58 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 59 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 60 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
# 61 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	lockall
# 62 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_NUVEMA_RIVAL_STATE, 2, NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendan
# 63 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 64 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 65 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 66 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 67 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendan::
# 68 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 69 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_RIVAL
# 70 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanEnters
# 71 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 72 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 73 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 74 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 75 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 76 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 78 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 79 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 80 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 81 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 82 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 83 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_RIVAL_STATE, 3
# 84 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 85 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_NUVEMA_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 86 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 1
# 87 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 88 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 90 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 91 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 92 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
# 93 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 94 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 95 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 96 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 97 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 98 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 99 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 100 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 101 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 102 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 103 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 104 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
# 105 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 106 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 107 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 108 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 109 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 110 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 111 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 112 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 113 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 114 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 115 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 116 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
# 117 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 118 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 119 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 120 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 121 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 122 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 123 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 124 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 125 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 126 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 127 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 128 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
# 129 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 130 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 131 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 132 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 133 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 134 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 135 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 136 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 137 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	return
# 138 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 139 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanEnters:
# 140 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 141 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 142 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 143 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 144 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 145 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
# 146 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 147 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 148 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 149 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 150 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 151 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 152 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 153 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
# 154 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 155 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 156 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 157 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 158 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 159 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 160 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 162 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 163 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 164 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
# 165 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 166 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 167 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 168 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 169 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 170 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 171 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 172 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 173 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 174 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
# 175 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 176 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 177 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 178 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 179 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 180 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
# 181 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 182 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 183 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 184 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 185 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 186 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 187 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 188 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 189 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
# 190 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 191 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 192 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 193 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 194 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 195 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 196 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 197 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
# 198 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 199 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 200 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 201 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 202 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 203 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 204 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
# 205 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 206 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 207 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 208 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 209 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 210 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 211 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 212 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 213 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 214 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 215 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
# 216 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 217 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 218 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 219 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 220 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 221 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 222 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 223 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 224 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
# 225 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 226 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 227 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 228 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 229 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 230 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 231 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 232 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 233 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
# 234 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 235 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 236 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 237 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 238 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 239 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 240 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 241 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
# 242 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 243 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 244 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 245 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	step_end
# 246 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 247 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_PC::
# 248 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	lockall
# 249 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 250 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, NuvemaTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 251 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, NuvemaTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 252 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 253 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 254 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 255 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 256 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 257 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 258 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 259 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 260 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 261 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 262 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 263 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 264 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 265 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 266 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 267 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 268 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 269 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 270 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 271 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
NuvemaTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 272 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 273 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 274 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 275 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 276 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 277 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 278 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 279 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 280 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 281 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 282 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	end
# 283 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 284 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped:
# 285 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 286 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 287 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 288 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
# 289 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 290 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 291 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 292 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 293 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 294 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 295 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 296 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 297 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 298 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 299 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 300 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 301 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 302 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 303 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 304 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 305 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 306 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 307 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 308 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "UNOVA region map.$"
# 309 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"

# 310 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 311 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 312 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 313 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

NuvemaTown_BrendansHouse_2F_EventScript_IntroCutscene::
# 317 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	lockall
# 318 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Approaches
# 319 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 320 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Cheren_Intro
# 321 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 322 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SET_WALL_CLOCK
# 323 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 2
# 324 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_BIANCA
# 325 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Climbs_Stairs
# 326 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 327 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Bianca_Arrives
# 328 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Meets_Bianca
# 329 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 330 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Cheren_Berating
# 331 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Enters
# 332 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 333 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Faces_Group
# 334 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 335 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Group
# 336 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 337 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Bianca_Apology
# 338 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_BIANCA, Bianca_Approaches_Starters
# 339 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 340 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Bianca
# 341 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 342 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Bianca_TimeToPick
# 343 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Cheren_Response
# 344 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_CHEREN, Cheren_Approaches_Starters
# 345 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 346 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_Faces_Starters
# 347 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 348 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	msgbox Cheren_TimeToPick
# 349 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
	return


NuvemaTown_BrendansHouse_2F_EventScript_StarterBag::
# 353 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	lockall
# 354 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 355 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 356 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	special ChooseStarter
# 357 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 358 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	special SetUnlockedPokedexFlags
# 359 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 360 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	releaseall
	return


# 363 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Cheren_Approaches:
# 364 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 365 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_left
	step_end

# 372 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Bianca_Climbs_Stairs:
# 373 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
	step_end

# 380 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Cheren_Meets_Bianca:
# 381 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_right
# 382 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_up
	step_end

# 389 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Bianca_Enters:
# 390 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 391 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 391 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 391 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 391 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 392 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
	step_end

# 395 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Cheren_Faces_Group:
# 396 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_player
	step_end

# 399 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Player_Faces_Group:
# 400 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_up
	step_end

# 407 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Bianca_Approaches_Starters:
# 408 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 409 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 409 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 410 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_player
	step_end

# 413 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Player_Faces_Bianca:
# 414 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_left
	step_end

# 425 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Cheren_Approaches_Starters:
# 426 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 427 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	walk_down
	step_end

# 430 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
Player_Faces_Starters:
# 431 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	face_down
	step_end

Cheren_Intro::
# 368 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Cheren: {PLAYER}! I heard from\n"
	.string "Professor Juniper. We can have a\l"
	.string "Pokémon?\l"
	.string "...\l"
	.string "...\l"
	.string "What's keeping Bianca? What time is it\l"
	.string "anyways?$"

Bianca_Arrives::
# 376 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Bianca: Am I a little late again?\n"
	.string "So-oooo-orry!$"

Cheren_Berating::
# 385 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Cheren: Bianca... I've known for ten\n"
	.string "years that you have no sense of time,\l"
	.string "but...seriously... Today's the day we can\l"
	.string "get a Pokémon from Professor Juniper!$"

Bianca_Apology::
# 403 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Bianca: I know. Sorry, {PLAYER}. Sorry,\n"
	.string "Cheren.$"

Bianca_TimeToPick::
# 417 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Bianca: So, where are the Pokémon? They\n"
	.string "were delivered to Player's house, so\l"
	.string "{PLAYER} gets first pick.$"

Cheren_Response::
# 421 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "Cheren: Naturally.$"

Cheren_TimeToPick::
# 434 "data/maps/NuvemaTown_BrendansHouse_2F/scripts.pory"
	.string "The Pokémon are waiting for us inside\n"
	.string "that gift box. Ok, {PLAYER}, you go\l"
	.string "first and take a peek at the gift box. I\l"
	.string "want to meet the Pokémon right now!$"
