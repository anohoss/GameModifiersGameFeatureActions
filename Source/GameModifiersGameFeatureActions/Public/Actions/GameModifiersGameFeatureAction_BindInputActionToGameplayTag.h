// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in EnhancedInput module.
#include "InputAction.h"

// Include headers in GameFeatures module.
#include "GameModifiersGameFeatureAction.h"

#include "GameModifiersGameFeatureAction_BindInputActionToGameplayTag.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_BindInputActionToGameplayTag : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:

	void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
