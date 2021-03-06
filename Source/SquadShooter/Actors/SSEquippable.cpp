// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "Player/SSBaseCharacter.h"
#include "SSEquippable.h"


// Sets default values
ASSEquippable::ASSEquippable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ASSEquippable::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASSEquippable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASSEquippable::OnEquip(ASSBaseCharacter* Equipper, FName SocketName)
{
	CurrentEquipper = Equipper;
	Mesh->AttachToComponent(CurrentEquipper->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);
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

void ASSEquippable::OnStartUsingPrimary_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("LOGGED FROM CPP"));
	if (!bIsPrimaryActive)
	{
		bIsPrimaryActive = true;
	}
}

void ASSEquippable::OnStopUsingPrimary_Implementation()
{
	bIsPrimaryActive = false;
}

void ASSEquippable::OnStartUsingSecondary_Implementation()
{
	if (!bIsSecondaryActive)
	{
		bIsSecondaryActive = true;
	}
}

void ASSEquippable::OnStopUsingSecondary_Implementation()
{
	bIsSecondaryActive = false;
}