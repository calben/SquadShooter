// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define NAKED UPROPERTY(EditAnywhere, BlueprintReadWrite)

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
	
	NAKED
		bool bIsSprinting;

	NAKED
		float MouseSensitivity;

	NAKED
		bool bIsJumping;

	NAKED
		bool bIsFalling;

	NAKED
		bool bIsAiming;

	NAKED
		bool bFirstPersonActive;

	NAKED
		bool bThirdPersonActive;

	NAKED
		float MaxHealth;

	NAKED
		float CurrentHealth;

	NAKED
		class UCameraComponent* FirstPersonCameraComponent;

	NAKED
		class UCameraComponent* ThirdPersonCameraComponent;

	NAKED
		class UWidgetComponent* HealthWidgetComponent;

	NAKED
		class USSHealthWidget* HealthWidget;

	NAKED
		class TSubclassOf<USSHealthWidget> HealthWidgetClass;

};
