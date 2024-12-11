// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Character/TABasketCharacter.h"

void ATAGameHUD::DrawHUD()
{
    Super::DrawHUD();
}

void ATAGameHUD::BeginPlay()
{
    Super::BeginPlay();
    PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), GameStaticUserWidget);
    if (PlayerHUDWidget)
    {
        PlayerHUDWidget->AddToViewport();
    }

    if (GetWorld())
    {
        if (const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode()))
        {
            GameMode->OnMatchStateChanged.AddUObject(this,&ATAGameHUD::OnMatchStateChanged);
        }
    }
}

void ATAGameHUD::ClearViewport() const 
{
    if (PlayerHUDWidget) { PlayerHUDWidget->RemoveFromParent(); }
}

void ATAGameHUD::AddStatisticToViewport() const
{
    if (const auto PlayerStatWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidget))
    {
        PlayerStatWidget->AddToViewport();
    }
}

void ATAGameHUD::AddPauseScreenToViewPort() const
{
    if (const auto Pause = CreateWidget<UUserWidget>(GetWorld(), PauseWidget))
    {
        Pause->AddToViewport();
    }
}

void ATAGameHUD::OnMatchStateChanged(ETAMatchState State) const
{
    if (State == ETAMatchState::GameOver)
    {
        ClearViewport();
        AddStatisticToViewport();
    }
    else if (State == ETAMatchState::Paused)
    {
        ClearViewport();
        AddPauseScreenToViewPort();
    }
}

ATABasketCharacter* ATAGameHUD::GetOwnCharacter() const
{
    return GetOwningPlayerController() ? Cast<ATABasketCharacter>(GetOwningPlayerController()->GetPawn()) : nullptr;
}