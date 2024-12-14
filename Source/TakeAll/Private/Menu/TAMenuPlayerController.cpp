// Take All.haser inc.All Rights Reserved.


#include "Menu/TAMenuPlayerController.h"

void ATAMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}