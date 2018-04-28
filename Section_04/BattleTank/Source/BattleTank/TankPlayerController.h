// Copyright Amanda Britton

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	
private:
	
	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void SetPawn(APawn* InPawn) override;

	//Start the tank moving the barrel so a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	//return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	UPROPERTY (EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	
};
