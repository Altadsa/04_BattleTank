// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Return when there is no difference in displacement between barrel and aimdirection
	auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	SetRelativeRotation(
		FRotator(
			FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation), 
			0, 
			0));
}


