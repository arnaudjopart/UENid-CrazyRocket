// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DemoRocketPawn.generated.h"

UCLASS()
class UENID_CRAZYROCKET_API ADemoRocketPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADemoRocketPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float ImpulseForce = 3000;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float RotationSpeed = 50;
	
	UFUNCTION(BlueprintCallable)
	void AddThrustCpp();
	UFUNCTION(BlueprintCallable)
	void RotateCpp(float Direction);

private :

	UPROPERTY(EditDefaultsOnly, Category = "My Variables")
	FString MyString = "Valentin is Awesomely funny";
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyFuckingStaticMeshComponent;

};
