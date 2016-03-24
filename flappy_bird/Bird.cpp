#include "Bird.h"

Bird::Bird(int x, int y, unsigned char* enemyImage)
{
    //ctor
    PixelMap = enemyImage;
    width = 19;
    height = 14;
    this->x = x;
    this->y = y;
}

Bird::~Bird()
{
    //dtor
}

void Bird::jump(bool j){
     if(j)
    {    
      y--;
    }else{
      delay(10);
      y++;
    }
}