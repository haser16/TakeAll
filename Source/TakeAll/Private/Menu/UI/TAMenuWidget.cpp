// Take All.haser inc.All Rights Reserved.


#include "Menu/UI/TAMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "TAGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(TAMenuWidgetLog, All, All);

void UTAMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UTAMenuWidget::OnStartGame);
    }
}

void UTAMenuWidget::OnStartGame()
{
    if (!GetWorld()) return;

    const auto GameInstance = GetWorld()->GetGameInstance<UTAGameInstance>();
    if (GameInstance->GetFabricLevelName().IsNone())
    {
        UE_LOG(TAMenuWidgetLog, Error, TEXT("Please set fabric level name in game instance."));
        return;
    }
    UGameplayStatics::OpenLevel(this, GameInstance->GetFabricLevelName());
}