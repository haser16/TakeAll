// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameDataWidget.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Character/TABasketCharacter.h"

int32 UTAGameDataWidget::GetTimeToOverRound() const
{
    const auto GameMode = GetTAGameMode();
    return GameMode ? GameMode->GetTimeRoundEnded() : 0;
}

int32 UTAGameDataWidget::GetGameScore() const
{
    const auto PlayerState = GetTACharacter();
    return PlayerState ? PlayerState->GetScore() : 0;
}

ATakeAllGameModeBase* UTAGameDataWidget::GetTAGameMode() const
{
    return GetWorld() ? Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}

bool UTAGameDataWidget::IsChangedColor() const
{
    const auto GameMode = GetTAGameMode();
    float Fraction = 4.f / 5.f;
    int32 IsTime = GameMode->GetRoundTime() * Fraction;

    return GameMode ? GameMode->GetTimeRoundEnded() >= IsTime : false;
}

ATABasketCharacter* UTAGameDataWidget::GetTACharacter() const
{
    return GetOwningPlayer() ? Cast<ATABasketCharacter>(GetOwningPlayerPawn()) : nullptr;
}