/*
 * SDLVehicle.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLVEHICLE_H_
#define SDL_SDLVEHICLE_H_

#include <SDL2/SDL.h>
#include <SDLCore.h>
#include <Entity.h>
#include "vehicle.h"

using namespace std;
namespace SDL {
class SDLVehicle: public Frogger::Vehicle {
public:

	SDLVehicle(GameProperties* gameProperties, int,  SDLCore*, SDL_Texture*, float, Frogger::Factory*);
	void Draw();
	virtual ~SDLVehicle();

private:
	SDLCore* sdlCore = NULL;

	SDL_Texture* newTexture = NULL;

	SDL_RendererFlip flip;
};

}
#endif /* SDL_SDLVEHICLE_H_ */
