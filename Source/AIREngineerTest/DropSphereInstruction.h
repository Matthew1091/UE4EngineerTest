// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Dropper.h"
#include "DropSphereInstruction.generated.h"

UCLASS(Blueprintable)
class AIRENGINEERTEST_API UDropSphereInstruction : public URobotInstruction
{
	GENERATED_BODY()

public:
	UDropSphereInstruction();

	UFUNCTION(BlueprintCallable, Category = Instruction)
	void DropSphere(AActor* robot, FVector location, FRotator rotation);
	
};
