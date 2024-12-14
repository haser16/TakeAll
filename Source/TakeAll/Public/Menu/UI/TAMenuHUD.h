// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TAMenuHUD.generated.h"

class UUserWidget;

UCLASS()
class TAKEALL_API ATAMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
    TSubclassOf<UUserWidget> MenuUserWidget;

    virtual void BeginPlay() override;

};