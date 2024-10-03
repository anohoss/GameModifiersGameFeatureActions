// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in DeveloperSettings module.
#include "Engine/DeveloperSettings.h"

#include "GameModifiersGameFeatureActionsSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Game Modifiers Game Feature Actions"))
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureActionsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	bool IsValidGameModifiersGameFeatureActionsPlugin(const FString& InPluginFilePath) const;
};
