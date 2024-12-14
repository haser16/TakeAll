// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GenericPlatform/GenericPlatformSplash.h"
#include "TAGameInstance.generated.h"

UCLASS()
class TAKEALL_API UTAGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    FName GetMenuLevelName() const {return MenuLevelName;}
    FName GetFabricLevelName() const {return FabricLevelName;}

protected:
    UPROPERTY(EditDefaultsOnly, Category = Game)
    FName MenuLevelName = NAME_None;

    UPROPERTY(EditDefaultsOnly, Category = Game)
    FName FabricLevelName = NAME_None;
};