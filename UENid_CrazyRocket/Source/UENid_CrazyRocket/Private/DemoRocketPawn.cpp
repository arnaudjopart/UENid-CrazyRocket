// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoRocketPawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADemoRocketPawn::ADemoRocketPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyFuckingStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("RocketMesh");

}

// Called when the game starts or when spawned
void ADemoRocketPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("My Text: %s"), *MyString);
	//OnClicked.AddDynamic(this, &ADemoRocketPawn::OnMouseClicked);
}

// Called every frame
void ADemoRocketPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADemoRocketPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemoRocketPawn::AddThrustCpp()
{
	FVector ImpulseDirection = MyFuckingStaticMeshComponent-> GetUpVector();
	ImpulseDirection *= ImpulseForce;
	MyFuckingStaticMeshComponent->AddImpulse(ImpulseDirection);
	UE_LOG(LogTemp, Warning, TEXT("AddThrustCpp"));
}

void ADemoRocketPawn::RotateCpp(float Direction)
{
	FRotator rotation = GetActorRotation();
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

	rotation += FRotator(0, 0, deltaTime * Direction * RotationSpeed);
	SetActorRotation(rotation);
}

/*void ADemoRocketPawn::OnMouseClicked(AActor* TouchedActor, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *TouchedActor->GetActorNameOrLabel());
}*/


