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
			break;
			case EGameStates::GS_EndGame:
				SetUI(EndGameUI);
			break;
			case EGameStates::GS_Menu: 
				SetUI(MenuUI);
			break;
			case EGameStates::GS_InProgress:
				SetUI(InProgressUI);
			break;
		}
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
			else
			{
				MenuWidget->AddToViewport();
				MenuWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}

	// Player HUD Widget
	if (IsValid(PlayerHUDWidget))
	{
		if(UIDefinition.ShowMenuUI)
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
			else
			{
				PlayerHUDWidget->AddToViewport();
				PlayerHUDWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}

	
}
