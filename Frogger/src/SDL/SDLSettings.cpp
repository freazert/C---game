/*
 * SDLSettings.cpp
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#include "SDLSettings.h"

namespace SDL
{

	SDLSettings::SDLSettings()
	{
		//ctor
	}

	SDLSettings::~SDLSettings()
	{
		//dtor
	}

	//Ophalen va de topscore. De 5 beste highscores
	void SDLSettings::ReadHigscore(int data[])
	{
		SDL_RWops* file = SDL_RWFromFile( "Files/highscore.bin", "r+b" );
		if( file == NULL )
		{
			printf( "Warning: Unable to open file! SDL Error: %s\n", SDL_GetError() );
			//Create file for writing
			file = SDL_RWFromFile( "Files/highscore.bin", "w+b" );
			if( file != NULL )
			{
				printf( "New file created!\n" );
				//Initialize data
				for( int i = 0; i < 5; ++i )
				{
					data[i] = 0;
					SDL_RWwrite( file,  &data[ i ], sizeof(int), 1 );
				}

				//Close file handler
				SDL_RWclose( file );

			}
			else
			{
				printf( "Error: Unable to create file! SDL Error: %s\n", SDL_GetError() );
				//success = false;
			}
		}
		 //File exists
		else
		{
			//Load data
			//printf( "Reading file...!\n" );

			for( int i = 0; i < 5; ++i )
			{
				//program crashes
				SDL_RWread( file, &data[ i ], sizeof(int), 1 );
			}

			//Close file handler
			SDL_RWclose( file );

		}
	}

	//wegschrijven van eventuele nieuwe data.
	void SDLSettings::WriteToFile(int data[])
	{
		//Open data for writing
		SDL_RWops* file = SDL_RWFromFile( "Files/highscore.bin", "w+b" );
		if( file != NULL )
		{
			//Save data
			for( int i = 0; i < 5; ++i )
			{
				SDL_RWwrite( file, &data[i], sizeof(int), 1 );
			}

			//Close file handler
			SDL_RWclose( file );
		}
		else
		{
			printf( "Error: Unable to save file! %s\n", SDL_GetError() );
		}
	}
}
