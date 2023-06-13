// Fill out your copyright notice in the Description page of Project Settings.


#include "MyResource.h"

AMyResource::AMyResource()
{
    PrimaryActorTick.bCanEverTick = false;
    bCanBePickedUp = true;
}

void AMyResource::BeginPlay()
{
    Super::BeginPlay();
}

bool AMyResource::CanBePickedUp() const
{
    return bCanBePickedUp;
}

