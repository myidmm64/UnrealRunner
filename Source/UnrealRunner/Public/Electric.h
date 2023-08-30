// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Electric.generated.h"

UCLASS()
class UNREALRUNNER_API AElectric : public APawn
{
    GENERATED_BODY()

public:
    AElectric();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Movement")
        void SetMovementDirection(const FVector& Direction);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
        class UFloatingPawnMovement* MovementComponent;

    UPROPERTY(EditAnywhere, Category = "Movement")
        float MovementSpeed;

    UPROPERTY(EditAnywhere, Category = "Movement")
    FVector CurrentMovementDirection; // 현재 이동 방향

    void MoveForward(float Value);

};
