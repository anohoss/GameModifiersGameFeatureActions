// Copyright (c) 2024 Anoho All rights reserved.

#include "GameModifiersGameFeaturesProjectPolicies.h"

// Include headers in GameFeatures module.
#include "GameFeaturesSubsystemSettings.h"

// Include headers in GameModifiersGameFeatureActions module.
#include "GameModifiersGameFeatureActionsSubsystem.h"

void UGameModifiersGameFeaturesProjectPolicies::InitGameFeatureManager()
{
	UE_LOG(LogGameFeatures, Log, TEXT("Scanning for built-in game feature plugins"));

	UGameFeaturesSubsystem::FBuiltInPluginAdditionalFilters AdditionalFilter = [&](
		const FString& PluginFilename,
		const FGameFeaturePluginDetails& PluginDetails,
		FBuiltInGameFeaturePluginBehaviorOptions& OutOptions) -> bool
		{
			return true;
		};

	UGameFeaturesSubsystem::Get().LoadBuiltInGameFeaturePlugins(AdditionalFilter);

	UE_LOG(LogGameFeatures, Log, TEXT("Scanning for built-in game modifier plugins (with gamefeatures)"));

	GEngine->GetEngineSubsystem<UGameModifiersGameFeatureActionsSubsystem>()->LoadBuiltInGameModifiersGameFeatureActionsPlugins();
}

void UGameModifiersGameFeaturesProjectPolicies::GetGameFeatureLoadingMode(bool& bLoadClientData, bool& bLoadServerData) const
{
	// Client もしくは Dedicated Server として実行されていなければデータを読み込まない
	bLoadClientData = IsRunningClientOnly();
	bLoadServerData = IsRunningDedicatedServer();
}

const TArray<FName> UGameModifiersGameFeaturesProjectPolicies::GetPreloadBundleStateForGameFeature() const
{
	// By default, use the bundles corresponding to loading mode
	bool bLoadClientData, bLoadServerData;

	GetGameFeatureLoadingMode(bLoadClientData, bLoadServerData);

	TArray<FName> FeatureBundles;

	if (bLoadClientData)
	{
		FeatureBundles.Add(UGameFeaturesSubsystemSettings::LoadStateClient);
	}

	if (bLoadServerData)
	{
		FeatureBundles.Add(UGameFeaturesSubsystemSettings::LoadStateServer);
	}

	return FeatureBundles;
}
