// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGrid.generated.h"

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
	
};

UCLASS()
class DUNGEONBUILDER_API ADungeonGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void DrawDebugGrid();

public:	

	//---------------------- Debug
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bDrawDebugGrid = true;

	UPROPERTY(EditAnywhere, Category = "Debug")
	FColor DebugColor = FColor::Purple;
	//---------------------- End Debug

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 GridSize = 20;

	UPROPERTY(EditAnywhere, Category="Grid Block")
	float GridBlockSize = 10.f;

private:
	TArray<FGridBlock> GridBlocks;
};
