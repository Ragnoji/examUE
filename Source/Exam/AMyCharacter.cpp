#include "AMyCharacter.h"
#include "MyResource.h"
#include "Blueprint/UserWidget.h"
#include "MyPauseWidgetComponent.h"

AAMyCharacter::AAMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    InteractionDistance = 200.0f;
}

void AAMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AAMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CheckForResource();
}

void AAMyCharacter::CheckForResource()
{
    FVector StartLocation = GetActorLocation();
    FVector EndLocation = StartLocation + GetActorForwardVector() * InteractionDistance;
    FHitResult HitResult;
    FCollisionQueryParams TraceParams(FName(TEXT("ResourceTrace")), true, this);

    GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);

    AMyResource* HitResource = Cast<AMyResource>(HitResult.GetActor());

    if (HitResource && HitResource->CanBePickedUp())
    {
        CurrentResource = HitResource;
    }
    else
    {
        CurrentResource = nullptr;
    }
}

void AAMyCharacter::Interact()
{
    if (CurrentResource)
    {
        CollectResource();
    }
}

void AAMyCharacter::CollectResource()
{
    if (CurrentResource)
    {
        CurrentResource->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GripPoint");
        CurrentResource->SetActorEnableCollision(false);
    }
}

void AAMyCharacter::DropResource()
{
    if (CurrentResource)
    {
        CurrentResource->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        CurrentResource->SetActorEnableCollision(true);
        CurrentResource = nullptr;
    }
}

void AAMyCharacter::PauseGame()
{
    if (UGameplayStatics::IsGamePaused(GetWorld()))
    {
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        UUserWidget* PauseWidget = CreateWidget<UUserWidget>(GetWorld(), UMyPauseWidgetComponent::StaticClass());
        if (PauseWidget)
        {
            PauseWidget->AddToViewport();
        }
    }
    else
    {
        UGameplayStatics::SetGamePaused(GetWorld(), true);
    }
}