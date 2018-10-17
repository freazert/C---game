/*
 * SDLSound.cpp
 *
 *  Created on: 19-jun.-2016
 *      Author: Kris
 */

#include <SDLSound.h>
#include<stdio.h>

namespace SDL {

SDLSound::SDLSound() {
	//Load music
	gMusic = Mix_LoadMUS("sounds/muziek.wav");
	if (gMusic == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: \n");
	}

	//Load sound effects
	gGameOver = Mix_LoadWAV("sounds/game_over.wav");
	if (gGameOver == NULL) {
		printf("Failed to load scratch sound effect! SDL_mixer Error:");
	}
}

// muziek opstarten
void SDLSound::StartMusic() {
	Mix_PlayMusic(gMusic, -1);
}

//Sound"game over" opstarten
void SDLSound::StartGameOverSound() {
	Mix_PlayChannel(-1, gGameOver, 0);;
}

//muziek puazeren of terug aanvatten.
void SDLSound::PauseMusic() {
	//als muziek speelt
	if (Mix_PausedMusic() != 1) {
		//Pause the music
		Mix_PauseMusic();
	}
}

//muziek puazeren of terug aanvatten.
void SDLSound::ResumeMusic() {
	//als muziek nit speelt
	if (Mix_PausedMusic() == 1) {
		//Resume the music
		Mix_ResumeMusic();
	}
}

SDLSound::~SDLSound() {
	Mix_FreeChunk(gGameOver);
	gGameOver = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
}

} /* namespace SDL */
