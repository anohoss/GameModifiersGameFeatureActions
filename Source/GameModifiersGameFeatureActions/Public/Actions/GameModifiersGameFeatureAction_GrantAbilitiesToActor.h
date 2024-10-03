// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameFeatures module.
#include "GameModifiersGameFeatureAction.h"

// Include headers in GameModifiers module.
#include "AbilitySystem/GameModifiersAbilitySet.h"

#include "GameModifiersGameFeatureAction_GrantAbilitiesToActor.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_GrantAbilitiesToActor : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:

	void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;

protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<AActor> ActorClassToBeGranted;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TObjectPtr<UGameModifiersAbilitySet> AbilitySetToGrant;
};
