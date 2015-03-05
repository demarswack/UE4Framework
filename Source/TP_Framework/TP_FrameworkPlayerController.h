// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TP_FrameworkTypes.h"
#include "TP_FrameworkMenuWidget.h"
#include "TP_FrameworkPlayerHUDWidget.h"
#include "TP_FrameworkPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TP_FRAMEWORK_API ATP_FrameworkPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StartGame")
	FUIDefinition StartGameUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EndGame")
	FUIDefinition EndGameUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MenuUI")
	FUIDefinition MenuUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pause")
	FUIDefinition PauseUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InProgress")
	FUIDefinition InProgressUI;

	virtual void Tick( float DeltaSeconds ) override;

	/** Constructor declaration */
	ATP_FrameworkPlayerController(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintNativeEvent, Category = "Game State")
	EGameStates GetGameState();
	EGameStates GetGameState_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Game State")
	void SetUI(FUIDefinition UIDefinition);
	void SetUI_Implementation(FUIDefinition UIDefinition);

public:

	class UTP_FrameworkMenuWidget* MenuWidget;
	class UTP_FrameworkPlayerHUDWidget* PlayerHUDWidget;
};


