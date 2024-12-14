// Take All.haser inc.All Rights Reserved.


#include "Menu/TakeAllMenuGameModeBase.h"
#include "Menu/TAMenuPlayerController.h"
#include "Menu/UI/TAMenuHUD.h"

ATakeAllMenuGameModeBase::ATakeAllMenuGameModeBase()
{
    PlayerControllerClass = ATAMenuPlayerController::StaticClass();
    HUDClass = ATAMenuHUD::StaticClass();
}