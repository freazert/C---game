/*
 * SDLCore.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLCore.h"
#include <SDL2/SDL_mixer.h>

namespace SDL {

// een texture maken aan de hand van de gegereneerde text.
SDL_Texture* SDLCore::renderText(const std::string &message) {

	SDL_Texture* texture = NULL;
	//Open the font
	TTF_Font *font = (TTF_OpenFont("Fonts/OpenSans-Regular.ttf", 20));
	if (font == NULL) {
		printf("error opening font");
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == NULL) {
		TTF_CloseFont(font);
		printf("error TTF_RenderText");
	}

	texture = SDL_CreateTextureFromSurface(gRenderer, surf);
	//error
	if (texture == NULL) {
		printf("error creating texture");
	}
	//Clean up the surface and font*/
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

//aanmaken van de Core/ screen
bool SDLCore::Init(int x, int y, int grid_width, int grid_height) {

	//absolute waardes
	SCREEN_HEIGHT = y;
	SCREEN_WIDTH = x;

	//grid waardes
	this->grid_height = grid_height;
	this->grid_width = grid_width;

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("S DL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		gWindow = SDL_CreateWindow("Frogger 2016", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		}
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

	//Initialize PNG loading

	 int imgFlags = IMG_INIT_PNG;
	 if( !( IMG_Init( imgFlags ) & imgFlags ) )
	 {
	 printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
	 //        success = false;
	 }
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SD L_mixer could not initialize! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
		TTF_GetError());
		success = false;
	}

	backgroundTexture = CreateTexture((char *) "Pictures/Background.bmp");
	if (backgroundTexture == NULL) {
		printf("Unable to create texture from %s! SDL Error: %s\n", "l",
				SDL_GetError());

	}
	//Get rid of old loaded surface
	return success;
}

//render background
void SDLCore::LoadBackground() {
	Render(0, 0, grid_width, grid_height - 1, backgroundTexture, SDL_FLIP_NONE);
}

//De texture in de gRanderer steken, de texture afmeting van relatief naar absoluut zetten.
void SDLCore::Render(float x, float y, float width, float height,
		SDL_Texture* texture, SDL_RendererFlip flipType) {

	SDL_Rect stretchRect;
	stretchRect.x = round(SCREEN_WIDTH / grid_width * x);
	stretchRect.y = round(SCREEN_HEIGHT / grid_height * y);
	stretchRect.w = round(SCREEN_WIDTH / grid_width * width);
	stretchRect.h = round(SCREEN_HEIGHT / grid_height * height);

	//Render texture to screen
	SDL_RenderCopyEx(gRenderer, texture, NULL, &stretchRect, 0, NULL, flipType);

}

//Het tekenen van alle  elementen op het scherm.
void SDLCore::ReRender(std::vector<Entity*>* entities,
		GameProperties* gameProperties) {
	//het scherm legen
	SDL_RenderClear(gRenderer);

	//het background laden
	LoadBackground();

	//alle entities laden
	for (unsigned int i = 0; i < entities->size(); i++) {
		entities->at(i)->Draw();
	}

	// de text renderen.
	SDL_Texture* renderVariableText = SDLCore::renderText(
			"score: " + NumberToString(gameProperties->score) + "      time: "
					+ NumberToString(gameProperties->stopwatch->time)
					+ "     lives: " + NumberToString(gameProperties->lives)
					+ "     level: " + NumberToString(gameProperties->level)
					+ "     highscore:"
					+ NumberToString(gameProperties->highscore)
					+ "      bullets: "
					+ NumberToString(gameProperties->totalBullets));
	Render(0, 19, 20, 1, renderVariableText, SDL_FLIP_NONE);

	// alles op het scherm toveren
	SDL_RenderPresent(gRenderer);

	//opruimen van een texture
	SDL_DestroyTexture(renderVariableText);
	renderVariableText = NULL;
}

//een 'sleep' van enkele milliseconden
void SDLCore::Delay(float ms) {
	SDL_Delay(ms);
}

//Aanmaken van een texture op basis van een path
SDL_Texture* SDLCore::CreateTexture(char* path) {

	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL) {
		printf("Unable to load surface from %s! SDL Error: %s\n", "l",
				SDL_GetError());
	}
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gRenderer,
			loadedSurface);
	if (newTexture == NULL) {
		printf("Unable to cre  ate texture from %s! SDL Error: %s\n", "l",
				SDL_GetError());
	}
	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

//opruimen van objecten
SDLCore::~SDLCore() {
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

}
}
