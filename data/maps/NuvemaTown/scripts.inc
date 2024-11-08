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
	@ 1: Intro Sequence (Male)
# 18 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Intro Sequence (Female)
# 19 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Entered house
# 20 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Told to go set clock
# 21 "data/maps/NuvemaTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 22 "data/maps/NuvemaTown/scripts.pory"
	@ 6: Set clock
# 23 "data/maps/NuvemaTown/scripts.pory"
	@ 7: Told to go meet rival
# 24 "data/maps/NuvemaTown/scripts.pory"

# 25 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_HOUSES_STATE_MAY
# 26 "data/maps/NuvemaTown/scripts.pory"
	@                    and VAR_NUVEMA_HOUSES_STATE_BRENDAN
# 27 "data/maps/NuvemaTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 28 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 29 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 30 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 31 "data/maps/NuvemaTown/scripts.pory"
	@ 5: Exited house after above event
# 32 "data/maps/NuvemaTown/scripts.pory"

# 33 "data/maps/NuvemaTown/scripts.pory"
	@ State descriptions for VAR_NUVEMA_RIVAL_STATE
# 34 "data/maps/NuvemaTown/scripts.pory"
	@ 1: Never occurs
# 35 "data/maps/NuvemaTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 36 "data/maps/NuvemaTown/scripts.pory"
	@ 3: Met Rival
# 37 "data/maps/NuvemaTown/scripts.pory"
	@ 4: Received Pokedex
# 38 "data/maps/NuvemaTown/scripts.pory"

# 39 "data/maps/NuvemaTown/scripts.pory"

# 40 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnTransition:
# 41 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_VISITED_NUVEMA_TOWN
# 42 "data/maps/NuvemaTown/scripts.pory"
	end
# 43 "data/maps/NuvemaTown/scripts.pory"

# 44 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EventScript_LeftLabAfterDexUpgrade::
# 45 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 46 "data/maps/NuvemaTown/scripts.pory"
	return
# 47 "data/maps/NuvemaTown/scripts.pory"

# 48 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnFrame:
# 49 "data/maps/NuvemaTown/scripts.pory"
	map_script_2 VAR_NUVEMA_TOWN_STATE, 0, NuvemaTown_EventScript_JuniperIntro
# 50 "data/maps/NuvemaTown/scripts.pory"
	.2byte 0
# 51 "data/maps/NuvemaTown/scripts.pory"

# 52 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_OnWarp:
# 53 "data/maps/NuvemaTown/scripts.pory"
	.2byte 0

NuvemaTown_EventScript_JuniperIntro::
# 56 "data/maps/NuvemaTown/scripts.pory"
	lockall
# 57 "data/maps/NuvemaTown/scripts.pory"
	special SpawnCameraObject
# 58 "data/maps/NuvemaTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, TRUE
# 59 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_LabToHouse
# 60 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_LabToHouse
# 61 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 62 "data/maps/NuvemaTown/scripts.pory"
	opendoor 12, 12
# 63 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 64 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_EnterHouse
# 65 "data/maps/NuvemaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, NuvemaTown_EnterHouse
# 66 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 67 "data/maps/NuvemaTown/scripts.pory"
	setvar VAR_NUVEMA_TOWN_STATE, 1
# 68 "data/maps/NuvemaTown/scripts.pory"
	setflag FLAG_HIDE_NUVEMA_TOWN_BRENDANS_HOUSE_TRUCK
# 69 "data/maps/NuvemaTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 70 "data/maps/NuvemaTown/scripts.pory"
	hideobjectat LOCALID_JUNIPER, MAP_NUVEMA_TOWN
# 71 "data/maps/NuvemaTown/scripts.pory"
	closedoor 12, 12
# 72 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 73 "data/maps/NuvemaTown/scripts.pory"
	opendoor 12, 12
# 74 "data/maps/NuvemaTown/scripts.pory"
	waitdooranim
# 75 "data/maps/NuvemaTown/scripts.pory"
	showobjectat LOCALID_JUNIPER, MAP_NUVEMA_TOWN
# 76 "data/maps/NuvemaTown/scripts.pory"
	applymovement LOCALID_JUNIPER, NuvemaTown_WalkOffCamera
# 77 "data/maps/NuvemaTown/scripts.pory"
	waitmovement 0
# 78 "data/maps/NuvemaTown/scripts.pory"
	removeobject LOCALID_JUNIPER
# 79 "data/maps/NuvemaTown/scripts.pory"
	warpsilent MAP_NUVEMA_TOWN_BRENDANS_HOUSE_2F, 4, 6
# 80 "data/maps/NuvemaTown/scripts.pory"
	waitstate
# 81 "data/maps/NuvemaTown/scripts.pory"
	releaseall
	return


# 84 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_LabToHouse:
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 85 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 86 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 86 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 86 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 86 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 86 "data/maps/NuvemaTown/scripts.pory"
	walk_right
# 87 "data/maps/NuvemaTown/scripts.pory"
	face_up
	step_end

# 90 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_EnterHouse:
# 91 "data/maps/NuvemaTown/scripts.pory"
	walk_up
	step_end

# 94 "data/maps/NuvemaTown/scripts.pory"
NuvemaTown_WalkOffCamera:
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
# 95 "data/maps/NuvemaTown/scripts.pory"
	walk_down
	step_end
