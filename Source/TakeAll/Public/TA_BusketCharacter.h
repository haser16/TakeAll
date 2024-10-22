// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TA_BusketCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class TAKEALL_API ATA_BusketCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATA_BusketCharacter();

protected:
    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;

    UPROPERTY(EditDefaultsOnly, Category = "BusketInput")
    UInputAction* MoveRight;

    UPROPERTY(EditDefaultsOnly, Category = "BusketInput")
    UInputMappingContext* InputMapping;

public:
    virtual void Tick(float DeltaTime) override;

private:
    void OnMoveRight(const FInputActionValue& Value);
};
