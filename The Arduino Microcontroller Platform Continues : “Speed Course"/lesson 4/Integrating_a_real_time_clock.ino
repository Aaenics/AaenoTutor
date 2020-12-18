#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <virtuabotixRTC.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Creation of the Real Time Clock Object
//6=SCL pin, 7=SDA pin, 8=Reset pin
virtuabotixRTC myRTC(6, 7, 8);

void setup()  {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();


  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
   //myRTC.setDS1302Time(00, 46, 19, 4, 17, 12, 2020);
  //The time is set once when the program runs
}

void loop()  {
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();

  // Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
  Serial.println(myRTC.dayofweek);

  //start printing on LCD screen
  //Time first
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TIME:");

  lcd.setCursor(6,0);
  lcd.print(myRTC.hours);
  lcd.setCursor(8,0);
  lcd.print(":");
  
  lcd.setCursor(9,0);
  lcd.print(myRTC.minutes);
  lcd.setCursor(11,0);
  lcd.print(":");
  
  lcd.setCursor(12,0);
  lcd.print(myRTC.seconds);

  //Date below it
  lcd.setCursor(0,1);
  lcd.print("DATE:");
  lcd.setCursor(6,1);
  lcd.print(myRTC.dayofmonth);
  lcd.setCursor(8,1);
  lcd.print("/");
  lcd.setCursor(9,1);
  lcd.print(myRTC.month);
  lcd.setCursor(11,1);
  lcd.print("/");
  lcd.setCursor(12,1);
  lcd.print(myRTC.year);
  
  // Delay so the program doesn't print non-stop
  delay( 1000);
  }
