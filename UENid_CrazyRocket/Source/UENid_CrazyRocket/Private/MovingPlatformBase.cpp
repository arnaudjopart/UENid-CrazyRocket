// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMovingPlatformBase::AMovingPlatformBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base");
	RootComponent = BaseStaticMesh;
}

// Called when the game starts or when spawned
void AMovingPlatformBase::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
	
}

void AMovingPlatformBase::Move()
{
}

// Called every frame
void AMovingPlatformBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

