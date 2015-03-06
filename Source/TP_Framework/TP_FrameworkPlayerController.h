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
	
	/** UI Struct for all the Game States */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | UI")
	FUIDefinition StartGameUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | UI")
	FUIDefinition EndGameUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | UI")
	FUIDefinition MenuUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | UI")
	FUIDefinition InProgressUI;

	/** UI Struct for all the Game States */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | Input")
	FInputDefinition StartGameInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | Input")
	FInputDefinition EndGameInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | Input")
	FInputDefinition MenuInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game State | Input")
	FInputDefinition InProgressInput;


	/** Tick override */
	virtual void Tick( float DeltaSeconds ) override;

	/** Constructor declaration */
	ATP_FrameworkPlayerController(const FObjectInitializer& ObjectInitializer);

	/**
	* Implementation: Getting Game State and than calling SetUI
	*
	* Is called by Tick
	* @return			Returns Current Game State
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game State")
	EGameStates GetGameState();
	EGameStates GetGameState_Implementation();

	/**
	* Implementation: Setting UI Widgets to be shown or hidden. 
	* 
	* FUIDefinition UIDefinition - UStruct of UI Definition
	*
	* @return			Returns Current Game State
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game State")
	void SetUI(FUIDefinition UIDefinition);
	void SetUI_Implementation(FUIDefinition UIDefinition);

	/**
	* Implementation: Setting Controls for Player according to State. 
	* 
	* FInputDefinition InputDefinition - UStruct of Input Definition
	*
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game State")
	void SetControls(FInputDefinition InputDefinition);
	void SetControls_Implementation(FInputDefinition InputDefinition);

public:

	/** UserWidget Class MenuWidget that will be defined by the Game Mode */
	class UTP_FrameworkMenuWidget* MenuWidget;

	/** UserWidget Class PlayerHudWidget that will be defined by the Game Mode */
	class UTP_FrameworkPlayerHUDWidget* PlayerHUDWidget;
};


