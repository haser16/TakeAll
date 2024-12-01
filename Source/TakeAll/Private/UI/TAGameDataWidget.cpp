// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameDataWidget.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "TakeAll/Public/TA_BusketCharacter.h"

int32 UTAGameDataWidget::GetTimeToOverRound() const
{
	const auto GameMode = GetTAGameMode();
	return GameMode ? GameMode->GetTimeRound() : 0;
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
ATA_BusketCharacter* UTAGameDataWidget::GetTACharacter() const
{
	return GetOwningPlayer() ? Cast<ATA_BusketCharacter>(GetOwningPlayerPawn()) : nullptr;
}
