// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankMovementComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:

	//How close the AI Tank can get to the Player
	float AcceptanceRadius = 3000.0f;
	
};
