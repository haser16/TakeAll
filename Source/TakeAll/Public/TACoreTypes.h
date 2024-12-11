#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class ETAMatchState: uint8
{
    WaitingToStart = 0,
    InProgress,
    Paused,
    GameOver,
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChanged, ETAMatchState);