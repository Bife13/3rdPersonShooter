// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UsableCharacterSkillSlot.h"
#include "UsableSkill.h"
#include "UObject/NoExportTypes.h"
#include "SkillBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CGLTPERSONSHOOTER_API USkillBase : public UObject, public IUsableSkill
{
public:
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	virtual void InitializeSkill(ACharacter* Playable, UWorld* World, int Team) override;
	UFUNCTION(BlueprintCallable)
	virtual void UseSkill() override;
	void StartCooldownTimer();
	virtual void CastSkill(UAnimMontage* AnimationToPlay) override;

	UFUNCTION()
	void ResetCooldown();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCast();
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse();
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitialize();

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	float AbilityCooldown;
	UFUNCTION(BlueprintCallable)
	void SetCooldown(float Cooldown);

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	float AbilityCastTime;
	UFUNCTION(BlueprintCallable)
	void SetCastTime(float CastTime);

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	float AbilitySpawnTime;
	UFUNCTION(BlueprintCallable)
	void SetSpawnTime(float SpawnTime);

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	float AbilityDamage;
	UFUNCTION(BlueprintCallable)
	void SetAbilityDamage(float Power, float AbilityPower, float AddValue);

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	float AbilityRange;
	UFUNCTION(BlueprintCallable)
	void SetAbilityRange(float Range);

	UPROPERTY(BlueprintReadWrite)
	bool bCanUse;

	UPROPERTY(BlueprintReadWrite)
	ACharacter* OwnerCharacter;
	UPROPERTY(BlueprintReadWrite)
	UWorld* CachedWorld;
	IUsableCharacterSkillSlot* CachedCharacterInterface;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	TSubclassOf<AActor> CastEffectToSpawn;
	UPROPERTY(BlueprintReadWrite)
	FRotator AbilityRotation;

	UPROPERTY(BlueprintReadWrite)
	UAnimMontage* AttackAnimation;

	UFUNCTION(BlueprintCallable)
	int GetTeamId() const { return TeamId; }

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnSkillActor(const FVector& SpawnPosition);
	UPROPERTY()
	int TeamId;
};
