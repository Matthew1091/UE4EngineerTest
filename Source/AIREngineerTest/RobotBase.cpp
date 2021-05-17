// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotBase.h"

// Sets default values
ARobotBase::ARobotBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARobotBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobotBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobotBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARobotBase::MoveFoward(float Distance)
{
}

void ARobotBase::Rotate(FRotator desiredRotation)
{
}

