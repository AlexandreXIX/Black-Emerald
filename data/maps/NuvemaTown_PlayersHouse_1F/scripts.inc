# 1 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"

# 2 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
.set LOCALID_MOM, 1
# 3 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
.set LOCALID_RIVAL_MOM, 4
# 4 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"

# 6 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_MapScripts::
# 7 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NuvemaTown_PlayersHouse_1F_OnLoad
# 8 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NuvemaTown_PlayersHouse_1F_OnTransition
# 9 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NuvemaTown_PlayersHouse_1F_OnFrame
# 10 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.byte 0
# 11 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"

# 12 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_OnLoad:
# 13 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	end
# 14 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"

# 15 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_OnTransition:
# 16 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	end
# 17 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"

# 18 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
NuvemaTown_PlayersHouse_1F_OnFrame:
# 19 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.2byte 0

NuvemaTown_PlayersHouse_1F_EventScript_Mom::
# 23 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	msgbox Players_Mom, MSGBOX_NPC
	return


Players_Mom::
# 26 "data/maps/NuvemaTown_PlayersHouse_1F/scripts.pory"
	.string "TBD$"
