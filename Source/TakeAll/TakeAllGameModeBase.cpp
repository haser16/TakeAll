// Copyright Epic Games, Inc. All Rights Reserved.

#include "TakeAllGameModeBase.h"
#include "Character/TABasketCharacter.h"
#include "Character/TAPlayerController.h"
#include "UI/TAGameHUD.h"

ATakeAllGameModeBase::ATakeAllGameModeBase()
{
    DefaultPawnClass = ATABasketCharacter::StaticClass();
    HUDClass = ATAGameHUD::StaticClass();
    PlayerControllerClass = ATAPlayerController::StaticClass();
}

void ATakeAllGameModeBase::StartPlay()
{
    Super::StartPlay();

    GetWorld()->GetTimerManager().SetTimer(GameRoundTimerHandle, this, &ATakeAllGameModeBase::RoundTimerUpdate, 1.f,
        true);

    SetMatchState(ETAMatchState::InProgress);
}

void ATakeAllGameModeBase::RoundTimerUpdate()
{
    if (SecondsRound < RoundTime)
        SecondsRound++;
    else if (SecondsRound == RoundTime)
        OnStopGame();
}

void ATakeAllGameModeBase::OnStopGame()
{
    GetWorld()->GetTimerManager().ClearTimer(GameRoundTimerHandle);
    SetMatchState(ETAMatchState::GameOver);
}


void ATakeAllGameModeBase::SetMatchState(ETAMatchState State)
{
    if (MatchState == State) { return; }

    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}