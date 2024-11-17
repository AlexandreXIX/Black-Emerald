.set LOCALID_RIVAL, 2

Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route3_OnLoad
	.byte 0

Route3_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route3_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route3_EventScript_OpenAlteringCave
	end

Route3_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route3_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route3_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route3_EventScript_RivalHilbert
	end

Route3_EventScript_RivalMay::
	msgbox Route3_Text_MayRoute3Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route3_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route3_EventScript_StartMayBattleTreecko
	case 1, Route3_EventScript_StartMayBattleTorchic
	case 2, Route3_EventScript_StartMayBattleMudkip
	end

Route3_EventScript_RivalHilbert::
	msgbox Route3_Text_HilbertRoute3Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_HILBERT, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route3_Text_HilbertLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route3_EventScript_StartHilbertBattleTreecko
	case 1, Route3_EventScript_StartHilbertBattleTorchic
	case 2, Route3_EventScript_StartHilbertBattleMudkip
	end

Route3_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_SNIVY, Route3_Text_MayDefeated
	goto Route3_EventScript_AfterMayBattle
	end

Route3_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_TEPIG, Route3_Text_MayDefeated
	goto Route3_EventScript_AfterMayBattle
	end

Route3_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_OSHAWOTT, Route3_Text_MayDefeated
	goto Route3_EventScript_AfterMayBattle
	end

Route3_EventScript_StartHilbertBattleTreecko::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_SNIVY, Route3_Text_HilbertDefeated
	goto Route3_EventScript_AfterHilbertBattle
	end

Route3_EventScript_StartHilbertBattleTorchic::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_TEPIG, Route3_Text_HilbertDefeated
	goto Route3_EventScript_AfterHilbertBattle
	end

Route3_EventScript_StartHilbertBattleMudkip::
	trainerbattle_no_intro TRAINER_BIANCA_INTRO_OSHAWOTT, Route3_Text_HilbertDefeated
	goto Route3_EventScript_AfterHilbertBattle
	end

Route3_EventScript_AfterMayBattle::
	msgbox Route3_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route3_EventScript_RivalExit
	end

Route3_EventScript_AfterHilbertBattle::
	msgbox Route3_Text_HilbertTimeToHeadBack, MSGBOX_DEFAULT
	goto Route3_EventScript_RivalExit
	end

Route3_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route3_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route3_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route3_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route3_EventScript_RivalExitFacingEastOrWest
	end

Route3_EventScript_RivalExitFacingNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route3_EventScript_RivalEnd
	end

Route3_EventScript_RivalExitFacingEastOrWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExit2
	waitmovement 0
	goto Route3_EventScript_RivalEnd
	end

Route3_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route3_Movement_RivalExit2
	waitmovement 0
	goto Route3_EventScript_RivalEnd
	end

Route3_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_NUVEMA_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE3
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route3_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route3_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route3_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route3_Movement_RivalExit1:
	walk_down
	step_end

Route3_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route3_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route3_EventScript_Boy::
	msgbox Route3_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route3_EventScript_Man::
	msgbox Route3_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route3_Text_DaisyIntro, Route3_Text_DaisyDefeated
	msgbox Route3_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route3_Text_AmyIntro, Route3_Text_AmyDefeated, Route3_Text_AmyNotEnoughPokemon, Route2_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route2_EventScript_AmyRematch
	msgbox Route3_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route3_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route2_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route3_Text_AmyRematchIntro, Route3_Text_AmyRematchDefeated, Route3_Text_AmyRematchNotEnoughPokemon
	msgbox Route3_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route3_Text_LivIntro, Route3_Text_LivDefeated, Route3_Text_LivNotEnoughPokemon, Route2_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route2_EventScript_LivRematch
	msgbox Route3_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route3_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route2_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route3_Text_LivRematchIntro, Route3_Text_LivRematchDefeated, Route3_Text_LivRematchNotEnoughPokemon
	msgbox Route3_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route3_Text_AndrewIntro, Route3_Text_AndrewDefeated
	msgbox Route3_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route3_Text_MiguelIntro, Route3_Text_MiguelDefeated, Route2_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_MiguelRematch
	msgbox Route3_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route2_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route3_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route3_Text_MiguelRematchIntro, Route3_Text_MiguelRematchDefeated
	msgbox Route3_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route3_Text_MarcosIntro, Route3_Text_MarcosDefeated
	msgbox Route3_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route3_Text_RhettIntro, Route3_Text_RhettDefeated
	msgbox Route3_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route3_Text_PeteIntro, Route3_Text_PeteDefeated
	msgbox Route3_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route3_Text_IsabelleIntro, Route3_Text_IsabelleDefeated
	msgbox Route3_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_MayRoute3Pokemon:
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 3 include…$"

Route3_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route3_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route3_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route3_Text_HilbertRoute3Pokemon:
	.string "HILBERT: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 3…$"

Route3_Text_HilbertLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route3_Text_HilbertDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route3_Text_HilbertTimeToHeadBack:
	.string "HILBERT: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route3_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route3_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route3_Text_RouteSign:
	.string "ROUTE 3\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

