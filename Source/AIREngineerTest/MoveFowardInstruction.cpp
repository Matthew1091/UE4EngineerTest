// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveFowardInstruction.h"

UMoveFowardInstruction::UMoveFowardInstruction() {

}

void UMoveFowardInstruction::MoveFoward(AActor* robot, float distance)
{
	ARobotBase* robotBase = (ARobotBase*)robot;

	robotBase->MoveFoward(distance);
}
