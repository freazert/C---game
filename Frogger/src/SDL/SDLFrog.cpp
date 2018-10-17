/*
 * SDLFrog.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLFrog.h"
namespace SDL {
SDLFrog::SDLFrog(GameProperties* gameProperties, Keyboard* keyboard,
		SDLCore* sdlCore, SDL_Texture* texture, Factory* factory) :
		Frog(gameProperties, keyboard, sdlCore->GetGridWidth(),
				sdlCore->GetGridHeight(), factory) {

	this->sdlCore = sdlCore;
	this->newTexture = texture;
}

SDLFrog::~SDLFrog() {
}

//het tekenen van de texture
void SDLFrog::Draw() {
	sdlCore->Render(x, y, width, height, newTexture, SDL_FLIP_NONE);
}
}

