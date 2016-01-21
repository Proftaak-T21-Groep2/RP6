RP6_DIRECTION direction_F = RP6_FORWARD;
RP6_DIRECTION direction_R = RP6_RIGHT;
RP6_DIRECTION direction_L = RP6_LEFT;

void moveToStationRight()
{
  Rp6.move( 100 , direction_F , 3700 );
  delay(8000);
  Rp6.rotate(100, direction_L, 93);
  delay(3000);
  Rp6.move( 100 , direction_F , 1700 );
  delay(6000);;
}
void moveToStationLeft()
{
  Rp6.move( 100 , direction_F , 1650 );
  delay(5000);
  Rp6.rotate(100, direction_L, 93);
  delay(3000);
  Rp6.move( 100 , direction_F , 1700 );
  delay(6000);;
}

void moveFromStationRight()
{
  Rp6.move( 100 , direction_F , 1000 );
  delay(3000);
  Rp6.rotate(100, direction_R, 93);
  delay(3000);
  Rp6.move( 100 , direction_F , 1700 );
  delay(6000);
}

void moveFromStationLeft()
{
  Rp6.move( 100 , direction_F , 1000 );
  delay(3000);
  Rp6.rotate(100, direction_R, 93);
  delay(3000);
  Rp6.move( 100 , direction_F , 3700 );
  delay(8000);
}
