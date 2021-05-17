// Fill out your copyright notice in the Description page of Project Settings.


#include "DropSphereInstruction.h"

UDropSphereInstruction::UDropSphereInstruction() {

}

void UDropSphereInstruction::DropSphere(AActor* robot, FVector location, FRotator rotation)
{
	ADropper* dropper = (ADropper*)robot;
		
	dropper->PlaceSphere(location, rotation);
}
