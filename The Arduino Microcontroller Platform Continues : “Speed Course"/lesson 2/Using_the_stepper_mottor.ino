#include <Stepper.h>

int pot = A0;//potentiometer
int potval; //potentiometer value
int step_speed; //

//this is the number of steps the motor it self will take to complete one revolution
int steps_per_rev = 32;

/*
   the 64:1 gear ratio in the BYJ stepper motor will hence make the
   total steps per revolution 2048, thus 32*60 =2048
*/

//Create Stepper object
Stepper myStepper(steps_per_rev, 8, 9, 10, 11);

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  potval = analogRead(pot);
  //map the potentiometer values to the speed range of the stepper motor
  step_speed = map(potval, 0, 1023, 0, 180);

  Serial.println(step_speed);

  if (step_speed > 0) {
    myStepper.setSpeed(step_speed);

    myStepper.step(1);
  }
}
