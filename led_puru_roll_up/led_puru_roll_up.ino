#include "LedControl.h"

LedControl lc=LedControl(12,11,10,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames
int offsetCounter = 0;

// Put values in arrays
byte alphaP[] =
{
   B00000000,  // First frame of invader #1
   B00000000,
   B01110000,
   B01010000,
   B01110000,
   B01000000,
   B01000000,
   B00000000
};

byte alphaU[] =
{
   B00000000,  // First frame of invader #1
   B00000000,
   B01001000,
   B01001000,
   B01001000,
   B01001000,
   B01111000,
   B00000000
};

byte alphaR[] =
{
   B00000000,  // First frame of invader #1
   B00000000,
   B01111000,
   B01001000,
   B01111000,
   B01100000,
   B01010000,
   B01001000
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  lc.setIntensity(0,2);  // Set intensity levels
  lc.setIntensity(1,2);
  lc.setIntensity(2,2);  // Set intensity levels
  lc.setIntensity(3,2);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
}


//  Take values in Arrays and Display them
void setP(int block, int offset)
{
  byte val;
  for (int i = 0; i < 8; i++)  
  {
    if (i + offset > 7)
    {
      offset = offset - 8;  
    }
    lc.setRow(block,i,alphaP[i + offset]);
  }
}

void setU(int block, int offset)
{
  for (int i = 0; i < 8; i++)  
  {
    if (i + offset > 7)
    {
      offset = offset - 8;    
    }
    lc.setRow(block,i,alphaU[i + offset]);
  }
}

void setR(int block, int offset)
{
  for (int i = 0; i < 8; i++)  
  {
    if (i + offset > 7)
    {
      offset = offset - 8;   
    }
    lc.setRow(block,i,alphaR[i + offset]);
  }
}


void loop()
{
// Put #1 frame on both Display
    if (offsetCounter > 7)
    {
      offsetCounter = 0;  
    }
    setP(3,offsetCounter);
    
    setU(2,offsetCounter);
    


// Put #2 frame on both Display
    setR(1,offsetCounter);
    
    setU(0,offsetCounter);
    delay(delayTime);

    offsetCounter++;

}
