/*
 * BonusEntity.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <BonusEntity.h>

const float widthC = 1;
const float heightC = 1;

namespace Frogger {

BonusEntity::BonusEntity(GameProperties* gameProperties, int grid_width, int grid_height, float y , int lane):Entity(grid_width, grid_height)
{
	this->gameProperties = gameProperties;
	this->lane = lane;
	this->y = y;

	waitTime = 0;

	//hoogte en breedte instellen
	width = widthC;
	height = heightC;
}

//om de 2 seconden wordt de bonus ergens random geplaatst
void BonusEntity::DoEvent() {
	if (waitTime < gameProperties->stopwatch->GetMili()) {
		x = (((float) (rand() % 1600)) / 100)+2;
		y = (((float) (rand() % 1200)) / 100)+4;
		waitTime = gameProperties->stopwatch->GetMili() + 2000;
	}
}

EntityType BonusEntity::GetType()
{
	return BonusType;
}

} /* namespace Frogger */
