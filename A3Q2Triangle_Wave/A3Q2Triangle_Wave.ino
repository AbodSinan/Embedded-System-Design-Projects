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
  float val = 0;
  *tccr1a = 0b10000011;
  *tccr1b = 0b00111011;
  Serial.begin(9600);
  while (1) 
    {
    *ocr1al = val;
    val += 0.85;
    Serial.println(*ocr1al);
    delay(11);
    }
}
