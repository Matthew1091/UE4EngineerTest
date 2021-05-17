// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "RobotBase.h"
#include "RotateInstruction.generated.h"

/**
 * 
 */
UCLASS()
class AIRENGINEERTEST_API URotateInstruction : public URobotInstruction
{
	GENERATED_BODY()

public:
	URotateInstruction();

	UFUNCTION(BlueprintCallable, Category = Instruction)
	void Rotate(AActor* robot, FRotator desiredRotation);
	
};
