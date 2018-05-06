// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGrid.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDungeonGrid, Log, All);

USTRUCT()
struct FGridBlock
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid GridBlockId;

	UPROPERTY()
	bool bIsGridBlockEmpty = true;

	UPROPERTY()
	FVector2D GridBlockWorldCoordinates = FVector2D::ZeroVector;

	UPROPERTY()
	bool bIsOccupied = false;

	UPROPERTY()
	TSubclassOf<AActor> OccupyingActor = nullptr;
	
	//---------------------- Debug
	UPROPERTY(EditAnywhere, Category = "Debug")
	FColor DebugColor = FColor::Red;
	//---------------------- End Debug
	
};

//class FIntVector2D : public FIntVector
//{
//public:
//	FIntVector2D(const int32 X, const int32 Y)
//		: FIntVector(X, Y, 0) {}
//
//	FORCEINLINE bool operator==(const FIntVector2D& Other) const
//	{
//		return X == Other.X && Y == Other.Y;
//	}
//};
typedef FVector2D FIntVector2D;

//FORCEINLINE uint32 GetTypeHash(const FIntVector2D& Vector)
//{
//	return FCrc::MemCrc_DEPRECATED(&Vector, sizeof(FIntVector2D));
//}

//struct FRoomCell {
//	FRoomCell(const int32 MinX, const int32 MinY, const int32 MaxX, const int32 MaxY) 
//	: CellStart(MinX, MinY)
//	, CellEnd(MaxX, MaxY)
//	{
//	}
//
//	FIntVector2D CellStart, CellEnd;
//
//	FIntVector2D GetCenter() const
//	{ 
//		return FIntVector2D(((CellEnd.X - CellStart.X) / 2) + CellStart.X,
//			((CellEnd.Y - CellStart.Y) / 2) + CellStart.Y);
//	}
//
//	FIntVector GetExtent() const
//	{
//		return (CellEnd - CellStart) / 2;
//	}
//};
typedef FBox FRoomCell;

template<typename InElementType>
class TArray2D : public TArray<InElementType>
{
public:
	InElementType & operator[](const FIntVector2D& Selection)
	{
		return GetAtCoordinates(Selection.X, Selection.Y);
	}

	inline int32 GridSize() { return FMath::Sqrt(Num()); }

private:

	InElementType & operator()(const int32 X, const int32 Y)
	{
		return GetAtCoordinates(X, Y);
	}

	InElementType& GetAtCoordinates(const int32 X, const int32 Y);


};

UCLASS()
class DUNGEONBUILDER_API ADungeonGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonGrid();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Draw cells in the world 
	void DrawDebugGridCellsWorld();

	void DrawDebugRoomCells();

	void DrawDebugRoomCell(const FRoomCell& RoomCell, const FColor LocalDebugColor);

public:	

	//---------------------- Debug
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bDrawDebugGrid = false;
	//---------------------- End Debug

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 GridSize = 40;

	UPROPERTY(EditAnywhere, Category = "RoomCells")
	int32 CellSize = 5;

	UPROPERTY(EditAnywhere, Category="Grid Block")
	float GridBlockSize = 20.f;


	UPROPERTY(EditAnywhere, Category = "Rooms")
	int32 RoomQuantity = 4;


private:

	TArray2D<FGridBlock> DungeonGrid;

	TArray2D<FRoomCell> RoomCells;

	TSet<FIntVector2D> SelectedCellsPositions;

	void GenerateInitialGrid(const int32 AmountOfGridBlocks);

	void SelectRoomCells(const int32 AmountOfRooms);

	void GenerateRoomCells(TArray<FRoomCell>& RoomCells);
};
