#include "LoadingScreenSettings.h"

ULoadingScreenSettings::ULoadingScreenSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (!IsRunningDedicatedServer())
	{
		CategoryName = TEXT("Game");
		SectionName = TEXT("Loading Screen Settings");
	}

	// Default/initial value for variables
	AreaInfoFont = FString(TEXT("/Game/Fonts/SomeFont/SomeFont-Regular_Font.SomeFont-Regular_Font"));
	ObjectivesListFont = FString(TEXT("/Game/Fonts/OtherFont/OtherFont-Bold_Font.OtherFont-Bold_Font"));
}
