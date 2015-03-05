// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#include "TP_Framework.h"
#include "TP_FrameworkPlayerController.h"
#include "TP_FrameworkGameState.h"

ATP_FrameworkGameState::ATP_FrameworkGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	IsGameStateCommmited = false;
}

EGameStates ATP_FrameworkGameState::RequestGameState(EGameStates GameState)
{
	EGameStates IncomingGameState;
	IncomingGameState = EGameStates::GS_StartGame;
	
	if(CurrentGameState != GameState)
	{
		IncomingGameState = GameState;
		LastGameState = CurrentGameState;

		switch (IncomingGameState)
		{
		case EGameStates::GS_StartGame:
			IsGameStateCommmited = SetStateStartGame(IncomingGameState);
		break;
		case EGameStates::GS_EndGame:
			IsGameStateCommmited = SetStateEndGame(IncomingGameState);
		break;
		case EGameStates::GS_Menu: 
			IsGameStateCommmited= SetStateMenu(IncomingGameState);
		break;
		case EGameStates::GS_InProgress:
			IsGameStateCommmited = SetStateInProgress(IncomingGameState);
		break;
		}
	}

	if (IsGameStateCommmited)
	{
		CurrentGameState = IncomingGameState;
		return CurrentGameState;
	}
	
	return LastGameState;
}

bool ATP_FrameworkGameState::SetStateStartGame_Implementation(EGameStates IncomingGameState)
{
	ATP_FrameworkPlayerController* PlayerController;
	PlayerController = Cast<ATP_FrameworkPlayerController>(GetWorld()->GetFirstLocalPlayerFromController());

	if(!IsValid(PlayerController))
	{
		return false;
	}

	if(IncomingGameState == EGameStates::GS_StartGame)
	{
		if(PlayerController->IsLocalPlayerController())
		{
			return true;
		}
	}

	return false;
}

bool ATP_FrameworkGameState::SetStateEndGame_Implementation(EGameStates IncomingGameState)
{
	ATP_FrameworkPlayerController* PlayerController;
	PlayerController = Cast<ATP_FrameworkPlayerController>(GetWorld()->GetFirstLocalPlayerFromController());

	if(!IsValid(PlayerController))
	{
		return false;
	}
	
	if(IncomingGameState == EGameStates::GS_EndGame)
	{
		if(PlayerController->IsLocalController())
		{
			return true;
		}
	}

	return false;
}

bool ATP_FrameworkGameState::SetStateMenu_Implementation(EGameStates IncomingGameState)
{
	ATP_FrameworkPlayerController* PlayerController;
	PlayerController = Cast<ATP_FrameworkPlayerController>(GetWorld()->GetFirstPlayerController());
	
	if(!IsValid(PlayerController))
	{
		return false;
	}

	if(IncomingGameState == EGameStates::GS_Menu)
	{
		if(PlayerController->IsLocalController())
		{
			return true;
		}
	}

	return false;
}

bool ATP_FrameworkGameState::SetStateInProgress_Implementation(EGameStates IncomingGameState)
{
	ATP_FrameworkPlayerController* PlayerController;
	PlayerController = Cast<ATP_FrameworkPlayerController>(GetWorld()->GetFirstLocalPlayerFromController());
	
	if(!IsValid(PlayerController))
	{
		return false;
	}
	
	if(IncomingGameState == EGameStates::GS_InProgress)
	{
		if(PlayerController->IsLocalController())
		{
			return true;
		}
	}

	return false;
}

