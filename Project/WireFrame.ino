char lookup[3][3][3] = {{ {'a', 'b', 'c'}, {'d', 'e', 'f'},{'g', 'h', 'i'} },
                          { {'j', 'k', 'l'}, {'m', 'n', 'o'},{'p', 'q', 'r'} },
                          { {'s', 't', 'u'}, {'v', 'w', 'x'},{'y', 'z', ' '} }

void setup()
{
  bool waitSignal, waitPeriod, reading = FALSE;
  int inputVal, counta, countb, countc;
  unsigned long startTime, endTime, signalPeriod, waitTime = 0
  output [10] = {};
  waitSignal = True;

  while(1)
  {
    if(waitSignal)
    {
      //read the value
      if (value > threshold)
      {
        startTime = millis();
        waitPeriod = TRUE;
        waitSignal = FALSE;
      } 
    }
    if(waitPeriod)
    {
      if (value < threshold)
      {
        periodTime = millis() - startTime;
        waitPeriod = FALSE;
        reading = TRUE
      }
    }
    if (reading)
    {
      counta++;
      for (int i = 0; ; i++)
      {
        startTime = millis();
        for (;;;)
        {
          counta++;
          if (counta > 3) Serial.println("Error reading the signal (bypassed the threshold)")
          if (millis() - startTime >= waitSignal)
          {
          //wait for the next signal
          }
        }
        for (;;;)
        {
          countb++;
          if (countb > 3) Serial.println("Error reading the signal (bypassed the threshold)")
          if (millis() - startTime >= waitSignal)
          {
          //wait for the next signal
          }
        }
        for (;;;)
        {
          countc++;
          if (countc > 3) Serial.println("Error reading the signal (bypassed the threshold)")
          if (millis() - startTime >= waitSignal)
          {
          //wait for the next signal
          }
        }
        if (millis() - startTime >= 2*waitSignal) //if the waiting period bypasses two signals, go to the next letter
        {
          break;
        }
        char [i] = lookup[counta][countb][countc];
      }
    }
  }
  
}
