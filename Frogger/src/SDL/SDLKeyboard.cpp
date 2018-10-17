/*
 * SDLKeyboard.cpp
 *
 *  Created on: 19-mei-2016
 *      Author: Kris
 */

#include <SDLKeyboard.h>

namespace SDL {
void SDLKeyboard::KeyToggle(Frogger::Stopwatch* stopwatch) {
	if (timeUntilNextPress < stopwatch->GetMili()) {
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		//Event handler
		SDL_Event e;
		SDL_PollEvent(&e);

		// sdlKeystatus mappen naar Keystatus array.
		this->keyStatus[Keyboard::UP] = currentKeyStates[SDL_SCANCODE_UP];
		this->keyStatus[Keyboard::Down] = currentKeyStates[SDL_SCANCODE_DOWN];
		this->keyStatus[Keyboard::Left] = currentKeyStates[SDL_SCANCODE_LEFT];
		this->keyStatus[Keyboard::Right] = currentKeyStates[SDL_SCANCODE_RIGHT];
		this->keyStatus[Keyboard::Exit] = currentKeyStates[SDL_SCANCODE_ESCAPE];
		this->keyStatus[Keyboard::Pause] = currentKeyStates[SDL_SCANCODE_P];
		this->keyStatus[Keyboard::Space] = currentKeyStates[SDL_SCANCODE_SPACE];

		//een tijd tussen de knoppen steken.
		timeUntilNextPress = stopwatch->GetMili() + 20;

		//for loop evry key
		if (this->keyStatus[Keyboard::Pause] && !keyChanged[Keyboard::Pause]) {
			keyPressed[Keyboard::Pause] = !keyPressed[Keyboard::Pause];
			keyChanged[Keyboard::Pause] = true;
		}
		if (!this->keyStatus[Keyboard::Pause] && keyChanged[Keyboard::Pause]) {
			keyChanged[Keyboard::Pause] = false;
		}
	}
}
} /* namespace SDL */
