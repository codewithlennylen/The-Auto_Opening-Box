#include<Servo.h>


const byte servoPin = 9;
const byte trigPin = 2;
const byte echoPin = 3;

Servo myServo;
long duration;
int distance;
byte triggerDistance = 15;
bool triggered = 0;


bool distance_triggered(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;

  if (distance < triggerDistance){
    return 1;  
  }else{
    return 0;  
  }
    
}

void open_box(){
  
  // Servo Position 10 :> Open
  // Servo Position 130:> Close
  Serial.println("Opening Box");
  for (byte pos=130; pos>10; pos--){
    myServo.write(pos);
    delay(10);
  }
  delay(2000);
  close_box();

}

void close_box(){
  
  // Servo Position 10 :> Open
  // Servo Position 130:> Close
  Serial.println("Closing Box");
  for (byte pos=10; pos<130; pos++){
    myServo.write(pos);
    delay(25);
  }

}

void setup() {
  
  Serial.begin(9600);
  
  myServo.attach(servoPin);
  myServo.write(130);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  
  triggered = distance_triggered();

  if (triggered == 1){
    open_box();
  }

  delay(100);

}
