# 1 "data/maps/NuvemaTown/scripts.pory"

# 2 "data/maps/NuvemaTown/scripts.pory"
.set LOCALID_JUNIPER, 1
# 3 "data/maps/NuvemaTown/scripts.pory"

# 4 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_MapScripts::
# 5 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_OnTransition
# 6 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_OnFrame
# 7 "data/maps/NuvemaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NuvemaTown_OnWarp
# 8 "data/maps/NuvemaTown/scripts.pory"
	.byte 0
# 9 "data/maps/NuvemaTown/scripts.pory"

# 10 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_TOWN_STATE
# 11 "data/maps/NuvemaTown/scripts.pory"
	@ 1: Met Rival
# 12 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Saving Birch
# 13 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Received Pokedex
# 14 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Received Running Shoes
# 15 "data/maps/NuvemaTown/scripts.pory"

# 16 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_INTRO_STATE
# 17 "data/maps/NuvemaTown/scripts.pory"
	@ 1: End of new game sequence
# 18 "data/maps/NuvemaTown/scripts.pory"
	@ 1: Juniper Walked
# 19 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Meet the Rivals
# 20 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Picked Starter
# 21 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Finished battles
# 22 "data/maps/NuvemaTown/scripts.pory"

# 23 "data/maps/NuvemaTown/scripts.pory"

# 24 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_HOUSES_STATE_MAY
# 25 "data/maps/NuvemaTown/scripts.pory"
	@                    and VAR_NUVEMA_HOUSES_STATE_HILBERT
# 26 "data/maps/NuvemaTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 27 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 28 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 29 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 30 "data/maps/NuvemaTown/scripts.pory"
	@ 5: Exited house after above event
# 31 "data/maps/NuvemaTown/scripts.pory"

# 32 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_RIVAL_STATE
# 33 "data/maps/NuvemaTown/scripts.pory"
	@ 1: Never occurs
# 34 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 35 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Met Rival
# 36 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Received Pokedex
# 37 "data/maps/NuvemaTown/scripts.pory"

# 38 "data/maps/NuvemaTown/scripts.pory"

# 39 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnTransition:
# 40 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_VISITED_NUVEMA_TOWN
# 41 "data/maps/NuvemaTown/scripts.pory"
	end
# 42 "data/maps/NuvemaTown/scripts.pory"

# 43 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_LeftLabAfterDexUpgrade::
# 44 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 45 "data/maps/NuvemaTown/scripts.pory"
	return
# 46 "data/maps/NuvemaTown/scripts.pory"

# 47 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnFrame:
# 48 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_INTRO_STATE, 0, NuvemaTown_EventScript_JuniperIntro
# 49 "data/maps/NuvemaTown/scripts.pory"
	.2byte 0
# 50 "data/maps/NuvemaTown/scripts.pory"

# 51 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnWarp:
# 52 "data/maps/NuvemaTown/scripts.pory"
	.2byte 0

NuvemaTown_EventScript_JuniperIntro::
# 55 "data/maps/NuvemaTown/scripts.pory"
	lockall
# 56 "data/maps/NuvemaTown/scripts.pory"
	special SpawnCameraObject
# 57 "data/maps/NuvemaTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, TRUE
# 58 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_LabToHouse
# 59 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_LabToHouse
# 60 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/NuvemaTown/scripts.pory"
	opendoor 12, 12
# 62 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 63 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_EnterHouse
# 64 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_EnterHouse
# 65 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_NUVEMA_INTRO_STATE, 1
# 67 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_PLAYERS_HOUSE_TRUCK
# 68 "data/maps/NuvemaTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 69 "data/maps/NuvemaTown/scripts.pory"
	hideobjectat LOCALID_JUNIPER, MAP_NUVEMA_TOWN
# 70 "data/maps/NuvemaTown/scripts.pory"
	closedoor 12, 12
# 71 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 72 "data/maps/NuvemaTown/scripts.pory"
	opendoor 12, 12
# 73 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 74 "data/maps/NuvemaTown/scripts.pory"
	showobjectat LOCALID_JUNIPER, MAP_NUVEMA_TOWN
# 75 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_ExitHouse
# 76 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 77 "data/maps/NuvemaTown/scripts.pory"
	closedoor 12, 12
# 78 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 79 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_WalkOffCamera
# 80 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 81 "data/maps/NuvemaTown/scripts.pory"
	removeobject LOCALID_JUNIPER
# 82 "data/maps/NuvemaTown/scripts.pory"
	warpsilent MAP_NUVEMA_TOWN_PLAYERS_HOUSE_2F, 4, 6
# 83 "data/maps/NuvemaTown/scripts.pory"
	waitstate
# 84 "data/maps/NuvemaTown/scripts.pory"
	releaseall
	return


# 87 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_LabToHouse:
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 88 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 89 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 89 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 89 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 89 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 89 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 90 "data/maps/NuvemaTown/scripts.pory"
	face_up
	step_end

# 93 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EnterHouse:
# 94 "data/maps/NuvemaTown/scripts.pory"
	walk_up
	step_end

# 97 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_ExitHouse:
# 98 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end

# 101 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_WalkOffCamera:
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 102 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end
