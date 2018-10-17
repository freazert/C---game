/*
 * FriendlyProjectile.h
 *
 *  Created on: 17-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_FRIENDLYPROJECTILE_H_
#define FROGGER_FRIENDLYPROJECTILE_H_

#include "player.h"

namespace Frogger {

class FriendlyProjectile: public Player {
public:
			FriendlyProjectile(int grid_width, int grid_height, int x,int y);
protected:
			virtual void Draw() =0;
			void DoEvent();


};
}; /* namespace Frogger */

#endif /* FROGGER_FRIENDLYPROJECTILE_H_ */
