// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"
#include "DrawDebugHelpers.h"

namespace DungeonGeneratorConstant
{
	static int32 GDebugGenerator = 0;
	FAutoConsoleVariableRef CVarDungeonGeneratorVisualization(TEXT("DGen.DrawDebug"), GDebugGenerator, TEXT(" 0 = Disable, 1 = Enable"));

	static const float Pi = 3.1415f;
	static const float OneMeter = 100.f;
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

	// Build Array of Random rooms
	for (int32 idx = 0; idx < NumberOfRooms; idx++)
	{
		FRoom RandomRoom;

		RandomRoom.RoomId = FGuid::NewGuid();
		RandomRoom.Coordinates = GetRandomPointInCircle();;
		RandomRoom.RoomWidth = RoundFloatToGrid(FMath::FRandRange(MinimumRoomWidth, MaximumRoomWidth), GeneratorGridSize);
		RandomRoom.RoomLength = RoundFloatToGrid(FMath::FRandRange(MinimumRoomLength, MaximumRoomLength), GeneratorGridSize);
		RandomRoom.RoomArea = RandomRoom.RoomWidth * RandomRoom.RoomLength;

		ArrayOfRandomRooms.Add(RandomRoom);
	}

	// Post-Process Rooms
	AssigMainRooms();

	// Spawn Rooms proxy
	SpawnRoomsProxies();

	//// Test Only : Spawn shapes to 
	#if !UE_BUILD_SHIPPING
	DrawDebugCircle(GetWorld(), FVector::ZeroVector, GeneratorCircleRadius, 50, FColor::Red, true,-1,0,4,FVector(1,0,0),FVector(0,1,0),false);
	for (FRoom Room : ArrayOfRandomRooms)
	{
		// Building debug box by extent ( Diagonal from center to corner ) 
		FBox DebugBox = FBox::BuildAABB(FVector(Room.Coordinates.X, Room.Coordinates.Y, 0), FVector(Room.RoomWidth /2, Room.RoomLength /2, 0));
		FColor DebugColor = Room.bIsMain ? FColor::Red : FColor::Green;
		DrawDebugSolidBox(GetWorld(), DebugBox, DebugColor, FTransform::Identity, true);
	}
	#endif
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector2D ADungeonGenerator::GetRandomPointInCircle()
{
	/** As seen on StackOverflow : https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly */
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

void ADungeonGenerator::AssigMainRooms()
{
	if (NumberOfMainRooms > NumberOfRooms)
	{
		UE_LOG(LogTemp, Warning, TEXT("Number Of MainRooms is Higher than number of rooms -- All rooms will be MainHubs"))
		NumberOfMainRooms = NumberOfRooms;
	}

	ArrayOfRandomRooms.Sort([](const FRoom& LHS, const FRoom& RHS) { return LHS.RoomArea > RHS.RoomArea; });

	for (int32 idx = 0; idx < NumberOfMainRooms; idx++)
	{
		ArrayOfRandomRooms[idx].bIsMain = true;
	}
}

void ADungeonGenerator::SpawnRoomsProxies()
{
	if (RoomProxyClass != nullptr)
	{
		for ( FRoom RoomDescription : ArrayOfRandomRooms )
		{
			// Calculate Room Transform 
			FVector RoomLocation = FVector(RoomDescription.Coordinates.X, RoomDescription.Coordinates.Y, 0);
			FRotator RoomRotation = FRotator::ZeroRotator;
			FVector RoomScale = FVector( RoomDescription.RoomWidth / DungeonGeneratorConstant::OneMeter, RoomDescription.RoomLength / DungeonGeneratorConstant::OneMeter, 1);
			FTransform RoomTransform = FTransform(RoomRotation, RoomLocation, RoomScale);

			// Set Spawn Parameters
			FActorSpawnParameters SpawnParams = FActorSpawnParameters();
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			// Spawn RoomProxy and Scale it to desired size
			AActor* RoomProxy = GetWorld()->SpawnActor<AActor>( RoomProxyClass, RoomTransform, SpawnParams );
			if ( RoomProxy) // Room might fail to spawn
			{
				RoomProxy->SetActorScale3D(RoomScale);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing Room Proxy class"))
	}
}

