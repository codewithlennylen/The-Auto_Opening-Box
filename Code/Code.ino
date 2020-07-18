#include<Servo.h>


// Define pins that the Servo and Ultrasonic Sensor are connected to
const byte servoPin = 9;
const byte trigPin = 2;
const byte echoPin = 3;

// Define Variables that will be used throughout the program
Servo myServo;
int openDelay = 2000; // time in milliseconds that the box will remain open
long duration;
int distance;
byte triggerDistance = 15; // If an obstacle's distance to the sensor is less than this value, Box opens
bool triggered = 0; // Track the state of the Sensor; triggered or not?


bool distance_triggered(){
  /*
   * This Function simply checks the distance. i.e the distance of an obstacle from the ultrasonic sensor
   * If the distance is less than the triggerDistance, the triggered boolean value is set to 1
   */
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance - This code returns distance in centimeters
  distance = duration*0.034/2; 

  if (distance < triggerDistance){
    return 1;  
  }else{
    return 0;  
  }
    
}

void open_box(){
  /*
   * This function simply opens the box by constantly decreasing the pos variable, which corresponds
   * to the servo's position
   */
  
  // Servo Position 10 :> Open
  // Servo Position 130:> Close
  Serial.println("Opening Box");
  for (byte pos=130; pos>10; pos--){
    myServo.write(pos);
    delay(10);
  }
  delay(openDelay);
  close_box(); // Close the box after the Delay (openDelay)

}

void close_box(){
  /*
   * This function simply closes the box by constantly increasing the pos variable, which corresponds
   * to the servo's position
   */
     
  // Servo Position 10 :> Open
  // Servo Position 130:> Close
  Serial.println("Closing Box");
  for (byte pos=10; pos<130; pos++){
    myServo.write(pos);
    delay(25);
  }

}

void setup() {

  // Start Serial monitor
  Serial.begin(9600);
  
  myServo.attach(servoPin);
  myServo.write(130); // Ensure the box is closed
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
