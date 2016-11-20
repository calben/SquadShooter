// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Actors/SSWeapon.h"
#include "SSWeaponRifle.generated.h"

/**
 * 
 */
UCLASS()
class SQUADSHOOTER_API ASSWeaponRifle : public ASSWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsHitscan = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor>  Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* MuzzlePoint;

	void OnStartUsingPrimary();

	void OnStopUsingPrimary();

};
