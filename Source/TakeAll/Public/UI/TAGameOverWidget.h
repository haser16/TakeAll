// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TAGameOverWidget.generated.h"

class ATABasketCharacter;


UCLASS()
class TAKEALL_API UTAGameOverWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    int32 GetScore();


private:
    ATABasketCharacter* GetCharacter() const;
};