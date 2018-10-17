/*
 * Factory.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_FACTORY_H_
#define FROGGER_FACTORY_H_

#include "BulletBonus.h"
#include <BonusScore.h>
#include"Core.h"
#include"Frog.h"
#include"Vehicle.h"
#include"Entity.h"
#include"Stopwatch.h"
#include"HostileProjectile.h"
#include"FriendlyProjectile.h"
#include"Settings.h"
#include"Keyboard.h"
#include"SOund.h"
#include"Tank.h"

// forward declareren, door dependecy
class Tank;

namespace Frogger {

class Frog;

class Factory {

public:

	virtual Core* CreateScreen(int, int, int, int) = 0;
	virtual Frogger::Frog* CreateFrog(GameProperties* gameProperties,Frogger::Keyboard*) = 0;
	virtual Vehicle* CreateVehicle(GameProperties*, int, float)= 0;
	virtual Tank* CreateTank(GameProperties*, int, float)= 0;
	virtual Stopwatch* CreateStopwatch() = 0;
	virtual HostileProjectile* CreateProjectile(GameProperties*, int, int, int,int) = 0;
	virtual FriendlyProjectile* CreateFriendlyProjectile(int, int) = 0;
	virtual BonusScore* CreateScoreBonus(GameProperties*, int) =0;
	virtual BulletBonus* CreateBulletBonus(GameProperties*, int) =0;
	virtual Settings* CreateSettings()=0;
	virtual Keyboard* CreateKeyboard() = 0;
	virtual Sound* 	  CreateSound() = 0;

	GameProperties* CreateGamePropertie(int totalBullets, int lifes, int score, int level, Stopwatch* stopwatch);

	virtual ~Factory();

protected:
	Core* core;
};
}
#endif /* FROGGER_FACTORY_H_ */
