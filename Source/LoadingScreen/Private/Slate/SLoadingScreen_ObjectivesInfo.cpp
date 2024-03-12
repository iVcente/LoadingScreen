#include "Slate/SLoadingScreen_ObjectiveInfo.h"

#include "LoadingScreenSettings.h"
#include "Widgets/Layout/SSpacer.h"

void SLoadingScreen_ObjectiveInfo::Construct(const FArguments& InArgs)
{
	const UObject* ObjectivesListFontObject = GetDefault<ULoadingScreenSettings>()->ObjectivesListFont.ResolveObject();

	if (!ObjectivesListFontObject)
	{
		UE_LOG(LogTemp, Error, TEXT("Loading Screen Module | Invalid fonts for objectives info UI."));
		return;
	}
	
	ChildSlot
	[
			SNew(SBox) // Size Box
			.HeightOverride(30.0f)
			[
				SNew(SHorizontalBox) // Horizontal Box
				+ SHorizontalBox::Slot() // Text Block
					.AutoWidth()
					.HAlign(EHorizontalAlignment::HAlign_Fill)
					.VAlign(EVerticalAlignment::VAlign_Center)
					.Padding(0.0f, 2.0f, 0.0f, 0.0f)
					[
						SNew(STextBlock)
						.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
						.Font(FSlateFontInfo(ObjectivesListFontObject, 8, FName("Default")))
						.Text(FText::FromString("Objectives: "))
					]
				+ SHorizontalBox::Slot() // Spacer
					.AutoWidth()
					.HAlign(EHorizontalAlignment::HAlign_Fill)
					.VAlign(EVerticalAlignment::VAlign_Fill)
					[
						SNew(SSpacer)
						.Size(FVector2D(8.0f, 1.0f))
					]
				+ SHorizontalBox::Slot() // Text Block
					.AutoWidth()
					.HAlign(EHorizontalAlignment::HAlign_Fill)
					.VAlign(EVerticalAlignment::VAlign_Center)
					[
						SNew(STextBlock)
						.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
						.Font(FSlateFontInfo(ObjectivesListFontObject, 13, FName("Bold")))
						.Text(FText::FromString(InArgs._Objective))
					]
			]
	];
}
