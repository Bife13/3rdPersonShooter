// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatSystem.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CGLTPERSONSHOOTER_API UStatSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStatSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float MaxHealth;
	UPROPERTY(EditAnywhere)
	float AttackSpeed;
	UPROPERTY(EditAnywhere)
	float MovementSpeed;
	UPROPERTY(EditAnywhere)
	float Damage;
	UPROPERTY(EditAnywhere)
	float CooldownReduction;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	float GetMaxHealth() const { return MaxHealth; }
	float GetAttackSpeed() const { return AttackSpeed; }
	float GetAttackSpeedAsCooldown() const { return 1 / AttackSpeed; }
	float GetMovementSpeed() const { return MovementSpeed; }
	float GetDamage() const { return Damage; }
	float GetCooldownReduction() const { return CooldownReduction; }

	void SetMaxHealth(float Amount) { MaxHealth += Amount; }
	void SetAttackSpeed(float Amount) { AttackSpeed += Amount; }
	void SetMovementSpeed(float Amount) { MovementSpeed += Amount; }
	void SetDamage(float Amount) { Damage += Amount; }
	void GetCooldownReduction(float Amount) { CooldownReduction += Amount; }
};
