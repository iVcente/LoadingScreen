#pragma once

class FDeferredCleanupSlateBrush;

class SLoadingScreen_DefaultScreen : public SCompoundWidget
{
	public:
		SLATE_BEGIN_ARGS(SLoadingScreen_DefaultScreen) {}
		
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);

	private:
		TSharedPtr<FDeferredCleanupSlateBrush> BackgroundImageBrush;
};
