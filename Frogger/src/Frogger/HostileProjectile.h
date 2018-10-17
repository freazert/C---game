/*
 * Projectile.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_PROJECTILE_H_
#define FROGGER_PROJECTILE_H_

#include "math.h"
#include "GameProperties.h"
#include "enemy.h"
namespace Frogger
{
	class HostileProjectile : public Enemy{
		public:
			HostileProjectile(GameProperties* gameProperties,int grid_width, int grid_height , int x, int y , int frogX, int frogY);

		protected:
			void DoEvent();
			virtual void Draw() =0;

		private:
			float velocity_x;
			float velocity_y;
	};
}

#endif /* FROGGER_PROJECTILE_H_ */
