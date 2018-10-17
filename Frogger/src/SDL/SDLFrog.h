/*
 * SDLFrog.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLFROG_H_
#define SDL_SDLFROG_H_

#include<SDL2/sdl.h>

#include<Frog.h>

#include<SDLCore.h>
#include<Factory.h>
#include<SDLStopwatch.h>
using namespace Frogger;
namespace SDL
{
	class SDLFrog :  public Frogger::Frog
	{
		public:

			SDLFrog(GameProperties* gameProperties,Keyboard*, SDLCore*, SDL_Texture*, Frogger::Factory*);
			virtual ~SDLFrog();

		protected:
			void Draw();

		private:
			SDLCore * sdlCore = NULL;
			SDL_Texture* newTexture = NULL;
	};
}
#endif /* SDL_SDLFROG_H_ */
