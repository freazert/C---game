/*
 * Frog.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_FROG_H_
#define FROGGER_FROG_H_

#include<Player.h>
#include<Keyboard.h>
#include <Factory.h>
#include "Gameproperties.h"
namespace Frogger {
class Factory;
class Frog: public Frogger::Player {
public:

	Frog(GameProperties* gameProperties, Keyboard*, int, int, Factory* factory);

	bool IsLevelUp();
	void ResetFrog();
	void SetPauze();
	bool IsFrogInBreak();


protected:

	virtual void Draw() = 0;
	void DoEvent();

private:
	Factory* factory;
	Keyboard* keyboard;
	GameProperties* gameProperties;

	int timeTillNextShot;
	bool levelUp;
	int pauze;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Shoot();



};
}
#endif /* FROGGER_FROG_H_ */
