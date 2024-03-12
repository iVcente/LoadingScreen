#pragma once

class SLoadingScreen_ObjectiveInfo : public SCompoundWidget
{
	public:
		SLATE_BEGIN_ARGS(SLoadingScreen_ObjectiveInfo):
			_Objective("")
		{}

		SLATE_ARGUMENT(FString, Objective)
		
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);
};
