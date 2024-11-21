# 1 "data/maps/Route1/scripts.pory"

# 2 "data/maps/Route1/scripts.pory"
Route1_MapScripts::
# 3 "data/maps/Route1/scripts.pory"
	.byte 0

Route1_HideTransition::
# 10 "data/maps/Route1/scripts.pory"
	lockall
# 11 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 12 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 1
# 13 "data/maps/Route1/scripts.pory"
	releaseall
	end


Route1_ShowTransition::
# 18 "data/maps/Route1/scripts.pory"
	lockall
# 19 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 20 "data/maps/Route1/scripts.pory"
	setvar VAR_ROUTE1_STATE, 0
# 21 "data/maps/Route1/scripts.pory"
	releaseall
	end


Route1_RouteSign::
# 26 "data/maps/Route1/scripts.pory"
	msgbox Route1_RouteSign_Text_0, MSGBOX_SIGN
	return


Route1_TrainerTips::
# 30 "data/maps/Route1/scripts.pory"
	msgbox Route1_TrainerTips_Text_0, MSGBOX_SIGN
	return


Route1_Boy::
# 36 "data/maps/Route1/scripts.pory"
	msgbox Route1_Boy_Text_0, MSGBOX_NPC
	return


Route1_Girl::
# 41 "data/maps/Route1/scripts.pory"
	msgbox Route1_Girl_Text_0, MSGBOX_NPC
	return


Route1_RouteSign_Text_0:
# 26 "data/maps/Route1/scripts.pory"
	.string "Route 1$"

Route1_TrainerTips_Text_0:
# 30 "data/maps/Route1/scripts.pory"
	.string "Trainer Tips!\p"
	.string "Make an effort to talk to all the people\n"
	.string "you meet during your journey!\p"
	.string "Chances are they will have something\n"
	.string "useful to tell you.$"

Route1_Boy_Text_0:
# 36 "data/maps/Route1/scripts.pory"
	.string "Wild Pokémon are hiding in the tall\n"
	.string "grass. What does this mean for you?\p"
	.string "It means when you want to battle or\n"
	.string "capture wild Pokémon, you should walk in\l"
	.string "the tall grass.$"

Route1_Girl_Text_0:
# 41 "data/maps/Route1/scripts.pory"
	.string "When your Pokémon's HP decreases, they\n"
	.string "no longer have the energy to fight.\p"
	.string "So, don't push your Pokémon too hard,\n"
	.string "and let them rest often.$"
