// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGenerator.generated.h"

USTRUCT()
struct FRoom 
{
	GENERATED_BODY()
	
	UPROPERTY()
	FGuid RoomId;

	UPROPERTY()
	FVector2D Coordinates = FVector2D::ZeroVector;

	UPROPERTY()
	float RoomLength = 0.f;

	UPROPERTY()
	float RoomWidth = 0.f;

	UPROPERTY()
	float RoomArea = 0.f;

	UPROPERTY()
	bool bIsMain = false;
};

UCLASS()
class DUNGEONBUILDER_API ADungeonGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* The radius of the circle the rooms will initially be spawned */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	TSubclassOf<AActor> RoomProxyClass;

	/* The radius of the circle the rooms will initially be spawned */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float GeneratorCircleRadius = 100.f;

	/* The Number of rooms to be generated*/
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float NumberOfRooms = 10.f;

	/* The Number of rooms to be considered Main hubs ( Not corridors ) */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float NumberOfMainRooms = 4.f;
	
	/* The Minimum Width of a room */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float MinimumRoomWidth = 50.f;

	/* The Maximum Width of a room */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float MaximumRoomWidth = 250.f;

	/* The Minimum Length of a room */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float MinimumRoomLength = 50.f;

	/* The Maximum Length of a room */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float MaximumRoomLength = 250.f;

	/* The Maximum Length of a room */
	UPROPERTY(EditAnywhere, Category = "Dungeon Generator")
	float GeneratorGridSize = 0.5f;


private:

	FVector2D GetRandomPointInCircle();

	//------------------------ Utils
	float RoundFloatToGrid( float InRawFloat, float GridSize );
	FVector2D RoundCoordinatesToGrid( FVector2D InRawCoord, float GridSize );
	void AssigMainRooms();
	void SpawnRoomsProxies();

private:
	TArray<FRoom> ArrayOfRandomRooms;
	
};
