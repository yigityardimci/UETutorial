// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	HandleLineTrace();
}

void UGrabber::HandleLineTrace() {

	/// Create Debug Line
	FVector PlayerLocation;
	FRotator PlayerRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerLocation, PlayerRotation);
	FVector LineTraceEnd = PlayerLocation + PlayerRotation.Vector()*Reach;
	DrawDebugLine(GetWorld(), PlayerLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 0, 5.f);


	//Handle LineTrace With PhysicsBody typed objects
	FHitResult LineTraceHit;
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("")),false,GetWorld()->GetFirstPlayerController()->GetPawn());

	GetWorld()->LineTraceSingleByObjectType(
		LineTraceHit, PlayerLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams
	);
	if (LineTraceHit.GetActor() !=  nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Hit to object %s"),*LineTraceHit.GetActor()->GetName());
	}
}

