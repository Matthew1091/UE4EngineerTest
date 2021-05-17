// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSphere.h"

// Sets default values
ATargetSphere::ATargetSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere'"));

    meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    meshComponent->SetupAttachment(this->GetRootComponent());
    meshComponent->SetStaticMesh(Mesh.Object);

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));

	TriggerCapsule->InitCapsuleSize(55.0f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(meshComponent);

}

// Called when the game starts or when spawned
void ATargetSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

