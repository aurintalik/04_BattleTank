
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is being possessed by AI!"), *(ControlledTank->GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI cannot find a tank to target!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Targetting player in %s!"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{			
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


