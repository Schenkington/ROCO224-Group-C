#include <Servo.h>

Servo servo0; //Servo setup
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;


void setup() {
  pinMode(1, OUTPUT); //Pins for H-bridge control
  pinMode(2, OUTPUT);
  
  servo0.attach(11); //Pins for servos
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(6);
  servo4.attach(5);
  servo5.attach(3);
  
  servo0.write(95); //Sets servos in initial position
  servo1.write(180);
  servo2.write(0);
  servo3.write(90);
  servo4.write(85);
  servo5.write(0);
}

void loop() {
  delay(5000);  
  servo3.write(20); //Begins move to pick up point
  delay(1000);
  servo1.write(160);
  delay(1000);
  servo3.write(25); //Ends move to pick up point
  digitalWrite(1, HIGH); //Runs H-bridge 
  digitalWrite(2, LOW);
  delay(2000);
  servo1.write(180); //Begins move to aim point
  delay(10);
  servo3.write(90); //Ends move to aim point
  delay(10); 
  digitalWrite(1, LOW); //Runs H-bridge
  digitalWrite(2, HIGH);
  delay(2000);
  servo5.write(180); //Pushes dart
  delay(2000);
  servo5.write(0); //Resets pusher
  digitalWrite(1, LOW); //Turns off motors
  delay(5000);
}
