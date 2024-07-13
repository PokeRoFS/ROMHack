.set LOCALID_MEMORY1, 3
.set LOCALID_MEMORY2, 1
.set LOCALID_MEMORY3, 2

InsideOfMemories_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfMemories_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfMemories_OnResume
	.byte 0

InsideOfMemories_OnLoad:
	end

InsideOfMemories_OnResume:
	end

InsideOfMemories_EventScript_Memory1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MEMORY1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox InsideOfMemories_Memory1_Script, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	release
	end

InsideOfMemories_EventScript_Memory2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox InsideOfMemories_Memory2_Script, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	release
	end

InsideOfMemories_EventScript_Memory3::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox InsideOfMemories_Memory3_Script, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	msgbox InsideOfMemories_What_Script, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 1, 4
	fadescreen FADE_FROM_BLACK
	setvar VAR_DREAM_STATE, 4
	goto LittlerootTown_BrendansHouse_2F_EventScript_WakeUp
	release
	end


InsideOfMemories_Memory1_Script:
	.string "Let's play invincible!$"

InsideOfMemories_Memory2_Script:
	.string "We can stay up so late for the\n"
	.string "New Year and play Madden!$"

InsideOfMemories_Memory3_Script:
	.string "Well we gotta do another Soul Link!\p"
	.string "...\p"
	.string "We played a lot of Pokemon.\p"
	.string "I wish they were real.$"

InsideOfMemories_What_Script:
	.string "What's going on?!?$"
