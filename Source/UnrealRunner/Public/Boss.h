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

    // �߰�: Electric ���� �ֱ� �� Ÿ�̸� ����
    UPROPERTY(EditAnywhere, Category = "Spawn")
        float SpawnInterval;

    float TimeSinceLastElectricSpawn;

    // �߰�: ������ Electric Ŭ�������� �����ϴ� �迭
    UPROPERTY(EditAnywhere, Category = "Spawn")
        TArray<TSubclassOf<class AActor>> ElectricClasses;

    int32 CurrentElectricIndex; // ���� ���� ���� Electric �ε���

    void SpawnElectric();
};
