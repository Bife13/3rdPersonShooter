// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"

#include "CGLTPersonShooterCharacter.h"
#include "SkillActor.h"
#include "UsableCharacterSkillSlot.h"

void USkillBase::InitializeSkill(ACharacter* Playable, UWorld* World, int Team)
{
	OwnerCharacter = Playable;
	CachedWorld = World;
	TeamId = Team;
	CachedCharacterInterface = Cast<IUsableCharacterSkillSlot>(OwnerCharacter);
	bCanUse = true;
	
	
	
	OnInitialize();
}

void USkillBase::CastSkill(UAnimMontage* AnimationToPlay, float CooldownModifier)
{
	if (bCanUse)
	{
		CachedCharacterInterface->SetIsCasting(true);
		AttackAnimation = AnimationToPlay;
		SetCooldownModifier(CooldownModifier);
		bCanUse = false;
		// HandleCastEvents(AbilityCooldown);
		OnCast();
	}
	else
	{
	GEngine->AddOnScreenDebugMessage(15, .5f, FColor::Black,TEXT("On Cooldown"));
	}
}

void USkillBase::UseSkill()
{
	const ACGLTPersonShooterCharacter* PlayableCharacter = Cast<ACGLTPersonShooterCharacter>(OwnerCharacter);
	AbilityRotation = PlayableCharacter->CachedMouseRotator;
	CachedCharacterInterface->SetIsCasting(false);
	StartCooldownTimer();
	OnUse();
}

void USkillBase::StartCooldownTimer()
{
	FTimerHandle THandle;
	const float Delay = AbilityCooldown;
	CachedWorld->GetTimerManager().SetTimer(THandle, this, &USkillBase::ResetCooldown, Delay, false);
}

void USkillBase::SpawnSkillActor(const FVector& SpawnPosition)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* SpawnedAbility = CachedWorld->SpawnActor(ActorToSpawn, &SpawnPosition, &AbilityRotation, SpawnParams);
	const ISkillActor* SkillActorInterface = Cast<ISkillActor>(SpawnedAbility);
	SkillActorInterface->Execute_SetValues(SpawnedAbility, TeamId, AbilityDamage, AbilityRange, SpawnPosition,
										   OwnerCharacter);
}

void USkillBase::ResetCooldown()
{
	bCanUse = true;
	// HandleResetEvents();
}

void USkillBase::SetCooldown(const float Cooldown)
{
	AbilityCooldown = Cooldown;
}

void USkillBase::SetCastTime(const float CastTime)
{
	AbilityCastTime = CastTime;
}

void USkillBase::SetSpawnTime(float SpawnTime)
{
	AbilitySpawnTime = SpawnTime;
}

void USkillBase::SetAbilityDamage(const float Power, float AbilityPower, float AddValue)
{
	AbilityDamage = (Power * AbilityPower) + AddValue;
}

void USkillBase::SetAbilityRange(const float Range)
{
	AbilityRange = Range;
}
