// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameModifiersGameFeatureActions module.
#include "Actions/GameModifiersGameFeatureAction.h"

#include "GameModifiersGameFeatureAction_LoadStreamLevel.generated.h"

USTRUCT()
struct GAMEMODIFIERSGAMEFEATUREACTIONS_API FGameModifiersGameFeatureActionsStreamLevelEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FName LevelName;

	UPROPERTY(EditDefaultsOnly)
	bool bLoadOnlyWithPersistentLevel;
};

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_LoadStreamLevel : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:

	void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;

public:

	UPROPERTY(EditDefaultsOnly)
	FName LevelName;

	UPROPERTY(EditDefaultsOnly)
	TArray<FGameModifiersGameFeatureActionsStreamLevelEntry> StreamLevels;
};
