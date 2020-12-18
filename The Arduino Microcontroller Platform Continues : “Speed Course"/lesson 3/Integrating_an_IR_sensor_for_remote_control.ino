#include <IRremote.h>

int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

//buttons and corresponding keys on the remote
//change it with the respective buttons and keys of yours

const int RedKey = 12125;
const int GreenKey = 60;
const int OrangeKey = 29549;
const int BlueKey = 42830;

//The LEDs and the pins they are connected to
int Red = 12;
int Green = 11;
int Orange = 10;
int Blue = 9;

//an array storing the current states of all the LEDs
//initially all the LEDs are low, thus = 0
int LedState[4] = {0, 0, 0, 0};

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Orange, OUTPUT);
  pinMode(Blue, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    unsigned int key = results.value;
    Serial.println(key);

    switch (key) {
      //case for when Red button is pressed
      case RedKey:
        if (LedState[0] == 0) {
          digitalWrite(Red, HIGH);
          LedState[0] = 1;
        }
        else {
          digitalWrite(Red, LOW);
          LedState[0] = 0;
        }
        break;

      //case for when Green button is pressed
      case GreenKey:
        if (LedState[1] == 0) {
          digitalWrite(Green, HIGH);
          LedState[1] = 1;
        }
        else {
          digitalWrite(Green, LOW);
          LedState[1] = 0;
        }
        break;

      //case for when Orange button is pressed
      case OrangeKey:
        if (LedState[2] == 0) {
          digitalWrite(Orange, HIGH);
          LedState[2] = 1;
        }
        else {
          digitalWrite(Orange, LOW);
          LedState[2] = 0;
        }
        break;

      //case for when Blue button is pressed
      case BlueKey:
        if (LedState[3] == 0) {
          digitalWrite(Blue, HIGH);
          LedState[3] = 1;
        }
        else {
          digitalWrite(Blue, LOW);
          LedState[3] = 0;
        }
        break;

    }
    delay(500);
    irrecv.resume(); // Receive the next value
  }

}
