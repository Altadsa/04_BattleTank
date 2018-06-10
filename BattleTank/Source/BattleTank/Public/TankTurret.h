// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Rotate(float RotationSpeed);

private:
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 25.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesRotation = 90.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreesRotation = -90.0f;
	
};
