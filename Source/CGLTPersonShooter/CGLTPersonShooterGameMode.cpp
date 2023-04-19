// Copyright Epic Games, Inc. All Rights Reserved.

#include "CGLTPersonShooterGameMode.h"
#include "CGLTPersonShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACGLTPersonShooterGameMode::ACGLTPersonShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
