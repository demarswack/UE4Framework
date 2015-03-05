// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#include "TP_Framework.h"
#include "TP_FrameworkPawn.h"


// Sets default values
ATP_FrameworkPawn::ATP_FrameworkPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATP_FrameworkPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_FrameworkPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATP_FrameworkPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

