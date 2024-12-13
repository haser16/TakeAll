// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "Blueprint/UserWidget.h"
#include "TAUnpauseWidget.generated.h"

class UButton;

UCLASS()
class TAKEALL_API UTAUnpauseWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* UnpauseButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void UnPause();

};