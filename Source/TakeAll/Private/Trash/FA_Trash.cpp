// Take All.haser inc.All Rights Reserved.

#include "Trash/FA_Trash.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "TA_BusketCharacter.h"

AFA_Trash::AFA_Trash()
{
    PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh Component");
    StaticMesh->SetSimulatePhysics(true);
    StaticMesh->SetupAttachment(RootComponent);

    CollisionSphere = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionSphere->SetSphereRadius(SphereRadius);
    CollisionSphere->SetupAttachment(RootComponent);
}

void AFA_Trash::BeginPlay()
{
    Super::BeginPlay();
}
