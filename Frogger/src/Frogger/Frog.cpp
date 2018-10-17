/*
 * Frog.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */
#include "Frog.h"
const float speed = 0.13f;

namespace Frogger {
Frog::Frog(GameProperties* gameProperties, Keyboard* keyboard, int grid_width, int grid_height, Factory* factory) :
		Player(grid_width, grid_height) {

	this->factory = factory;
	this->gameProperties = gameProperties;
	this->keyboard = keyboard;

	levelUp = false;

	timeTillNextShot = 0;
	width = 1;
	height = 1;
	pauze = 0;

	//startPosite
	x = grid_width / 2;
	y = grid_height - height-1;

}

// controleren of er een level up is.
bool Frog::IsLevelUp() {
	if (levelUp) {
		levelUp = false;
		return true;
	}
	return false;
}

//afhankelijk van de ingedrukte toets wort de juist event uitgevoerd.
void Frog::DoEvent() {
	if (keyboard->keyStatus[Keyboard::UP]) {
		MoveUp();
	}
	if (keyboard->keyStatus[Keyboard::Down]) {
		MoveDown();
	}
	if (keyboard->keyStatus[Keyboard::Left]) {
		MoveLeft();
	}
	if (keyboard->keyStatus[Keyboard::Right]) {
		MoveRight();
	}
	// 500 ms wachten vooralleer er een andere kogel geschoten kan worden
	if (keyboard->keyStatus[Keyboard::Space]
			&& timeTillNextShot < gameProperties->stopwatch->GetMili()) {
		Shoot();
		timeTillNextShot = 500 + gameProperties->stopwatch->GetMili();
	}

}

// zolang er nog meer bullets zijn dan 0, kan er een kogel geschoten worden.
//kogel toevoegen aan entities
void Frog::Shoot() {
	if (gameProperties->totalBullets > 0) {
		gameProperties->entities->push_back(
				factory->CreateFriendlyProjectile(x, y));
		gameProperties->totalBullets--;
	}
}
//frog naar onder schuiven, mag niet buiten het scherm treden
void Frog::MoveDown() {

	if (y < grid_height - height-1)
		y += speed;
}

//frog naar link schuiven, mag niet buiten het scherm treden
void Frog::MoveLeft() {

	if (x > 0)
		x -= speed;
}
//frog naar rechts schuiven, mag niet buiten het scherm treden
void Frog::MoveRight() {
	if (x < grid_width - width) //frog width
		x += speed;
}
//extra controle bij naar boven gaan om te zien of er levelup is
void Frog::MoveUp() {
	if (y > 0)
		y -= speed;

	if (this->y < 2) {
		levelUp = true;
	}
}

//zet de kikker op de orginele plaats. + wacht een seconde voor de kikker terug reageert.
void Frog::ResetFrog() {
	this->x = 10;
	this->y = 17;
	this->SetPauze();
}

// de pauze klaar zetten.
void Frog::SetPauze() {
	pauze = gameProperties->stopwatch->GetMili() + 1000;
}

//kijken of er een pauze is, zolang de variabelen 'tijd' hoger is dan de tijd is er een pauze
bool Frog::IsFrogInBreak() {
	if (pauze < gameProperties->stopwatch->GetMili()) {
		return false;
	}
	return true;

}
}

