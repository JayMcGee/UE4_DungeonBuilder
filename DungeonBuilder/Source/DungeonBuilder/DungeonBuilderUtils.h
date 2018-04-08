// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DungeonBuilderUtils.generated.h"

namespace DungeonGeneratorConstant
{
	static const float Pi = 3.1415f;
	static const float OneMeter = 100.f;
}

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
