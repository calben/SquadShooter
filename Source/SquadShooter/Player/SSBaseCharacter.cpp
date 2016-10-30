// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "SSBaseCharacter.h"


// Sets default values
ASSBaseCharacter::ASSBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSBaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ASSBaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

