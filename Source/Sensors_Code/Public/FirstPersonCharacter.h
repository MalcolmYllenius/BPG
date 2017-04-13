// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class SENSORS_CODE_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> sensorsPlaced;
	UPROPERTY(EditAnywhere)
	FKey sensorKey = EKeys::F;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
