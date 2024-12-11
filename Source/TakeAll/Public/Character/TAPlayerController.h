// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/PlayerController.h"
#include "TAPlayerController.generated.h"

UCLASS()
class TAKEALL_API ATAPlayerController : public APlayerController
{
	GENERATED_BODY()
    ATAPlayerController();

    virtual void BeginPlay() override;
private:
    void OnMatchStateChange(ETAMatchState State);
};
