// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "TP_FrameworkActor.generated.h"

/**
 * Actor is the base class for an Object that can be placed or spawned in a level.
 *
 * Actors may contain a collection of ActorComponents, which can be used to control how actors move, how they are rendered, etc.
 * The other main function of an Actor is the replication of properties and function calls across the network during play.
 * 
 * @see https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Actors/
 * @see UActorComponent
 */
UCLASS()
class TP_FRAMEWORK_API ATP_FrameworkActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATP_FrameworkActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
