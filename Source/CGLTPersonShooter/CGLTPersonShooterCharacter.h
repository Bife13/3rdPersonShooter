// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HealthSystem.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputMappingQuery.h"
#include "SkillBase.h"
#include "StatSystem.h"
#include "UsableCharacterSkillSlot.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "CGLTPersonShooterCharacter.generated.h"



UCLASS(config=Game)
class ACGLTPersonShooterCharacter : public ACharacter, public IUsableCharacterSkillSlot, public IDamageable
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	/** Basic Attack Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> BasicAttackAction;

	/** First Ability Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FirstAbilityAction;

	/** Second Ability Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SecondAbilityAction;

	/** Third Ability Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ThirdAbilityAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Health, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHealthSystem> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStatSystem> StatComponent;
	
public:
	ACGLTPersonShooterCharacter();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	UFUNCTION()
	virtual bool GetIsCasting() override;
	UFUNCTION()
	virtual void SetIsCasting(bool Value) override;

	UFUNCTION()
	UArrowComponent* GetShootingPoint() const { return ShootingPoint; }

	UPROPERTY()
	FRotator CachedMouseRotator;

	UPROPERTY()
	FVector2D CachedMovementVector;

	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(float Amount) override;
	UFUNCTION(BlueprintCallable)
	virtual void RecoverHealth(float Amount) override;


protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY()
	UWorld* CachedWorld;

	UFUNCTION()
	void TestGround();

	UPROPERTY()
	float GroundedTime = 0;
	UPROPERTY(EditAnywhere)
	float JumpBuffer;
	UPROPERTY()
	bool bIsCasting = false;

	UFUNCTION()
	virtual void UseBasicAttack() override;
	UFUNCTION()
	virtual void UseFirstAbility() override;
	UFUNCTION()
	virtual void UseSecondAbility() override;
	UFUNCTION()
	virtual void UseThirdAbility() override;

	UPROPERTY(BlueprintReadWrite)
	UArrowComponent* ShootingPoint;

	UFUNCTION()
	void PopulateSkillArray();

	UFUNCTION()
	FRotator CalculateShootingAngle(const FVector InitialPoint, const float Range) const;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<USkillBase>> Skills;
	UPROPERTY(VisibleAnywhere)
	TArray<USkillBase*> RuntimeSkills;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UAnimMontage*> AttackAnimations;
	UPROPERTY(EditAnywhere)
	float AttackRange;
};
