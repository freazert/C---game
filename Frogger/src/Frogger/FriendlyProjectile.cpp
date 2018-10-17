/*
 * FriendlyProjectile.cpp
 *
 *  Created on: 17-jun.-2016
 *      Author: Kris
 */

#include <FriendlyProjectile.h>
#include <Math.h>
namespace Frogger {

FriendlyProjectile::FriendlyProjectile(int grid_width, int grid_height, int x,int y) :
		Player(grid_width, grid_height) {

	bullet = true;

	//hoogte en breedte zetten
	width = 0.5f;
	height = 0.5f;

	//coordinaten zetten
	this->x = x;
	this->y = y;
}

// vliegt naar boven + controle of het niet buiten het scherm vliegt. Anders moet
//de entety verwijderd worden.
void FriendlyProjectile::DoEvent() {
	if (x < 0 || x > grid_width || y < 0 || y > grid_height) {
		this->SetDelete();
	} else {
		y -= 0.19;
	}
}
}/* namespace Frogger */
