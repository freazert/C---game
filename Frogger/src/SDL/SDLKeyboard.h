/*
 * SDLKeyboard.h
 *
 *  Created on: 19-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLKEYBOARD_H_
#define SDL_SDLKEYBOARD_H_
#include <SDL2/SDL.h>
#include <Stopwatch.h>
#include <keyboard.h>
namespace SDL {

class SDLKeyboard : public Frogger::Keyboard {

public:
	void KeyToggle(Frogger::Stopwatch* stopwatch);

private:
	int timeUntilNextPress;
};

} /* namespace SDL */

#endif /* SDL_SDLKEYBOARD_H_ */
