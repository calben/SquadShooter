// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SSSquadSpawnZone.generated.h"

UCLASS()
class SQUADSHOOTER_API ASSSquadSpawnZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASSSquadSpawnZone();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SquadNumber = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TeamNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DefaultSpawnHeight = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowRespawn = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ASSBaseCharacter> DefaultCharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Zone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class ASSBaseCharacter*> SpawnedCharacters;

	UFUNCTION(BlueprintCallable, Category = "Util")
		class ASSBaseCharacter* SpawnCharacter(TSubclassOf<class ASSBaseCharacter> SpawnClass);

};
