// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordDataInstruction.h"

URecordDataInstruction::URecordDataInstruction()
{
}

void URecordDataInstruction::RecordData(AActor* robot)
{
	AGrabber* grabber = (AGrabber*)robot;
	grabber->RecordData();
}
