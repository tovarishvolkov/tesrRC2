// Copyright Epic Games, Inc. All Rights Reserved.

#include "tesrRC2GameMode.h"
#include "tesrRC2Character.h"
#include "UObject/ConstructorHelpers.h"

AtesrRC2GameMode::AtesrRC2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
