// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlatformBase.h"
#include "HorizontalMovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class UENID_CRAZYROCKET_API AHorizontalMovingPlatform : public AMovingPlatformBase
{
	GENERATED_BODY()
	

public:
	AHorizontalMovingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Move() override;

public:
	void Tick(float DeltaTime) override;

};
