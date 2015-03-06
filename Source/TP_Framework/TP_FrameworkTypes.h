// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#pragma once

#include "TP_FrameworkTypes.generated.h"

/** GameStates which are used in the GameState and GameMode to invoke certain behaviors for UI, GameRules and Controls*/
UENUM(BlueprintType)
enum class EGameStates : uint8
{
		GS_StartGame		UMETA(DisplayName="Start Game"),
		GS_EndGame			UMETA(DisplayName="End Game"),
		GS_Menu				UMETA(DisplayName="Menu"),
		GS_InProgress		UMETA(DisplayName="InProgress")
};

/** UStruct for UI Definition, to be used to allow or disallow UI Elements */
USTRUCT()
struct FUIDefinition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="UIDefinition")
	bool ShowMenuUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIDefinition")
	bool ShowPlayerHUD;
};

/** UStruct for Mouse Input Definition */
USTRUCT()
struct FMouseInputDefinition
{
   GENERATED_USTRUCT_BODY()

   UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="Mouse Input Definition")
   bool ShowMouse;

   UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="Mouse Input Definition")
   bool AllowClickEvents;

   UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="Mouse Input Definition")
   bool AllowMouseOverEvents;
   
};

/** UStruct for Control Definition, to be used to allow or disallow Input */
USTRUCT()
struct FInputDefinition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Definition")
	bool MovementControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Definition")
	bool LookControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input Definition")
	FMouseInputDefinition MouseInput;

};

UCLASS()
class TP_FRAMEWORK_API UTP_FrameworkTypes : public UObject
{
	GENERATED_BODY()
};

