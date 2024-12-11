// Take All.haser inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TACoreTypes.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TABasketCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGamePause);

UCLASS()
class TAKEALL_API ATABasketCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATABasketCharacter();

protected:
    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMeshTop;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMeshDown;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "BusketInput")
    UInputAction* MoveRight;
    
    UPROPERTY(EditDefaultsOnly, Category = "BusketInput")
    UInputAction* Pause;

    UPROPERTY(EditDefaultsOnly, Category = "BusketInput")
    UInputMappingContext* InputMapping;

protected:
    UFUNCTION()
    void OnBeginTrashOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
        const FHitResult& SweepResult);

public:
    virtual void Tick(float DeltaTime) override;

    int32 GetScore() const { return Score; };

    FOnGamePause OnGamePause;

private:
    void OnMoveRight(const FInputActionValue& Value);
    int32 Score = 0;
    void OnPause(const FInputActionValue& Value);

    void OnMatchStateChanged(ETAMatchState State);
};
