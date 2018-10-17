/*
 * SDLBonus.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLBonus.h"

using namespace Frogger;
namespace SDL
{
	SDLBonus::SDLBonus(GameProperties* gameProperties, SDLCore* sdlCore, SDL_Texture* texture, float y, int lane):BonusScore(gameProperties, sdlCore->GetGridWidth(), sdlCore->GetGridHeight(), y, lane)
	{
		//ctor
		this->sdlCore = sdlCore;
		this->newTexture = texture;
	}

	SDLBonus::~SDLBonus()
	{
		//dtor
	}

	//tekenen van Bonus
	void SDLBonus::Draw()
	{
		sdlCore->Render(x,y,width,height, newTexture, SDL_FLIP_NONE);
	}
}
