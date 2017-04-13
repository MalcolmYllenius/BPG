// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Sensor.generated.h"

UCLASS()
class SENSORS_CODE_API ASensor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASensor();
	UPROPERTY(EditAnywhere)
	USphereComponent* detectionSphere;
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> victimsWithinProximity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
