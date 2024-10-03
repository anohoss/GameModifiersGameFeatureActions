// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameFeatures module.
#include "GameModifiersGameFeatureAction.h"

#include "GameModifiersGameFeatureAction_AddComponents.generated.h"

USTRUCT()
struct GAMEMODIFIERSGAMEFEATUREACTIONS_API FGameModifiersActorEntry
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TSubclassOf<AActor> ActorClass;
};

USTRUCT()
struct GAMEMODIFIERSGAMEFEATUREACTIONS_API FGameModifiersComponentEntry
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TSubclassOf<UActorComponent> ComponentClass;

	UPROPERTY()
	FName ComponentNameToBeReplaced;
};

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeatureAction_AddComponents : public UGameModifiersGameFeatureAction
{
	GENERATED_BODY()

public:


};
