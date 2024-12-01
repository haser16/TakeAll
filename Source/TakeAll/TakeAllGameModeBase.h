// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
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

public:
	
	int32 GetTimeRound() const { return SecondsRound; }

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Round")
	int32 RoundTime = 60;

	UFUNCTION()
	void RoundTimerUpdate();

	FOnGameStopped OnGameStopped;

private:
	FTimerHandle GameRoundTimerHandle;
	void OnStopTimer();
	int32 SecondsRound = 1;
};
