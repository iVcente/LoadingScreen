// Fill out your copyright notice in the Description page of Project Settings.

#include "FunctionLibraries/MiscFunctionLibrary.h"

#include "LoadingScreen.h"

void UMiscFunctionLibrary::DisplayDetailedLoadingScreen(const bool bDisplayUntilStopped, const FLoadingScreenOptions& UiOptions)
{
	FLoadingScreenModule& LoadingScreenModule = FLoadingScreenModule::Get();
	LoadingScreenModule.DisplayDetailedLoadingScreen(bDisplayUntilStopped, UiOptions);
}

void UMiscFunctionLibrary::DisplayDefaultLoadingScreen(const bool bDisplayUntilStopped)
{
	FLoadingScreenModule& LoadingScreenModule = FLoadingScreenModule::Get();
	LoadingScreenModule.DisplayDefaultLoadingScreen(bDisplayUntilStopped);
}

void UMiscFunctionLibrary::HideLoadingScreen()
{
	FLoadingScreenModule& LoadingScreenModule = FLoadingScreenModule::Get();
	LoadingScreenModule.HideLoadingScreen();
}
