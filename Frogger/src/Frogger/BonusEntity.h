/*
 * BonusEntity.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_BONUSENTITY_H_
#define FROGGER_BONUSENTITY_H_

#include "Entity.h"
#include "GameProperties.h"
#include <cstdlib>
namespace Frogger {

class BonusEntity: public Entity {
public:
	BonusEntity(GameProperties* gameProperties, int grid_width, int grid_height, float y , int lane);

	private:
		int lane;
		int waitTime;

	protected:
		GameProperties* gameProperties;

		EntityType GetType();
		virtual void DoCollision(Entity* coll) = 0;
		void DoEvent();


};

} /* namespace Frogger */

#endif /* FROGGER_BONUSENTITY_H_ */
