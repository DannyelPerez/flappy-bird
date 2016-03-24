#include "Pipe.h"
Pipe::Pipe(int x, int y, int width, int height, unsigned char* enemyImage)
{
  //ctor
  this->PixelMap = enemyImage;
  this->width = width;
  this->height =height;
  this->x = x;
  this->y = y;
}

Pipe::~Pipe()
{
  //dtor
}

void Pipe::move(){
  if(movement){
    if (direction=='l'){
      x--;
    }
  }
}


