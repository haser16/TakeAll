// Take All.haser inc.All Rights Reserved.


#include "UI/TAGoToMenuWidget.h"
#include "Components/Button.h"
#include "TAGameInstance.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogTAGoToMenuWidget, Log, All);

void UTAGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GoToMenuButton)
    {
        GoToMenuButton->OnClicked.AddDynamic(this, &UTAGoToMenuWidget::OnGoToMenu);
    }
}

void UTAGoToMenuWidget::OnGoToMenu()
{
    if (!GetWorld()) return;

    const auto GameInstance = GetWorld()->GetGameInstance<UTAGameInstance>();
    if (!GameInstance) return;

    if (GameInstance->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogTAGoToMenuWidget, Error, TEXT("Please set name menu level name in Game Instance."))
        return;
    }
    UGameplayStatics::OpenLevel(this, GameInstance->GetMenuLevelName());
}