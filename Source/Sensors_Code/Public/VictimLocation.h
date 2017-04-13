// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VictimLocation.generated.h"

UCLASS()
class SENSORS_CODE_API AVictimLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVictimLocation();
	UPROPERTY(EditAnywhere)
	USphereComponent* collisionSphere;
	UPROPERTY(EditAnywhere)
	USoundWave* victimAudio;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	USoundWave* GetAudio();	
};
