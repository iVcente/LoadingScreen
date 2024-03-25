This is my solution for a loading screen in Unreal. It's possible to manually or automatically display/hide the loading screen. Its UI cannot be built with UMG Widgets, so this repo should also serve as a reference for my future self on how to work with Slate (and expose it to Blueprints), as well as with Modules and Developer Settings. I plan to create a Plugin out of it as soon as possible.

In the engine source code, I believe there's a bug on the **MoviePlayer** module, specifically in the _DefaultMoviePlayer.cpp_ file. The way this bug behaves is that even if you set up your `FLoadingScreenAttributes` property `bMoviesAreSkippable` to `false`, movies can still be skipabble. This really becomes a problem when you'd like, for instance, to display the loading screen and manually hide it when your game routines are completely ready.

My proposed change on the source code is on the line 908 of the given file:

```
if (IsMovieStreamingFinished() && LoadingScreenAttributes.bMoviesAreSkippable)
```

The entire file with this change can be found in the _Engine/DefaultMoviePlayer.cpp_ file of this repo.

References
---
* [Async Loading Screens and Transition Levels | Unreal Fest Europe 2019 | Unreal Engine](https://youtu.be/ON1_dEHoNDg?si=1Hw0O96w9AagTuUW);
* [AsyncLoadingScreen](https://github.com/truong-bui/AsyncLoadingScreen/tree/master) by [truong-bui](https://github.com/truong-bui);
* [Action RPG](https://www.unrealengine.com/marketplace/en-US/product/action-rpg) sample project by Epic Games. 
