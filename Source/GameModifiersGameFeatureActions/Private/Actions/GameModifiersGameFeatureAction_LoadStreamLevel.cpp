// Copyright (c) 2024 Anoho All rights reserved.

#include "Actions/GameModifiersGameFeatureAction_LoadStreamLevel.h"

// Include headers in GameModifiers module.
#include "GameModifiersLevelRegistry.h"

void UGameModifiersGameFeatureAction_LoadStreamLevel::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	TObjectPtr<UGameModifiersLevelRegistry> GameModifierLevelRegistry = GEngine->GetEngineSubsystem<UGameModifiersLevelRegistry>();

	if (GameModifierLevelRegistry)
	{
		for (const FGameModifiersGameFeatureActionsStreamLevelEntry& StreamLevel : StreamLevels)
		{
			GameModifierLevelRegistry->RegisterStreamLevelByName(LevelName, StreamLevel.LevelName);
		}
	}
}

void UGameModifiersGameFeatureAction_LoadStreamLevel::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	TObjectPtr<UGameModifiersLevelRegistry> GameModifierLevelRegistry = GEngine->GetEngineSubsystem<UGameModifiersLevelRegistry>();

	if (GameModifierLevelRegistry)
	{
		for (const FGameModifiersGameFeatureActionsStreamLevelEntry& StreamLevel : StreamLevels)
		{
			GameModifierLevelRegistry->UnregisterStreamLevelByName(LevelName, StreamLevel.LevelName);
		}
	}
}
