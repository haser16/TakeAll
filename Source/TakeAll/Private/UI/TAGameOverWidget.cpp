// Take All.haser inc.All Rights Reserved.

#include "UI/TAGameOverWidget.h"
#include "Character/TABasketCharacter.h"


int32 UTAGameOverWidget::GetScore()
{
    if (auto Character = GetCharacter())
    {
        return Character->GetScore();
    }
    return 0;
}

ATABasketCharacter* UTAGameOverWidget::GetCharacter() const
{
    return GetOwningPlayer() ? Cast<ATABasketCharacter>(GetOwningPlayerPawn()) : nullptr;
}