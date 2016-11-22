// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LaserAimingBead.generated.h"

UCLASS()
class SQUADSHOOTER_API ALaserAimingBead : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserAimingBead();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPointLightComponent* PointLight;
	
};
