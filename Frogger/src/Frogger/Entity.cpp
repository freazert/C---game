#include "Entity.h"
#include "stdio.h"
#include "algorithm"

namespace Frogger {

Entity::Entity(int grid_width, int grid_height) {

	bullet = false;

	x = 0;
	y = 0;

	height = 0;
	width = 0;

	//grid vaststellen
	this->grid_height = grid_height;
	this->grid_width = grid_width;

	DeleteUnit = false;
}

bool Entity::IsDeleteUnit() {
	return DeleteUnit;
}

float Entity::GetHeight() {
	return height;
}
float Entity::GetWidth() {
	return width;
}

float Entity::GetX() {
	return x;
}

float Entity::GetY() {
	return y;
}

//check of een entity tegen een andere entity gebokst is.
bool Entity::Collision(Entity* entity) {

	bool hit = true;

	float rightA = x + width;
	float bottomA = y + height;
	float leftB = entity->GetX();
	float rightB = entity->GetX() + entity->GetWidth();
	float topB = entity->GetY();
	float bottomB = entity->GetY() + entity->GetHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) {
		hit = false;
	}

	if (y >= bottomB) {
		hit = false;
	}

	if (rightA <= leftB) {

		hit = false;
	}

	if (x >= rightB) {
		hit = false;
	}
	return hit;
}

bool Entity::isBullet() {
	return bullet;
}
// set true zodat volgende iteratie deze entity verwijderd kan worden.
void Entity::SetDelete() {
	DeleteUnit = true;
}

Entity::~Entity() {
}
}

