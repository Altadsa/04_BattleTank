// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("Posessing Nothing..."))
	else
		UE_LOG(LogTemp, Warning, TEXT("Posessing %s"), *ControlledTank->GetName())
		
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

