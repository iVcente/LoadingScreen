#include "LoadingScreen.h"

#include "LoadingScreenSettings.h"
#include "MoviePlayer.h"
#include "Slate/SLoadingScreen_DefaultScreen.h"
#include "Slate/SLoadingScreen_DetailedScreen.h"

IMPLEMENT_GAME_MODULE(FLoadingScreenModule, LoadingScreen);

void FLoadingScreenModule::StartupModule()
{
	// This code will execute after your module is loaded into memory. The exact timing is specified in the .uproject file
	
	if (!IsRunningDedicatedServer() && FSlateApplication::IsInitialized())
	{
		// Load assets into memory so when showing loading screen for the first time, it's already loaded

		// Background images for each area
		for (FSoftObjectPath BackgroundAreaImage : GetDefault<ULoadingScreenSettings>()->BackgroundAreaImages)
		{
			LoadObject<UObject>(nullptr, *BackgroundAreaImage.ToString());
		}

		// Default background image
		LoadObject<UObject>(nullptr, *GetDefault<ULoadingScreenSettings>()->BackgroundDefaultImage.ToString());
	
		// Fonts
		LoadObject<UObject>(nullptr, *GetDefault<ULoadingScreenSettings>()->AreaInfoFont.ToString());
		LoadObject<UObject>(nullptr, *GetDefault<ULoadingScreenSettings>()->ObjectivesListFont.ToString());
		
		// Enable to show loading screen automatically on every game load
		// if (IsMoviePlayerEnabled())
		// {
		// 	GetMoviePlayer()->OnPrepareLoadingScreen().AddRaw(this, &FLoadingScreenModule::EnableAutomaticallyDisplayLoadingScreen);				
		// }

		// Show loading screen on initial game load
		// if (IsMoviePlayerEnabled())
		// {
		//     DisplayDefaultLoadingScreen(false);
		// }
	}
}

void FLoadingScreenModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module. For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!IsRunningDedicatedServer())
	{
		GetMoviePlayer()->OnPrepareLoadingScreen().RemoveAll(this);
	}
}

bool FLoadingScreenModule::IsGameModule() const
{
	return true;
}

void FLoadingScreenModule::DisplayDetailedLoadingScreen(const bool bDisplayUntilStopped, const FLoadingScreenOptions& UiOptions)
{
	FLoadingScreenAttributes LoadingScreen;
	LoadingScreen.MinimumLoadingScreenDisplayTime = -1.0f;
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bDisplayUntilStopped;
	LoadingScreen.bMoviesAreSkippable = false;
	LoadingScreen.bWaitForManualStop = bDisplayUntilStopped;
	LoadingScreen.bAllowEngineTick = bDisplayUntilStopped;
	LoadingScreen.WidgetLoadingScreen = SNew(SLoadingScreen_DetailedScreen)
											.BackgroundImageIndex(UiOptions.BackgroundImageIndex)
											.AreaName(UiOptions.AreaName)
											.ObjectivesList(UiOptions.ObjectivesList);

	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}

void FLoadingScreenModule::DisplayDefaultLoadingScreen(const bool bDisplayUntilStopped)
{
	FLoadingScreenAttributes LoadingScreen;
	LoadingScreen.MinimumLoadingScreenDisplayTime = -1.0f;
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bDisplayUntilStopped;
	LoadingScreen.bMoviesAreSkippable = false;
	LoadingScreen.bWaitForManualStop = bDisplayUntilStopped;
	LoadingScreen.bAllowEngineTick = bDisplayUntilStopped;
	LoadingScreen.WidgetLoadingScreen = SNew(SLoadingScreen_DefaultScreen);

	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}

void FLoadingScreenModule::HideLoadingScreen()
{
	GetMoviePlayer()->StopMovie();
}

void FLoadingScreenModule::EnableAutomaticallyDisplayLoadingScreen()
{
	DisplayDefaultLoadingScreen(false);
}
