// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "CrazyRocketPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UENID_CRAZYROCKET_API ACrazyRocketPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
	ACrazyRocketPlayerController();
	protected:
	virtual void BeginPlay() override;


private:
	void KeyPressed(FKey key);
	void KeysPressed();
	void ThrustAction(const FInputActionValue& InputActionValue);
	void ApplyRotation(const FInputActionValue& InputActionValue);
	
	virtual void SetupInputComponent() override;
	UPROPERTY(EditAnywhere)
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere)
	const UInputAction* ThurstInputAction;
	UPROPERTY(EditAnywhere)
	const UInputAction* RotateInputAction;
};
