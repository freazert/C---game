/*
 * Factory.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "Factory.h"
namespace Frogger
{
	Factory::~Factory()
	{

	}

	GameProperties* Factory::CreateGamePropertie(int totalBullets, int lifes, int score, int level, Stopwatch* stopwatch)
	{
		return new GameProperties(totalBullets, lifes, score, level, stopwatch);
	}
}
