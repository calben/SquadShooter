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

public:

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = Ammo)
		bool bInfiniteAmmo = true;

	UPROPERTY(EditAnywhere, Category = Ammo)
		bool bInfiniteClip = true;

	UPROPERTY(EditAnywhere, Category = Ammo)
		int32 MaxAmmo = 120;

	UPROPERTY(EditAnywhere, Category = Ammo)
		int32 AmmoPerClip = 25;

	UPROPERTY(EditAnywhere, Category = Ammo)
		int32 InitialClips = 2;

	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float TimeBetweenShots = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor>  Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* MuzzlePoint;

	void OnStartUsingPrimary();

	void OnStopUsingPrimary();

};
