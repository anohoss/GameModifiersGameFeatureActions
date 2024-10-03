// Copyright (c) 2024 Anoho All rights reserved.

#include "GameModifiersGameFeatureActionsPluginTemplateDescription.h"

// Include headers in AssetTools module.
#include "IAssetTools.h"

// Include headers in GameFeatures module.
#include "GameFeatureData.h"
#include "GameFeaturePluginOperationResult.h"

// Include headers in GameModifiersGameFeatureActions module.
#include "GameModifiersGameFeatureActionsSubsystem.h"
#include "GameModifiersGameFeatureActionsSettings.h"

// Include headers in UnrealEd module.
#include "FileHelpers.h"

FGameModifiersGameFeatureActionsPluginTemplateDescription::FGameModifiersGameFeatureActionsPluginTemplateDescription(FText InName, FText InDescription, FString InOnDiskPath)
	: FPluginTemplateDescription(InName, InDescription, InOnDiskPath, true, EHostType::Runtime)
{
	bCanBePlacedInEngine = false;
}

void FGameModifiersGameFeatureActionsPluginTemplateDescription::CustomizeDescriptorBeforeCreation(FPluginDescriptor& Descriptor)
{
	Descriptor.Category = TEXT("Game Modifiers");
	Descriptor.bNoCode = true;	// GameModifiers プラグインは pak としてパッケージ化するため、コードを含まない
}

void FGameModifiersGameFeatureActionsPluginTemplateDescription::UpdatePathWhenTemplateSelected(FString& InOutPath)
{
	FString TestPluginFilePath = FPaths::ConvertRelativePathToFull(FPaths::CreateStandardFilename(InOutPath / TEXT("test.uplugin")));
	
	if (!GetDefault<UGameModifiersGameFeatureActionsSettings>()->IsValidGameModifiersGameFeatureActionsPlugin(TestPluginFilePath))
	{
		FString Result = IFileManager::Get().ConvertToAbsolutePathForExternalAppForWrite(*(FPaths::ProjectModsDir() / TEXT("GameFeatures/")));

		FPaths::MakePlatformFilename(Result);

		InOutPath = Result;
	}
}

void FGameModifiersGameFeatureActionsPluginTemplateDescription::UpdatePathWhenTemplateUnselected(FString& InOutPath)
{
	FString Result = IFileManager::Get().ConvertToAbsolutePathForExternalAppForWrite(*FPaths::ProjectModsDir());

	FPaths::MakePlatformFilename(Result);

	InOutPath = Result;
}

void FGameModifiersGameFeatureActionsPluginTemplateDescription::OnPluginCreated(TSharedPtr<IPlugin> NewPlugin)
{
	TSubclassOf<UGameFeatureData> GameFeatureDataClass = UGameFeatureData::StaticClass();

	const FString& AssetName = NewPlugin->GetName();
	const FString& PackagePath = NewPlugin->GetMountedAssetPath();

	UObject* GameFeatureDataAsset = IAssetTools::Get().CreateAsset(AssetName, PackagePath, GameFeatureDataClass, /*Factory=*/ nullptr);

	FGameModifiersGameFeaturesActionsPluginLoaded PluginLoaded = FGameModifiersGameFeaturesActionsPluginLoaded::CreateLambda([GameFeatureDataAsset](const UE::GameFeatures::FResult&)
		{
			// 作成した GameFeatureData をエディタで開く
			if (GameFeatureDataAsset != nullptr)
			{
				GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(GameFeatureDataAsset);
			}
		});

	GEngine->GetEngineSubsystem<UGameModifiersGameFeatureActionsSubsystem>()->LoadBuiltInGameModifiersGameFeatureActionsPlugin(NewPlugin.ToSharedRef(), PluginLoaded);
}
