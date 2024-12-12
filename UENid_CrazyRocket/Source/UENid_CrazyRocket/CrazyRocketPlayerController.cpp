// Fill out your copyright notice in the Description page of Project Settings.


#include "CrazyRocketPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerDefaultPawn.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStatics.h"

ACrazyRocketPlayerController::ACrazyRocketPlayerController()
{
	
}

void ACrazyRocketPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ACrazyRocketPlayerController::BeginPlay"));

}

void ACrazyRocketPlayerController::KeyPressed(FKey key)
{
	FName KeyName = key.GetFName();
	if (KeyName == "A")
	{
		UE_LOG(LogTemp, Warning, TEXT("A"));
	}
}

void ACrazyRocketPlayerController::KeysPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("A"));
}

void ACrazyRocketPlayerController::ThrustAction(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn"));
	if (APlayerDefaultPawn* currentPlayer = CastChecked<APlayerDefaultPawn>(GetPawn()))
	{
		currentPlayer->AddThrust();
	}
}

void ACrazyRocketPlayerController::ApplyRotation(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn"));
	if (APlayerDefaultPawn* currentPlayer = CastChecked<APlayerDefaultPawn>(GetPawn()))
	{
		currentPlayer->Rotate(InputActionValue.Get<float>());
	}
}

void ACrazyRocketPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext,0);
		UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent);		
		check(EIC);
		EIC->BindAction(ThurstInputAction, ETriggerEvent::Triggered,this,&ACrazyRocketPlayerController::ThrustAction);
		EIC->BindAction(RotateInputAction, ETriggerEvent::Triggered,this,&ACrazyRocketPlayerController::ApplyRotation);
		
	}
	
	//InputComponent->BindKey(EKeys::A,IE_Pressed, this,&ACrazyRocketPlayerController::KeysPressed);
}
