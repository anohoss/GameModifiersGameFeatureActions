// Copyright (c) 2024 Anoho All rights reserved.

#include "Actions/GameModifiersGameFeatureAction_ReplaceActor.h"

// Include headers in Engine module.
#include "Engine/GameInstance.h"

// Include headers in GameModifiers module.
#include "GameModifiersActorRegistry.h"

void UGameModifiersGameFeatureAction_ReplaceActor::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	TObjectPtr<UGameModifiersActorRegistry> GameModifierActorRegistry = GEngine->GetEngineSubsystem<UGameModifiersActorRegistry>();

	if (GameModifierActorRegistry)
	{
		GameModifierActorRegistry->RegisterOverrideForActorClass(ActorClassToBeReplaced, ActorClassToReplace);
	}
}

void UGameModifiersGameFeatureAction_ReplaceActor::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	TObjectPtr<UGameModifiersActorRegistry> GameModifierActorRegistry = GEngine->GetEngineSubsystem<UGameModifiersActorRegistry>();

	if (GameModifierActorRegistry)
	{
		GameModifierActorRegistry->UnregisterOverrideForActorClass(ActorClassToBeReplaced);
	}
}
