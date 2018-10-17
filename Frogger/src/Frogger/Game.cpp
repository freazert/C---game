/*
 * Game.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "Game.h"

#include <iostream>

namespace Frogger {

//Abstracte variable --singleton.
Game* Game::GameInstance = 0;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 620;
const int widthGrid = 20;
const int heightGrid = 20;
const int SCREEN_FPS = 80;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

using namespace std;

//private constructor
Game::Game(Factory* factory) {

	fac = factory;
	maxTanks = 0;
	milliFPS = 0;

	pauseRender = false;

	stopwatch = NULL;
	entities = NULL;
	gameProperties =NULL;
	core = NULL;
	frog = NULL;
	settings = NULL;
	keyboard = NULL;
	sound = NULL;
}

// zorgen voor maar één instance
Game* Game::GetGameInstance(Factory* factory) {
	if (!GameInstance) {
		GameInstance = new Game(factory);
	}
	return GameInstance;
}

void Game::Start() {

	//alle variable initialiseren voor het starten van het spel
	InitializeVariables();

	//Muziek starten
	sound->StartMusic();

	// genereer de auto objecten
	SpawnCars();

	//zolang er geen escape gedrukt wordt, moet de gae loop werken
	while (!keyboard->keyStatus[Keyboard::Exit]) {

		//keyboard leest de toetsslagen.
		keyboard->KeyToggle(stopwatch);

		//zolang er niet gepauzeerd wordt 'p', wordt er geloopt.
		if (!keyboard->keyPressed[Keyboard::Pause]) {

			//als de muziek niet aanstaat, dan de muziek opzetten.
			sound->ResumeMusic();

			//timer van seconden een illiseconden bijdoen.
			stopwatch->doEvent();

			//bekijken of er een game over is.
			if (gameProperties->lives < 1) {
				this->GameOver();
			}

			// als frog op de juiste positie is, is er een levelup
			if (frog->IsLevelUp()) {
				this->LevelUp();
			}

			//Wanneer de score hoger is dan de higscore data
			//schrijven van de higscore naar de file + higscore variabelen veranderen
			if (gameProperties->score > data[0]) {
				gameProperties->highscore = gameProperties->score;
				data[0] = gameProperties->score;
				settings->WriteToFile(data);
			}

			// voor alle enities in de vecotr worden dezelfde zaken gedaan.
			for (unsigned int i = 0; i < entities->size(); i++) {
				//loop voor collision. Enkel kijken op collision van unfriendly en bonus met een friendly type
				for (unsigned int j = 0; j < entities->size(); j++) {
					if ((entities->at(i)->GetType() == UnfriendlyType
							|| entities->at(i)->GetType() == BonusType)
							&& (entities->at(j)->GetType() == FriendlyType)) {
						//als er een collisie plaatsvindt, wordt de collisie event van die entity uitgevoerd
						if (entities->at(i)->Collision(entities->at(j))) {
							//entity
							if (entities->at(i) != entities->at(j))
								entities->at(i)->DoCollision(entities->at(j));
						}
					}
				}
				// als we een frog hebben & die niet in een pauze is, wordt de event gedaan en ook bij andere entities.
				if (!frog->IsFrogInBreak() || i != 0) {
					entities->at(i)->DoEvent();
				}
				// als de delete true is, wordt deze unit verwijderd, zodat er gene memory leaks zijn.
				if (entities->at(i)->IsDeleteUnit()) {
					Entity* entity = entities->at(i);
					entities->erase(
							std::find(entities->begin(), entities->end(),
									entities->at(i)));
					delete entity;
				}
			}
		}else
		{
			//pauzeren van de muziek
			sound->PauseMusic();
		}

		// alles tekenen op het scherm
		core->ReRender(entities, gameProperties);

		//FPS bereken
		//kijken per frame hoelang het duurt, kijken hoeveel frames er per second mag gerenderd worden.
		//Als de frame te snel is effe wachten.
		const int FRAMES_PER_SECOND = 80;
		milliFPS -= stopwatch->GetMili();
		if (milliFPS < (1000 / FRAMES_PER_SECOND)) {
			//Sleep the remaining frame time
			core->Delay((1000 / FRAMES_PER_SECOND) - milliFPS);
		}
		milliFPS = stopwatch->GetMili();
	}

	//opruimen van alle elementen!
	DeleteList();

	delete frog;
	frog = 0;

	delete gameProperties;
	gameProperties = 0;

	delete settings;
	settings = 0;

	delete keyboard;
	keyboard = 0;

	delete stopwatch;
	stopwatch = 0;

	delete core;
	core = 0;
}
//Bij het detecteren van een level up, worden alle elementen uit de enitity vector gehaald buiten frog
//De maximale tanks op het veld wordt verhoogd met één
void Game::LevelUp() {
	DeleteList();
	maxTanks++;

	//per level worden er 2 auto's toegevoed. Eerst wordt er gecontroleerd of de verschillen aantal op de lanes niet te veel varieert.
	//Zoja wordt de laagste lane opgevuld.

	//anders wordt er een auto in een random lane gestoken.
	int max =  maxVehiclesInGame[0];
	int low = maxVehiclesInGame[0];
	int lowPos= 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			if (maxVehiclesInGame[j] > max) {
				max = maxVehiclesInGame[j];
			}
			if (maxVehiclesInGame[j] < low) {
				low = maxVehiclesInGame[j];
				lowPos = j;
			}
		}
		//4-> vverschil van aantal auto's op een lane.
		if ((max - low) > 4) {
			maxVehiclesInGame[lowPos]++;
		} else {
			maxVehiclesInGame[rand() % 8]++;
			time[i] = 0;
		}
	}
	//verhogen van enkel properties
	gameProperties->level++;
	gameProperties->score++;
	gameProperties->totalBullets += gameProperties->level;

	//Auto's opnieuw in de vector laden
	SpawnCars();

	// frog terug naar het begin zetten + kleine pauze
	frog->ResetFrog();
}

// alle objecten/ data op begin variabelen initialiseren.
void Game::InitializeVariables() {
	//stopwatch object voor de timing
	stopwatch = fac->CreateStopwatch();

	//alle properties
	gameProperties = fac->CreateGamePropertie(2, 3, 0, 1, stopwatch);

	//linken
	entities = gameProperties->entities;

	//highscore object -> data wegschrijven
	settings = fac->CreateSettings();

	//object voor window manipuklatie
	core = fac->CreateScreen(SCREEN_WIDTH, SCREEN_HEIGHT, widthGrid,
			heightGrid);

	//keyslagen mappen naar een eigen object
	keyboard = fac->CreateKeyboard();
	sound = fac->CreateSound();

	//De frog
	frog = fac->CreateFrog(gameProperties, keyboard);
	entities->push_back(frog);

	//highscore uit het bestand verkrijgen
	settings->ReadHigscore(data);
	gameProperties->highscore = data[0];


	maxTanks = 0;

	gameProperties->lives = 3;
	gameProperties->level = 1;
	gameProperties->score = 0;

	for (int i = 0; i < 8; i++) {
		maxVehiclesInGame[i] = 1;
		time[i] = 0;
	}
}

// het verwijderen van alle objecten buiten de kikker.
void Game::DeleteList() {
	//eerste element is altijd kikker.
	for (std::vector<Entity*>::iterator iter = entities->begin() + 1;
			iter != entities->end(); iter++) {
		Entity *temp = *iter;
		delete temp;
		temp = 0;
	}
	//het legen van de lijst.
	entities->erase(entities->begin() + 1, entities->end());
}

// auto's, tanks & bonussen aanmaken
void Game::SpawnCars() {

	//lokale variabelen voor te rekenen.
	int tanksInGame = maxTanks;
	int countVehicles = 0;

	//aantal wagens bereken die in het spel gebruikt mogen gebruikt worden
	for (int i = 0; i < 8; i++) {
		countVehicles += maxVehiclesInGame[i];
	}

	//bijhouden welke auto plaats een tank moet zijn
	bool placeOfTanks[countVehicles];

	// initialiseren dat er nergens een tank staat.
	for (int i = 0; i < countVehicles; i++) {
		placeOfTanks[i] = false;
	}

	//De posities va de tanken berekenen tot dat alle tanken geplaatst zijn
	while (tanksInGame != 0) {
		for (int i = 0; i < countVehicles; i++) {
			if (rand() % 10 == 0 && tanksInGame != 0) {
				placeOfTanks[i] = true;
				tanksInGame--;
			}
		}
	}

	// het plaatsen van de tanken en de auto over de verschillende rijvakken
	int b = 0;
	// per rij wordt er berekend waar de auto/tank ergens gestart moet worden.
	// algoritme zorgt ervoor dat de auto's dynamisch gespreid worden over het rijvak, afhankelijk van de aantal auto's op het rijvak, zodat ze niet allemaal op elkaar spawnen
	for (int i = 0; i < 8; i++) {
		float part = (float) (widthGrid - 2) / (maxVehiclesInGame[i]);
		for (int j = 0; j < maxVehiclesInGame[i]; j++) {
			float spawnX = (((part) * ((float) ((20 + rand() % 60)) / 100))
					+ (part * (j))) + 1;
			if (placeOfTanks[b]) {
				entities->push_back(fac->CreateTank(gameProperties, i, spawnX));
				tanksInGame--;
			} else {
				entities->push_back(
						fac->CreateVehicle(gameProperties, i, spawnX));
			}
			b++;
		}
	}

	//beide bonussen aanmaken  en op random plaats zetten.
	entities->push_back(fac->CreateScoreBonus(gameProperties, rand() % 8));
	entities->push_back(fac->CreateBulletBonus(gameProperties, rand() % 2));
}

// wanneer er een game over plaatsvind, worden de variabelen gereset
void Game::GameOver() {

	maxTanks = 0;
	gameProperties->lives = 3;
	gameProperties->score = 0;
	gameProperties->level = 1;
	gameProperties->totalBullets = 2;

	// Game over sound laten spelen
	sound->StartGameOverSound();
	//frog terug naar begin met een kleine pauze
	frog->ResetFrog();
	//alle element terug verwijderen
	DeleteList();

	//reset van de aantal vehicles
	for (int i = 0; i < 8; i++) {
		maxVehiclesInGame[i] = 1;
		time[i] = 0;
	}
	//opnieuw de auto's spawnen.
	SpawnCars();
}

}
