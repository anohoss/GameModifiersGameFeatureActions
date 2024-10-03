// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in Projects module.
#include "Interfaces/IPluginManager.h"
#include "PluginDescriptor.h"

// Include headers in UnrealEd module.
#include "Features/IPluginsEditorFeature.h"

/**
 *
 */
struct FGameModifiersGameFeatureActionsPluginTemplateDescription : public FPluginTemplateDescription
{
public:

	FGameModifiersGameFeatureActionsPluginTemplateDescription(FText InName, FText InDescription, FString InOnDiskPath);

	~FGameModifiersGameFeatureActionsPluginTemplateDescription() override {};

public:

	// Begin FPluginTemplateDescription interface

	void CustomizeDescriptorBeforeCreation(FPluginDescriptor& Descriptor) override;

	void UpdatePathWhenTemplateSelected(FString& InOutPath) override;

	void UpdatePathWhenTemplateUnselected(FString& InOutPath) override;

	void OnPluginCreated(TSharedPtr<IPlugin> NewPlugin) override;

	// End FPluginTemplateDescription interface
};
