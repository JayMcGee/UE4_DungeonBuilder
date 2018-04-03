// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"

namespace DungeonGeneratorConstant
{
	static const float Pi = 3.1415;
}


// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();

	for (int32 idx = 0; idx < NumberOfRooms; idx++)
	{
		FVector2D RandomCoordinate = GetRandomPointInCircle();
		ArrayOfRandomPointsInsideACircle.Add(RandomCoordinate);
	}
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector2D ADungeonGenerator::GetRandomPointInCircle()
{
	const float RandomRadius = 2 * DungeonGeneratorConstant::Pi * FMath::FRandRange(0, 1);
	const float RandomNumber = FMath::FRandRange(0, 1) + FMath::FRandRange(0, 1);	
	const float RandomInverseNumber = RandomNumber > 1 ? 2 - RandomNumber : RandomNumber;

	const float X = GeneratorCircleRadius * RandomInverseNumber * FMath::Cos(RandomRadius);
	const float Y = GeneratorCircleRadius * RandomInverseNumber * FMath::Sin(RandomRadius);

	return FVector2D(X, Y);
}

