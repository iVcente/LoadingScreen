// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MyProject : ModuleRules
{
	public MyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
			{
                "ApplicationCore",
				"Core", 
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"EnhancedInput",
				"Json",
				"JsonUtilities",
				"InputCore",
				"UMG"
			}
		);

		PrivateDependencyModuleNames.AddRange(new string[] 
			{
				"LoadingScreen",
				"JSONDatabaseSubsystem",
			}
		);
	}
}
