// Fill /+	out your copyright notice in the Description page of Project Settings.

#include "DungeonRoomProxy.h"


// Sets default values
ADungeonRoomProxy::ADungeonRoomProxy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RoomCollisionMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RoomCollisionMesh"));
	RootComponent = RoomCollisionMeshComp;

	// Collision handling parameters
	RoomCollisionMeshComp->SetLinearDamping(100.f);

	RoomCollisionMeshComp->GetBodyInstance()->bLockZTranslation = true;
	RoomCollisionMeshComp->GetBodyInstance()->bLockRotation = true;
	RoomCollisionMeshComp->SetConstraintMode(EDOFMode::Default);
	RoomCollisionMeshComp->SetEnableGravity(false);

	RoomCollisionMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RoomCollisionMeshComp->OnComponentHit.AddDynamic(this, &ADungeonRoomProxy::OnRoomHit);

	RoomCollisionMeshComp->bGenerateOverlapEvents = false;
}

// Called when the game starts or when spawned
void ADungeonRoomProxy::BeginPlay()
{
	Super::BeginPlay();
	

	
}

// Called every frame
void ADungeonRoomProxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
*  Set the room in resolve mode or in static mode
*/

void ADungeonRoomProxy::SetRoomPositionResolveEnabled(bool bEnable)
{
	if (RoomCollisionMeshComp)
	{
		RoomCollisionMeshComp->SetCollisionEnabled(bEnable ? ECollisionEnabled::PhysicsOnly : ECollisionEnabled::PhysicsOnly);
		

		if (bEnable)
		{
			RoomCollisionMeshComp->SetSimulatePhysics(true);
			RoomCollisionMeshComp->SetNotifyRigidBodyCollision(true);
			// Register to delegate callbacks
		}
		else
		{	
			RoomCollisionMeshComp->SetSimulatePhysics(false);
			RoomCollisionMeshComp->SetNotifyRigidBodyCollision(false);
			// Unregsiter from callbacks
		}
	}
}

void ADungeonRoomProxy::OnRoomHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("Some collision occured between %s and %s"), *GetFName().ToString(), *OtherActor->GetFName().ToString());
}

void ADungeonRoomProxy::SetRoomFromFRoom(const FRoom& RoomData)
{
	UWorld* World = GetWorld();

	if (World)
	{
		const FVector RoomLocation = FVector(RoomData.Coordinates, 0.f);
		const FRotator RoomRotation = FRotator::ZeroRotator;
		const FVector RoomScale = FVector(RoomData.RoomWidth / 100.f, RoomData.RoomLength / 100.f, 1.f);

		const FTransform RoomTransform = FTransform(RoomRotation, RoomLocation, RoomScale);
		
		SetActorTransform(RoomTransform);
	}
}

