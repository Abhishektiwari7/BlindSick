/*Author Abhishek Tiwari
Date: 12-NOV-2019
*/
const int trigPin = 9;
const int echoPin = 10;
const int motor = 8;
const int buzzer = 3;
const int watersensor = A5;
int waterVal;
long duration;
long distance;
int val;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(watersensor, INPUT);
 digitalWrite(buzzer, LOW);
 digitalWrite(motor, LOW);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here,  to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;

 // Serial.println(distance);
   //Serial.print(distance); 
  //Serial.print("cm");
   //Serial.println();
   delay(100);

  if (distance <=30 && distance >20) {
    digitalWrite(motor, HIGH);
    delay(50);
    digitalWrite(motor, LOW);
    digitalWrite(motor, HIGH);
    delay(50);
    digitalWrite(motor, LOW);
    digitalWrite(motor, HIGH);
    delay(50);
    digitalWrite(motor, LOW);
  } else {
    digitalWrite(motor, LOW);
  }
 if (distance <=20 && distance >10) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(buzzer, LOW);
  }
   if (distance <=10 && distance >=0) {
    digitalWrite(buzzer,HIGH);
       digitalWrite(motor,HIGH);
       delay(50);
       digitalWrite(buzzer,LOW);
       digitalWrite(motor,LOW);
       }
      
      else
      { digitalWrite(buzzer, LOW);
        }

  waterVal = analogRead(watersensor);
  //Serial.println(waterVal); 

 if (waterVal > 400){
    digitalWrite(buzzer,HIGH);
    digitalWrite(motor,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    digitalWrite(motor,LOW);
    delay(50);
    digitalWrite(buzzer,HIGH);
    digitalWrite(motor,HIGH); 
 }
 else
      { digitalWrite(buzzer, LOW);
      digitalWrite(motor, LOW);
        }
}

   
