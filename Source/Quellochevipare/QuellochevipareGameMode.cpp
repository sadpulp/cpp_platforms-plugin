// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuellochevipareGameMode.h"
#include "QuellochevipareCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQuellochevipareGameMode::AQuellochevipareGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
