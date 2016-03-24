#include "Sprite.h"
Sprite::Sprite(){
	//ctor
}
Sprite::~Sprite()
{
    //dtor
}


void Sprite::move(){
}

void Sprite::setMovement(char direction){
	movement  = true;
	this->direction = direction; 
}