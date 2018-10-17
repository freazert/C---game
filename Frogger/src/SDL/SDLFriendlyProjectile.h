/*
 * SDLFriendlyProjectile.h
 *
 *  Created on: 17-jun.-2016
 *      Author: Kris
 */

#ifndef SDL_SDLFRIENDLYPROJECTILE_H_
#define SDL_SDLFRIENDLYPROJECTILE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <SDLCore.h>
#include <FriendlyProjectile.h>
using namespace Frogger;
namespace SDL {

class SDLFriendlyProjectile: public FriendlyProjectile {

	public:
		SDLFriendlyProjectile(SDLCore* sdlCore, int x ,int y,SDL_Texture* texture);
		virtual ~SDLFriendlyProjectile();

	protected:
		void Draw();

	private:
		SDLCore* sdlCore = NULL;
		SDL_Texture* newTexture = NULL;
	};
} /* namespace SDL */

#endif /* SDL_SDLFRIENDLYPROJECTILE_H_ */
