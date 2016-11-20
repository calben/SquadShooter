// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Actors/SSEquippable.h"
#include "SSWeapon.generated.h"

UCLASS()
class SQUADSHOOTER_API ASSWeapon : public ASSEquippable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASSWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DamageOnHit;

	void OnStartUsingPrimary();

	void OnStopUsingPrimary();

	void OnStartUsingSecondary();

	void OnStopUsingSecondary();

};
