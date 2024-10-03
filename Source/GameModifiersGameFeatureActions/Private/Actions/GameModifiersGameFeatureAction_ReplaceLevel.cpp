// Copyright (c) 2024 Anoho All rights reserved.

#include "Actions/GameModifiersGameFeatureAction_ReplaceLevel.h"

// Include headers in Engine module.
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"

// Include headers in GameModifiers module.
#include "GameModifiersLevelRegistry.h"

void UGameModifiersGameFeatureAction_ReplaceLevel::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	TObjectPtr<UGameModifiersLevelRegistry> GameModifierLevelRegistry = GEngine->GetEngineSubsystem<UGameModifiersLevelRegistry>();

	if (GameModifierLevelRegistry)
	{
		GameModifierLevelRegistry->RegisterLevelOverrideByName(LevelNameToBeReplaced, LevelNameToReplace);
	}
}

void UGameModifiersGameFeatureAction_ReplaceLevel::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	TObjectPtr<UGameModifiersLevelRegistry> GameModifierLevelRegistry = GEngine->GetEngineSubsystem<UGameModifiersLevelRegistry>();

	if (GameModifierLevelRegistry)
	{
		GameModifierLevelRegistry->UnregisterLevelOverrideByName(LevelNameToBeReplaced);
	}
}
