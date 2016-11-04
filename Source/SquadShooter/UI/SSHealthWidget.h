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

	UFUNCTION(BlueprintCallable, Category="UI")
		float GetHealth();
	
};
