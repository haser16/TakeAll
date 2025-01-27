// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/TABaseCharacter.h"
#include "TABasketCharacter.generated.h"

UCLASS()
class TAKEALL_API ATABasketCharacter : public ATABaseCharacter
{
    GENERATED_BODY()

public:
    ATABasketCharacter();

protected:
    virtual void BeginPlay() override;


};
