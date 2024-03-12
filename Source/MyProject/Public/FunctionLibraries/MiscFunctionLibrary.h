// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MiscFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMiscFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:	
		#pragma region LoadingScreen
			UFUNCTION(BlueprintCallable, Category = "LoadingScreen")
			static void DisplayDetailedLoadingScreen(const bool bDisplayUntilStopped, const FLoadingScreenOptions& UiOptions);

			UFUNCTION(BlueprintCallable, Category = "LoadingScreen")
			static void DisplayDefaultLoadingScreen(const bool bDisplayUntilStopped);

			UFUNCTION(BlueprintCallable, Category = "LoadingScreen")
			static void HideLoadingScreen();
		#pragma endregion LoadingScreen
};
