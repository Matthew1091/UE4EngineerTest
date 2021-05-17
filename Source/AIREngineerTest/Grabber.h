// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotBase.h"
#include "TargetSphere.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "UnrealClient.h"
#include "AIController.h"
#include "Containers/StringFwd.h"
#include "Misc/FileHelper.h"
#include "UObject/ConstructorHelpers.h"
#include "TargetSphere.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Grabber.generated.h"

UCLASS()
class AIRENGINEERTEST_API AGrabber : public ARobotBase
{
	GENERATED_BODY()


public:
	AGrabber();

	//Take a screenshot and save it to the screenshot folder
	void TakeScreenshot();

	//Record all of the actors visible in a .txt and save it to the screenshot folder
	void RecordData();

	void MoveFoward(float Distance) override;

	void Rotate(FRotator desiredRotation) override;

	virtual void Tick(float DeltaTime) override;
	
	//Test for spheres
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

private:
	class USpringArmComponent* springArm;
	class UCameraComponent* camera;
	UStaticMeshComponent* meshComponent;
	float moveSpeed = 0;
	int screenShotNumber = 0;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	class UCapsuleComponent* TriggerCapsule;
};
