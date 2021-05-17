// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateInstruction.h"

URotateInstruction::URotateInstruction() {

}

void URotateInstruction::Rotate(AActor* robot, FRotator desiredRotation)
{
	ARobotBase* robotBase = (ARobotBase*)robot;

	robotBase->Rotate(desiredRotation);
}
