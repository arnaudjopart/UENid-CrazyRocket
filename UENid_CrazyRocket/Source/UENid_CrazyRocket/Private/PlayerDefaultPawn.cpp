// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDefaultPawn.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerDefaultPawn::APlayerDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	Mesh = GetComponentByClass<UStaticMeshComponent>();
}

// Called every frame
void APlayerDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerDefaultPawn::AddThrust()
{
	FVector UpVector = Mesh->GetUpVector();
	Mesh->AddImpulse(FVector(Impulse * UpVector));
}

void APlayerDefaultPawn::Rotate(float Direction)
{
	
	FRotator CurrentRotation = GetActorRotation();
	float stepRotation = Direction * UGameplayStatics::GetWorldDeltaSeconds(this)*RotationSpeed;
	CurrentRotation+=FRotator(0,0,stepRotation);
	SetActorRotation(CurrentRotation);
/*
	FRotator CurrentRotation = Mesh->GetComponentRotation();
	float stepRotation = Direction * UGameplayStatics::GetWorldDeltaSeconds(this)*RotationSpeed;
	UE_LOG(LogTemp, Display, TEXT("Rotate: %f"),stepRotation);
	CurrentRotation+=FRotator(0,0,stepRotation);
	Mesh->SetWorldRotation(CurrentRotation);
	*/
}
