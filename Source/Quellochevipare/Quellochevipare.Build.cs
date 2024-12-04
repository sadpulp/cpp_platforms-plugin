// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Quellochevipare : ModuleRules
{
	public Quellochevipare(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" , "LevelSequence", "Platforms"});
	}
}
