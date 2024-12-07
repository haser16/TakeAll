// Take All.haser inc.All Rights Reserved.

#include "Trash/TASpawnerTrash.h"
#include "Trash/FA_Trash.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Kismet/GameplayStatics.h"

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
    int32 IsSpawn = FMath::RandRange(0, 10);
    FString Message = FString::Printf(TEXT("IsSpawn: %d"), IsSpawn);
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
    if (IsSpawn < 5)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        GetWorld()->SpawnActor<AFA_Trash>(SpawnClass, GetActorLocation(), GetActorRotation(), SpawnParams);
    }
}