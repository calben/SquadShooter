// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "SSBaseCharacter.generated.h"

UCLASS()
class SQUADSHOOTER_API ASSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASSBaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsSprinting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MouseSensitivity; //!< Scalar multiplied to the axis value when adding mouse input

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsJumping = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsFalling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsAiming = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SquadNumber = 0; //!< Indicates to which squad this character belongs, 0 is NONE

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TeamNumber = 0; //!< Indicates to which team this character belongs, 0 is NONE

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bFirstPersonActive = true; //!< If the first person is active, then use first person camera and models

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bThirdPersonActive; //!< If the third person is active, then use third person camera and models

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentHealth = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxShield = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentShield = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bLimitRotation = false; //!< Rotation should be limited during some actions, such as when jumping

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* ThirdPersonCameraSpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* ThirdPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UWidgetComponent* HealthWidgetComponent; //!< Widget component that will hold the HealthWidget

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USSHealthWidget* HealthWidget; //!< The health widget that displays health and shield properties to the user

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class TSubclassOf<USSHealthWidget> HealthWidgetClass; //!< Used to define the blueprint UMG widget to use for the health widget

	UFUNCTION(BlueprintCallable, Category = "Control")
		void MoveForward(float Val);

	UFUNCTION(BlueprintCallable, Category = "Control")
		void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Character")
		void OnEquip(TSubclassOf<class ASSEquippable> EquipableClass);
};
