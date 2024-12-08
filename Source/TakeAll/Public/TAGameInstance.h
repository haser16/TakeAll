// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TAGameInstance.generated.h"

UCLASS()
class TAKEALL_API UTAGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    FName GetMenuLevelName() const {return MenuLevelName;}

protected:
    UPROPERTY(EditDefaultsOnly, Category = Game)
    FText StartupLevelName = FText::GetEmpty();

    UPROPERTY(EditDefaultsOnly, Category = Game)
    FName MenuLevelName = NAME_None;
};