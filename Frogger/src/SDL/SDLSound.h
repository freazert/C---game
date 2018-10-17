/*
 * SDLSound.h
 *
 *  Created on: 19-jun.-2016
 *      Author: Kris
 */

#ifndef SDL_SDLSOUND_H_
#define SDL_SDLSOUND_H_



#include <SDL2/SDL.h>
#include <Sound.h>
#include <SDL2/SDL_mixer.h>

namespace SDL {

class SDLSound: public Frogger::Sound{

public:
	SDLSound();
	~SDLSound();

protected:

	void StartMusic();
	void PauseMusic();
	void StartGameOverSound();
	void ResumeMusic();

private:

	Mix_Music* gMusic = NULL;
	Mix_Chunk* gGameOver = NULL;
};

} /* namespace SDL */

#endif /* SDL_SDLSOUND_H_ */
