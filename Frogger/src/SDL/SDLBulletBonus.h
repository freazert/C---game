/*
 * SDLBulletBonus.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef SDL_SDLBULLETBONUS_H_
#define SDL_SDLBULLETBONUS_H_

#include<SDL2/SDL.h>
#include<GameProperties.h>
#include<SDLCore.h>
#include<Stopwatch.h>
#include<BulletBonus.h>

namespace SDL {

class SDLBulletBonus: public Frogger::BulletBonus {
public:
	SDLBulletBonus(GameProperties*, SDLCore*, SDL_Texture*, float, int);
	virtual ~SDLBulletBonus();
	void Draw();

protected:

private:
	SDLCore * sdlCore;

	SDL_Texture* newTexture;
};
} /* namespace Frogger */

#endif /* SDL_SDLBULLETBONUS_H_ */
