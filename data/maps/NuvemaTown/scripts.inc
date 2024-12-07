NuvemaTown_MapScripts::
# 37 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_OnTransition
# 38 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 42 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

NuvemaTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 39 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 0, NuvemaTown_EventScript_JuniperIntro
# 40 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_TOWN_STATE, 0, NuvemaTown_EventScript_PidoveCutscene
	.2byte 0

NuvemaTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 42 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 0, NuvemaTown_OnWarp_Intro
# 43 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_TOWN_STATE, 0, NuvemaTown_OnWarp_FirstExit
	.2byte 0


NuvemaTown_OnTransition::
# 47 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_VISITED_NUVEMA_TOWN
	end


NuvemaTown_OnWarp_Intro::
# 52 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NuvemaTown_OnWarp_Intro_Movement_0
# 53 "data/maps/NuvemaTown/scripts.pory"
	applymovement 2, NuvemaTown_OnWarp_Intro_Movement_0
# 54 "data/maps/NuvemaTown/scripts.pory"
	applymovement 3, NuvemaTown_OnWarp_Intro_Movement_0
# 55 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_PIDOVES
	return


NuvemaTown_OnWarp_FirstExit::
# 59 "data/maps/NuvemaTown/scripts.pory"
	setobjectxy 3, 17, 15
	return


NuvemaTown_EventScript_JuniperIntro::
# 63 "data/maps/NuvemaTown/scripts.pory"
	lockall
# 64 "data/maps/NuvemaTown/scripts.pory"
	special SpawnCameraObject
# 65 "data/maps/NuvemaTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, TRUE
# 66 "data/maps/NuvemaTown/scripts.pory"
	applymovement 1, NuvemaTown_LabToHouse
# 67 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_LabToHouse
# 68 "data/maps/NuvemaTown/scripts.pory"
	applymovement 4, NuvemaTown_OnWarp_Intro_Movement_0
# 69 "data/maps/NuvemaTown/scripts.pory"
	applymovement 5, NuvemaTown_OnWarp_Intro_Movement_0
# 70 "data/maps/NuvemaTown/scripts.pory"
	applymovement 6, NuvemaTown_OnWarp_Intro_Movement_0
# 71 "data/maps/NuvemaTown/scripts.pory"
	applymovement 7, NuvemaTown_OnWarp_Intro_Movement_0
# 72 "data/maps/NuvemaTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 73 "data/maps/NuvemaTown/scripts.pory"
	opendoor 18, 12
# 74 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 75 "data/maps/NuvemaTown/scripts.pory"
	applymovement 1, NuvemaTown_EnterHouse
# 76 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_EnterHouse
# 77 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 78 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 1
# 79 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_INTRO_JUNIPER
# 80 "data/maps/NuvemaTown/scripts.pory"
	clearflag FLAG_HIDE_NUVEMA_TOWN_PIDOVES
# 81 "data/maps/NuvemaTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 82 "data/maps/NuvemaTown/scripts.pory"
	hideobjectat 1, MAP_NUVEMA_TOWN
# 83 "data/maps/NuvemaTown/scripts.pory"
	closedoor 18, 12
# 84 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 85 "data/maps/NuvemaTown/scripts.pory"
	delay 30
# 86 "data/maps/NuvemaTown/scripts.pory"
	opendoor 18, 12
# 87 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 88 "data/maps/NuvemaTown/scripts.pory"
	showobjectat 1, MAP_NUVEMA_TOWN
# 89 "data/maps/NuvemaTown/scripts.pory"
	applymovement 1, NuvemaTown_ExitHouse
# 90 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 91 "data/maps/NuvemaTown/scripts.pory"
	closedoor 18, 12
# 92 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 93 "data/maps/NuvemaTown/scripts.pory"
	applymovement 1, NuvemaTown_WalkOffCamera
# 94 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 95 "data/maps/NuvemaTown/scripts.pory"
	removeobject 1
# 96 "data/maps/NuvemaTown/scripts.pory"
	warpsilent MAP_NUVEMA_TOWN_PLAYERS_HOUSE_2F, 4, 6
# 97 "data/maps/NuvemaTown/scripts.pory"
	waitstate
# 98 "data/maps/NuvemaTown/scripts.pory"
	releaseall
	return


NuvemaTown_EventScript_PidoveCutscene::
# 102 "data/maps/NuvemaTown/scripts.pory"
	lockall
# 103 "data/maps/NuvemaTown/scripts.pory"
	applymovement 3, NuvemaTown_EventScript_PidoveCutscene_Movement_0
# 104 "data/maps/NuvemaTown/scripts.pory"
	applymovement 4, NuvemaTown_EventScript_PidoveCutscene_Movement_1
# 105 "data/maps/NuvemaTown/scripts.pory"
	applymovement 5, NuvemaTown_EventScript_PidoveCutscene_Movement_2
# 106 "data/maps/NuvemaTown/scripts.pory"
	applymovement 6, NuvemaTown_EventScript_PidoveCutscene_Movement_2
# 107 "data/maps/NuvemaTown/scripts.pory"
	applymovement 7, NuvemaTown_EventScript_PidoveCutscene_Movement_3
# 108 "data/maps/NuvemaTown/scripts.pory"
	playse SE_M_RAZOR_WIND
# 109 "data/maps/NuvemaTown/scripts.pory"
	waitse
# 110 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 7
# 111 "data/maps/NuvemaTown/scripts.pory"
	removeobject 3
# 112 "data/maps/NuvemaTown/scripts.pory"
	removeobject 4
# 113 "data/maps/NuvemaTown/scripts.pory"
	removeobject 5
# 114 "data/maps/NuvemaTown/scripts.pory"
	removeobject 6
# 115 "data/maps/NuvemaTown/scripts.pory"
	removeobject 7
# 116 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 1
# 117 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_PIDOVES
# 118 "data/maps/NuvemaTown/scripts.pory"
	releaseall
	end


# 122 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_LabToHouse:
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 123 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 124 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 124 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 124 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 124 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 124 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 125 "data/maps/NuvemaTown/scripts.pory"
	face_up
	step_end

# 128 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EnterHouse:
# 129 "data/maps/NuvemaTown/scripts.pory"
	walk_up
	step_end

# 132 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_ExitHouse:
# 133 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end

# 136 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_WalkOffCamera:
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 137 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end

# 52 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnWarp_Intro_Movement_0:
# 52 "data/maps/NuvemaTown/scripts.pory"
	set_invisible
	step_end

# 103 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_PidoveCutscene_Movement_0:
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 103 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end

# 104 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_PidoveCutscene_Movement_1:
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
# 104 "data/maps/NuvemaTown/scripts.pory"
	walk_left
	step_end

# 105 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_PidoveCutscene_Movement_2:
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
# 105 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_southeast
	step_end

# 107 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_PidoveCutscene_Movement_3:
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
# 107 "data/maps/NuvemaTown/scripts.pory"
	walk_diag_northwest
	step_end
