/*
 * Vehicle.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_VEHICLE_H_
#define FROGGER_VEHICLE_H_

#include<vector>
#include <Enemy.h>
#include<SDLStopwatch.h>
#include "Vehicle.h"
#include "Stopwatch.h"
#include "GameProperties.h"
#include "entity.h"

#include <RidingObject.h>

using namespace std;

namespace Frogger {
class Factory;
class Vehicle: public RidingObject {
public:

	Vehicle(GameProperties* gameProperties, int lane, int grid_width,
			int grid_height, float spawnX);
protected:
	virtual void Draw() = 0;
	virtual ~Vehicle();
	void Shoot();

private:
};
}
#endif /* FROGGER_VEHICLE_H_ */
