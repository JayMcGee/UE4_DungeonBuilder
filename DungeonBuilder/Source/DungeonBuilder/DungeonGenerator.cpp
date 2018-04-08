// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"
#include "DrawDebugHelpers.h"
#include "DungeonRoomProxy.h"

namespace DungeonGeneratorConstant
{
	static int32 GDebugGenerator = 0;
	FAutoConsoleVariableRef CVarDungeonGeneratorVisualization(TEXT("DGen.DrawDebug"), GDebugGenerator, TEXT(" 0 = Disable, 1 = Enable"));

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

		RandomRoom.RoomId = FGuid::NewGuid();
		RandomRoom.Coordinates = GetRandomPointInCircle();;
		RandomRoom.RoomWidth = RoundFloatToGrid(FMath::FRandRange(MinimumRoomWidth, MaximumRoomWidth), GeneratorGridSize);
		RandomRoom.RoomLength = RoundFloatToGrid(FMath::FRandRange(MinimumRoomLength, MaximumRoomLength), GeneratorGridSize);

		ArrayOfRandomRooms.Add(RandomRoom);
	}

	SpawnRooms();

	//// Test Only : Spawn shapes to 
#if !UE_BUILD_SHIPPING
	DrawDebugCircle(GetWorld(), FVector::ZeroVector, GeneratorCircleRadius, 50, FColor::Red, true,-1,0,4,FVector(1,0,0),FVector(0,1,0),false);
	for (FRoom Room : ArrayOfRandomRooms)
	{
		DrawDebugPoint(GetWorld(), FVector(Room.Coordinates.X, Room.Coordinates.Y, 0), 5.f, FColor::Green, true);
		// Building debug box by extent ( Diagonal from center to corner ) 
		FBox DebugBox = FBox::BuildAABB(FVector(Room.Coordinates.X, Room.Coordinates.Y, 0), FVector(Room.RoomWidth /2, Room.RoomLength /2, 0));
		DrawDebugSolidBox(GetWorld(), DebugBox, FColor::Green, FTransform::Identity, true);
	}
#endif
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADungeonGenerator::EnableRoomResolve()
{

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

void ADungeonGenerator::CalculateMeanWidthAndLength(TArray<FRoom> const& ArrayOfRooms, float& OutWidthMean, float& OutLengthMean)
{
	float WidthMean = 0;
	float LengthMean = 0;

	for (FRoom Room : ArrayOfRooms)
	{
		WidthMean += Room.RoomWidth;
		LengthMean += Room.RoomLength;
	}

	OutWidthMean = WidthMean / ArrayOfRooms.Num();
	OutLengthMean = LengthMean / ArrayOfRooms.Num();
}

void ADungeonGenerator::SpawnRooms()
{
	if (RoomProxyClass != nullptr)
	{
		UWorld* World = GetWorld();
		
		for ( FRoom RoomDescription : ArrayOfRandomRooms )
		{
			ADungeonRoomProxy* RoomProxy = World->SpawnActor<ADungeonRoomProxy>( RoomProxyClass );
			
			
			RoomProxy->SetRoomFromFRoom(RoomDescription);
		}
	}

}

