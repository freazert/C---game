/*
 * SDLStopwatch.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLSTOPWATCH_H_
#define SDL_SDLSTOPWATCH_H_

#include<Stopwatch.h>

#include<SDL2/SDL.H>

namespace SDL {
class SDLStopwatch: public Frogger::Stopwatch {
public:
	SDLStopwatch();

protected:
	int GetMili();
	void doEvent();

private:
	int localticks;
};
}
#endif /* SDL_SDLSTOPWATCH_H_ */
