// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "LaserAimingBead.h"


// Sets default values
ALaserAimingBead::ALaserAimingBead()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));

}

// Called when the game starts or when spawned
void ALaserAimingBead::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserAimingBead::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

