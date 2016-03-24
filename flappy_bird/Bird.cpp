#include "Bird.h"
Bird::Bird(int x, int y, unsigned char* enemyImage)
{
  //ctor
  this->PixelMap = enemyImage;
  width = 19;
  height = 14;
  this->x = x;
  this->y = y;
  movementRate=3;
  dropRate=2;
  dropCounter=0;
  movementCounter=0;
}

Bird::~Bird()
{
  //dtor
}

void Bird::move(){
   
  if(movement){
    if (direction=='u'){
      if(++movementCounter == movementRate){
     movementCounter  = 0;
      y--;
      }
    }else if(direction=='d'){
      
     y++;    
      
    }
    if(y>=106)
      y=0;
    if(y<=0)
      y=0;
  }
   
}


