/*
 * Enemy.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */
#include "Frog.h"
#include "Enemy.h"
namespace Frogger {

Enemy::Enemy(GameProperties* gameProperties, int grid_width, int grid_height) :
		Entity(grid_width, grid_height) {

	this->gameProperties = gameProperties;
	points = 10;
}

EntityType Enemy::GetType() {
	return UnfriendlyType;
}

void Enemy::DoCollision(Entity* coll) {
	//check of het een collision is met frog
	if (gameProperties->entities->at(0) == coll) {
		gameProperties->lives--;

		//cast to frog
		Frog* frog = dynamic_cast<Frog*>(gameProperties->entities->at(0));
		frog->ResetFrog();

		//alle kogels verwijderen uit het spel.
		for (unsigned int i = 0; i < gameProperties->entities->size(); i++) {
			if (gameProperties->entities->at(i)->isBullet()) {
				gameProperties->entities->at(i)->SetDelete();
			}
		}
	}

	//uitvoeren bij het raken van een friendly bullet
	else
	{
		//verwijderen van de bullet en de auto
		//afhankelijk van wat de points in de subklasse, worden de punten verhoogd.
		gameProperties->score += points;
		this->SetDelete();
		coll->SetDelete();
	}

}
}
