// Take All.haser inc.All Rights Reserved.

#include "Character/TABasketCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Trash/FATrash.h"
#include "TakeAll/TakeAllGameModeBase.h"
#include "Sound/SoundCue.h"


ATABasketCharacter::ATABasketCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->MaxWalkSpeed = 500.f;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true;

    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATABasketCharacter::OnBeginTrashOverlap);

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    StaticMeshTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshTop"));
    StaticMeshTop->SetupAttachment(GetMesh());

    StaticMeshDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshDown"));
    StaticMeshDown->SetupAttachment(GetMesh());
}

void ATABasketCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(InputMapping, 0);
        }
    }
    if (GetWorld())
    {
        if (const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode()))
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ATABasketCharacter::OnMatchStateChanged);
        }
    }
}

void ATABasketCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATABasketCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveRight, ETriggerEvent::Triggered, this, &ATABasketCharacter::OnMoveRight);
        EnhancedInputComponent->BindAction(Pause, ETriggerEvent::Triggered, this, &ATABasketCharacter::OnPause);
    }
}

void ATABasketCharacter::OnMoveRight(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void ATABasketCharacter::OnPause(const FInputActionValue& Value)
{
    if (!GetWorld()) return;

    const auto GameMode = Cast<ATakeAllGameModeBase>(GetWorld()->GetAuthGameMode());
    GameMode->SetMatchState(ETAMatchState::Paused);
}

void ATABasketCharacter::OnBeginTrashOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Score++;

    if (AFATrash* Trash = Cast<AFATrash>(OtherActor))
    {
        Trash->Destroy();
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), TrashSound, GetActorLocation());
    }
}

void ATABasketCharacter::OnMatchStateChanged(ETAMatchState State)
{
    if (State == ETAMatchState::Paused || State == ETAMatchState::GameOver)
    {
        DisableInput(nullptr);
    }
    else
    {
        EnableInput(nullptr);
    }
}

