// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    // Find the owning Actor
    Owner = GetOwner();
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
    
}

void UOpenDoor::OpenDoor() {
    // Open Door
    UE_LOG(LogTemp, Warning, TEXT("OPENING DOOR"));
    
    Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor() {
    // Close Door
    UE_LOG(LogTemp, Warning, TEXT("CLOSING DOOR"));
    
    // Set the door rotation
    Owner->SetActorRotation(FRotator(0.f, 90.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger Volume
    if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
        // If the Actor that Opens touches the volume
        OpenDoor();
        // track when the door was last opened
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }
    
    // Check if it is time to close the door
    if ((GetWorld()->GetTimeSeconds() - LastDoorOpenTime) > DoorCloseDelay) {
        CloseDoor();
    }
    
}







