// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameHUD.h"
#include "Blueprint/WidgetTree.h"
#include "TakeAll/TakeAllGameModeBase.h"

void ATAGameHUD::DrawHUD()
{
    Super::DrawHUD();
}

void ATAGameHUD::BeginPlay()
{
    Super::BeginPlay();
    
    if (GetWorld())
    {
        if (const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode()))
        {
            GameMode->OnMatchStateChanged.AddUObject(this,&ATAGameHUD::OnMatchStateChanged);
        }
    }

    StartPlay();
}

void ATAGameHUD::StartPlay()
{
    GameWidgets.Add(ETAMatchState::GameOver, CreateWidget<UUserWidget>(GetWorld(), GameOverWidget));
    GameWidgets.Add(ETAMatchState::Paused, CreateWidget<UUserWidget>(GetWorld(), PauseWidget));
    GameWidgets.Add(ETAMatchState::InProgress, CreateWidget<UUserWidget>(GetWorld(), GameStaticUserWidget));

    for (const auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget) continue;

        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}


void ATAGameHUD::OnMatchStateChanged(ETAMatchState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }
    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
    }
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }
}
