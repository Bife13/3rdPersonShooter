// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SkillActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USkillActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CGLTPERSONSHOOTER_API ISkillActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetValues(int TeamValue, float DamageValue, float RangeValue, FVector SpawnPositionVector,
	               APawn* OwnerCharacter);
};
