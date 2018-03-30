// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DungeonBuilderGameMode.h"
#include "DungeonBuilderPlayerController.h"
#include "DungeonBuilderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonBuilderGameMode::ADungeonBuilderGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADungeonBuilderPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}