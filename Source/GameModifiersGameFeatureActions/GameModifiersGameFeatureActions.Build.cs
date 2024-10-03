// Copyright (c) 2024 Anoho All rights reserved.

using UnrealBuildTool;

public class GameModifiersGameFeatureActions : ModuleRules
{
	public GameModifiersGameFeatureActions(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[] 
			{ 
				"Core", 
				"CoreUObject",
				"DeveloperSettings",
				"Engine", 
				"EnhancedInput",
				"GameFeatures",
				"GameModifiers",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
				"InputCore",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
			});
	}
}
