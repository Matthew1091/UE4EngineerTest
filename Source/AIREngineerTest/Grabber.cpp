// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"

AGrabber::AGrabber() {
	this->AIControllerClass = ConstructorHelpers::FClassFinder<AAIController>(TEXT("/Game/BehaviorTrees/GrabberAIController")).Class;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid'"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh")); 
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));

	meshComponent->SetupAttachment(this->GetRootComponent());
	meshComponent->SetStaticMesh(Mesh.Object);

	springArm->SetupAttachment(meshComponent);

	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
	
	springArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	springArm->TargetArmLength = 400.f;
	springArm->bEnableCameraLag = true;

	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AGrabber::OnOverlapBegin);

}

void AGrabber::BeginPlay()
{
	Super::BeginPlay();

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(this);
}

//Take a screenshot and save it to the screenshot folder
void AGrabber::TakeScreenshot()
{
	FString filename = "image_";
	filename.Append(FString::FromInt(screenShotNumber));

	FScreenshotRequest::RequestScreenshot(filename, false, false);
}

//Record all of the actors visible in a .txt and save it to the screenshot folder
void AGrabber::RecordData()
{
	FString filename = "image_";
	filename.Append(FString::FromInt(screenShotNumber));
	filename.Append("_actors.txt");

	TArray<FString> actorList;

	for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	{
		if (Itr->GetLastRenderTime() > 1.0f)
		{
			FString actorLine = Itr->GetFName().ToString();
			actorList.Add(actorLine);
		}
	}

	FFileHelper::EEncodingOptions encodingOptions = FFileHelper::EEncodingOptions::AutoDetect;
	uint32 writeFlags = 0;

	FFileHelper::SaveStringArrayToFile(actorList, *(FPaths::ScreenShotDir() + filename), encodingOptions, &IFileManager::Get(), writeFlags);

	screenShotNumber++;
}

void AGrabber::MoveFoward(float Distance)
{
	moveSpeed = Distance;
}

void AGrabber::Rotate(FRotator desiredRotation)
{
	this->SetActorRotation(desiredRotation, ETeleportType::None);
}

void AGrabber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->GetActorForwardVector();

	FVector DesiredMovementDirection = this->GetActorForwardVector();
	FVector CurrentPos = GetActorLocation();
	CurrentPos.X += DesiredMovementDirection.X * moveSpeed * DeltaTime;
	CurrentPos.Y += DesiredMovementDirection.Y * moveSpeed * DeltaTime;
	SetActorLocation(CurrentPos);
}

void AGrabber::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (OtherActor->GetClass() == ATargetSphere::StaticClass()) {

			TakeScreenshot();
			RecordData();
			OtherActor->Destroy();
		}
	}
}
