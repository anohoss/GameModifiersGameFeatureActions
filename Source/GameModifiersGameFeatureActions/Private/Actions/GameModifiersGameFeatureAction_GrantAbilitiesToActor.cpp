// Copyright (c) 2024 Anoho All rights reserved.

#include "Actions/GameModifiersGameFeatureAction_GrantAbilitiesToActor.h"

// Include headers in Engine module.
#include "Engine/GameInstance.h"

// Include headers in GameModifiers module.
#include "GameModifiersActorRegistry.h"

void UGameModifiersGameFeatureAction_GrantAbilitiesToActor::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	TObjectPtr<UGameModifiersActorRegistry> GameModifierActorRegistry = GEngine->GetEngineSubsystem<UGameModifiersActorRegistry>();

	if (GameModifierActorRegistry)
	{
		GameModifierActorRegistry->RegisterAbilitySetForActorClass(ActorClassToBeGranted, AbilitySetToGrant);
	}
}

void UGameModifiersGameFeatureAction_GrantAbilitiesToActor::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	TObjectPtr<UGameModifiersActorRegistry> GameModifierActorRegistry = GEngine->GetEngineSubsystem<UGameModifiersActorRegistry>();

	if (GameModifierActorRegistry)
	{
		GameModifierActorRegistry->UnregisterAbilitySetForActorClass(ActorClassToBeGranted, AbilitySetToGrant);
	}
}
