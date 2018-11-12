unsigned char *tccr2a = (unsigned char*) 0x80;
unsigned char *tccr2b = (unsigned char*) 0x81;
unsigned char *ocr2b = (unsigned char*) 0xB4;
unsigned char *tcnt1l = (unsigned char *) 0x84;
unsigned char *tcnt1h = (unsigned char *) 0x85;

void setup()
{
  DDRB = (1<<1); //set the timer1 as an output
  float val = 0; //the variable should be set to float to account the decimal increments
  float period = 300;
  float increment = (255*11)/(period*10); //255* Sample_period if we decide to used the program below
  /*we can use the line below to make the program even more flexible*/
  //float Sample_period = 1/Sample Freq;
  /*set the prescaler (the question does not specify a certain value so anything is OK)*/
  *tccr2a = 0b10000011;
  *tccr2b = 0b00001011;
  Serial.begin(9600);
  while (1) 
    {
    *ocr2b = val; //the value will be converted to int in this process
    val += increment; //this is done to get the period of 3s by incrementing by (255/300)
    Serial.println(*ocr2b);
    delay(11);
    }
}
