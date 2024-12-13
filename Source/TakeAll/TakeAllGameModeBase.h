// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/GameModeBase.h"
#include "TakeAllGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStopped);

UCLASS()
class TAKEALL_API ATakeAllGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATakeAllGameModeBase();

	virtual void StartPlay() override;
	
	int32 GetTimeRoundEnded() const { return SecondsRound; }
	int32 GetRoundTime() const { return RoundTime; }
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Round")
	int32 RoundTime = 60;

	UFUNCTION()
	void RoundTimerUpdate();

	FOnGameStopped OnGameStopped;
    FOnMatchStateChanged OnMatchStateChanged;

private:
    ETAMatchState MatchState = ETAMatchState::WaitingToStart;
	FTimerHandle GameRoundTimerHandle;
	void OnStopGame();
	int32 SecondsRound = 1;
    void OnMatchStateChange(ETAMatchState State);

public:
    void SetMatchState(ETAMatchState State);
};
