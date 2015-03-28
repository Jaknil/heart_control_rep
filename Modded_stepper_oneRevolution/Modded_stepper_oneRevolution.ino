
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */
int rpm =8; //8 is max
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // set the speed at rpm:

  myStepper.setSpeed(rpm);
  Serial.println(rpm);
  
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  myStepper.step(stepsPerRevolution/8);
  delay(500);
  
  rpm--;
  if (rpm<1) rpm=8;
  Serial.println(rpm);
  myStepper.setSpeed(rpm);
  /*
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
  */
}

