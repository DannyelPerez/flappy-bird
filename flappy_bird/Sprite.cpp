#include "Sprite.h"
Sprite::Sprite(){
	//ctor
}
Sprite::~Sprite(){
    //dtor
}
void Sprite::move(){
}

bool Sprite::isCollidingWith(Sprite* sprite){
	bool colliding = true;
	colliding = (this->x+this->width) > sprite->x?true:false;
	colliding = colliding && this->x < (sprite->width + sprite->x)?true:false;
	colliding = colliding && (this->y+this->height) > sprite->y?true:false;
	colliding = colliding && this->y < (sprite->height + sprite->y)?true:false;
	return colliding;
}

void Sprite::setMovement(char direction){
	movement  = true;
	this->direction = direction; 
}

void Sprite::setPositions(int x, int y){
	this->x = x;
	this->y=y;
}

void Sprite::stopMovement(){
	movement=false;
}
