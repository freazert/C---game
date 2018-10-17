/*
 * SDLTank.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <SDLTank.h>

namespace SDL {

SDLTank::SDLTank(GameProperties* gameProperties, int lane,SDLCore* sdlCore, SDL_Texture* texture, float spawnX, Factory* factory) :
		Tank(gameProperties,lane, sdlCore->GetGridWidth(), sdlCore->GetGridHeight() ,factory, spawnX) {
	this->sdlCore = sdlCore;
	newTexture = texture;

	//afhankelijk van de directie wordt er gekeken of de texture geflipt moet worden
	if (direction) {
		flip = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		flip = SDL_FLIP_NONE;
	}

}

//Tekenen van de SDLTank texture
void SDLTank::Draw() {
	sdlCore->Render(x, y, width, height, this->newTexture, flip);
}

SDLTank::~SDLTank() {
}


} /* namespace SDL */
