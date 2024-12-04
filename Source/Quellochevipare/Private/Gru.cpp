// Fill out your copyright notice in the Description page of Project Settings.


#include "Gru.h"

// Sets default values
AGru::AGru(): MinionInterval(1.f), TimeSinceLastMinion(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGru::BeginPlay()
{
	Super::BeginPlay();

	
	
}

AMinion* AGru::GetRandomAvailableMinion()
{
	return Minions[FMath::RandRange(0, Minions.Num() - 1)];
}

// Called every frame
void AGru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimeSinceLastMinion >= MinionInterval)
	{
		AMinion* Minion = GetRandomAvailableMinion();
		
		if (Minion && Minion->IsInUse == false)
		{
			Minion->IsInUse = true;
			Minion->SetActorHiddenInGame(false);
			UE_LOG(LogTemp, Warning, TEXT("Gru is sending %s to do stuff"), *Minion->GetName());
		}

		TimeSinceLastMinion = 0.f;
	}
	else
	{
		TimeSinceLastMinion += DeltaTime;
	}

}

