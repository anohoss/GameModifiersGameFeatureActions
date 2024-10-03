// Copyright (c) 2024 Anoho All rights reserved.

#include "GameModifiersGameFeatureActionsSettings.h"

bool UGameModifiersGameFeatureActionsSettings::IsValidGameModifiersGameFeatureActionsPlugin(const FString& InPluginFilePath) const
{
	return FPathViews::IsParentPathOf(FPaths::Combine(FPaths::ProjectDir(), TEXT("Mods"), TEXT("GameFeatures")), InPluginFilePath);
}
