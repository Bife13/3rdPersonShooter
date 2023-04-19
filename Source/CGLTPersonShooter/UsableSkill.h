// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UsableSkill.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUsableSkill : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CGLTPERSONSHOOTER_API IUsableSkill
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void InitializeSkill(ACharacter* Playable, UWorld* World,int Team) = 0;
	virtual void UseSkill() = 0;
	virtual void CastSkill(UAnimMontage* AnimationToPlay) = 0;
};
