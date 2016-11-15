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
		UArrowComponent* MuzzlePoint; //!< Point from which projectiles should spawn

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ASSBaseCharacter* User; //!< User to which the weapon is currently attached

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 BurstCounter; //!< Number of bullets in a burst set

};
