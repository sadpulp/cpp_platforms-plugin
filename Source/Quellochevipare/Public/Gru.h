// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Minion.h"
#include "GameFramework/Actor.h"
#include "Gru.generated.h"

UCLASS()
class QUELLOCHEVIPARE_API AGru : public AActor
{
	GENERATED_BODY()
	
public:	
	AGru();

protected:
	UPROPERTY(EditAnywhere, Category = "Minions")
	TArray<AMinion*> Minions;

	UPROPERTY(EditAnywhere, Category = "Minions")
	float MinionInterval;

	UPROPERTY(VisibleAnywhere, Category = "Minions")
	float TimeSinceLastMinion;
	
	virtual void BeginPlay() override;

	AMinion* GetRandomAvailableMinion();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
