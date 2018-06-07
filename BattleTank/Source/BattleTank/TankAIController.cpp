// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank || !PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Possessing Nothing"));
	}
	else
	{

	}
}

//Called every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO Move towards Player

		//Aim towards the Player
		auto HitLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(HitLocation);
	}
}

//Returns the Tank which is controlled by the class
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Returns the Player Tank
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


