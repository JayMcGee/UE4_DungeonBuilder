// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"
#include "DrawDebugHelpers.h"

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
		FRoom RandomRoom;
		FVector2D RandomCoordinates = GetRandomPointInCircle();
		
		RandomRoom.RoomId = FGuid::NewGuid();
		RandomRoom.Coordinates = RandomCoordinates;
		RandomRoom.RoomWidth = RoundFloatToGrid(FMath::FRandRange(MinimumRoomWidth, MaximumRoomWidth), GeneratorGridSize);
		RandomRoom.RoomLength = RoundFloatToGrid(FMath::FRandRange(MinimumRoomLength, MaximumRoomLength), GeneratorGridSize);

		ArrayOfRandomRooms.Add(RandomRoom);
	}

	//// Test Only : Spawn shapes to test
	DrawDebugCircle(GetWorld(), FVector::ZeroVector, GeneratorCircleRadius, 50, FColor::Red, true,-1,0,4,FVector(1,0,0),FVector(0,1,0),false);
	for (FRoom Room : ArrayOfRandomRooms)
	{
		DrawDebugPoint(GetWorld(), FVector(Room.Coordinates.X, Room.Coordinates.Y, 0), 5.f, FColor::Green, true);
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
	
	return RoundCoordinatesToGrid(FVector2D(X, Y), GeneratorGridSize);
}

float ADungeonGenerator::RoundFloatToGrid( float InRawFloat, float GridSize )
{
	return FMath::RoundHalfToZero(InRawFloat / GridSize) * GridSize;	
}

FVector2D ADungeonGenerator::RoundCoordinatesToGrid(FVector2D InRawCoord, float GridSize)
{
	FVector2D GridAlignedCoord;
	GridAlignedCoord.X = RoundFloatToGrid(InRawCoord.X, GridSize);
	GridAlignedCoord.Y = RoundFloatToGrid(InRawCoord.Y, GridSize);

	return GridAlignedCoord;
}

