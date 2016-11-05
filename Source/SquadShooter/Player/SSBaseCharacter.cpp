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
	FirstPersonCameraComponent->SetupAttachment(GetMesh());
	ThirdPersonCameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("ThirdPersonCameraSpringArmComponent"));
	ThirdPersonCameraSpringArmComponent->SetupAttachment(GetMesh());
	ThirdPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCameraComponent"));
	ThirdPersonCameraComponent->SetupAttachment(ThirdPersonCameraSpringArmComponent);

	HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("ResponseWidget"));
	HealthWidgetComponent->SetupAttachment(FirstPersonCameraComponent);
	HealthWidgetComponent->bAbsoluteLocation = false;
	HealthWidgetComponent->bAbsoluteRotation = false;
	HealthWidgetComponent->bAbsoluteScale = false;
	HealthWidgetComponent->RelativeLocation = FVector(40.f, 25.f, -10.f);
	HealthWidgetComponent->RelativeRotation = FRotator(0.f, 15.f, -160.f);
	HealthWidgetComponent->RelativeScale3D = FVector(0.03f, 0.03f, 0.03f);
	HealthWidgetComponent->SetDrawSize(FVector2D(600.f, 300.f));
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
void ASSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASSBaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASSBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASSBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerPitchInput);

}

void ASSBaseCharacter::MoveForward(float Val)
{
	if (Controller && Val != 0.f)
	{
		// Limit pitch when walking or falling
		const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction, Val);
	}
}

void ASSBaseCharacter::MoveRight(float Val)
{
	if (Controller && Val != 0.f)
	{
		const FRotator Rotation = GetActorRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Val);
	}
}
