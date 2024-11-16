# 1 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"

# 2 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
NuvemaTown_CherensHouse_1F_MapScripts::
# 3 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	.byte 0

NuvemaTown_CherensHouse_1F_EventScript_Man::
# 7 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	lockall
# 8 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	msgbox Cherens_Dad, MSGBOX_NPC
# 9 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	releaseall
	return


NuvemaTown_CherensHouse_1F_EventScript_Woman::
# 13 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	msgbox Cherens_Mom, MSGBOX_NPC
	return


Cherens_Dad::
# 16 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	.string "Cheren's Dad: Traveling is great!\n"
	.string "You encounter so many things you've\l"
	.string "never seen and things you don't yet\l"
	.string "understand. Wherever you go, you'll\l"
	.string "learn something new and grow up a\l"
	.string "little.$"

Cherens_Mom::
# 20 "data/maps/NuvemaTown_CherensHouse_1F/scripts.pory"
	.string "Cheren's Mom: Why, {PLAYER}.\n"
	.string "I heard the professor asked you to\l"
	.string "complete the Pokédex.\l"
	.string "Don't worry! You'll always have Pokémon\l"
	.string "by your side.$"
