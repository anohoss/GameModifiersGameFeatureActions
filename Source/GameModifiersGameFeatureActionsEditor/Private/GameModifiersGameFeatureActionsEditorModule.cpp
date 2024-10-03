// Copyright (c) 2024 Anoho All rights reserved.

#include "GameModifiersGameFeatureActionsEditorModule.h"

#include "Modules/ModuleManager.h"

// Include headers in GameModifiersEditor module.
#include "Features/IGameModifiersEditorPluginsFeature.h"

// Include headers in GameModifiersGameFeatureActionsEditor module.
#include "GameModifiersGameFeatureActionsPluginTemplateDescription.h"

#define LOCTEXT_NAMESPACE "GameModifiersGameFeatureActionsEditor"

void FGameModifiersGameFeatureActionsEditorModule::StartupModule()
{
	RegisterPluginTemplates();
}

void FGameModifiersGameFeatureActionsEditorModule::RegisterPluginTemplates()
{
	// PluginTemplateDescription を登録するために IGameModifiersEditorPluginsFeature が必要
	if (!IGameModifiersEditorPluginsFeature::IsAvailable())
	{
		return;
	}

	TSharedPtr<IPlugin> GameModifiersGameFeatureActionsPlugin = IPluginManager::Get().FindPlugin(TEXT("GameModifiersGameFeatureActions"));

	if (!GameModifiersGameFeatureActionsPlugin.IsValid())
	{
		return;
	}

	auto RegisterPluginTemplate = [](const TSharedRef<FGameModifiersGameFeatureActionsPluginTemplateDescription> InTemplate)
		{
			IGameModifiersEditorPluginsFeature::Get().RegisterPluginTemplate(InTemplate);
		};

	const FString& PluginBaseDir = GameModifiersGameFeatureActionsPlugin->GetBaseDir();

	// Add content-only template.
	{
		const FText TemplateName = LOCTEXT("ContentOnlyTemplateName", "Content Only (with Game Features)");
		const FText TemplateDescription = LOCTEXT("ContentOnlyTemplateDescription", "Create a blank plugin that can only contain content.");
		const FString TemplateOnDiskPath = PluginBaseDir / TEXT("Templates/ContentOnly");

		TSharedRef<FGameModifiersGameFeatureActionsPluginTemplateDescription> Template = MakeShareable(
			new FGameModifiersGameFeatureActionsPluginTemplateDescription(
				TemplateName,
				TemplateDescription,
				TemplateOnDiskPath)
		);

		RegisterPluginTemplate(Template);
	}
}

#undef LOCTEXT_NAMESPACE // GameModifiersGameFeatureActionsEditor

IMPLEMENT_MODULE( FGameModifiersGameFeatureActionsEditorModule, GameModifiersGameFeatureActionsEditor );
