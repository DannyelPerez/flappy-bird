#include "Renderer.h"
#include "Bird.h"


Renderer::Renderer()
{
    //ctor
}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::render(Sprite* sprite){
	VGA.writeArea(sprite->x,sprite->y,sprite->width,sprite->height,sprite->PixelMap);
}

void Renderer::clear(){
	VGA.clear();
}
