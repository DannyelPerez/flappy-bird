#include "Bird.h"
Bird::Bird(int x, int y, unsigned char* enemyImage)
{
    //ctor
    this->PixelMap = enemyImage;
    width = 19;
    height = 14;
    this->x = x;
    this->y = y;
}

Bird::~Bird()
{
    //dtor
}

void Bird::move(){
     if(movement)
    {
      if (direction=='u')
          {
            y--;
          }
      else if(direction=='d'){
        y++;    
    }
    }
}


