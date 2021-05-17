// Fill out your copyright notice in the Description page of Project Settings.


#include "TakeScreenshotInstruction.h"

UTakeScreenshotInstruction::UTakeScreenshotInstruction() {

}

void UTakeScreenshotInstruction::TakeScreenshot(AActor* robot)
{
	AGrabber* grabber = (AGrabber*)robot;
	grabber->TakeScreenshot();
}
