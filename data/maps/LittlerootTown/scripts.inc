# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_JUNIPER, 1
# 3 "data/maps/LittlerootTown/scripts.pory"

# 4 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 5 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 6 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 7 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 8 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 9 "data/maps/LittlerootTown/scripts.pory"

# 10 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 11 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 12 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 13 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 14 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 15 "data/maps/LittlerootTown/scripts.pory"

# 16 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Intro Sequence (Male)
# 18 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Intro Sequence (Female)
# 19 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 23 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 24 "data/maps/LittlerootTown/scripts.pory"

# 25 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 26 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 27 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 28 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 29 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 30 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 32 "data/maps/LittlerootTown/scripts.pory"

# 33 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 35 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 36 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 37 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 38 "data/maps/LittlerootTown/scripts.pory"

# 39 "data/maps/LittlerootTown/scripts.pory"

# 40 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 41 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 42 "data/maps/LittlerootTown/scripts.pory"
	end
# 43 "data/maps/LittlerootTown/scripts.pory"

# 44 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 45 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 46 "data/maps/LittlerootTown/scripts.pory"
	return
# 47 "data/maps/LittlerootTown/scripts.pory"

# 48 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 49 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 50 "data/maps/LittlerootTown/scripts.pory"
	return
# 51 "data/maps/LittlerootTown/scripts.pory"

# 52 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 53 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_JuniperIntro
# 54 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 55 "data/maps/LittlerootTown/scripts.pory"

# 56 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 57 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0

LittlerootTown_EventScript_JuniperIntro::
# 60 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 61 "data/maps/LittlerootTown/scripts.pory"
	special SpawnCameraObject
# 62 "data/maps/LittlerootTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, TRUE
# 63 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_JUNIPER, LittlerootTown_LabToHouse
# 64 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittlerootTown_LabToHouse
# 65 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/LittlerootTown/scripts.pory"
	opendoor 12, 12
# 67 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 68 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_JUNIPER, LittlerootTown_EnterHouse
# 69 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 71 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 72 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 6, 3
# 73 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 74 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


# 77 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_LabToHouse:
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 78 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 79 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 79 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 79 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 79 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 79 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 80 "data/maps/LittlerootTown/scripts.pory"
	face_up
	step_end

# 83 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EnterHouse:
# 84 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end
