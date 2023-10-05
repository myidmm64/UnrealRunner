#include "Boss.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SkeletalMeshComponent.h"

ABoss::ABoss()
{
    PrimaryActorTick.bCanEverTick = true;

    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
    MovementComponent->UpdatedComponent = RootComponent;

    MovementSpeed = 1200.0f;
    CurrentElectricIndex = 0;
}

void ABoss::BeginPlay()
{
    Super::BeginPlay();
}


void ABoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (isFront)
        MoveForward(-1.0f);
    else
        MoveForward(1.0f);

    if (isFront)
    {
        TimeSinceLastElectricSpawn += DeltaTime;
        if (TimeSinceLastElectricSpawn >= electricTimes[CurrentElectricIndex])
        {
            if (ElectricClasses.IsValidIndex(CurrentElectricIndex))
            {
                SpawnElectric();
                CurrentElectricIndex++;
                if (CurrentElectricIndex >= ElectricClasses.Num())
                {
                    CurrentElectricIndex = 0;
                }
            }
            TimeSinceLastElectricSpawn = 0.0f;
        }
    }
}

void ABoss::MoveForward(float Value)
{
    FVector ForwardVector = GetActorForwardVector();
    FVector Movement = ForwardVector * Value * MovementSpeed;
    MovementComponent->AddInputVector(Movement);
}

void ABoss::SpawnElectric()
{
    UWorld* World = GetWorld();
    if (World && ElectricClasses.IsValidIndex(CurrentElectricIndex))
    {
        FVector SpawnLocation = GetActorLocation(); // Boss의 위치를 사용
        SpawnLocation.Y += 1500.0f;
        FRotator SpawnRotation = GetActorRotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AActor* NewElectric = World->SpawnActor<AActor>(ElectricClasses[CurrentElectricIndex], SpawnLocation, SpawnRotation, SpawnParams);
    }
}