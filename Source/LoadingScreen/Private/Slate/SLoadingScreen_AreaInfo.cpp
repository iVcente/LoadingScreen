#include "Slate/SLoadingScreen_AreaInfo.h"

#include "LoadingScreenSettings.h"
#include "Widgets/Layout/SSpacer.h"

void SLoadingScreen_AreaInfo::Construct(const FArguments& InArgs)
{
	const UObject* AreaInfoFontObject = GetDefault<ULoadingScreenSettings>()->AreaInfoFont.ResolveObject();

	if (!AreaInfoFontObject)
	{
		UE_LOG(LogTemp, Error, TEXT("Loading Screen Module | Invalid font for area info."));
		return;
	}
	
	ChildSlot
	[
			SNew(SVerticalBox)
					+ SVerticalBox::Slot() // Area
						.AutoHeight()
						.HAlign(EHorizontalAlignment::HAlign_Fill)
						.VAlign(EVerticalAlignment::VAlign_Fill)
						[
							SNew(STextBlock)
							.Margin(FMargin(2.0f, 0.0f, 0.0f, 0.0f))
							.TransformPolicy(ETextTransformPolicy::ToUpper)
							.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
							.Font(FSlateFontInfo(AreaInfoFontObject, 9, FName("Regular")))
							.Text(FText::FromString("Area"))
						]
					+ SVerticalBox::Slot() // Area Name
						.AutoHeight()
						.HAlign(EHorizontalAlignment::HAlign_Fill)
						.VAlign(EVerticalAlignment::VAlign_Fill)
						[
							SNew(STextBlock)
							.Margin(FMargin(1.0f, -7.0f, 0.0f, 0.0f))
							.TransformPolicy(ETextTransformPolicy::ToUpper)
							.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
							.Font(FSlateFontInfo(AreaInfoFontObject, 22, FName("Regular")))
							.Text(FText::FromString(InArgs._AreaName))
						]
	];
}
