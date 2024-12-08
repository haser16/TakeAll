// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TAGoToMenuWidget.generated.h"

class UButton;

UCLASS()
class TAKEALL_API UTAGoToMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* GoToMenuButton;

    virtual void NativeOnInitialized() override;
private:
    UFUNCTION()
    void OnGoToMenu();

};