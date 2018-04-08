// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>

#include "DungeonRoomProxy.generated.h"

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
		bool bIsMain = false;
};

UCLASS()
class DUNGEONBUILDER_API ADungeonRoomProxy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonRoomProxy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RoomCollisionMeshComp;

	UFUNCTION(BlueprintCallable)
		void SetRoomPositionResolveEnabled(bool bEnable);

	void SetRoomFromFRoom(const FRoom& RoomData);
};
