/*
 * SDLSettings.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef SDL_SDLSETTINGS_H_
#define SDL_SDLSETTINGS_H_

#include<Settings.h>
#include <SDL2/SDL.h>

#include<stdio.h>
namespace SDL
{
	class SDLSettings: public Frogger::Settings
	{
		public:
			SDLSettings();
			virtual ~SDLSettings();

		protected:
			void ReadHigscore(int[]);
			void WriteToFile(int[]);


	};
}
#endif /* SDL_SDLSETTINGS_H_ */
