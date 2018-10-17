/*
 * Vehicle.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "Vehicle.h"

namespace Frogger
{
	const float width = 1.2f;
	const float height = 1;

	Vehicle::Vehicle(GameProperties* gameProperties, int lane, int grid_width, int grid_height, float spawnX) :
		RidingObject(gameProperties, grid_width, grid_height,lane, spawnX) {
		//Score van enemy zetten
		points = 10;
	}

	Vehicle::~Vehicle() {
	}

	//geen body omdat deze niet moet kunnen schieten.
	void Vehicle::Shoot()
	{

	}
}
