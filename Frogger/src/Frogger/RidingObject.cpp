/*
 * MovingObject.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <RidingObject.h>

const float widthC = 1.2f;
const float heightC = 1;

namespace Frogger {
RidingObject::RidingObject(GameProperties* gameproperties, int grid_height,
		int grid_width, int lane, float spawnX) :
		Enemy(gameproperties, grid_height, grid_width) {

	this->gameProperties = gameProperties;
	this->lane = lane;

	//set de start x coordinate van de entity
	this->x = spawnX;

	//zet de hoogte en de breedte van de entity
	width = widthC;
	height = heightC;

	//afhankelijk van welke lane de auto zit wordt de directie van de entity bepaald.
	if (lane % 2) {
		direction = 0;
	} else {
		direction = 1;
	}

	// op basis van de lane worden de coordinaten gezet op welke y hij moet rijden.
	switch (lane) {
	case 0:
		y = grid_height - 5.2f;
		break;
	case 1:
		y = grid_height - 6.5f;
		break;
	case 2:
		y = grid_height - 7.8f;
		break;
	case 3:
		y = grid_height - 9.1f;
		break;
	case 4:
		y = grid_height - 11.8f;
		break;
	case 5:
		y = grid_height - 13.1f;
		break;
	case 6:
		y = grid_height - 14.4f;
		break;
	case 7:
		y = grid_height - 15.7f;
		break;
	}
}

RidingObject::~RidingObject() {

}

// afhankelijk van de directie wordt de entity naar links/rechts gezet, of welke snelheid gebruikt moet worden
// wanneer de auto rechts uitgaat, komt hij links terug in en omgekeerd.
void RidingObject::DoEvent() {
	if (direction) {
		if (x < grid_width) {
			x += 0.06f;
		} else {
			x = 0;
		}
	} else {
		if (x > -1) {
			x -= 0.08f;
		} else {
			x = grid_width;
		}
	}
	//Afhankelijk van de subklasse wordt de shoot functie uitgevoerd
	Shoot();
}
}/* namespace Frogger */
