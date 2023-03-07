#include <Servo.h>

Servo mark_servo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int pos = 0; 


void setup() {
  mark_servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  /*
  for (pos = 0; pos <= 180; pos += 1) {
    mark_servo.write(pos);
    delay(10);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    mark_servo.write(pos);
    delay(10);
  }
  */

  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  mark_servo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  
}
