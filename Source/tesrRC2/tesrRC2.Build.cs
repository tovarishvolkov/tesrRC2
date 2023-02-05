// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class tesrRC2 : ModuleRules
{
	public tesrRC2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AkAudio" });
	}
}
