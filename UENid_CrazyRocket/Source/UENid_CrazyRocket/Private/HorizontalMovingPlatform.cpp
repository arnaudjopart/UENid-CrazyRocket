// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalMovingPlatform.h"
#include "Kismet/GameplayStatics.h"

AHorizontalMovingPlatform::AHorizontalMovingPlatform()
{
	
}

void AHorizontalMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	UMaterialInstanceConstant* MI_SkySphere = LoadObject<UMaterialInstanceConstant>(nullptr, TEXT("/Game/Hero/WeatherSystem/Materials/Sky/MI_SkySphere.MI_SkySphere"));

	if (MI_SkySphere)
	{

		//GetComponentByClass<UStaticMeshComponent>()->CreateDynamicMaterialInstance(0, M)
	}
}

void AHorizontalMovingPlatform::Move()
{
	Super::Move();
	float TimeSinceLevelStarted = UGameplayStatics::GetTimeSeconds(this);

	FVector nexPosition = StartPosition + FVector::RightVector * (Amplitude* FMath::Sin(TimeSinceLevelStarted*Frequency));
	SetActorLocation(nexPosition);
}

void AHorizontalMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
