// Fill out your copyright notice in the Description page of Project Settings.

#include "Sensors_Code.h"
#include "VictimLocation.h"


// Sets default values
AVictimLocation::AVictimLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* sphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	RootComponent = sphere;
	sphere->InitSphereRadius(50.0f);
	collisionSphere = sphere;

	USoundWave* audio = CreateDefaultSubobject<USoundWave>(TEXT("VictimAudio"));
	victimAudio = audio;
}

// Called when the game starts or when spawned
void AVictimLocation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVictimLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USoundWave* AVictimLocation::GetAudio()
{
	return victimAudio;
}

