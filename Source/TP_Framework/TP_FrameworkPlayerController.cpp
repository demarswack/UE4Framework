// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#include "TP_Framework.h"
#include "TP_FrameworkGameState.h"
#include "TP_FrameworkPlayerController.h"


ATP_FrameworkPlayerController::ATP_FrameworkPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void ATP_FrameworkPlayerController::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	GetGameState();
}

EGameStates ATP_FrameworkPlayerController::GetGameState_Implementation()
{
	
	ATP_FrameworkGameState* GameState;
	GameState = Cast<ATP_FrameworkGameState>(GetWorld()->GetGameState());

	if(IsValid(GameState))
	{
		switch (GameState->GetCurrentGameState())
		{
			case EGameStates::GS_StartGame:
				SetUI(StartGameUI);
				SetControls(StartGameInput);
			break;
			case EGameStates::GS_EndGame:
				SetUI(EndGameUI);
				SetControls(EndGameInput);
			break;
			case EGameStates::GS_Menu: 
				SetUI(MenuUI);
				SetControls(MenuInput);
			break;
			case EGameStates::GS_InProgress:
				SetUI(InProgressUI);
				SetControls(InProgressInput);
			break;
		}
		return GameState->GetCurrentGameState();
	}

	return EGameStates::GS_StartGame;
}

void ATP_FrameworkPlayerController::SetUI_Implementation(FUIDefinition UIDefinition)
{
	// Menu Widget
	if (IsValid(MenuWidget))
	{
		if(UIDefinition.ShowMenuUI)
		{
			if(MenuWidget->IsInViewport())
			{
				MenuWidget->SetVisibility(ESlateVisibility::Visible);
			}
			else
			{
				MenuWidget->AddToViewport();
				MenuWidget->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else
		{
			if(MenuWidget->IsInViewport())
			{
				MenuWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}

	// Player HUD Widget
	if (IsValid(PlayerHUDWidget))
	{
		if(UIDefinition.ShowPlayerHUD)
		{
			if(PlayerHUDWidget->IsInViewport())
			{
				PlayerHUDWidget->SetVisibility(ESlateVisibility::Visible);
			}
			else
			{
				PlayerHUDWidget->AddToViewport();
				PlayerHUDWidget->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else
		{
			if(PlayerHUDWidget->IsInViewport())
			{
				PlayerHUDWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

void ATP_FrameworkPlayerController::SetControls_Implementation(FInputDefinition InputDefinition)
{
	if(InputDefinition.MovementControls)
	{
		SetIgnoreMoveInput(false);
	}
	else
	{
		SetIgnoreMoveInput(true);	
	}

	if(InputDefinition.LookControls)
	{
		SetIgnoreLookInput(false);
	}
	else
	{
		SetIgnoreLookInput(true);	
	}

	if(InputDefinition.MouseInput.ShowMouse)
	{
		bShowMouseCursor = true;	
	}
	else
	{
		bShowMouseCursor = false;
	}

	if(InputDefinition.MouseInput.AllowClickEvents)
	{
		bEnableClickEvents = true;
	}
	else
	{
		bEnableClickEvents = false;	
	}

	if(InputDefinition.MouseInput.AllowMouseOverEvents)
	{
		bEnableMouseOverEvents = true;
	}
	else
	{
		bEnableMouseOverEvents = false;
	}
}
