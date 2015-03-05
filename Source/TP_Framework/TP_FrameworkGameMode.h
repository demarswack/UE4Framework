// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

#pragma once

#include "GameFramework/GameMode.h"
#include "TP_FrameworkTypes.h"
#include "TP_FrameworkTypes.h"
#include "TP_FrameworkMenuWidget.h"
#include "TP_FrameworkPlayerHUDWidget.h"
#include "TP_FrameworkGameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * It is only instanced on the server and will never exist on the client. 
 *
 * A GameMode actor is instantiated when the level is initialized for gameplay in
 * C++ UGameEngine::LoadMap().  
 * 
 * The class of this GameMode actor is determined by (in order) either the URL ?game=xxx, 
 * the GameMode Override value set in the World Settings, or the DefaultGameMode entry set 
 * in the game's Project Settings.
 *
 * @see https://docs.unrealengine.com/latest/INT/Gameplay/Framework/GameMode/index.html
 */
UCLASS()
class TP_FRAMEWORK_API ATP_FrameworkGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	
	class UTP_FrameworkMenuWidget* MenuWidget;
	class UTP_FrameworkPlayerHUDWidget* PlayerHUDWidget;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UTP_FrameworkPlayerHUDWidget> PlayerHUDWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UTP_FrameworkMenuWidget> MenuWidgetClass;

	virtual void BeginPlay() override;

public:

	/** Constructor declaration */
	ATP_FrameworkGameMode(const FObjectInitializer& ObjectInitializer);

};
