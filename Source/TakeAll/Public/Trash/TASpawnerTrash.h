// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/Actor.h"
#include "TASpawnerTrash.generated.h"

class AFATrash;

UCLASS()
class TAKEALL_API ATASpawnerTrash : public AActor
{
    GENERATED_BODY()

public:
    ATASpawnerTrash();

protected:
    virtual void BeginPlay() override;

protected:
    UFUNCTION()
    void SpawningActor() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float DelaySpawning = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TSubclassOf<AFATrash> SpawnClass;

private:
    FTimerHandle TrashHandle;
    int32 Time = 1;

    UFUNCTION()
    void OnMatchStateChanged(ETAMatchState State);

    void StartGame();
};