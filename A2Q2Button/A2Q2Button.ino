class Button
{
  public:
    unsigned char* port;
    unsigned char* pinR;
    unsigned char pin;
    bool previous = 0;
    bool waitFlag;
    bool clickFlag;
    bool normState;
    int deb;
    unsigned long start = (unsigned long) 0;
    unsigned long startClick = (unsigned long) 0;
    void (*Pressed) ();
    void (*DoubleClicked) ();
    
    Button(unsigned char portNo, unsigned char pinNo,int val, bool norm, bool intern)
    {
      pin = pinNo;
      deb = val;
      normState = norm;
      //set pointers to registers depending on the port
      switch(portNo)
      {
        case 'B': port = (unsigned char*)0x25; pinR = (unsigned char*)0x23; break;
        case 'C': port = (unsigned char*)0x28; pinR = (unsigned char*)0x26; break;
        case 'D': port = (unsigned char*)0x2B; pinR = (unsigned char*)0x29; break;
      }
      
      if (intern) *port |= (1<<pin); //if intern is 1 activate internal pull-up            
    }
    void Refresh()
    {
      if (millis()- startClick > 500) //if no 2nd click was made within standard period (500ms)
      {
        clickFlag = 0; //stop waiting for second click
      }
        
      if (waitFlag == 1) //if waiting for debounce
      {
        if (millis() - start > deb)
        {
          bool current = ((*pinR &(1<<pin))!= (normState<<pin));
          if (current)
          {
            Pressed(); //excecute the fuction pointed to by *pressed
            waitFlag = 0; //stop waiting for debounce
            clickFlag = 1; //Turn on the click flag
            startClick = millis(); //take the time until next click in case  of double clicking
          }
        }
      }
      else
      {
        bool current = ((*pinR & (1<<pin))!= (normState<<pin));
        if (current && !previous) //to detect the transition
        {
          if (clickFlag == 1) //if we are still waiting for 2nd click
          {
            DoubleClicked(); //excecute the function pointed to by *DoubleClicked
            clickFlag = 0;
          }
          start = millis();
          waitFlag = 1;        
        }
        previous = current;
      }
    }

};

unsigned int A_count=0, B_count=0, C_count=0, D_count=0, E_count=0;
Button A('D', 2, 20, 1, 1);
Button B('B', 0, 20, 1, 1);

void setup() 
{
  Serial.begin(9600);
  A.Pressed=A_gets_pressed;
  A.DoubleClicked = A_double;
  B.Pressed=B_gets_pressed;
  B.DoubleClicked = B_double;
  while(1)
  {
    A.Refresh();
    B.Refresh();
  }
}

void A_double()
{
  Serial.println("Button A has been Double Clicked");
}
void B_double()
{
  Serial.println("Button B has been Double Clicked");
}
void A_gets_pressed()
{
  A_count++;
  print();
}
void B_gets_pressed()
{
  B_count++;
  print();
}

void print()
{
  Serial.print("A = ");
  Serial.print(A_count);
  Serial.print(" B = ");
  Serial.println(B_count);
}
