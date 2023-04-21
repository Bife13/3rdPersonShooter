// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthSystem.h"

// Sets default values for this component's properties
UHealthSystem::UHealthSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	// TODO MAYBE CHANGE THIS
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	// ...
}


// Called when the game starts
void UHealthSystem::BeginPlay()
{
	Super::BeginPlay();
	SetHealthToMaxHealth();
}

void UHealthSystem::TakeDamage(float Amount)
{
    GEngine->AddOnScreenDebugMessage(INDEX_NONE,1,FColor::Red, TEXT("HIT"));
	if (Amount > 0)
	{
		Health -= Amount;
	}

	if (Health <= 0)
	{
		Health = 0;
		//TODO DEATH THINGIES HERE
	}
}

void UHealthSystem::RecoverHealth(float Amount)
{
	const float HealAmount = Amount;
	if (HealAmount > 0 && Health != MaxHealth)
	{
		if (Health + HealAmount > MaxHealth)
		{
			Health = MaxHealth;
		}
		else
		{
			Health += HealAmount;
		}
	}
}

float UHealthSystem::GetHealth() const
{
	return Health;
}

float UHealthSystem::GetMaxHealth() const
{
	return MaxHealth;
}

float UHealthSystem::GetHealthAsPercentage() const
{
	return Health / MaxHealth;
}

void UHealthSystem::SetHealthToMaxHealth()
{
	Health = MaxHealth;
}

void UHealthSystem::SetMaxHealth(float Amount)
{
	MaxHealth = Amount;
}

void UHealthSystem::ResetHealth()
{
	Health = MaxHealth;
}
