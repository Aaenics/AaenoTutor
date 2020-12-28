//This program uses the SN74HC595 shift register to control 8 LEDs in patterns
//Modify the codes for your projects

int datapin = 2; //connected to serial data pin of the SN74HC595
int clockpin = 3;//connected to Serial clock pin of the SN74HC595
int latchpin = 4; //connected to the latch/register clock pin of the SN74HC595

byte LEDS = 0; //variable that holds which LED patterns are currently ON or OFF.
//A Byte of 0 means (8 0s), thus "00000000"

void setup() {
  Serial.begin(9600);
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop() {
  LEDS = 0;
  updateShiftRegister();
  
  /******************************************************************************/
  for (int i = 0; i < 8; i++) {
    bitSet(LEDS, i);    // Set the bit that controls that LED to HIGH
    updateShiftRegister();
    Serial.println(LEDS);

  }
  for (int i = 0; i < 8; i++) {
    bitClear(LEDS, i);    // Set the bit that controls that LED to LOW
    delay(100);
    updateShiftRegister();
    Serial.println(LEDS);
  }
  delay(500);
  
  for (int i = 7; i >= 0; i--) {
    bitSet(LEDS, i);    // Set the bit that controls that LED to HIGH
    delay(50);
    updateShiftRegister();
    Serial.println(LEDS);
  }
  for (int i = 7; i >= 0; i--) {
    bitClear(LEDS, i);    // Set the bit that controls that LED to LOW
    delay(100);
    updateShiftRegister();
    Serial.println(LEDS);
  }
    delay(500);
/**********************************************************************************/
}

void updateShiftRegister() {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, LEDS);
  digitalWrite(latchpin, HIGH);
}
