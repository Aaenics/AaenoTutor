#include <IRremote.h>

int RECV_PIN = 4;

//create object for your IR sensor
IRrecv irrecv(RECV_PIN);
//create object for the results to be retrieved
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))//if something is receieved
  {
    unsigned int key = results.value;
    Serial.println(key);
    irrecv.resume(); // Receive the next value
  }
}
