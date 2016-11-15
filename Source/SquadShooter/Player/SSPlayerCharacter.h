// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Player/SSBaseCharacter.h"
#include "SSPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SQUADSHOOTER_API ASSPlayerCharacter : public ASSBaseCharacter
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<class ASSEquippable> DefaultWeapon;
	
};
