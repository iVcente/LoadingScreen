#pragma once

class FDeferredCleanupSlateBrush;

class SLoadingScreen_DetailedScreen : public SCompoundWidget
{
	public:
		SLATE_BEGIN_ARGS(SLoadingScreen_DetailedScreen):
			_BackgroundImageIndex(-1),  // Default arguments
			_AreaName(TEXT("")),
			_ObjectivesList(TArray<FString>())
		{}

			SLATE_ARGUMENT(int32, BackgroundImageIndex)
		
			SLATE_ARGUMENT(FString, AreaName)
			
			SLATE_ARGUMENT(TArray<FString>, ObjectivesList)
	
		SLATE_END_ARGS()
	
		void Construct(const FArguments& InArgs);

	private:
		TSharedPtr<FDeferredCleanupSlateBrush> BackgroundImageBrush;
};
