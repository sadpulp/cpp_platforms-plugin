// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform(): speed(1.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		PlatformMesh->SetStaticMesh(CubeMeshAsset.Object);
		PlatformMesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.2f));
	}

	TargetBillboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("PlatformTarget"));
	TargetBillboard->SetupAttachment(RootComponent);
	TargetBillboard->SetRelativeLocation(FVector(0, 100, 0));
	TargetBillboard->bIsEditorOnly = true;

	// Set default sprite for the billboard
	static ConstructorHelpers::FObjectFinder<UTexture2D> BillboardSprite(TEXT("/Engine/EditorResources/S_TargetPoint.S_TargetPoint"));
	if (BillboardSprite.Succeeded())
	{
		TargetBillboard->Sprite = BillboardSprite.Object;
		TargetBillboard->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
	}
}

void AMovingPlatform::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	InitialLocation = GetActorLocation();
	TargetLocation = TargetBillboard->GetComponentLocation();
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
	TargetLocation = TargetBillboard->GetComponentLocation();
	MovementVector = TargetLocation - InitialLocation;
}
#if WITH_EDITOR
void AMovingPlatform::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.Property->GetName() == TEXT("targetAttached"))
	{
		if (targetAttached)
		{
			FVector currentBillboardLocation = TargetBillboard->GetComponentLocation();
			TargetBillboard->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			TargetBillboard->SetWorldLocation(currentBillboardLocation);
		}
		else
		{
			TargetBillboard->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		}
	}	
}
#endif



void AMovingPlatform::MovePlatform()
{
	SetActorLocation(InitialLocation + (MovementVector * (FMath::Sin(speed * GetWorld()->TimeSeconds * 2 * PI) + 1)/2) );
}



// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform();
}

