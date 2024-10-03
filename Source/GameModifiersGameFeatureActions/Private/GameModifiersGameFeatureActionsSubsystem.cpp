// Copyright (c) 2024 Anoho All rights reserved.

#include "GameModifiersGameFeatureActionsSubsystem.h"

// Include headers in GameFeatures module.
#include "GameFeaturePluginOperationResult.h"

// Include headers in GameModifiersGameFeatureActions module.
#include "GameFeaturesProjectPolicies.h"
#include "GameModifiersGameFeatureActionsSettings.h"

void UGameModifiersGameFeatureActionsSubsystem::LoadBuiltInGameModifiersGameFeatureActionsPlugin(const TSharedRef<IPlugin> InPlugin, const FGameModifiersGameFeaturesActionsPluginLoaded& InPluginLoaded)
{
	if (GetDefault<UGameModifiersGameFeatureActionsSettings>()->IsValidGameModifiersGameFeatureActionsPlugin(InPlugin->GetDescriptorFileName()))
	{
		UGameFeaturesSubsystem& GameFeaturesSubsystem = UGameFeaturesSubsystem::Get();
		UGameFeaturesProjectPolicies& GameSpecificPolicies = GameFeaturesSubsystem.GetPolicy();

		const FString& PluginURL = GameFeaturesSubsystem.GetPluginURL_FileProtocol(InPlugin->GetDescriptorFileName());

		if (GameSpecificPolicies.IsPluginAllowed(PluginURL))
		{
			// InitialState の設定を PluginDescriptor に追加する
			// TargetState の値を InitialState に置き換える

			GameFeaturesSubsystem.ChangeGameFeatureTargetState(PluginURL, EGameFeatureTargetState::Active, InPluginLoaded);
		}
	}
}

void UGameModifiersGameFeatureActionsSubsystem::LoadBuiltInGameModifiersGameFeatureActionsPlugins(const FGameModifiersGameFeaturesActionsPluginsLoaded& InPluginsLoaded)
{
	struct FLoadContext
	{
		TMap<FString, UE::GameFeatures::FResult> Results;

		FGameModifiersGameFeaturesActionsPluginsLoaded PluginsLoaded;

		~FLoadContext()
		{
			PluginsLoaded.ExecuteIfBound(Results);
		}
	};

	TSharedRef<FLoadContext> LoadContext = MakeShared<FLoadContext>();

	LoadContext->PluginsLoaded = InPluginsLoaded;

	TArray<TSharedRef<IPlugin>> EnabledPlugins = IPluginManager::Get().GetEnabledPlugins();

	LoadContext->Results.Reserve(EnabledPlugins.Num());

	// 読み込み対象のプラグインを待機中としてマークしておく
	for (TSharedRef<IPlugin> Plugin : EnabledPlugins)
	{
		LoadContext->Results.Add(Plugin->GetName(), MakeError("Pending"));
	}

	for (TSharedRef<IPlugin> Plugin : EnabledPlugins)
	{
		FGameModifiersGameFeaturesActionsPluginLoaded PluginLoaded = FGameModifiersGameFeaturesActionsPluginLoaded::CreateLambda([LoadContext, Plugin](const UE::GameFeatures::FResult& Result)
			{
				LoadContext->Results.Add(Plugin->GetName(), Result);
			});

		LoadBuiltInGameModifiersGameFeatureActionsPlugin(Plugin, PluginLoaded);
	}
}
