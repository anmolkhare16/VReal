const int trigPin = 2;
const int echoPin = 4;
#include <Servo.h>
Servo myservo;
int p=0;
int c=0;
void setup() {
 myservo.attach(9);
  Serial.begin(9600);
}

void loop()
{

  long duration, inches, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);


  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if(cm<=5 || (cm>=8 && cm<=10)){
    //while(cm<=5 || (cm>=8 && cm<=10)){
c=c+1;
   
    
    if(c==1){
       myservo.write(30);
    }
    
   //  p=p+1;
   }
  else{
     c&=0;
     myservo.write(0);
  }
  
  //Serial.print(inches);
 // Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
