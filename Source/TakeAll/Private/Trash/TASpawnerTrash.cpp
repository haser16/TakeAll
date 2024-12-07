// Take All.haser inc.All Rights Reserved.

#include "Trash/TASpawnerTrash.h"
#include "Trash/FATrash.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(TrashSpawner, All, All);


ATASpawnerTrash::ATASpawnerTrash()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATASpawnerTrash::BeginPlay()
{
    Super::BeginPlay();

    StartGame();
}

void ATASpawnerTrash::StartGame()
{
    DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 30, FColor::Red, false, -1.f);
    ATakeAllGameModeBase* GameMode = Cast<ATakeAllGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(TrashHandle, this, &ATASpawnerTrash::SpawningActor, DelaySpawning, true);
    }

    GameMode->OnGameStopped.AddDynamic(this, &ATASpawnerTrash::OnGameStopped);
}

void ATASpawnerTrash::OnGameStopped()
{
    UE_LOG(TrashSpawner, Display, TEXT("The trash is stopped spawn."));

    GetWorld()->GetTimerManager().ClearTimer(TrashHandle);
}

void ATASpawnerTrash::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATASpawnerTrash::SpawningActor() const
{
    if (FMath::RandBool())
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        GetWorld()->SpawnActor<AFATrash>(SpawnClass, GetActorLocation(), GetActorRotation(), SpawnParams);
    }
}