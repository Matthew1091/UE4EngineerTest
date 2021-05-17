// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Grabber.h"
#include "RecordDataInstruction.generated.h"

UCLASS(Blueprintable)
class AIRENGINEERTEST_API URecordDataInstruction : public URobotInstruction
{
	GENERATED_BODY()

public:
	URecordDataInstruction();

	UFUNCTION(BlueprintCallable, Category = Instruction)
	void RecordData(AActor* robot);
	
};
