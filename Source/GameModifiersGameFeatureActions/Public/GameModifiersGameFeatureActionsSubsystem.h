// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/EngineSubsystem.h"

// Include headers in Projects module.
#include "Interfaces/IPluginManager.h"

// Include headers in GameFeatures module.
#include "GameFeaturesSubsystem.h"

#include "GameModifiersGameFeatureActionsSubsystem.generated.h"

using FGameModifiersGameFeaturesActionsPluginLoaded = FGameFeaturePluginLoadComplete;
using FGameModifiersGameFeaturesActionsPluginsLoaded = FBuiltInGameFeaturePluginsLoaded;

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureActionsSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:

	void LoadBuiltInGameModifiersGameFeatureActionsPlugin(const TSharedRef<IPlugin> Plugin, const FGameModifiersGameFeaturesActionsPluginLoaded& CompleteDelegate = FGameModifiersGameFeaturesActionsPluginLoaded());

	void LoadBuiltInGameModifiersGameFeatureActionsPlugins(const FGameModifiersGameFeaturesActionsPluginsLoaded& CompleteDelegate = FGameModifiersGameFeaturesActionsPluginsLoaded());
};
