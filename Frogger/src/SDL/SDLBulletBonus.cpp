/*
 * SDLBulletBonus.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <SDLBulletBonus.h>

namespace SDL {
SDLBulletBonus::SDLBulletBonus(GameProperties* gameProperties, SDLCore* sdlCore, SDL_Texture* texture, float y, int lane) :BulletBonus(gameProperties, sdlCore->GetGridWidth(),sdlCore->GetGridHeight(), y, lane) {
	//ctor
	this->sdlCore = sdlCore;
	this->newTexture = texture;

}

SDLBulletBonus::~SDLBulletBonus() {
	//dtor
}

//tekenen van bulletbonus
void SDLBulletBonus::Draw() {

	sdlCore->Render(x, y, width, height, newTexture, SDL_FLIP_NONE);
}
} /* namespace Frogger */
