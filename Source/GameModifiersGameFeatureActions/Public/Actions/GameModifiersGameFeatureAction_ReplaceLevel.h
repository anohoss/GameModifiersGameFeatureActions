// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameFeatures module.
#include "GameModifiersGameFeatureAction.h"

#include "GameModifiersGameFeatureAction_ReplaceLevel.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_ReplaceLevel : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FName LevelNameToBeReplaced;

	UPROPERTY(EditDefaultsOnly)
	FName LevelNameToReplace;

public:

	void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
