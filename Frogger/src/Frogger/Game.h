/*
 * Game.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_GAME_H_
#define FROGGER_GAME_H_

#include<vector>
#include<Entity.h>
#include<Core.h>
#include<Stopwatch.h>
#include<GameProperties.h>
#include<Settings.h>

#include <Factory.h>
#include <stdio.h>
#include <algorithm>
#include <Frog.h>
//moet nog eens bezien woden

class Factory;
using namespace std;
namespace Frogger {
class Game {
public:
	static Game* GetGameInstance(Factory*);
	void Start();
	void GameOver();
	void LevelUp();
	void GetExtraPointsBonus(Entity*);

private:
	Game(Factory*);
	static Game* GameInstance;

	int data[5];
	int maxVehiclesInGame[8];
	int time[8];

	int maxTanks;
	float milliFPS;

	bool pauseRender;

	vector<Entity*>* entities;
	Factory *fac;
	Core* core;
	Frogger::Stopwatch* stopwatch;
	Frog* frog;
	Sound* sound;
	GameProperties* gameProperties;
	Settings* settings;
	Keyboard* keyboard;

	void DeleteList();
	void SpawnCars();
	void HoldTime();
	bool IsFrogInBreak();
	void SetBreakFrog();
	void InitializeVariables();

};
}
#endif /* FROGGER_GAME_H_ */
