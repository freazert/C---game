/*
 * SDLFact.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLFACT_H_
#define SDL_SDLFACT_H_

#include<SDL2/SDL.h>
#include<Core.h>
#include<Frog.h>
#include<Vehicle.h>
#include<Stopwatch.h>
#include<HostileProjectile.h>
#include<Entity.h>
#include<GameProperties.h>
#include<Settings.h>
#include<Sound.h>
#include<Keyboard.h>
#include <BonusScore.h>

#include <SDLBulletBonus.h>
#include<SDLFriendlyProjectile.h>
#include<SDLSound.h>
#include<SDLCore.h>
#include<SDLFrog.h>
#include<SDLVehicle.h>
#include<SDLTank.h>
#include<SDLHostileProjectile.h>
#include<SDLBonus.h>
#include<SDLSettings.h>
#include<SDLKeyboard.h>


using namespace Frogger;
using namespace std;
namespace SDL
{

	class SDLFact : public Frogger::Factory
	{
		public:
			SDLFact();

		protected:
			Core* CreateScreen(int, int,int, int);
			Frogger::Frog* CreateFrog(GameProperties* gameProperties, Frogger::Keyboard*);
			Stopwatch* CreateStopwatch();
			Frogger::HostileProjectile* CreateProjectile(GameProperties*,int,int,int,int);
			Frogger::Vehicle* CreateVehicle(GameProperties*,int, float);
			Frogger::Tank* CreateTank(GameProperties*,int, float);

			FriendlyProjectile* CreateFriendlyProjectile(int,int);
			BonusScore* CreateScoreBonus(GameProperties*, int);
			BulletBonus* CreateBulletBonus(GameProperties*, int);
			Keyboard* CreateKeyboard();
			Settings* CreateSettings();
			Sound* 	  CreateSound();

			virtual ~SDLFact();

		private:
			SDL::SDLCore* sDLCore= NULL;
			SDL_Texture* projectiel_texture = NULL;
			SDL_Texture* frog_texture = NULL;
			SDL_Texture* tank_texture = NULL;
			SDL_Texture* bullet_bonus_texture = NULL;
			SDL_Texture* Bonus_texture = NULL;

			SDL_Texture* vehicle_textures[3];
			SDL_Texture* friendly_projectile_texture = NULL;

	};
}
#endif /* SDL_SDLFACT_H_ */
