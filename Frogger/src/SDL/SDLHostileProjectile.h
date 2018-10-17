/*
 * SDLProjectile.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLPROJECTILE_H_
#define SDL_SDLPROJECTILE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <SDLCore.h>
#include <HostileProjectile.h>
namespace SDL
{
	class SDLHostileProjectile : public Frogger::HostileProjectile
	{
		public:
			SDLHostileProjectile(GameProperties* gameProperties,SDLCore* sdlCore, int x, int y, int frogX, int frogY, SDL_Texture* texture);
			virtual ~SDLHostileProjectile();

		protected:
			void Draw();

		private:
			SDLCore* sdlCore =  NULL;
			SDL_Texture* newTexture = NULL;

	};
}
#endif /* SDL_SDLPROJECTILE_H_ */
