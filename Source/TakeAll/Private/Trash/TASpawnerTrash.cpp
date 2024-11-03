// Take All.haser inc.All Rights Reserved.

#include "Trash/TASpawnerTrash.h"
#include "Trash/FA_Trash.h"
#include "Components/DrawSphereComponent.h"

ATASpawnerTrash::ATASpawnerTrash()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATASpawnerTrash::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(TrashHandle, this, &ATASpawnerTrash::SpawningActor, DelaySpawning, true);
    DrawDebugSphere(GetWorld(), GetActorLocation(), 20.f, 20, FColor::Black, true, -1.0f);
}

void ATASpawnerTrash::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATASpawnerTrash::SpawningActor() 
{
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    GetWorld()->SpawnActor<AFA_Trash>(SpawnClass, GetActorLocation(), GetActorRotation(), SpawnParams);
}
