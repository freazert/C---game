/*
 * Keyboard.h
 *
 *  Created on: 19-mei-2016
 *      Author: Kris
 */

#ifndef SDL_KEYBOARD_H_
#define SDL_KEYBOARD_H_

#include <Stopwatch.h>

namespace Frogger {
class Keyboard {
public:

	//functie die in de game opgeroept wordt om te zien welke key ingetikt is.
	virtual void KeyToggle(Frogger::Stopwatch* stopwatch) = 0;
	virtual ~Keyboard();
	Keyboard();

	//verschillende keys die gemapt worden.
	enum Key {
		UP, Down, Left, Right, Exit, Pause, Space, Null
	};

	//Houdt bij of de key op dat moment ingedrukt is.
	bool keyStatus[8];
	//Houdt bij of de key van het één in het andere is veranderd.
	bool keyPressed[8];

protected:
	bool keyChanged[8];

};

} /* namespace Frogger */

#endif /* SDL_KEYBOARD_H_ */
