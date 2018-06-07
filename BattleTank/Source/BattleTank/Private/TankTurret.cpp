// Fill out your copyright notice in the Description page of Project Settings.

#include "public/TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RotationSpeed)
{
	//We need to get the y position of our camera and of our turrent
	//We need to rotate the turret until it matches the y pos of the camera

	auto Speed = FMath::Clamp<float>(RotationSpeed, -1, 1);
	auto RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(
		FRotator(
			0,
			FMath::Clamp(RawNewRotation, MinDegreesRotation, MaxDegreesRotation),
			0
		));
}


