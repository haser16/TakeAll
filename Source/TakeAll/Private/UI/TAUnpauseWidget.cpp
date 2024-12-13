// Take All.haser inc.All Rights Reserved.


#include "UI/TAUnpauseWidget.h"
#include "Components/Button.h"
#include "TakeAll/TakeAllGameModeBase.h"

void UTAUnpauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (UnpauseButton)
    {
        UnpauseButton->OnClicked.AddDynamic(this, &UTAUnpauseWidget::UnPause);
    }
}

void UTAUnpauseWidget::UnPause()
{
    if (!GetWorld()) return;

    const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode());
    if (!GameMode) return;

    GameMode->SetMatchState(ETAMatchState::InProgress);
}