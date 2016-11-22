// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SSEquippable.generated.h"

UCLASS()
class SQUADSHOOTER_API ASSEquippable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASSEquippable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ASSBaseCharacter* CurrentEquipper; //!< Pointer to character equipping the equippable

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* Mesh; //!< Equippable mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsPrimaryActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsSecondaryActive = false;

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnEquip(class ASSBaseCharacter* Equipper, FName SocketName);

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnBeginEquip();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnFinishedEquip();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnUnEquip();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnStartUsingPrimary();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnStopUsingPrimary();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnStartUsingSecondary();

	UFUNCTION(BlueprintCallable, Category = Equippable)
		void OnStopUsingSecondary();

};
