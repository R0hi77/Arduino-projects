int relayPin=5;
int triggerPin=10;
int echoPin=12;

long  readDistance(int triggerPin, int echoPin)
  {
    pinMode(triggerPin,OUTPUT);
    
    
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);

    pinMode(echoPin,INPUT);
    return pulseIn(echoPin,HIGH);
  }
void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  Serial.begin(9600);

 
  

}

void loop() {
  long distance;
  distance=0.0175*readDistance(triggerPin, echoPin);
  Serial.println(distance);
  delay(20);

   if(distance<10)
  {digitalWrite(relayPin,HIGH);}
  else{
    digitalWrite(relayPin,LOW);}
  }
  


