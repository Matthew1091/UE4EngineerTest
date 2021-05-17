// Fill out your copyright notice in the Description page of Project Settings.


#include "Dropper.h"

ADropper::ADropper() {
    this->AIControllerClass = ConstructorHelpers::FClassFinder<AAIController>(TEXT("/Game/BehaviorTrees/DropperAIController")).Class;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid'"));

    meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    meshComponent->SetupAttachment(this->GetRootComponent());
    meshComponent->SetStaticMesh(Mesh.Object);
}

void ADropper::PlaceSphere(FVector location, FRotator rotation)
{
    FActorSpawnParameters spawnInfo;
    GetWorld()->SpawnActor<ATargetSphere>(location, rotation, spawnInfo);
}

void ADropper::MoveFoward(float Distance)
{
    moveSpeed = Distance;
}

void ADropper::Rotate(FRotator desiredRotation)
{
    this->SetActorRotation(desiredRotation, ETeleportType::None);
}

void ADropper::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    this->GetActorForwardVector();

    FVector DesiredMovementDirection = this->GetActorForwardVector();
    FVector CurrentPos = GetActorLocation();
    CurrentPos.X += DesiredMovementDirection.X * moveSpeed * DeltaTime;
    CurrentPos.Y += DesiredMovementDirection.Y * moveSpeed * DeltaTime;
    SetActorLocation(CurrentPos);
}