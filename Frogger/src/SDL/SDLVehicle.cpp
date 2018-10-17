/*
 * SDLVehicle.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLVehicle.h"

namespace SDL {
SDLVehicle::SDLVehicle(GameProperties* gameProperties, int lane,SDLCore* sdlCore, SDL_Texture* texture, float spawnX, Factory* factory) :
		Vehicle(gameProperties, lane, sdlCore->GetGridWidth(),sdlCore->GetGridHeight(), spawnX) {

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
//Tekenen van de auto texture.
void SDLVehicle::Draw() {
	sdlCore->Render(x, y, width, height, this->newTexture, flip);
}

SDLVehicle::~SDLVehicle() {}

}
