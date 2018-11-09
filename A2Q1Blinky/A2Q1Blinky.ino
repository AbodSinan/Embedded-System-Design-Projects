#include <stdio.h>
#include <stdlib.h>

class Blinky
{
  public:
    unsigned char* port;
    unsigned char* ddr;
    unsigned char pin;
    int on;
    int off;
    Blinky(unsigned char val1, unsigned char val2, int onTime, int offTime)
    {
      
      on = onTime;
      off = offTime;
      pin = val2;
      switch (val1)
      {
        case 'B': ddr = 0x24; port = 0x25;break;
        case 'C': ddr = 0x27; port = 0x28;break;
        case 'D': ddr = 0x2A; port = 0x2B;break;
      }
      *ddr |= (1<<pin);
    }
    
    void Refresh()
    {
      if (millis() % (on+off) < on)
      {
        *port |= (1 << pin);
      }
      else
      {
        *port &= ~(1<< pin);
      }
      }    
  };



void setup()
{
  Serial.begin(9600);
  Blinky led0('B',0,750,350);
  Blinky led1('D',5, 1430, 643);
    while(1)
    {
      led0.Refresh();
      led1.Refresh();
    }     
}
