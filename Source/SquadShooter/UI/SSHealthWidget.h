// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "SSHealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class SQUADSHOOTER_API USSHealthWidget : public UUserWidget
{
	GENERATED_BODY()	

public:

	class ASSBaseCharacter* Character;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		float GetHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		FString GetHealthString();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		float GetHealthPercentage();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		float GetShield();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		FString GetShieldString();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
		float GetShieldPercentage();
	
};
