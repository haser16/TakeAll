// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FATrash.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class TAKEALL_API AFATrash : public AActor
{
    GENERATED_BODY()

public:
    AFATrash();

protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    USphereComponent* CollisionSphere;

protected:
    UFUNCTION()
    void DestroyActor();

private:
    float SphereRadius = 20.f;

    FTimerHandle DestroyTimer;
    float DestroyDelay = 3.f;

protected:
    virtual void BeginPlay() override;
};