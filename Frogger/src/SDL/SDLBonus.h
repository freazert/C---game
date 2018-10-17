/*
 * SDLBonus.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLBONUS_H_
#define SDL_SDLBONUS_H_

#include<SDL2/SDL.h>
#include<GameProperties.h>
#include<SDLCore.h>
#include<Stopwatch.h>
#include<BonusScore.h>
using namespace Frogger;
namespace SDL
{
	class SDLBonus : public Frogger::BonusScore
	{
		public:
			SDLBonus(GameProperties* gameProperties, SDLCore* sdlCore, SDL_Texture* texture, float y, int lane);
			virtual ~SDLBonus();

		protected:
			void Draw();

		private:
			SDLCore * sdlCore;
			SDL_Texture* newTexture;
	};
}
#endif /* SDL_SDLBONUS_H_ */
