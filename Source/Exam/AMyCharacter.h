// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AMyCharacter.generated.h"

UCLASS()
class EXAM_API AAMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	float InteractionDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	class AMyResource* CurrentResource;

	void CheckForResource();

	void Interact();

private:	
	virtual void Tick(float DeltaTime) override;

	void CollectResource();

	void DropResource();

	void PauseGame();
};
