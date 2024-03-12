#pragma once

class SLoadingScreen_AreaInfo : public SCompoundWidget
{
	public:
		SLATE_BEGIN_ARGS(SLoadingScreen_AreaInfo):
			_AreaName(TEXT(""))
		{}
		
		SLATE_ARGUMENT(FString, AreaName)
		
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);
};
