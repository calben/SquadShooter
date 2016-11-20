// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "Player/SSBaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "SSSquadSpawnZone.h"


// Sets default values
ASSSquadSpawnZone::ASSSquadSpawnZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Zone = CreateDefaultSubobject<UBoxComponent>(TEXT("Zone"));
	Zone->SetBoxExtent(FVector(100.f, 500.f, 10.f));
}

// Called when the game starts or when spawned
void ASSSquadSpawnZone::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 5; ++i)
	{
		SpawnCharacter(DefaultCharacterClass);
	}
}

// Called every frame
void ASSSquadSpawnZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// WILL NOT RUN
}

ASSBaseCharacter* ASSSquadSpawnZone::SpawnCharacter(TSubclassOf<class ASSBaseCharacter> SpawnClass)
{
	FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), Zone->GetScaledBoxExtent());
	SpawnLocation.Z = DefaultSpawnHeight;
	FRotator SpawnRotation = GetActorRotation();
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ASSBaseCharacter* BaseCharacter = GetWorld()->SpawnActor<ASSBaseCharacter>(SpawnClass, SpawnLocation, SpawnRotation, SpawnInfo);
	BaseCharacter->SpawnZone = this;
	BaseCharacter->TeamNumber = this->TeamNumber;
	BaseCharacter->SquadNumber = this->SquadNumber;
	return BaseCharacter;
}
