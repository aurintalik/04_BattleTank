// Copyright Amanda Britton

#include "Tank.h"
#include "UObjectGlobals.h"
#include "TankAimingComponent.h"
#include "Turret.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//UE_LOG(LogTemp, Warning, TEXT("Kitty : Tank Constructor Loaded!"));
}

void ATank::Fire()
{
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
	
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Kitty : Tank BeginPlay Loaded!"));
}

void ATank::AimAt(FVector OutHitLocation)
{
	if (!TankAimingComponent)
	{
		return;
	}
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}
