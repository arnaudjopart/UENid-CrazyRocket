// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerDefaultPawn.generated.h"

UCLASS()
class APlayerDefaultPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerDefaultPawn();

protected:
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddThrust();
	void Rotate(float Direction);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere,category = "Movement")
	float Impulse;
	UPROPERTY(EditAnywhere, category = "Movement")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, category = "Movement")
	float MaxLandingSpeed =30;

private:
	UStaticMeshComponent* Mesh;
	UFUNCTION(BlueprintCallable)
	bool OnCollisionTrigger(AActor* Other);
};


