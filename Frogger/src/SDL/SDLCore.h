/*
 * SDLCore.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLCORE_H_
#define SDL_SDLCORE_H_

#include<sstream>
#include<SDL2/sdl_ttf.h>
#include<SDL2/sdl_image.h>
#include<Core.h>
#include<Entity.h>
#include<stdio.h>
#include "math.h"
#include <SDL2/SDL_mixer.h>
#include <GameProperties.h>

template<typename T>
std::string NumberToString(T Number) {
	std::stringstream ss;
	ss << Number;
	return ss.str();
}

using namespace Frogger;

namespace SDL {

class SDLCore: public Frogger::Core {
public:
	//Starts up SDL and creates window
	bool Init(int, int, int, int);

	void Render(float, float, float, float, SDL_Texture*, SDL_RendererFlip);
	void ReRender(std::vector<Entity*>*, GameProperties*);

	SDL_Texture* CreateTexture(char* path);

	virtual ~SDLCore();

protected:
	void Delay(float seconds);


private:

	SDL_Window* gWindow = NULL;
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	SDL_Texture* gTexture = NULL;
	SDL_Texture* backgroundTexture = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	SDL_Texture* renderText(const std::string &message);
	void RenderText(std::string text);
	void LoadBackground();
};
}
#endif /* SDL_SDLCORE_H_ */
