#include <Servo.h>
#define threshold 440
#define unpress_angle 60                          
#define press_angle 0
#define threshold2 600 

Servo myservo;  // create servo object to control a servo

void setup() {          
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(unpress_angle);   
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  int sensorValue = analogRead(A0); // read the value from the sensor
  int sensorValue2=analogRead(A1);
  
  // Display the sensor value on the serial monitor
  Serial.print("A1: ");
  Serial.print(sensorValue2);
  Serial.print("A0: ");
  Serial.println(sensorValue);

  myservo.write(unpress_angle);  // unpress the button
  delay(1);
  
  if(sensorValue2 > threshold2){
    if (sensorValue < threshold) {
    myservo.write(press_angle);  // press the button
    delay(100);  // waits 100ms for the servo to reach the position
    }
  }else{
    if (sensorValue > threshold) {
    myservo.write(press_angle);  // press the button
    delay(100);  // waits 100ms for the servo to reach the position
    }
  }
  
}