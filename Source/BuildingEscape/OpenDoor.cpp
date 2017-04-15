// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


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

	// Open Door
    UE_LOG(LogTemp, Warning, TEXT("ATTEMPTING DOOR OPENING"));
    
    // Find the owning Actor
    AActor * Owner = GetOwner();
    
    // Create a rotator
    FRotator DoorRotation = FRotator(0.f, 120.f, 0.f);
    
    FRotator DoorRotation2 = FRotator(0.f, 90.f, 0.f);
    
    FRotator DoorRotation3 = FRotator(0.f, 180.f, 0.f);
    
    // Set the door rotation
    Owner->SetActorRotation(DoorRotation);
    
    Owner->SetActorRotation(DoorRotation2);
    
    Owner->SetActorRotation(DoorRotation3);
    
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

