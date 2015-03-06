// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#pragma once

#include "GameFramework/GameState.h"
#include "TP_FrameworkGameMode.h"
#include "TP_FrameworkTypes.h"
#include "TP_FrameworkGameState.generated.h"

/**
 *  GameState is replicated and is valid on servers and clients.
 *  Using various States that are than define in the Game Mode.
 */
UCLASS()
class TP_FRAMEWORK_API ATP_FrameworkGameState : public AGameState
{
	GENERATED_BODY()

protected:

	// Game State Variables used for RequestGameState function
	EGameStates CurrentGameState;
	EGameStates LastGameState;

	/** If a game state is committed or not to be returned */
	bool IsGameStateCommmited;

	class ATP_FrameworkGameMode* GameMode;

	/** Initialize StartGame State */
	UFUNCTION(BlueprintNativeEvent, Category = "Game States")
	bool SetStateStartGame(EGameStates IncomingGameState);
	bool SetStateStartGame_Implementation(EGameStates IncomingGameState);

	/** Initialize EndGame State */
	UFUNCTION(BlueprintNativeEvent, Category = "Game States")
	bool SetStateEndGame(EGameStates IncomingGameState);
	bool SetStateEndGame_Implementation(EGameStates IncomingGameState);

	/** Initialize Menu State */
	UFUNCTION(BlueprintNativeEvent, Category = "Game States")
	bool SetStateMenu(EGameStates IncomingGameState);
	bool SetStateMenu_Implementation(EGameStates IncomingGameState);

	/** Initialize InProgress State */
	UFUNCTION(BlueprintNativeEvent, Category = "Game States")
	bool SetStateInProgress(EGameStates IncomingGameState);
	bool SetStateInProgress_Implementation(EGameStates IncomingGameState); 

public:

	/** Constructor declaration */
	ATP_FrameworkGameState(const FObjectInitializer& ObjectInitializer);

	/**
	* Requesting a GameState change to set GameState
	* @param GameState	The requested GameState
	*
	* @return			Returns current Game State
	*/
	UFUNCTION(BlueprintCallable, Category = "Game States")
	EGameStates RequestGameState(EGameStates GameState);

	/**
	* Public function to get the Current Game State
	*
	* @return			Returns current Game State
	*/
	FORCEINLINE virtual EGameStates GetCurrentGameState() const
	{
		return CurrentGameState;	
	}
	
	/**
	* Public function to get the Last Game State
	*
	* @return			Returns Last Game State
	*/
	FORCEINLINE virtual EGameStates GetLastGameState() const
	{
		return LastGameState;	
	}
	
};
