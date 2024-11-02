// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FA_Trash.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class TAKEALL_API AFA_Trash : public AActor
{
    GENERATED_BODY()

public:
    AFA_Trash();

protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    USphereComponent* CollisionSphere;
    

private:
    float SphereRadius = 20.f;

protected:
    virtual void BeginPlay() override;
};
