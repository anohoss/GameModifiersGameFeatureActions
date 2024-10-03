// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameModifiersGameFeatureActionsEditor module.
#include "IGameModifiersGameFeatureActionsEditor.h"

class FGameModifiersGameFeatureActionsEditorModule : public IGameModifiersGameFeatureActionsEditor
{
public:

	// Begin IModuleInterface interface

	void StartupModule() override;

	// End IModuleInterface interface

private:

	void RegisterPluginTemplates();
};
