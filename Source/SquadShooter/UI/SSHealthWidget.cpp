// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "SSHealthWidget.h"
#include "Player/SSBaseCharacter.h"

float USSHealthWidget::GetHealth()
{
	return Character->CurrentHealth;
}

