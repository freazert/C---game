/*
 * Core.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_CORE_H_
#define FROGGER_CORE_H_
#include "Entity.h"
#include "GameProperties.h"
namespace Frogger {
class Core {
public:
	//Starts up SDL and creates window
	//x-> width van totale scherm
	//y-> height van total scherm
	virtual bool Init(int x, int y, int grid_width, int grid_height) = 0;
	virtual void ReRender(std::vector<Entity*>* entities, GameProperties* gameProperties) = 0;
	//laat het spel enkele miliseconden slapen
	virtual void Delay(float ms) = 0;

	int GetGridWidth();
	int GetGridHeight();

	virtual ~Core();

protected:
	int SCREEN_HEIGHT;
	int SCREEN_WIDTH;
	int grid_width;
	int grid_height;

};
}
#endif /* FROGGER_CORE_H_ */
