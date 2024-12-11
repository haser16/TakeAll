// Take All.haser inc.All Rights Reserved.


#include "Character/TAPlayerController.h"
#include "TakeAll/TakeAllGameModeBase.h"

ATAPlayerController::ATAPlayerController()
{
}

void ATAPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        if (const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode()))
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ATAPlayerController::OnMatchStateChange);
        }
    }
}

void ATAPlayerController::OnMatchStateChange(ETAMatchState State)
{
    if (State == ETAMatchState::Paused || State == ETAMatchState::GameOver || State == ETAMatchState::WaitingToStart)
    {
        SetShowMouseCursor(true);
    }
}