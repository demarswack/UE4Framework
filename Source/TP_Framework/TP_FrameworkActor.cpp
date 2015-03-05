// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#include "TP_Framework.h"
#include "TP_FrameworkActor.h"


// Sets default values
ATP_FrameworkActor::ATP_FrameworkActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATP_FrameworkActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_FrameworkActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

