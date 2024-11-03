// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TASpawnerTrash.generated.h"

class AFA_Trash;

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
    void SpawningActor();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float DelaySpawning = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TSubclassOf<AFA_Trash> SpawnClass;

private:
    FTimerHandle TrashHandle;

public:
    virtual void Tick(float DeltaTime) override;
};
