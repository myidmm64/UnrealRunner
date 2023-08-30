#include "Electric.h"
#include "GameFramework/FloatingPawnMovement.h"

AElectric::AElectric()
{
    PrimaryActorTick.bCanEverTick = true;
    MovementSpeed = 500.0f;
    CurrentMovementDirection = FVector::ForwardVector; // �ʱ� �̵� ���� ����
}

void AElectric::BeginPlay()
{
    Super::BeginPlay();
}

void AElectric::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MoveForward(1.0f);
}

void AElectric::MoveForward(float Value)
{
    FVector Movement = CurrentMovementDirection * Value * MovementSpeed * GetWorld()->GetDeltaSeconds();
    AddActorLocalOffset(Movement);
}

void AElectric::SetMovementDirection(const FVector& Direction)
{
    CurrentMovementDirection = Direction.GetSafeNormal(); // �Էµ� ������ ����ȭ�Ͽ� ����
}