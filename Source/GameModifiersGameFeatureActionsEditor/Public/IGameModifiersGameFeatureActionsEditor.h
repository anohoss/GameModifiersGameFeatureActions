// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in Core module.
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IGameModifiersGameFeatureActionsEditor : public IModuleInterface
{
public:

	static inline IGameModifiersGameFeatureActionsEditor& Get()
	{
		return FModuleManager::LoadModuleChecked<IGameModifiersGameFeatureActionsEditor>("GameModifiersGameFeatureActionsEditor");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("GameModifiersGameFeatureActionsEditor");
	}
};
