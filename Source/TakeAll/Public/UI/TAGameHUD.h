// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/HUD.h"
#include "TAGameHUD.generated.h"

class UTAGameDataWidget;

UCLASS()
class TAKEALL_API ATAGameHUD : public AHUD
{
    GENERATED_BODY()

    virtual void DrawHUD() override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameStaticUserWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameOverWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> PauseWidget;

private:
    void OnMatchStateChanged(ETAMatchState State);

    UPROPERTY()
    TMap<ETAMatchState, UUserWidget*> GameWidgets;

    UPROPERTY()
    UUserWidget* CurrentWidget = nullptr;

    void StartPlay();
};
