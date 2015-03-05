// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TP_FrameworkTarget : TargetRules
{
	public TP_FrameworkTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "TP_Framework" } );
	}
}
