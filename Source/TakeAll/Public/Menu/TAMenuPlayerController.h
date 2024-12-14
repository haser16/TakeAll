// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TAMenuPlayerController.generated.h"

UCLASS()
class TAKEALL_API ATAMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
	
};
