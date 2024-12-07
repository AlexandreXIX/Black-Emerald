NuvemaTown_PlayersHouse_1F_MapScripts::
# 6 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 4, NuvemaTown_PlayersHouse_1F_MomApology
	.2byte 0

NuvemaTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 4, NuvemaTown_PlayersHouse_1F_Intro
	.2byte 0


NuvemaTown_PlayersHouse_1F_MomApology::
# 11 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setobjectxy 1, 6, 6
# 12 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, NuvemaTown_PlayersHouse_1F_MomApology_Movement_0
	return


NuvemaTown_PlayersHouse_1F_Intro::
# 17 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	special SpawnCameraObject
# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_PlayersHouse_1F_Intro_Movement_0
# 19 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 20 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_0
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_1
# 22 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 23 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_1
# 24 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_2
# 26 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_3
# 28 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 2, NuvemaTown_PlayersHouse_1F_Intro_Movement_2
# 29 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_4
# 31 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playse SE_PIN
# 32 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_3
# 33 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_4
# 35 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 36 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_5
# 37 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_5
# 38 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 39 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Intro_Text_6
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 3, NuvemaTown_PlayersHouse_1F_Intro_Movement_6
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 2, NuvemaTown_PlayersHouse_1F_Intro_Movement_7
# 42 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 2
# 43 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	removeobject 2
# 44 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	removeobject 3
# 45 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playse SE_EXIT
# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_PlayersHouse_1F_Intro_Movement_8
# 48 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 49 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, NuvemaTown_PlayersHouse_1F_Intro_Movement_9
# 51 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 1
# 52 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_PlayersHouse_1F_Intro_Movement_5
# 53 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_1
# 54 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, NuvemaTown_PlayersHouse_1F_Intro_Movement_10
# 55 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 1
# 56 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_2
# 57 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, NuvemaTown_PlayersHouse_1F_MomApology_Movement_0
# 58 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitmovement 1
# 59 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_3
# 60 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 61 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_4
# 62 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 63 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	switch VAR_RESULT
# 64 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	case MALE, NuvemaTown_PlayersHouse_1F_Intro_3
# 65 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	case FEMALE, NuvemaTown_PlayersHouse_1F_Intro_4
NuvemaTown_PlayersHouse_1F_Intro_1:
# 67 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	waitfanfare
# 68 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_XTRANS_GET
# 69 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_RECEIVED_XTRANS
# 70 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_5
# 71 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 5
# 72 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	special RemoveCameraObject
# 73 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	playbgm MUS_NUVEMA, FALSE
# 74 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	releaseall
	end

NuvemaTown_PlayersHouse_1F_Intro_3:
# 64 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_XTRANSCEIVER_BLUE
	goto NuvemaTown_PlayersHouse_1F_Intro_1

NuvemaTown_PlayersHouse_1F_Intro_4:
# 65 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_XTRANSCEIVER_RED
	goto NuvemaTown_PlayersHouse_1F_Intro_1


NuvemaTown_PlayersHouse_1F_EventScript_Mom::
# 79 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	lockall
# 80 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	compare VAR_NUVEMA_INTRO_STATE, 5
	goto_if_eq NuvemaTown_PlayersHouse_1F_EventScript_Mom_2
NuvemaTown_PlayersHouse_1F_EventScript_Mom_1:
# 81 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	releaseall
	end

NuvemaTown_PlayersHouse_1F_EventScript_Mom_2:
# 80 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox NuvemaTown_PlayersHouse_1F_Mom_Intro_5, MSGBOX_NPC
	goto NuvemaTown_PlayersHouse_1F_EventScript_Mom_1


# 12 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_MomApology_Movement_0:
# 12 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_right
	step_end

# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_0:
# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
	step_end

# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_1:
# 21 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_left
	step_end

# 28 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_2:
# 28 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 28 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_up
	step_end

# 32 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_3:
# 32 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_4:
# 34 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_up
	step_end

# 37 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_5:
# 37 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_left
	step_end

# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_6:
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 40 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
	step_end

# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_7:
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 41 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_down
	step_end

# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_8:
# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 47 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
	step_end

# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_9:
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 50 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_right
	step_end

# 54 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_Intro_Movement_10:
# 54 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	face_down
	step_end

NuvemaTown_PlayersHouse_1F_Intro_Text_0:
# 20 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: I'm very sorry about all the\n"
	.string "trouble, ma'am.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_1:
# 23 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Bianca: Well, um...\n"
	.string "We can clean up...$"

NuvemaTown_PlayersHouse_1F_Intro_Text_2:
# 24 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Mom: Cleaning up?\n"
	.string "No worries. I'll take care of it later.\p"
	.string "Shouldn't you be on your way to meet\n"
	.string "Professor Juniper?$"

NuvemaTown_PlayersHouse_1F_Intro_Text_3:
# 26 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: Yes, thank you!\n"
	.string "Please excuse us.\p"
	.string "Come on.\n"
	.string "Let's go thank Professor Juniper.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_4:
# 30 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Cheren: I'll be waiting in front of the\n"
	.string "Pokémon Research Lab.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_5:
# 36 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Bianca: Oh! Wait!\n"
	.string "I've gotta go home first.$"

NuvemaTown_PlayersHouse_1F_Intro_Text_6:
# 39 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Thanks for having us over!$"

NuvemaTown_PlayersHouse_1F_Mom_Intro_1::
# 85 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Mom: My, my, {PLAYER}.\p"
	.string "Pokémon battles are so lively,\n"
	.string "aren't they?\p"
	.string "I could hear the Pokémon's\n"
	.string "cries clear down here!$"

NuvemaTown_PlayersHouse_1F_Mom_Intro_2::
# 91 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Hm. That sure reminded me of my first\n"
	.string "Pokémon battle!$"

NuvemaTown_PlayersHouse_1F_Mom_Intro_3::
# 95 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Oh, and you know? After a battle,\n"
	.string "you need to rest your Pokémon!$"

NuvemaTown_PlayersHouse_1F_Mom_Intro_4::
# 99 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "Your Pokémon is looking great!\p"
	.string "Now, if you're out,\n"
	.string "don't forget your “cross-transceiver”!$"

NuvemaTown_PlayersHouse_1F_Mom_Intro_5::
# 105 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "You're going to thank the\n"
	.string "professor too, right?\l"
	.string "Better ge going, honey!$"
