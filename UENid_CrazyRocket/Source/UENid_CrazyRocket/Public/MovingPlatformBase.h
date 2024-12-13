// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformBase.generated.h"

UCLASS()
class UENID_CRAZYROCKET_API AMovingPlatformBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatformBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector StartPosition;
	virtual void Move();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* BaseStaticMesh;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 500 ;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 1;


};
