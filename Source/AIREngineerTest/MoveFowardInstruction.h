// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "RobotBase.h"
#include "MoveFowardInstruction.generated.h"

/**
 * 
 */
UCLASS()
class AIRENGINEERTEST_API UMoveFowardInstruction : public URobotInstruction
{
	GENERATED_BODY()

public:
	UMoveFowardInstruction();

	UFUNCTION(BlueprintCallable, Category = Instruction)
	void MoveFoward(AActor* robot, float distance);
	
};
