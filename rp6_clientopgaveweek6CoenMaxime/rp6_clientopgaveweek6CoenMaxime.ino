//Maxime en Coen
/*

DIT PROGRAMMA IS VAN MAXIME EN COEN
ALLEEN BEDOELD OM EEN INZICHT TE KRIJGEN
HOE DEZE OPGAVE KAN WORDEN OPGELOST

*/
#include "Rp6.h"

RP6_registers regs;
RP6_LEDs leds;
RP6_DIRECTION dif = RP6_FORWARD;
RP6_DIRECTION dib = RP6_BACKWARD;
RP6_DIRECTION dir = RP6_RIGHT;
RP6_DIRECTION dil = RP6_LEFT;


void moveStationRight()
{
  Rp6.move( 100 , dif , 3800 );
  delay(9000);
  Rp6.rotate(100, dil, 93);
  delay(4000);
  Rp6.move( 100 , dif , 1650 );
  delay(5000);;
}

void moveStationLeft()
{
  Rp6.move( 100 , dif , 1650 );
  delay(5000);
  Rp6.rotate(100, dil, 93);
  delay(4000);
  Rp6.move( 100 , dif , 1650 );
  delay(5000);;

}

void setup()
{
  Serial.begin(9600);

  Rp6.begin();
}

void loop()
{
  delay(5000);
  moveStationLeft();
  delay(5000);
  moveStationRight();

}
