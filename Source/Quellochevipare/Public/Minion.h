// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Minion.generated.h"

UCLASS()
class QUELLOCHEVIPARE_API AMinion : public AActor
{
	GENERATED_BODY()
	
public:	
	AMinion();

	UPROPERTY(EditAnywhere, Category = "Minion")
	bool IsInUse;

	UPROPERTY(EditAnywhere, Category = "Minion")
	FString Name;

protected:

	UPROPERTY(EditAnywhere, Category = "Minion")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Minion")
	float DoStuffInterval;

	UPROPERTY(VisibleAnywhere, Category = "Minion")
	float TimeSinceLastDoStuff;
	
	virtual void BeginPlay() override;

	virtual void DoStuff();

public:	
	virtual void Tick(float DeltaTime) override;

};
