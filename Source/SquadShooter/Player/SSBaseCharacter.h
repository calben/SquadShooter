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
		bool bIsSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MouseSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsAiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bFirstPersonActive = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bThirdPersonActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentHealth = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxShield = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentShield = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* ThirdPersonCameraSpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* ThirdPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UWidgetComponent* HealthWidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USSHealthWidget* HealthWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class TSubclassOf<USSHealthWidget> HealthWidgetClass;

};
