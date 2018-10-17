/*
 * SDLFriendlyProjectile.cpp
 *
 *  Created on: 17-jun.-2016
 *      Author: Kris
 */

#include <SDLFriendlyProjectile.h>

namespace SDL {

SDLFriendlyProjectile::SDLFriendlyProjectile(SDLCore* sdlCore, int x ,int y,SDL_Texture* texture):FriendlyProjectile(sdlCore->GetGridWidth(), sdlCore->GetGridHeight(),x,y)
{
	this->sdlCore = sdlCore;
	newTexture = texture;
}

//het tekenen van de texture
void SDLFriendlyProjectile::Draw() {
	sdlCore->Render(x, y, width, height, this->newTexture, SDL_FLIP_NONE);
}

SDLFriendlyProjectile::~SDLFriendlyProjectile() {

}
} /* namespace SDL */
