/*
 * BulletBonus.cpp
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#include <BulletBonus.h>

namespace Frogger {
BulletBonus::BulletBonus(GameProperties* gameProperties, int grid_width, int grid_height, float y, int lane) :
		BonusEntity(gameProperties, grid_width, grid_height, y , lane) {
	//ctor
	this->gameProperties = gameProperties;

}

BulletBonus::~BulletBonus() {
	//dtor
}

// verhoogt de bullets met 2 en de bonus mag dan verwijderd worden.
void BulletBonus::DoCollision(Entity* coll) {
		gameProperties->totalBullets += 2;
		this->SetDelete();
	}
}/* namespace Frogger */
