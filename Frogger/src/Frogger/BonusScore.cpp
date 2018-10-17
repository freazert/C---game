/*
 * Bonus.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include <BonusScore.h>

namespace Frogger {

BonusScore::BonusScore(GameProperties* gameProperties, int grid_width, int grid_height,float y, int lane) :BonusEntity(gameProperties, grid_width, grid_height, y , lane) {
	//ctor
	this->gameProperties = gameProperties;
}

BonusScore::~BonusScore() {
	//dtor
}

//Deze bonus verhoogt de score met 10.
void BonusScore::DoCollision(Entity* coll) {
		gameProperties->score += 10;
		this->SetDelete();
	}
}

