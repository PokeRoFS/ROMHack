.set LOCALID_BROTHER, 5

Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_TriggerBrother1::
	lockall
	applymovement LOCALID_BROTHER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BROTHER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_BROTHER, Route102_Movement_BrotherMovetoTrigger1
	waitmovement 0
	msgbox Route102_Text_IntroBrotherBattle, MSGBOX_DEFAULT
	goto Route102_EventScript_Brother
	end

Route102_EventScript_TriggerBrother2::
	lockall
	applymovement LOCALID_BROTHER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BROTHER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_BROTHER, Route102_Movement_BrotherMovetoTrigger2
	waitmovement 0
	msgbox Route102_Text_IntroBrotherBattle, MSGBOX_DEFAULT
	goto Route102_EventScript_Brother
	releaseall
	end

Route102_EventScript_Brother::
	trainerbattle_no_intro TRAINER_BROTHER1, Route102_Text_Brother1Defeated
	goto Route102_EventScript_BrotherDefeated
	end

Route102_EventScript_BrotherDefeated::
	msgbox Route102_Text_Brother1PostBattle, MSGBOX_AUTOCLOSE
	applymovement LOCALID_BROTHER, Route102_Movement_Brother1Leaves
	waitmovement 0
	setflag FLAG_HIDE_BROTHER_1
	setvar VAR_ROUTE102_STATE, 1
	hideobjectat LOCALID_BROTHER, MAP_ROUTE102
	release
	end

Route102_Movement_BrotherMovetoTrigger1:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_BrotherMovetoTrigger2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_Brother1Leaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route102_Text_IntroBrotherBattle:
	.string "What's up loser?\p"
	.string "I assume MR. HARSHBARGER\n"
	.string "gave you a pokemon too?\p"
	.string "I'm gonna make mine strong...\n"
	.string "Don't fall behind!$"

Route102_Text_WatchMeCatchPokemon:
	.string "TRUEMAN: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "I'm gonna get a V.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "TRUEMAN: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "I wanna keep this other one too...!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
