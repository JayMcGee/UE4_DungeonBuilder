// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGrid.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY(LogDungeonGrid);

// Sets default values
ADungeonGrid::ADungeonGrid()
{}

// Called when the game starts or when spawned
void ADungeonGrid::BeginPlay()
{
	Super::BeginPlay();

	const int32 AmountOfGridBlocks = GridSize * GridSize;
		
	// Start by creating the inital grid blocks
	GenerateInitialGrid(AmountOfGridBlocks);

	/* http://roguebasin.roguelikedevelopment.org/index.php?title=Grid_Based_Dungeon_Generator */

	// Then generate room cells that will be used to place rooms in the grid
	GenerateRoomCells(RoomCells);

	// Select some room cells depending on room quantity
	SelectRoomCells(RoomQuantity);

	// Using the selected room cells create actual rooms with the grid

	// Add delaunay Triangulation to select connections between actual final rooms with their extents

	// Add tunnel creation algorithm here

	if (bDrawDebugGrid )
	{
		DrawDebugGridCellsWorld();
	}
	
}

template <typename InElementType>
InElementType& TArray2D<InElementType>::GetAtCoordinates(const int32 X, const int32 Y)
{
	check(Num());
	int32 idx = X + (Y * GridSize());
	if (idx >= Num())
	{
		UE_LOG(LogDungeonGrid, Error, TEXT("Bad coordinates : X = %d, Y = %d. Returning first item"), X, Y);
		idx = 0;
	}
	return GetData()[idx];
}


void ADungeonGrid::GenerateInitialGrid(const int32 AmountOfGridBlocks)
{
	// Check that this is called once on a grid only
	check(DungeonGrid.Num() == 0);

	for (int32 idx = 0; idx < AmountOfGridBlocks; idx++)
	{
		float const GridExtent = (GridSize * GridBlockSize) / 2;

		float const NewBlockX = (idx % GridSize) * GridBlockSize - GridExtent;
		float const NewBlockY = (idx / GridSize) * GridBlockSize - GridExtent;

		FGridBlock NewGridBlock;
		NewGridBlock.GridBlockWorldCoordinates = FVector2D(NewBlockX, NewBlockY);
		DungeonGrid.Add(NewGridBlock);
	}
}

void ADungeonGrid::SelectRoomCells(const int32 AmountOfRooms)
{
	// Get random point in the grid using the size of the grid to find some points
	// Check that the size of the grid is bigger than 2
	check(GridSize > 2);

	const int32 CellCount1D = GridSize / CellSize;

	SelectedCellsPositions.Empty();

	// Select 6 room cells
	// Rinse and repeat until we have filled the grid with the amount of rooms
	for (int i = 0; i < AmountOfRooms; i++)
	{
		// While we have duplicate coordinates, search for more TODO : add safety if there's not enough cells 
		bool bIsAlreadySet = false;
		do 
		{
			// Select point in the gridblocks
			const int32 RandomX = FMath::RandRange(0, CellCount1D - 1);
			const int32 RandomY = FMath::RandRange(0, CellCount1D - 1);
			UE_LOG(LogDungeonGrid, Log, TEXT(" Room cell tested is  : %d, %d"), RandomX, RandomY);

			SelectedCellsPositions.Add(FIntVector2D(RandomX, RandomY), &bIsAlreadySet);
		} while (bIsAlreadySet);
	}

	// Display these room cells
	for (const FIntVector2D& Elem : SelectedCellsPositions)
	{
		const FRoomCell& SelectedRoomCell = RoomCells[Elem];
		DrawDebugRoomCell(SelectedRoomCell, FColor::Blue);
	}	
}

void ADungeonGrid::GenerateRoomCells(TArray<FRoomCell>& RoomCells)
{
	RoomCells.Empty();

	const int32 CellCount1D = GridSize / CellSize;
	const int32 CellCountRemains = GridSize % CellSize;

	// Uneven cell counts and grid size results
	if (CellCountRemains > 0)
	{
		UE_LOG(LogDungeonGrid, Warning, TEXT("The cell count remains = %d"), CellCountRemains);
	}

	const int32 CellCount = CellCount1D * CellCount1D;
	if (CellCount1D > 0)
	{
		// Iterate and create equal sized cells, that will be used to create rooms
		UE_LOG(LogDungeonGrid, Log, TEXT("The cell count is %d, generating the cells for room creation"), CellCount);
		for (int idx = 0; idx < CellCount; idx++)
		{
			const int32 MinX = (idx % CellCount1D) * CellSize;
			const int32 MinY = (idx / CellCount1D) * CellSize;

			const int32 MaxX = MinX + CellSize;
			const int32 MaxY = MinY + CellSize;

			RoomCells.Add(FRoomCell(FVector(MinX, MinY, 0), FVector(MaxX, MaxY, 0)));
		}
	}
	else
	{
		UE_LOG(LogDungeonGrid, Error, TEXT("The cell count is %d, should be atleast 1"), CellCount);
	}
	DrawDebugRoomCells();
}


void ADungeonGrid::DrawDebugGridCellsWorld()
{
	for (FGridBlock GridBlock : DungeonGrid)
	{
		FColor const LocalDebugColor = GridBlock.DebugColor;
		FVector const DebugPosition = FVector(GridBlock.GridBlockWorldCoordinates.X, GridBlock.GridBlockWorldCoordinates.Y, 0.f);
		DrawDebugPoint(GetWorld(), DebugPosition, 2.f, FColor::Purple, true);
		FBox DebugBox = FBox::BuildAABB(DebugPosition, FVector(GridBlockSize / 2, GridBlockSize / 2, 0));
		DrawDebugBox(GetWorld(), DebugBox.GetCenter(), DebugBox.GetExtent(), FQuat::Identity, LocalDebugColor, true, -1.f, 0, 1);
	}
}

void ADungeonGrid::DrawDebugRoomCells()
{
	const int32 CellCount1D = GridSize / CellSize;
	for (int32 idx = 0; idx < RoomCells.Num(); idx++)
	{
		int32 const X = (idx % CellCount1D);
		int32 const Y = (idx / CellCount1D);

		FRoomCell& SelectedRoomCell = RoomCells[FIntVector2D(X, Y)];
		DrawDebugRoomCell(SelectedRoomCell, FColor::Green);
	}
}

void ADungeonGrid::DrawDebugRoomCell(const FRoomCell& RoomCell, const FColor LocalDebugColor)
{
	const FVector Center = RoomCell.GetCenter();
	const FVector Extent = RoomCell.GetExtent();

	DrawDebugPoint(GetWorld(), Center, 2.f, FColor::Purple, true);
	FBox DebugBox = FBox::BuildAABB(Center, FVector(GridBlockSize / 2, GridBlockSize / 2, 0));
	DrawDebugBox(GetWorld(), Center, Extent, FQuat::Identity, LocalDebugColor, true, -1.f, 0, 1);
}
