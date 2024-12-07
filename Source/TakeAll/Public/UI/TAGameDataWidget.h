// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TAGameDataWidget.generated.h"


class ATABasketCharacter;
class ATakeAllGameModeBase;

UCLASS()
class TAKEALL_API UTAGameDataWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetTimeToOverRound() const;
	
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetGameScore() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsChangedColor() const;

private:
	ATakeAllGameModeBase* GetTAGameMode() const;
	ATABasketCharacter* GetTACharacter() const;
};
