// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>

#include "DungeonBuilderUtils.h"

#include "DungeonRoomProxy.generated.h"



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
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RoomCollisionMeshComp;

	UFUNCTION(BlueprintCallable)
		void SetRoomPositionResolveEnabled(bool bEnable);

	UFUNCTION()
	void OnRoomHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void SetRoomFromFRoom(const FRoom& RoomData);
};
