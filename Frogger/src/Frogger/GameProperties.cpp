/*
 * GameProperties.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "GameProperties.h"

using namespace std;

namespace Frogger
{
	GameProperties::GameProperties(int totalBullets, int lives, int score, int level, Stopwatch* stopwatch)
	{
		this->entities = new vector<Entity*>;
		this->lives = lives;
		this->score = score;
		this->level = level;
		this->frogBreak = 0;
		this->totalBullets = totalBullets;
		this->highscore = 0;
		this->stopwatch = stopwatch;
	}
}
