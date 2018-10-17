/*
 * Player.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_PLAYER_H_
#define FROGGER_PLAYER_H_
#include "Entity.h"
namespace Frogger {
class Player: public Entity {
public:
	Player(int grid_width, int grid_height);
protected:
	EntityType GetType();
	void DoCollision(Entity* coll);
};
}
#endif /* FROGGER_PLAYER_H_ */
