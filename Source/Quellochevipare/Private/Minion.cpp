// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"

// Sets default values
AMinion::AMinion(): IsInUse(false), Health(100.f),
DoStuffInterval(1.f), TimeSinceLastDoStuff(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMinion::DoStuff()
{
	UE_LOG(LogTemp, Warning, TEXT("Doing stuff"));
}

// Called every frame
void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (TimeSinceLastDoStuff >= DoStuffInterval)
	{
		DoStuff();
		TimeSinceLastDoStuff = 0.f;
	}
	else
	{
		TimeSinceLastDoStuff += DeltaTime;
	}
}

