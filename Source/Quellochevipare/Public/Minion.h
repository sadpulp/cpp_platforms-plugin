// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "Minion.generated.h"

UCLASS()
class QUELLOCHEVIPARE_API AMinion : public AActor
{
	GENERATED_BODY()
	
public:
	AMinion();

	UPROPERTY(EditAnywhere, Category = "Components")
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComponent;

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

	/*
	 
	 Esempi di Hungarian notation:

     private e protected
     _variable
     
     public
     variable

     const NOME_VARIABILE

     static s_variabile
	 
	 */
	
	virtual void BeginPlay() override;

	virtual void DoStuff();

	virtual void OnDeath();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	virtual void Tick(float DeltaTime) override;

	void Kill();

};
