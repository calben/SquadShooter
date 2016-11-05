// Fill out your copyright notice in the Description page of Project Settings.

#include "SquadShooter.h"
#include "UI/SSHealthWidget.h"
#include "SSBaseCharacter.h"


// Sets default values
ASSBaseCharacter::ASSBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCameraComponent"));
	ThirdPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCameraComponent"));
	ThirdPersonCameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("ThirdPersonCameraSpringArmComponent"));
	ThirdPersonCameraSpringArmComponent->SetupAttachment(ThirdPersonCameraComponent);

	HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("ResponseWidget"));
	HealthWidgetComponent->SetupAttachment(FirstPersonCameraComponent);
	HealthWidgetComponent->bAbsoluteLocation = false;
	HealthWidgetComponent->bAbsoluteRotation = false;
	HealthWidgetComponent->bAbsoluteScale = false;
	HealthWidgetComponent->RelativeLocation = FVector(100.f, 50.f, -50.f);
	HealthWidgetComponent->RelativeRotation = FRotator(0.f, 180.f, 0.f);
	HealthWidgetComponent->RelativeScale3D = FVector(0.2f, 0.2f, 0.2f);
}

// Called when the game starts or when spawned
void ASSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (HealthWidgetClass)
	{
		HealthWidget = CreateWidget<USSHealthWidget>(GetWorld()->GetFirstPlayerController(), HealthWidgetClass);
		HealthWidgetComponent->SetWidget(HealthWidget);
		HealthWidget->Character = this;
	}
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

