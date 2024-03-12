#include "Slate/SLoadingScreen_DefaultScreen.h"

#include "LoadingScreenSettings.h"
#include "Slate/DeferredCleanupSlateBrush.h"
#include "Widgets/Images/SThrobber.h"


void SLoadingScreen_DefaultScreen::Construct(const FArguments& InArgs)
{
	// Find already loaded background image
	UTexture2D* BackgroundImage = Cast<UTexture2D>(GetDefault<ULoadingScreenSettings>()->BackgroundDefaultImage.ResolveObject());
	
	if (!BackgroundImage)
	{
		UE_LOG(LogTemp, Error, TEXT("Loading Screen Module | Invalid background image."));
		return;
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
	];
	
	// Canvas Panel
	// On WBP, Slot attributes Position X and Position Y correspond respectively to Offset.Left and Offset.Top on Slate
	// On WBP, Slot attributes Size X and Size Y correspond respectively to Offset.Right and Offset.Bottom on Slate
	// On WBP, * used to defined widget pivot corresponds to Alignment attribute
}
