// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SkeletalMeshComponent.h"

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create FloatingPawnMovementComponent
    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
    MovementComponent->UpdatedComponent = RootComponent;

    MovementSpeed = 1200.0f;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();
}

void ABoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // AI Logic
    MoveForward(1.0f); // Move forward with maximum speed
}

void ABoss::MoveForward(float Value)
{
    FVector ForwardVector = GetActorForwardVector();
    FVector Movement = ForwardVector * Value * MovementSpeed;
    MovementComponent->AddInputVector(Movement);
}