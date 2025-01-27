#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class ETAMatchState: uint8
{
    Menu=0,
    WaitingToStart,
    InProgress,
    Paused,
    GameOver,
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChanged, ETAMatchState);