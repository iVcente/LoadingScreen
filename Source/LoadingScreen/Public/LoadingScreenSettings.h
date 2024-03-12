#pragma once

#include "LoadingScreenSettings.generated.h"

USTRUCT(BlueprintType)
struct FLoadingScreenOptions
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 BackgroundImageIndex = -1;

	UPROPERTY(BlueprintReadWrite)
	FString AreaName = TEXT("");

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ObjectivesList;
};

UCLASS(Config = "Game", DefaultConfig)
class LOADINGSCREEN_API ULoadingScreenSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
		ULoadingScreenSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

		UPROPERTY(Config, EditAnywhere, Category = "General", Meta = (AllowedClasses = "/Script/Engine.Texture2D"))
		TArray<FSoftObjectPath> BackgroundAreaImages;

		UPROPERTY(Config, EditAnywhere, Category = "General", Meta = (AllowedClasses = "/Script/Engine.Texture2D"))
		FSoftObjectPath BackgroundDefaultImage;

		UPROPERTY(Config, EditAnywhere, Category = "General", Meta = (AllowedClasses = "/Script/Engine.Font"))
		FSoftObjectPath AreaInfoFont;
	
		UPROPERTY(Config, EditAnywhere, Category = "General", Meta = (AllowedClasses = "/Script/Engine.Font"))
		FSoftObjectPath ObjectivesListFont;

		UPROPERTY(Config, EditAnywhere, Category = "General", Meta = (AllowedClasses = "/Script/Engine.Font"))
		FSoftObjectPath IconFont;
};
