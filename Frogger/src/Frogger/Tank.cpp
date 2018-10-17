/*
 * Tank.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <Tank.h>

namespace Frogger {

const float width = 1.2f;
const float height = 1;

Tank::Tank(GameProperties* gameProperties, int lane, int grid_width,
		int grid_height, Factory* fac, float spawnX) :
		RidingObject(gameProperties, grid_width, grid_height, lane, spawnX) {
	//score van enemy zetten
	points = 20;

	this->factory = fac;
	this->gameProperties = gameProperties;
}
// een tank schiet random een kogel, die kogel moet richting de frog gaan daarom worden de coordinaten van de frog meegegeven.
void Tank::Shoot() {
	if ((rand() % (900)) == 0) {
		gameProperties->entities->push_back(
				this->factory->CreateProjectile(gameProperties, x, y,
						gameProperties->entities->at(0)->GetX(),
						gameProperties->entities->at(0)->GetY()));
	}
}

Tank::~Tank() {
}
} /* namespace Frogger */
