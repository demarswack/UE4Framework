// Copyright 1998-2015 Martin Egger, Switzerland. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TP_FrameworkEditorTarget : TargetRules
{
	public TP_FrameworkEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
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
