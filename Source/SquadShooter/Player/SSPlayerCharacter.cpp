// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "SSPlayerCharacter.h"

void ASSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	OnEquip(DefaultWeapon, FName("BendellWeaponSocket"));
}

