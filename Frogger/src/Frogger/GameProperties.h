/*
 * GameProperties.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_GAMEPROPERTIES_H_
#define FROGGER_GAMEPROPERTIES_H_

#include<Entity.h>
#include<stopwatch.h>

using namespace std;
namespace Frogger {
class GameProperties {
public:

	GameProperties(int totalBullets, int lifes, int score, int level, Stopwatch* stopwatch);

	int lives;
	int level;
	int score;
	int frogBreak;
	int totalBullets;
	int highscore;

	vector<Entity*>* entities;
	Frogger::Stopwatch* stopwatch;
};
}
#endif /* FROGGER_GAMEPROPERTIES_H_ */
