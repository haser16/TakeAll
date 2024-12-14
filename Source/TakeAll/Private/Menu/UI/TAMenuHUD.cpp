// Take All.haser inc.All Rights Reserved.


#include "Menu/UI/TAMenuHUD.h"
#include "Blueprint/UserWidget.h"

void ATAMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuUserWidget)
    {
        if (const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuUserWidget))
        {
            MenuWidget->AddToViewport();
        }
    }
}