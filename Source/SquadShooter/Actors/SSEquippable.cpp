// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "SSEquippable.h"


// Sets default values
ASSEquippable::ASSEquippable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASSEquippable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSEquippable::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASSEquippable::OnEquip(ASSBaseCharacter* Equipper)
{
	CurrentEquipper = Equipper;
}

void ASSEquippable::OnBeginEquip()
{

}

void ASSEquippable::OnFinishedEquip()
{

}

void ASSEquippable::OnUnEquip()
{
	CurrentEquipper = nullptr;
}
