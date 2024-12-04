// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"

// Sets default values
AMinion::AMinion(): IsInUse(false), Health(100.f),
DoStuffInterval(1.f), TimeSinceLastDoStuff(0.f)
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMinion::OnOverlapBegin);
}

void AMinion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMinion::DoStuff()
{
	UE_LOG(LogTemp, Warning, TEXT("Doing stuff"));
}

void AMinion::OnDeath()
{
	
}

void AMinion::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Kill();
}

void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsInUse == false) return;
	
	
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

void AMinion::Kill()
{
	SetActorHiddenInGame(true);
	IsInUse = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (TEXT("%s I HAVE BEEN KILLED!! AAAAAAAH"), *GetName()));
	OnDeath();
}

