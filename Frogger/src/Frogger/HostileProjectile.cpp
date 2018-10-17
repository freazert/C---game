/*
 * Projectile.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "HostileProjectile.h"

const float speed = 0.058f;
const float widthC = 0.5f;
const float heightC = 0.5f;

namespace Frogger
{
	HostileProjectile::HostileProjectile(GameProperties* gameProperties,int grid_width, int grid_height , int x, int y , int frogX, int frogY):Enemy(gameProperties,grid_width, grid_height)
	{
		bullet = true;
		points = 5;

		//Zet de positie van de entity
		this->x = x;
		this->y = y;

		//breedte en hoogte van de entity
		this->height = heightC;
		this->width= widthC;

		//bereken de richting de kogel moet gaan voor de kikker te bereiken.
		float diff_x = frogX - x;
		float diff_y = frogY - y;
		float magnitude = sqrt(diff_x*diff_x + diff_y*diff_y);
		velocity_x = diff_x/magnitude * speed;
		velocity_y = diff_y/magnitude * speed;
	}

	void HostileProjectile::DoEvent()
	{
		//wanneer de kogel buiten het scherm is klaarzetten om te verwijderen.
		if(x < 0|| x > grid_width || y < 0 || y > grid_height)
		{
			this->SetDelete();
		}
		else
		{
			// richting de kikker voorruit gaan.
			x+=velocity_x;
			y+=velocity_y;
		}

	}
}
