#include "Slate/SLoadingScreen_DetailedScreen.h"
#include "UMG/ULoadingScreen_DetailedScreen.h"

#if WITH_EDITOR
	const FText ULoadingScreen_DetailedScreen::GetPaletteCategory()
	{
		return INVTEXT("Loading Screen");
	}
#endif

void ULoadingScreen_DetailedScreen::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	LoadingScreen_DetailedScreen.Reset();
}

TSharedRef<SWidget> ULoadingScreen_DetailedScreen::RebuildWidget()
{
	LoadingScreen_DetailedScreen = SNew(SLoadingScreen_DetailedScreen)
		.BackgroundImageIndex(BackgroundImageIndex)
		.AreaName(AreaName)
		.ObjectivesList(ObjectivesList);

	return LoadingScreen_DetailedScreen.ToSharedRef();
}
