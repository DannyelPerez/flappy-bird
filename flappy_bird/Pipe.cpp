#include "Pipe.h"
Pipe::Pipe(int x, int y, int width, int height, unsigned char* enemyImage,bool upper)
{
  //ctor
  this->PixelMap = enemyImage;
  this->width = width;
  this->height =height;
  this->x = x;
  this->y = y;
  movementRate=2;
  movementCounter=0;
  this->upper=upper;
}

Pipe::~Pipe()
{
  //dtor
}

void Pipe::move(){
  if(++movementCounter == movementRate){
     movementCounter  = 0;
  if(movement){
    if (direction=='l'){
      x--;
    }
    if(x<=0)
      x=137;  
  }
  }
}


