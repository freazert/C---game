/*
 * SDLFact.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLFact.h"
#include "stdio.h"

namespace SDL {

SDLFact::SDLFact() {
	//vehicle_textures[3] = NULL;
}

//aanmaken van een frog object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
Frogger::Frog* SDLFact::CreateFrog(GameProperties* gameProperties, Keyboard* keyboard) {
	if (frog_texture == NULL) {
		frog_texture = this->sDLCore->CreateTexture((char *) "Pictures/kikker.bmp");
	}
	return new SDLFrog(gameProperties, keyboard, this->sDLCore,
			frog_texture, this);
}

//aanmaken van een FriendlyProjectile object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
FriendlyProjectile* SDLFact::CreateFriendlyProjectile(int x, int y) {
	if (friendly_projectile_texture == NULL) {
		friendly_projectile_texture = this->sDLCore->CreateTexture((char *) "Pictures/kikker.bmp");
	}
	return new SDLFriendlyProjectile(this->sDLCore, x, y,friendly_projectile_texture);

}

//aanmaken van een Settings object
Settings* SDLFact::CreateSettings() {
	return new SDLSettings();
}

//aanmaken van een Vehicle object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
Frogger::Vehicle* SDLFact::CreateVehicle(Frogger::GameProperties* gameProperties, int lane,float spawnX) {

	// één van de verschillende texture random pakken
	int random = rand()%3;
	if(vehicle_textures[random] == NULL)
	{
		switch(random)
		{
		case 0:
			vehicle_textures[random] = this->sDLCore->CreateTexture((char *) "Pictures/auto.bmp");
			break;

		case 1:
			vehicle_textures[random] = this->sDLCore->CreateTexture((char *) "Pictures/yellow.bmp");
			break;

		default:
			vehicle_textures[random] = this->sDLCore->CreateTexture((char *) "Pictures/cyan.bmp");
			break;
		}
	}
		return new SDLVehicle(gameProperties, lane, this->sDLCore ,vehicle_textures[random], spawnX, this);
}

//aanmaken van een Tank object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
Frogger::Tank* SDLFact::CreateTank(GameProperties* gameProperties,int lane, float spawnX)
{
	if (tank_texture == NULL) {
		tank_texture =this->sDLCore->CreateTexture(
					(char *) "Pictures/tank.bmp");
			}

	return new SDLTank(gameProperties, lane, this->sDLCore,tank_texture, spawnX,this);
}

//aanmaken van een Keyboard object
Keyboard* SDLFact::CreateKeyboard() {
	return new SDLKeyboard();
}

//aanmaken van de basis core + scherm opstarten.
//init kan vervangen worden door constructor.
Core* SDLFact::CreateScreen(int x, int y, int grid_y, int grid_x) {
	if(this->sDLCore == NULL)
	{
		this->sDLCore = new SDLCore;
		this->sDLCore->Init(x, y, grid_y, grid_x);
	}
	return sDLCore;
}


Sound* SDLFact::CreateSound()
{
	return new SDLSound();
}

//aanmaken van een Stopwatch object
Stopwatch* SDLFact::CreateStopwatch() {
	return new SDLStopwatch();
}

//aanmaken van een HostileProjectile object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
Frogger::HostileProjectile* SDLFact::CreateProjectile(GameProperties* gameProperties,
		int x, int y, int frogX, int frogY) {
	if (projectiel_texture == NULL) {
		projectiel_texture = this->sDLCore->CreateTexture(
				(char *) "Pictures/Projectiel.bmp");
	}
	return new SDLHostileProjectile(gameProperties, this->sDLCore, x, y, frogX, frogY,
			projectiel_texture);
}

//aanmaken van een ScoreBonus object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
Frogger::BonusScore* SDLFact::CreateScoreBonus(GameProperties* gameProperties, int lane) {
	if (Bonus_texture == NULL) {
		Bonus_texture = this->sDLCore->CreateTexture(
				(char *) "Pictures/bonus_score.bmp");
	}
	return new SDLBonus(gameProperties, sDLCore, Bonus_texture, 0, lane);
}

//aanmaken van een BulletBonus object + het gebruik van lazy loading -> elke texture maar één keer aanmaken als het nodig is.
BulletBonus* SDLFact::CreateBulletBonus(GameProperties* gameProperties, int lane)
{
	if (bullet_bonus_texture == NULL) {
		bullet_bonus_texture = this->sDLCore->CreateTexture(
					(char *) "Pictures/bullets.bmp");
		}
		return new SDLBulletBonus(gameProperties, sDLCore, bullet_bonus_texture, 0, lane);
}

//Het opruimen van alle lazy loading objecten.
SDLFact::~SDLFact() {


	SDL_DestroyTexture(projectiel_texture);
	SDL_DestroyTexture(frog_texture);
	SDL_DestroyTexture(tank_texture);
	SDL_DestroyTexture(bullet_bonus_texture);
	SDL_DestroyTexture(Bonus_texture);
	SDL_DestroyTexture(friendly_projectile_texture);

	SDL_DestroyTexture(vehicle_textures[0]);
	SDL_DestroyTexture(vehicle_textures[1]);
	SDL_DestroyTexture(vehicle_textures[2]);

}
}
