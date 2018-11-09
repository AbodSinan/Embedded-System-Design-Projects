unsigned char *tccr1a = (unsigned char*) 0x80;
unsigned char *tccr1b = (unsigned char*) 0x81;
unsigned char *tccr1c = (unsigned char*) 0x82;
unsigned char *ocr1al = (unsigned char*) 0x88;
unsigned char *ocr1ah = (unsigned char*) 0x89;
unsigned char *tcnt1l = (unsigned char *) 0x84;
unsigned char *tcnt1h = (unsigned char *) 0x85;

void setup()
{
  DDRB = (1<<1); //set the timer1 as an output
  long value = 0;
  unsigned int count = 0;
  *tccr1a = 0b10000011;
  *tccr1b = 0b00111011;
  Serial.begin(9600);
  while (1) 
    {/*If we require the output to be 16-bit for some reason*/
    //value = (65525/2)*sin(count*2*PI/5000)+ (65525/2);
    //*ocr1al = (value & 255);
    //*ocr1ah = (value >> 8);
    count+= 11;
    if (count >= 5000) count%= 5000;
    delay(11);
    }
}
