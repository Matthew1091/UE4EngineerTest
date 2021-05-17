// Copyright Epic Games, Inc. All Rights Reserved.


#include "DefaultPlayerController.h"
#include "AIREngineerTestGameModeBase.h"

AAIREngineerTestGameModeBase::AAIREngineerTestGameModeBase() {

	this->PlayerControllerClass = ADefaultPlayerController::StaticClass();
}