// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Grabber.h"
#include "TakeScreenshotInstruction.generated.h"

UCLASS(Blueprintable)
class AIRENGINEERTEST_API UTakeScreenshotInstruction : public URobotInstruction
{
	GENERATED_BODY()

public:
	UTakeScreenshotInstruction();

	UFUNCTION(BlueprintCallable, Category = Instruction)
	void TakeScreenshot(AActor* robot);
};
