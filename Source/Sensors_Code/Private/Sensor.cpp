// Fill out your copyright notice in the Description page of Project Settings.

#include "Sensors_Code.h"
#include "Sensor.h"
#include "VictimLocation.h"


// Sets default values
ASensor::ASensor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* sphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	RootComponent = sphere;
	sphere->InitSphereRadius(500.0f);
	detectionSphere = sphere;
}

// Called when the game starts or when spawned
void ASensor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> overlappingActors;
	detectionSphere->GetOverlappingActors(overlappingActors, AActor::StaticClass());
	for (int i = 0; i < overlappingActors.Num(); i++)
	{
		if (overlappingActors[i]->IsA(AVictimLocation::StaticClass()))
		{
			AVictimLocation* victimLocation = (AVictimLocation*)overlappingActors[i];
			bool isNew = true;
			for (int j = 0; j < victimsWithinProximity.Num(); j++)
			{
				if (victimLocation == victimsWithinProximity[j])
				{
					isNew = false;
					break;
				}
			}
			if (isNew)
				victimsWithinProximity.Add(victimLocation);
		}
	}	
}

// Called every frame
void ASensor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

