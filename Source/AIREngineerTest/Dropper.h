// The class for the robot that places the spheres

#pragma once

#include "CoreMinimal.h"
#include "RobotBase.h"
#include "TargetSphere.h"
#include "AIController.h"
#include "Components/StaticMeshComponent.h"
#include "Dropper.generated.h"

UCLASS()
class AIRENGINEERTEST_API ADropper : public ARobotBase
{
	GENERATED_BODY()

public:
		ADropper();

		void PlaceSphere(FVector location, FRotator rotation);

		void MoveFoward(float Distance) override;

		void Rotate(FRotator desiredRotation) override;

		virtual void Tick(float DeltaTime) override;

private:
		UStaticMeshComponent* meshComponent;
		float moveSpeed = 0;
};
