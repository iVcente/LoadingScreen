#include "Slate/SLoadingScreen_DetailedScreen.h"

#include "LoadingScreenSettings.h"
#include "Slate/DeferredCleanupSlateBrush.h"
#include "Slate/SLoadingScreen_ObjectiveInfo.h"
#include "Slate/SLoadingScreen_AreaInfo.h"
#include "Widgets/Images/SThrobber.h"

void SLoadingScreen_DetailedScreen::Construct(const FArguments& InArgs)
{
	// Find already loaded background image
	UTexture2D* BackgroundImage;
	
	const ULoadingScreenSettings* LoadingScreenSettings = GetDefault<ULoadingScreenSettings>();
	const int32 BackgroundImageIndex = InArgs._BackgroundImageIndex;
	
	if (BackgroundImageIndex == -1) // Should use default background image
	{
		BackgroundImage = Cast<UTexture2D>(LoadingScreenSettings->BackgroundDefaultImage.ResolveObject());
	}
	else
	{
		BackgroundImage = Cast<UTexture2D>(LoadingScreenSettings->BackgroundAreaImages[BackgroundImageIndex].ResolveObject());
	}
	
	if (!BackgroundImage)
	{
		UE_LOG(LogTemp, Error, TEXT("Loading Screen Module | Invalid background image."));
		return;
	}

	const TSharedRef<SVerticalBox> SObjectivesList = SNew(SVerticalBox);
	
	for (const FString& Objective : InArgs._ObjectivesList)
	{
		SObjectivesList.Get().AddSlot()
			.AutoHeight()
			[
				SNew(SLoadingScreen_ObjectiveInfo).Objective(Objective)
			];
	}

	BackgroundImageBrush = FDeferredCleanupSlateBrush::CreateBrush(BackgroundImage);
	
	ChildSlot
	[
		SNew(SOverlay) // Overlay Panel
			+ SOverlay::Slot() // Image
				.HAlign(EHorizontalAlignment::HAlign_Fill)
				.VAlign(EVerticalAlignment::VAlign_Fill)
				[
					SNew(SImage)
						.Image(BackgroundImageBrush.IsValid() ? BackgroundImageBrush->GetSlateBrush() : nullptr)
				]
			+ SOverlay::Slot() // Circular Throbber
				.HAlign(EHorizontalAlignment::HAlign_Right)
				.VAlign(EVerticalAlignment::VAlign_Bottom)
				.Padding(0.0f, 0.0f, 10.0f, 10.0f)
				[
					SNew(SCircularThrobber)
						.Radius(24.0f)
						.RenderTransform(FSlateRenderTransform(FScale2D(-1.0f, 1.0f)))
						.RenderTransformPivot(FVector2D(0.5f, 0.5f))
				]
			+ SOverlay::Slot() // Vertical Box | Objectives List
				.HAlign(EHorizontalAlignment::HAlign_Right)
				.VAlign(EVerticalAlignment::VAlign_Top)
				.Padding(0.0f, 150.0f, 150.0f, 0.0f)
				[
					SObjectivesList
				]
			+ SOverlay::Slot() // Vertical Box | Area Info
				.HAlign(EHorizontalAlignment::HAlign_Left)
				.VAlign(EVerticalAlignment::VAlign_Bottom)
				.Padding(107.0f, 0.0f, 0.0f, 105.0f)
				[
					SNew(SLoadingScreen_AreaInfo)
						.AreaName(InArgs._AreaName)
				]
	];
	
	// Canvas Panel
	// On WBP, Slot attributes Position X and Position Y correspond respectively to Offset.Left and Offset.Top on Slate
	// On WBP, Slot attributes Size X and Size Y correspond respectively to Offset.Right and Offset.Bottom on Slate
	// On WBP, * used to defined widget pivot corresponds to Alignment attribute
}
