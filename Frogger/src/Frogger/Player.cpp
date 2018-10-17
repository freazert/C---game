/*
 * Player.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "Player.h"
namespace Frogger
{
	Player::Player(int grid_width, int grid_height):Entity(grid_width, grid_height)
	{
	}

	EntityType Player::GetType()
	{
		return FriendlyType;
	}

	//momenteel geen collision check nodig.
	void Player::DoCollision(Entity* coll)
	{

	}
}
