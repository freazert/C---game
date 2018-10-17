/*
 * Enemy.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_ENEMY_H_
#define FROGGER_ENEMY_H_

#include<Entity.h>
#include<GameProperties.h>

namespace Frogger
{
	class Enemy: public Frogger::Entity {

	public:
		Enemy(GameProperties*, int, int);

	protected:
		EntityType GetType();
		void DoCollision(Entity* coll);

	private:
		GameProperties* gameProperties;

	protected:
		int points;

	};
}
#endif /* FROGGER_ENEMY_H_ */
