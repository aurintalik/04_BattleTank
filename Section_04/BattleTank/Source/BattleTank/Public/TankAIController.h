// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	
protected:
	//How close can the AI tank get
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultsOnly - That crashed me to shit last time so no.
	float AcceptanceRadius = 8000;

private:
	virtual void Tick(float DeltaTime) override;

	
	
	
	
};
