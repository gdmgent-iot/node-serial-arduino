#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.println("Hello from Arduino");
  
}

void loop() {
  while(Serial.available() == 0) {
     // do nothing
  }

  // hoek uitlezen
  String strAngle = Serial.readString(); // \r \n --> trim
  strAngle.trim();
  int angle = strAngle.toInt();
  
  myservo.write(angle);
  delay(500);
}

void turn() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
