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
    UPROPERTY(VisibleAnywhere, Category = "Components")
        UFloatingPawnMovement* MovementComponent;

    UPROPERTY(EditAnywhere, Category = "Movement")
        float MovementSpeed;

    // 추가: Electric 생성 주기 및 타이머 변수
    UPROPERTY(EditAnywhere, Category = "Spawn")
        float SpawnInterval;

    float TimeSinceLastElectricSpawn;

    // 추가: 생성할 Electric 클래스들을 저장하는 배열
    UPROPERTY(EditAnywhere, Category = "Spawn")
        TArray<TSubclassOf<class AActor>> ElectricClasses;

    int32 CurrentElectricIndex; // 현재 생성 중인 Electric 인덱스

    void SpawnElectric();
};
