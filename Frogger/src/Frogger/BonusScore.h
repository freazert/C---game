/*
 * Bonus.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_SCOREBONUS_H_
#define FROGGER_SCOREBONUS_H_

#include<Player.h>
#include<Gameproperties.h>
#include<Stopwatch.h>
#include"BonusEntity.h"
#include<SDLStopwatch.h>

namespace Frogger {
class BonusScore: public Frogger::BonusEntity {
public:
	BonusScore(GameProperties* gameProperties, int grid_width, int grid_height,
			float y, int lane);

protected:
	virtual ~BonusScore();
	virtual void Draw() =0;
	void DoCollision(Entity* coll);

private:
	GameProperties* gameProperties;

};
}
#endif /* FROGGER_SCOREBONUS_H_ */
