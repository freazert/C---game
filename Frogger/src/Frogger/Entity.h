/*
 * Entity.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_ENTITY_H_
#define FROGGER_ENTITY_H_
#include<vector>
namespace Frogger {

//gebruiken om te weten wat met elkaar mag botsen.
enum EntityType {
	FriendlyType, UnfriendlyType, BonusType
};

class Entity {

public:
	Entity(int grid_width, int grid_height);
	virtual ~Entity();

	virtual void DoEvent() = 0;
	virtual void Draw() = 0;
	virtual EntityType GetType() = 0;
	virtual void DoCollision(Entity* collisionEntity) = 0;

	//getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	bool IsDeleteUnit();
	bool isBullet();


	bool Collision(Entity* coll);
	void SetDelete();


protected:

	float x;
	float y;
	float width;
	float height;
	int grid_width;
	int grid_height;
	bool bullet;
	bool DeleteUnit;


};
}
#endif /* FROGGER_ENTITY_H_ */
