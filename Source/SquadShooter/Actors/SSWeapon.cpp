// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "Player/SSBaseCharacter.h"
#include "SSWeapon.h"


// Sets default values
ASSWeapon::ASSWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	Mesh->bReceivesDecals = true;
	Mesh->CastShadow = true;
	Mesh->SetCollisionObjectType(ECC_WorldDynamic);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void ASSWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASSWeapon::OnStartUsingPrimary()
{
	Super::BeginPlay();

}

void ASSWeapon::OnStopUsingPrimary()
{
	Super::BeginPlay();

}


void OnStartUsingPrimary()
{
}

void OnStopUsingPrimary()
{
}

void OnStartUsingSecondary()
{
}

void OnStopUsingSecondary()
{
}