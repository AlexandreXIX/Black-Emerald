NuvemaTown_PlayersHouse_1F_MapScripts::
# 6 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_PlayersHouse_1F_OnTransition
# 7 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 4, NuvemaTown_PlayersHouse_1F_Intro
	.2byte 0


NuvemaTown_PlayersHouse_1F_OnTransition::
# 12 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	compare VAR_NUVEMA_INTRO_STATE, 4
	goto_if_eq NuvemaTown_PlayersHouse_1F_OnTransition_1
	return

NuvemaTown_PlayersHouse_1F_OnTransition_1:
# 13 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setobjectxy 1, 6, 6
# 14 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, NuvemaTown_PlayersHouse_1F_OnTransition_Movement_0
	return


NuvemaTown_PlayersHouse_1F_Intro::
# 20 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_PlayersHouse_1F_Intro_Movement_0
# 22 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 23 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_0
# 24 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_1
# 25 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 26 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_1
# 27 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_2
# 29 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_3
# 31 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 2, NuvemaTown_PlayersHouse_1F_Intro_Movement_2
# 32 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 33 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_4
# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_3
# 35 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 36 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_4
# 37 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_5
# 39 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_5
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_6
# 42 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_6
# 43 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 2, NuvemaTown_PlayersHouse_1F_Intro_Movement_0
# 44 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 2
# 45 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	removeobject 2
# 46 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	removeobject 3
# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playse SE_EXIT
# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_PlayersHouse_1F_Intro_Movement_7
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 51 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 52 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitfanfare
# 53 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 54 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitfanfare
# 55 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 56 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	switch VAR_RESULT
# 57 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	case MALE, NuvemaTown_PlayersHouse_1F_Intro_3
# 58 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	case FEMALE, NuvemaTown_PlayersHouse_1F_Intro_4
NuvemaTown_PlayersHouse_1F_Intro_1:
# 60 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitfanfare
# 61 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_XTRANS_GET
# 62 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_RECEIVED_XTRANS
# 64 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 5
# 65 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	special RemoveCameraObject
# 66 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	releaseall
	end

NuvemaTown_PlayersHouse_1F_Intro_3:
# 57 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_XTRANSCEIVER_BLUE
	goto NuvemaTown_PlayersHouse_1F_Intro_1

NuvemaTown_PlayersHouse_1F_Intro_4:
# 58 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_XTRANSCEIVER_RED
	goto NuvemaTown_PlayersHouse_1F_Intro_1


NuvemaTown_PlayersHouse_1F_EventScript_Mom::
# 71 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	lockall
# 72 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_XTRANS
# 73 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
# 74 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 75 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILBERT
# 76 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
# 77 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 78 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	clearfullscreenimage
# 79 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 80 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	delay 60
# 81 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 82 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILDA
# 83 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
# 84 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 85 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	clearfullscreenimage
# 86 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 87 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	delay 60
# 88 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 89 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILDA
# 90 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILBERT
# 91 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
# 92 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 93 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	clearfullscreenimage
# 94 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 95 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	delay 60
# 96 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 97 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILBERT
# 98 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	drawfullscreenimage SCENEHILDA
# 99 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
# 100 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 101 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	clearfullscreenimage
# 102 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 103 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	releaseall
	end


# 14 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_OnTransition_Movement_0:
# 14 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_right
	step_end

# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_0:
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
	step_end

# 24 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_1:
# 24 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_left
	step_end

# 31 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_2:
# 31 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 31 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_up
	step_end

# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_3:
# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 36 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_4:
# 36 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_up
	step_end

# 39 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_5:
# 39 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_left
	step_end

# 42 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_6:
# 42 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 42 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
	step_end

# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_7:
# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
	step_end

NuvemaTown_PlayersHouse_1F_Intro_Text_0:
# 23 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: I'm very sorry about all the\n"
	.string "trouble, ma'am.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_1:
# 26 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Bianca: Well, um...\n"
	.string "We can clean up...$"

NuvemaTown_PlayersHouse_1F_Intro_Text_2:
# 27 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Mom: Cleaning up?\n"
	.string "No worries. I'll take care of it later.\p"
	.string "Shouldn't you be on your way to meet\n"
	.string "Professor Juniper?$"

NuvemaTown_PlayersHouse_1F_Intro_Text_3:
# 29 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: Yes, thank you!\n"
	.string "Please excuse us.\p"
	.string "Come on.\n"
	.string "Let's go thank Professor Juniper.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_4:
# 33 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: I'll be waiting in front of the\n"
	.string "Pokémon Research Lab.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_5:
# 38 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Bianca: Oh! Wait!\n"
	.string "I've gotta go home first.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_6:
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Thanks for having us over!$"

Players_Mom::
# 107 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Let's test your Xtransceiver...$"

Players_Phone::
# 111 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Phone Message Box$"

Players_Video::
# 115 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Can you see this?$"
