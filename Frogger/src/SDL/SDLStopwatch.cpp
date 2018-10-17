/*
 * SDLStopwatch.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLStopwatch.h"
namespace SDL
{
	SDLStopwatch::SDLStopwatch()
	{
		localticks = 0;
		time = 0;
	}

	// milliseconden terugkrijgen.
	int SDLStopwatch::GetMili()
	{
		return SDL_GetTicks();
	}

	//Per cycle wordt er oproep wordt er gekeken of er een second voorbij is.
	void SDLStopwatch::doEvent()
	{
		if(this->localticks < SDL_GetTicks())
		{
			this->time++;
			localticks = SDL_GetTicks() + 1000;
		}
	}
}
