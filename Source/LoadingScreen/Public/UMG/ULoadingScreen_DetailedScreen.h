#pragma once

#include "Components/Widget.h"

#include "ULoadingScreen_DetailedScreen.generated.h"

class SLoadingScreen_DetailedScreen;

UCLASS()
class LOADINGSCREEN_API ULoadingScreen_DetailedScreen : public UWidget
{
	GENERATED_BODY()
	
	public:
		#if WITH_EDITOR
			virtual const FText GetPaletteCategory() override;
		#endif

		UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Loading Screen Settings")
		int32 BackgroundImageIndex = -1;
		
		UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Loading Screen Settings")
		FString AreaName = TEXT("");
		
		UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Loading Screen Settings")
		TArray<FString> ObjectivesList;
	
		virtual void ReleaseSlateResources(bool bReleaseChildren) override; // UVisual interface
	
	protected:
		TSharedPtr<SLoadingScreen_DetailedScreen> LoadingScreen_DetailedScreen; // Native Slate Widget
	
		virtual TSharedRef<SWidget> RebuildWidget() override; // UWidget interface
};
