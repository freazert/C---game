/*
 * Keyboard.cpp
 *
 *  Created on: 19-mei-2016
 *      Author: Kris
 */

#include <Keyboard.h>

namespace Frogger {

Keyboard::Keyboard()
{
	//Houdt bij of de key op dat moment ingedrukt is.
	keyStatus[8] = {false};
	//Houdt bij of de key getoggled is.
	keyPressed[8] = {false};
	//tussenvariabel
	keyChanged[8] = {false};


}
Keyboard::~Keyboard()
{

}

}
/* namespace Frogger */
