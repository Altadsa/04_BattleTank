// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"
#include "Public/TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);

	//UE_LOG(LogTemp, Warning, TEXT("%s moving at velocity: %s"), *TankName, *MoveVelocity.ToString())
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(RightTrack && LeftTrack)) { return; }

	RightTrack->SetThrottleRequest(Throw);
	LeftTrack->SetThrottleRequest(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(RightTrack && LeftTrack)) { return; }

	RightTrack->SetThrottleRequest(Throw);
	LeftTrack->SetThrottleRequest(-Throw);
}

