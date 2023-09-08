int PushButton = 13;
int DigitalPushButtonRead = 0;
int Buzzer = 12;
int LED[5] = {7,6,5,4,3};
int count = 0;
unsigned long pmillis = 0;
unsigned long smillis = 0;
int seconds = 0;
int ledswitch = 0;
void setup() {
  pinMode(13, INPUT_PULLUP);
  for(int i=0;i<5;i++)
  {
      pinMode(LED[i], OUTPUT);
  }
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);

}
void LEDPattern()
{
       smillis = millis();
       if(ledswitch==0)
       {
          seconds = 300;
       }
       else if(ledswitch==7)
       {
            seconds = 2900;
       }
       else 
       {
          seconds = 2500;
       }
       if(smillis - pmillis >= seconds)
       {
        
          pmillis = smillis;
          switch(ledswitch)
          {
                case 1:
                {
                      for(int i=0;i<5;i++)
                      {
                            if(i==0)
                            {
                                digitalWrite(LED[i], HIGH);
                            }
                            else
                            {
                                digitalWrite(LED[i], LOW);
                            }
                      }
                      break;
                }
                case 2:
                {
                      for(int i=0;i<5;i++)
                      {
                            if(i==1)
                            {
                                digitalWrite(LED[i], HIGH);
                            }
                            else
                            {
                                digitalWrite(LED[i], LOW);
                            }
                      }
                      break;

                }
                case 3:
                {
                      for(int i=0;i<5;i++)
                      {
                            if(i==2)
                            {
                                digitalWrite(LED[i], HIGH);
                            }
                            else
                            {
                                digitalWrite(LED[i], LOW);
                            }
                            

                      }
                      break;
                }
                case 4:
                {
                      for(int i=0;i<5;i++)
                      {
                            if(i==3)
                            {
                                digitalWrite(LED[i], HIGH);
                            }
                            else
                            {
                                digitalWrite(LED[i], LOW);
                            }
                        

                      }
                         break;
                }
                case 5:
                {
                      for(int i=0;i<5;i++)
                      {
                            if(i==4)
                            {
                                digitalWrite(LED[i], HIGH);
                            }
                            else
                            {
                                digitalWrite(LED[i], LOW);
                            }
                         

                      }
                          break;
                }
                case 6:
                {

                      for(int i=0;i<5;i++)
                      {
                          digitalWrite(LED[i], LOW);
                      }
                      break;
                }
                case 7:
                {

                      for(int i=0;i<5;i++)
                      {
                          digitalWrite(LED[i], HIGH);
                      }
                      break;
                }
                 case 8:
                {

                      for(int i=0;i<5;i++)
                      {
                          digitalWrite(LED[i], LOW);
                      }
                      break;
                }
          }
          ledswitch = (ledswitch + 1) % 9;
       }
}
void loop() {
  DigitalPushButtonRead = digitalRead(PushButton);
  if(DigitalPushButtonRead==HIGH)
  {
       
        delay(800);
        tone(Buzzer,430,400);
        count++;
        Serial.println(count);


  }
  if(count==1)
  {
      for(int i=0;i<5;i++)
      {
          if(i==0)
          {
               digitalWrite(LED[i], HIGH);
          }
          else
          {
              digitalWrite(LED[i], LOW);
          }
      }
  }
  else if(count==2)
  {
      for(int i=0;i<5;i++)
      {
          if(i==1)
          {
               digitalWrite(LED[i], HIGH);
          }
          else
          {
              digitalWrite(LED[i], LOW);
          }
      }
     
  } 
  else if(count==3)
  {
      for(int i=0;i<5;i++)
      {
          if(i==2)
          {
               digitalWrite(LED[i], HIGH);
          }
          else
          {
              digitalWrite(LED[i], LOW);
          }
      }
 
  } 
  else if(count==4)
  {
      for(int i=0;i<5;i++)
      {
          if(i==3)
          {
               digitalWrite(LED[i], HIGH);
          }
          else
          {
              digitalWrite(LED[i], LOW);
          }
      }
     
  } 
  else if(count==5)
  {
      for(int i=0;i<5;i++)
      {
          if(i==4)
          {
               digitalWrite(LED[i], HIGH);
          }
          else
          {
              digitalWrite(LED[i], LOW);
          }
      }
    
  } 
  else if(count==6)
  {
        LEDPattern();
  }
  else if(count==7)
  {
      count = 0;
      ledswitch = 0;
      for(int i=0;i<5;i++)
      {
          
            digitalWrite(LED[i], LOW);
       
      }
  }
}
