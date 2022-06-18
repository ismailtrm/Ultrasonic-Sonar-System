// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
    pinMode (34,OUTPUT);
       pinMode (32,OUTPUT);
          pinMode (30,OUTPUT);
}

void led_kontrol(){
  if(distance<=10){
    digitalWrite(30,HIGH); //red
    digitalWrite(32,LOW);  //yellow
    digitalWrite(34,LOW);  //green
  }else if(distance>10&&distance<=20){
    digitalWrite(30,LOW);
    digitalWrite(32,HIGH);
    digitalWrite(34,LOW);;
  }else if(distance>20&&distance<=30){
    digitalWrite(30,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,HIGH);
  }else{
    digitalWrite(30,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

  led_kontrol();
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

    
  
  }

  
 
 
 // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();

   led_kontrol();
  
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");

  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
