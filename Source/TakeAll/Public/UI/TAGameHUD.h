// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TAGameHUD.generated.h"

UCLASS()
class TAKEALL_API ATAGameHUD : public AHUD
{
    GENERATED_BODY()

private:
    virtual void DrawHUD() override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameStaticUserWidget;
    
    UFUNCTION()
    void OnGameStopped();

    UUserWidget* PlayerHUDWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameOverWidget;
};