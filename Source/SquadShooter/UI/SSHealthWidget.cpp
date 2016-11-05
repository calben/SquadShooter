// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "SSHealthWidget.h"
#include "Player/SSBaseCharacter.h"

float USSHealthWidget::GetHealth()
{
	return Character->CurrentHealth;
}

FString USSHealthWidget::GetHealthString()
{
	return FString::SanitizeFloat(Character->CurrentHealth);
}

float USSHealthWidget::GetHealthPercentage()
{
	return Character->CurrentHealth / Character->MaxHealth;
}

float USSHealthWidget::GetShield()
{
	return Character->CurrentShield;
}

FString USSHealthWidget::GetShieldString()
{
	return FString::SanitizeFloat(Character->CurrentShield);
}

float USSHealthWidget::GetShieldPercentage()
{
	return Character->CurrentShield / Character->MaxShield;
}

