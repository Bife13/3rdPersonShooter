// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damageable.h"
#include "Components/ActorComponent.h"
#include "HealthSystem.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CGLTPERSONSHOOTER_API UHealthSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	// virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void TakeDamage(float Amount);
	UFUNCTION()
	void RecoverHealth(float Amount);

	UFUNCTION(BlueprintPure)
	float GetHealth() const;
	UFUNCTION(BlueprintPure)
	float GetMaxHealth() const;
	UFUNCTION(BlueprintPure)
	float GetHealthAsPercentage() const;

	UFUNCTION()
	void SetHealthToMaxHealth();
	UFUNCTION()
	void SetMaxHealth(float Amount);
	UFUNCTION()
	void ResetHealth();

	UPROPERTY(VisibleAnywhere)
	float Health;
	UPROPERTY(VisibleAnywhere)
	float MaxHealth;

	// UPROPERTY(VisibleAnywhere, Replicated)
	// float Shield;
	// UPROPERTY(VisibleAnywhere)
	// float Resistance;
	// UPROPERTY()
	// bool bLowHealth = false;
	// UFUNCTION(BlueprintCallable)
	// void SetResistance(float Amount);
	// UFUNCTION(Server, Reliable)
	// void SetShield(float Amount);
	// UFUNCTION(BlueprintCallable)
	// float GetShield() const{return Shield;}
};
