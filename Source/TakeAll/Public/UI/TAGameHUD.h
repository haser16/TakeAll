// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/HUD.h"
#include "TAGameHUD.generated.h"

UCLASS()
class TAKEALL_API ATAGameHUD : public AHUD
{
    GENERATED_BODY()

    virtual void DrawHUD() override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameStaticUserWidget;

    UUserWidget* PlayerHUDWidget;

    class ATABasketCharacter* GetOwnCharacter() const;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> GameOverWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
    TSubclassOf<UUserWidget> PauseWidget;

private:
    void ClearViewport() const ;
    void AddStatisticToViewport() const;
    void AddPauseScreenToViewPort() const;
    void OnMatchStateChanged(ETAMatchState State) const;
};