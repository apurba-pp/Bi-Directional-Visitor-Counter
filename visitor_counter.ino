#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,3,4,5,6);
const int trigPin = 10;
const int trigPin1 = 12;
const int echoPin = 9;
const int echoPin1 = 11;
const int buzz = 8;

long duration, durationNew,duration1, durationNew1;
int distance,distanceNew, count=0,distance1,distanceNew1, count1=0,x;

int flag1=0, flag2=0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzz, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("People in Room:");
  
}
void loop() {
  flag1=0;
  flag2=0;
  
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1=pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;
  delay(700);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durationNew=pulseIn(echoPin, HIGH);
  distanceNew= durationNew*0.034/2;
  

  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  durationNew1=pulseIn(echoPin1, HIGH);
  distanceNew1= durationNew1*0.034/2;
  

  while((11*(distanceNew)/10) < distance)
  {
    if(flag1==0){
        flag1=1;
    }
        digitalWrite(trigPin1, LOW);
  		delayMicroseconds(2);
        digitalWrite(trigPin1, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin1, LOW);

        durationNew1=pulseIn(echoPin1, HIGH);
        distanceNew1= durationNew1*0.034/2;
    	delay(100);
    	if((11*(distanceNew1)/10)<distance1)
  		{
    		count=count+1;

          	digitalWrite(buzz, HIGH);
        	
        	break;
  		}
  } 
  while((11*(distanceNew1)/10)<distance1&& flag1==0)
  {
    if(flag2==0){
        flag2=1;
    }
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      durationNew=pulseIn(echoPin, HIGH);
      distanceNew= durationNew*0.034/2;
      delay(100);
      if((11*(distanceNew)/10)<distance)
  		{
    		count=count-1;
        	break;
  		}
  } 

  lcd.setCursor(0,1);

  if(count>=0)
  {

    lcd.print(count);
  }
  else
  {
    lcd.print(0);
  }
  delay(100);
  digitalWrite(buzz, LOW);

}
