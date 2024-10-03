// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameFeatures module.
#include "GameModifiersGameFeatureAction.h"

#include "GameModifiersGameFeatureAction_ReplaceActor.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_ReplaceActor : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> ActorClassToBeReplaced;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> ActorClassToReplace;

public:

	void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
