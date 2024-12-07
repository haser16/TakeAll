// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Kismet/GameplayStatics.h"

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
    ATakeAllGameModeBase* GameMode = Cast<ATakeAllGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
    GameMode->OnGameStopped.AddDynamic(this, &ATAGameHUD::OnGameStopped);

}

void ATAGameHUD::OnGameStopped()
{
    if (PlayerHUDWidget) { PlayerHUDWidget->RemoveFromViewport(); }

    if (auto PlayerStatWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidget))
    {
        PlayerStatWidget->AddToViewport();
    }
}