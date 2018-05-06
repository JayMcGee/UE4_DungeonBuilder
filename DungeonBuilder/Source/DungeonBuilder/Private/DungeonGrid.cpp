// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGrid.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADungeonGrid::ADungeonGrid()
{

}

// Called when the game starts or when spawned
void ADungeonGrid::BeginPlay()
{
	Super::BeginPlay();

	const int32 AmountOfGridBlocks = GridSize * GridSize;
		
	for ( int32 idx = 0; idx < AmountOfGridBlocks; idx++)
	{
		float const GridExtent = (GridSize * GridBlockSize) / 2;
		float const NewBlockX = (idx % GridSize) * GridBlockSize - GridExtent; 
		float const NewBlockY = (idx / GridSize) * GridBlockSize - GridExtent;

		FGridBlock NewGridBlock;
		NewGridBlock.GridBlockWorldCoordinates = FVector2D( NewBlockX, NewBlockY);				
		GridBlocks.Add(NewGridBlock);
	}

	if (bDrawDebugGrid )
	{
		DrawDebugGrid();
	}
	
}

void ADungeonGrid::DrawDebugGrid()
{
	for (FGridBlock GridBlock : GridBlocks)
	{
		FColor LocalDebugColor = GridBlock.bIsOccupied ? FColor::Red : DebugColor;
		FVector const DebugPosition = FVector(GridBlock.GridBlockWorldCoordinates.X, GridBlock.GridBlockWorldCoordinates.Y, 0.f);
		DrawDebugPoint(GetWorld(), DebugPosition, 2.f, FColor::Purple, true);
		FBox DebugBox = FBox::BuildAABB(DebugPosition, FVector(GridBlockSize / 2, GridBlockSize / 2, 0));
		DrawDebugBox(GetWorld(), DebugBox.GetCenter(), DebugBox.GetExtent(), FQuat::Identity, LocalDebugColor, true, -1.f, 0, 1);
	}
}

