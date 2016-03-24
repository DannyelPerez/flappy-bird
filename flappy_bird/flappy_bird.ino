#include "VGA.h"
#include <stdio.h>
#include <string.h> 

void setup() {

  VGA.clear();
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  Serial.begin(9600);
  unsigned char android[] = {
    GREEN,BLACK,BLACK,BLACK,GREEN,BLACK,GREEN,GREEN,GREEN,BLACK,GREEN,BLACK,GREEN,BLACK,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN
  };
  //VGA.writeArea(20,10,5,5,android);
  VGA.setBackgroundColor(RED);
}

void loop() {

}

