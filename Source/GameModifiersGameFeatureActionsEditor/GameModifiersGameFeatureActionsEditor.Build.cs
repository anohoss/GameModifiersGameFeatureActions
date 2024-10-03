// Copyright (c) 2024 Anoho All rights reserved.

using UnrealBuildTool;

public class GameModifiersGameFeatureActionsEditor : ModuleRules
{
	public GameModifiersGameFeatureActionsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine",
				"InputCore",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AssetTools",
				"GameFeatures",
				"GameModifiersEditor",
				"GameModifiersGameFeatureActions",
				"Projects",
				"UnrealEd",
			});
	}
}
