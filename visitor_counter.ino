#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,3,4,5,6);

//designating pin names
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
  distance= duration*0.034/2;                            //distance from sensor 1
  
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1=pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;                          //distance from sensor 2
  
  
  delay(700);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durationNew=pulseIn(echoPin, HIGH);
  distanceNew= durationNew*0.034/2;                     //New distance from Sensor 1
  

  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  durationNew1=pulseIn(echoPin1, HIGH);
  distanceNew1= durationNew1*0.034/2;                   //New distance from Sensor 2
  

  while((11*(distanceNew)/10) < distance)               //Comparing the new and old distance of sensor 1 with a error margin of 10%
  {                                                     //Therefore goes into the loop if something is detected in sensor 1
    if(flag1==0){
        flag1=1;                                        //flag1 set to 1
    }
        digitalWrite(trigPin1, LOW);
  		  delayMicroseconds(2);
        digitalWrite(trigPin1, HIGH);                  //sensor 1 has been isolated but sensor 2 is still sending ultrasonic in loop
        delayMicroseconds(10);
        digitalWrite(trigPin1, LOW);

        durationNew1=pulseIn(echoPin1, HIGH);
        distanceNew1= durationNew1*0.034/2;
    
    	  delay(100);
    
    	  if((11*(distanceNew1)/10)<distance1)           //searching for any change in new distance of sensor 2
  		  {
    		    count=count+1;                             //if found then the person has entered the room

          	digitalWrite(buzz, HIGH);                  //Set the buzzer on
        	
        	  break;
  		  }
  } 
  while((11*(distanceNew1)/10)<distance1&& flag1==0)  //Comparing the new and old distance of sensor 1 with a error margin of 10%
  {                                                   //Therefore goes into the loop if something is detected in sensor 1
    if(flag2==0){
        flag2=1;                                      //flag1 set to 1
    }
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);                     //sensor 2 has been isolated but sensor 1 is still sending ultrasonic in loop
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      durationNew=pulseIn(echoPin, HIGH);
      distanceNew= durationNew*0.034/2;
      delay(100);
      if((11*(distanceNew)/10)<distance)               //searching for any change in new distance of sensor 1
  		{
    		count=count-1;                                 //if found then the person has exited the room
        	break;
  		}
  } 

  lcd.setCursor(0,1);                                  //LCD screen cursor set to second row first column

  if(count>=0)
  {
    lcd.print(count);                                  //printing no. of people inside if count is grater than 0
  }
  else
  {
    lcd.print(0);                                      //else no. of people inside is zero
  }
  delay(100);
  digitalWrite(buzz, LOW);                             //buzzer set off

}
