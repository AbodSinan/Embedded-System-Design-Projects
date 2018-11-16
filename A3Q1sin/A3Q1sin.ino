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
  int period = 5000; //the period can be decreased everso slightly to compensate the discrepancy caused by excecuting the statements in the loop
  long value = 0;
  unsigned int count = 0;
  unsigned char output = 0; 
  *tccr1a = 0b10000011;
  *tccr1b = 0b00111011;
  Serial.begin(9600);
  while (1) 
    {
    value = 128* sin(count*2*PI/period)+ 128;
    output = (unsigned char) value
    *ocr1al = output;
    Serial.println(*ocr1al);
    count+= 11;
    if (count>=5000) count = 0;
    delay(11);
    }
}
