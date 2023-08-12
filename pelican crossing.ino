
byte color = 3;
byte interupt = 0; // 0 is automatic , 1 = button pressed
int timer = 0;
byte safety = 0;// 0 not  == safe to cross
int button;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT); //red
  pinMode(4,OUTPUT);// yellow
  pinMode(5,OUTPUT);// green
  pinMode(11,INPUT_PULLUP);// button
  pinMode(10,OUTPUT);//BUZZER
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:'"
  Serial.println(11);
  reset();
  while(timer <= 500 && interupt == 0)
  {
    // automatic sequence
    Blink(color);
    delay(50);
    timer++;
    //
    if(digitalRead(11) == 0)
    {
      interupt = 1; // breaks out of this loop
      digitalWrite(10,HIGH);
    }
  }

  if(interupt == 1)
  {
    inducedTraffic(color);
    color = 3;
  }
  unBlink(color);
  director(color);
}

void Blink(byte pin)
{
  digitalWrite(pin,HIGH);
}
void unBlink(byte pin)
{
  digitalWrite(pin,LOW);
}

void director(byte nxtcolor) //determines the nextColor to display
{
  switch(nxtcolor)
  {
    case 3: //red
      color = 4;
      break;
    case 4: //green
      color = 5;
      break;
    case 5://yellow
      color = 3;
      safety = 1;// safe to cross;
      break;
    default:
      break;
  }
}
void reset() // help to send back to automatic switching
{
  timer = 0;
  digitalWrite(10,LOW);
  interupt = 0; //pedestrain not interferring
}

void safeToCross()
{
    //show safe to cross
    Blink(10);
    delay(200);
    unBlink(10);
    safety = 0;
}

void inducedTraffic(byte nxtcolor)
{
  switch(nxtcolor)
  {
    case 3: //red
      Blink(3);
      delay(1000);
      unBlink(3);
      break;
    case 4: //yellow
      delay(100);
      unBlink(5);
      unBlink(4);
      Blink(3);
      delay(1000);
      break;
    case 5://green
      delay(500);
      Blink(4);
      delay(500);
      unBlink(5);
      unBlink(4);
      Blink(3);
      delay(6000);
      //unBlink(4);
      //unBlink(5);
      //delay(1000);
      break;
    default:
    Blink(color);
      break;
  }
}

 /* 
  while(timer <= 500)
  {
    Blink(color);
    delay(1);
    timer++;
  }
  unBlink(color);
  director(color);
  reset();
  while(interupt == 0)
  {
    if(digitalRead(11) == 0)
    {
      interupt = 1;
    }
    Blink(color);
  }
   unBlink(color);
  director(color);
  */
