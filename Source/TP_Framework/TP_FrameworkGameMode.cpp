// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#include "TP_Framework.h"
#include "TP_FrameworkGameState.h"
#include "TP_FrameworkGameInstance.h"
#include "TP_FrameworkPlayerController.h"
#include "TP_FrameworkPawn.h"
#include "TP_FrameworkMenuWidget.h"
#include "TP_FrameworkGameMode.h"

ATP_FrameworkGameMode::ATP_FrameworkGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = ATP_FrameworkPlayerController::StaticClass();
	DefaultPawnClass = ATP_FrameworkPawn::StaticClass();
	GameStateClass = ATP_FrameworkGameState::StaticClass();

}

void ATP_FrameworkGameMode::BeginPlay()
{

	Super::BeginPlay();

	FConstPlayerControllerIterator PlayerControllerItr(GetWorld()->GetPlayerControllerIterator());
	
	for (PlayerControllerItr; PlayerControllerItr; ++PlayerControllerItr)
	{
		ATP_FrameworkPlayerController* PlayerController;
		PlayerController = Cast<ATP_FrameworkPlayerController>(*PlayerControllerItr);
		
	
		if(PlayerController->IsLocalPlayerController())
		{
			// Construction Menu UI Widget
			if(MenuWidgetClass)
			{
				PlayerController->MenuWidget = CreateWidget<UTP_FrameworkMenuWidget>(PlayerController, MenuWidgetClass);
				PlayerController->MenuWidget->AddToViewport(100);
				PlayerController->MenuWidget->SetVisibility(ESlateVisibility::Hidden);

			}

			// Construction Player HUD Widget
			if(PlayerHUDWidgetClass)
			{
				PlayerController->PlayerHUDWidget = CreateWidget<UTP_FrameworkPlayerHUDWidget>(PlayerController, PlayerHUDWidgetClass);
				PlayerController->PlayerHUDWidget->AddToViewport(99);
				PlayerController->PlayerHUDWidget->SetVisibility(ESlateVisibility::Hidden);

			}
		}
	}

}