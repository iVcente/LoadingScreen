#pragma once

#include "Modules/ModuleManager.h"

struct FLoadingScreenOptions;

class LOADINGSCREEN_API FLoadingScreenModule : public IModuleInterface
{
	public:
		/* * * * * * * * * * * * * * * *
		 * * * Mandatory Functions * * *
		 * * * * * * * * * * * * * * * */
	
		/**
		 * Singleton-like access to this module's interface. This is just for convenience!
		 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
		 *
		 * @return Returns singleton instance, loading the module on demand if needed
		 */
		static inline FLoadingScreenModule& Get()
		{
			return FModuleManager::LoadModuleChecked<FLoadingScreenModule>("LoadingScreen");
		}

	   /**
		* Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
		*
		* @return True if the module is loaded and ready to use
		*/
		static inline bool IsAvailable()
		{
			return FModuleManager::Get().IsModuleLoaded("LoadingScreen");
		}

		// Called right after the module DLL has been loaded and the module object has been created
		virtual void StartupModule() override;

		// Called before the module is unloaded, right before the module object is destroyed
		virtual void ShutdownModule() override;

		/**
		 * Returns true if this module hosts gameplay code 
		 * 
		 * @return True for "gameplay modules", or false for engine code modules, plugins, etc.
		 */
		virtual bool IsGameModule() const override;

		/* * * * * * * * * * * * * * *
		 * * * Custom Functions * * *
	     * * * * * * * * * * * * * * */
	
		static void DisplayDetailedLoadingScreen(const bool bDisplayUntilStopped, const FLoadingScreenOptions& UiOptions);
	
		static void DisplayDefaultLoadingScreen(bool bDisplayUntilStopped);

		static void HideLoadingScreen();

		void EnableAutomaticallyDisplayLoadingScreen();
};
