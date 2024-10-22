// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FA_Trash.generated.h"

UCLASS()
class TAKEALL_API AFA_Trash : public AActor
{
    GENERATED_BODY()

public:
    AFA_Trash();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};
