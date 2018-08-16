// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoorComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoorComponent::UOpenDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorComponent::BeginPlay()
{
	Super::BeginPlay();
	auto actor = GetOwner();
	auto opendoor = FRotator(0.f, 100.f, 0.f);
	UE_LOG(LogTemp, Warning, TEXT("Object %s 's position is changing lelelel"), *actor->GetName());
	actor->SetActorRotation(opendoor);

	


	// ...

	
}


// Called every frame
void UOpenDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

