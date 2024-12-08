// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Components/BillboardComponent.h"
#include "UObject/UnrealType.h"
#include "Engine/World.h"
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS(Blueprintable)
class PLATFORMS_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(VisibleAnywhere, Category = "MovingPlatform")
	FVector InitialLocation;
	
	UPROPERTY(VisibleAnywhere, Category = "MovingPlatform")
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform", meta = (ClampMin = "0.1", ClampMax = "10"))
	float speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform")
	bool targetAttached = true;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UBillboardComponent* TargetBillboard;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	#endif

	UPROPERTY(BlueprintReadOnly, Category = "MovingPlatform")
	FVector MovementVector;

	virtual void MovePlatform();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
