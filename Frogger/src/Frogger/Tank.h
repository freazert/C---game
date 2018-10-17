/*
 * Tank.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_TANK_H_
#define FROGGER_TANK_H_

#include<vector>
#include <Enemy.h>

#include<SDLStopwatch.h>
#include "Stopwatch.h"
#include "GameProperties.h"

#include "Factory.h"
#include "entity.h"
#include "RidingObject.h"
namespace Frogger {

class Factory;
class Tank: public Frogger::RidingObject {

public:
		Tank(GameProperties* gameProperties, int lane, int grid_width, int grid_height, Factory* fac, float spawnX);
		virtual ~Tank();

protected:
		virtual void Draw() = 0;
		void Shoot();

private:
		Factory* factory = NULL;
		GameProperties* gameProperties  = NULL;
	};
} /* namespace Frogger */

#endif /* FROGGER_TANK_H_ */
