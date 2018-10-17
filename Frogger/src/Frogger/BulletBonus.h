/*
 * BulletBonus.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_BULLETBONUS_H_
#define FROGGER_BULLETBONUS_H_
#include "BonusEntity.h"
#include "GameProperties.h"
#include "BonusScore.h"

namespace Frogger {

class BulletBonus: public BonusEntity {
public:
	BulletBonus(GameProperties* gameProperties, int grid_width, int grid_height, float y, int lane);
	virtual ~BulletBonus();

protected:
	virtual void Draw() =0;
	void DoCollision(Entity* coll);

};

} /* namespace Frogger */

#endif /* FROGGER_BULLETBONUS_H_ */
