// Take All.haser inc.All Rights Reserved.

#include "Trash/FATrash.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

AFATrash::AFATrash()
{
    PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh Component");
    StaticMesh->SetSimulatePhysics(true);
    StaticMesh->SetupAttachment(RootComponent);

    CollisionSphere = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionSphere->SetSphereRadius(SphereRadius);
    CollisionSphere->SetupAttachment(RootComponent);
}

void AFATrash::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(DestroyTimer, this, &AFATrash::DestroyActor, DestroyDelay, false);
    }
}

void AFATrash::DestroyActor()
{
    Destroy();
}