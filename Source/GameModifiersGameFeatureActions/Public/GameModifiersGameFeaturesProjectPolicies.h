// Copyright (c) 2024 Anoho All rights reserved.

#pragma once

#include "CoreMinimal.h"

// Include headers in GameFeatures plugin.
#include "GameFeaturesProjectPolicies.h"

#include "GameModifiersGameFeaturesProjectPolicies.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMODIFIERSGAMEFEATUREACTIONS_API UGameModifiersGameFeaturesProjectPolicies : public UGameFeaturesProjectPolicies
{
	GENERATED_BODY()

public:

	virtual void InitGameFeatureManager() override;

	virtual void GetGameFeatureLoadingMode(bool& bLoadClientData, bool& bLoadServerData) const override;

	virtual const TArray<FName> GetPreloadBundleStateForGameFeature() const override;
};
