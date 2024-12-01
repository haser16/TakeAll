// Take All.haser inc.All Rights Reserved.


#include "UI/TAGameHUD.h"
#include "Blueprint/UserWidget.h"

void ATAGameHUD::DrawHUD()
{
	Super::DrawHUD();

	
}

void ATAGameHUD::BeginPlay()
{
    Super::BeginPlay();
    
    if (auto PlayerHUDWidget = CreateWidget<UUserWidget>( GetWorld(), GameStaticUserWidget ))
    {
        PlayerHUDWidget->AddToViewport();
    }
}
