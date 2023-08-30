#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SkeletalMeshComponent.h"
#include "Boss.generated.h"

UCLASS()
class UNREALRUNNER_API ABoss : public APawn
{
    GENERATED_BODY()

public:
    ABoss();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "AI")
        void MoveForward(float Value);

private:
    UPROPERTY(EditAnyWhere, Category = Movement)
        UFloatingPawnMovement* MovementComponent;

    UPROPERTY(EditAnywhere, Category = "AI")
        float MovementSpeed;
};