// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank || !PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Possessing Nothing"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s is has found Player Tank %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


