// Copyright Epic Games, Inc. All Rights Reserved.

#include "TakeAllGameModeBase.h"
#include "TA_BusketCharacter.h"
#include "UI/TAGameHUD.h"

ATakeAllGameModeBase::ATakeAllGameModeBase()
{
    DefaultPawnClass = ATA_BusketCharacter::StaticClass();
    HUDClass = ATAGameHUD::StaticClass();
}

void ATakeAllGameModeBase::StartPlay()
{
	Super::StartPlay();

	GetWorld()->GetTimerManager().SetTimer(GameRoundTimerHandle, this, &ATakeAllGameModeBase::RoundTimerUpdate, 1.f,
										   true);
}

void ATakeAllGameModeBase::RoundTimerUpdate()
{
	if (SecondsRound < RoundTime)
		SecondsRound++;
	else if (SecondsRound == RoundTime)
		OnStopTimer();
}

void ATakeAllGameModeBase::OnStopTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(GameRoundTimerHandle);

	OnGameStopped.Broadcast();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	ACharacter* Character = PlayerController->GetCharacter();
	Character->TornOff();
	Character->DisableInput(nullptr);
}
