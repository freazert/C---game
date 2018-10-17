/*
 * SDLTank.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef SDL_SDLTANK_H_
#define SDL_SDLTANK_H_

#include "GameProperties.h"

#include <SDL2/SDL.h>
#include <SDLCore.h>
#include <Factory.h>
#include <Entity.h>

namespace SDL {
class SDLTank : public Frogger::Tank{
public:

	SDLTank(GameProperties* gameProperties, int lane, SDLCore* sdlCore, SDL_Texture* texture, float spawnX, Frogger::Factory* factory);
	virtual ~SDLTank();

protected:
	void Draw();

private:
	SDLCore* sdlCore = NULL;

	SDL_Texture* newTexture = NULL;

	SDL_RendererFlip flip;
};

}; /* namespace SDL */

#endif /* SDL_SDLTANK_H_ */
