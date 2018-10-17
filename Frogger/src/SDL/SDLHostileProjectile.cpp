/*
 * SDLProjectile.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLHostileProjectile.h"
namespace SDL
{
	SDLHostileProjectile::SDLHostileProjectile(GameProperties* gameProperties,SDLCore* sdlCore, int x, int y, int frogX, int frogY, SDL_Texture* texture): HostileProjectile(gameProperties, sdlCore->GetGridWidth(), sdlCore->GetGridHeight(),x,y, frogX, frogY)
	{
		this->sdlCore = sdlCore;
		newTexture = texture;
	}


	//het tekenen van de texture
	void SDLHostileProjectile::Draw(){
		sdlCore->Render(x,y,width,height, this->newTexture, SDL_FLIP_NONE);
	}

	SDLHostileProjectile::~SDLHostileProjectile()
	{

	}
}
