/*
 * MovingObject.h
 *
 *  Created on: 18-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_MOVINGOBJECT_H_
#define FROGGER_MOVINGOBJECT_H_

#include "Enemy.h"
#include "gameproperties.h"
namespace Frogger {

class RidingObject : public Enemy {
public:
	RidingObject(GameProperties* gameproperties, int grid_height, int grid_width,int lane, float spawnX);
	virtual ~RidingObject();

protected:
	int direction;
	int lane;
	GameProperties* gameProperties;

	virtual void Shoot() =0;
	void DoEvent();


};

} /* namespace Frogger */

#endif /* FROGGER_MOVINGOBJECT_H_ */
