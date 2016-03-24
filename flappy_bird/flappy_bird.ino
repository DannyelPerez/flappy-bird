#include "VGA.h"
#include "Bird.h"
#include "Pipe.h"
#include "Renderer.h"
#include <stdio.h>
#include <string.h> 


int x=0;
int y=0;
int yP=0;
int yP1=90;
boolean gameOver=false;
int xP=50;
int xP1=100;
unsigned char bird[] = {
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, WHITE, BLACK, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, WHITE, WHITE, WHITE, BLACK, BLACK,  BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,  BLACK, BLACK, BLACK, BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, WHITE, WHITE, BLACK, WHITE, BLACK, BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,   WHITE, WHITE, WHITE, WHITE, BLACK, YELLOW,  YELLOW,  YELLOW,  BLACK, WHITE, WHITE, BLACK, WHITE, BLACK, BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,   WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, YELLOW,  YELLOW,  YELLOW,  BLACK, WHITE, WHITE, WHITE, BLACK, BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,   YELLOW,  WHITE, WHITE, WHITE, YELLOW,  BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
  BLACK,  BLACK,  BLACK, YELLOW,  YELLOW,  YELLOW,  BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, RED, RED, RED, RED, RED, BLACK, BLACK,
  BLACK,  BLACK,  BLACK,  BLACK, BLACK, BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, RED, RED, RED, RED, BLACK, BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, BLACK, YELLOW,  YELLOW,  YELLOW,  YELLOW,  BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK
};

unsigned char pipe[] = {
  BLACK, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  BLACK, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
  GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN
};

Bird _bird(x,y,bird);
Pipe _pipe1(xP,yP,23,43,pipe,true);
Pipe _pipe2(xP1,yP1,23,30,pipe,false);
Renderer _render;

void setup() {
  VGA.clear();
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  Serial.begin(9600);
}

int rand_range(int min_n, int max_n)
{
  return rand() % (max_n - min_n + 1) + min_n;
}

void gameover(){
   VGA.clear();
   VGA.printtext(42, 30, "Game Over");
   VGA.setColor(RED);
   delay(60);
}

bool colission(Bird bird,Pipe pipe)
{
    if( pipe.upper==true && ( bird.x + 19 ) >= pipe.x && bird.y <= pipe.height)
        true;
    else if( pipe.upper==false && ( bird.x + 19 ) >= pipe.x && ( bird.y + 14 ) >= pipe.y )
        true;
}


void animation(){
  if(digitalRead(FPGA_BTN_1)){    
    _bird.setMovement('u');
    _bird.move();
  }else{
    _bird.setMovement('d');
    _bird.move();
  }
  xP--;
  xP1--;
  VGA.clear();
  _render.render(&_bird);
  _render.render(&_pipe1);
  _render.render(&_pipe2);
  _pipe1.setMovement('l');
  _pipe1.move();
  _pipe2.setMovement('l');
  _pipe2.move();

  if(colission(_bird,_pipe1))
    _bird.dead=true;;
  colission(_bird,_pipe2);
}







void loop() {
 if(_bird.dead==false){
  animation();
  }else
  {
    gameover();
  }
}

