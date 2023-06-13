// MyResource.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyResource.generated.h"

UCLASS()
class EXAM_API AMyResource : public AActor
{
    GENERATED_BODY()

public:
    AMyResource();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    bool bCanBePickedUp;

public:
    virtual void BeginPlay() override;

    bool CanBePickedUp() const;
};