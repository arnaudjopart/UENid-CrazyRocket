// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDefaultPawn.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerDefaultPawn::APlayerDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerDefaultPawn::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn::OnHit"));
}

void APlayerDefaultPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn::OnComponentHit"));
}

/*void APlayerDefaultPawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn::OnHit"));
}*/

// Called when the game starts or when spawned
void APlayerDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	Mesh = GetComponentByClass<UStaticMeshComponent>();
	Mesh->OnComponentHit.AddDynamic(this, &APlayerDefaultPawn::OnComponentHit);
}

// Called every frame
void APlayerDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float speed = Mesh->GetPhysicsLinearVelocity().Length();
	UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn: %f"),speed);

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

bool APlayerDefaultPawn::OnCollisionTrigger(AActor* Other)
{
	
	if (Mesh->GetPhysicsLinearVelocity().SquaredLength()>pow(MaxLandingSpeed,2))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerDefaultPawn::Destroy"));
		return false;
	}

	if (Other->ActorHasTag("StartPlatform")) return false;
	return true;

	
}
