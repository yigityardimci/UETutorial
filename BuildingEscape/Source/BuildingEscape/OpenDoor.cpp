// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	Itself = GetOwner();

	// ...
	
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	HandleGameMechanism();
	
	

	// ...
}


void UOpenDoor::HandleGameMechanism() {
	float LastOpenedTime = 0.0f;
	if (Pawn == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("PAWN IS NULL"));
	}
	else {
		if (ControlTemplate->IsOverlappingActor(Pawn)) {
			OpenDoor();
			LastOpenedTime = GetWorld()->GetTimeSeconds();
		}

		if (GetWorld()->GetTimeSeconds() - LastOpenedTime > Delay) {
			CloseDoor();
		}
	}
}
void UOpenDoor::OpenDoor()
{
	FRotator NewRotation = FRotator(0.f, OpenAngle, 0.f);
	Itself->SetActorRotation(NewRotation);
}
void UOpenDoor::CloseDoor()
{
	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);
	Itself->SetActorRotation(NewRotation);
}


