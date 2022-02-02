#include "Keyboard.h"

int UKPin = A2;    // UK
int EuroPin = A3;    // EURO

String UKStatus = "unplugged";  // variable to store the value coming from the sensor
String EuroStatus = "unplugged";  // variable to store the value coming from the sensor

int UKVal = 0;
int EuroVal = 0;

void setup() {
      // initialize serial communication
      Serial.begin(9600); 
      Keyboard.begin();
}

void loop() {

  delay(250);

  UKVal = analogRead(UKPin);
  EuroVal = analogRead(EuroPin);  
  
  if (UKVal > 320){
    UKStatus = "unplugged";
  }
  
  if ((UKVal < 320) and (UKStatus == "unplugged"))
  {
    UKStatus = "plugged in";
    delay(500);
//    Keyboard.press(KEY_TAB);
//    Keyboard.release(KEY_TAB);
    Keyboard.print("UK CHARGER");
    Keyboard.press(KEY_TAB);
    Keyboard.release(KEY_TAB);    
  }

  if (EuroVal > 320){
    EuroStatus = "unplugged";
  }
  
  if ((EuroVal < 320) and (EuroStatus == "unplugged"))
  {
    EuroStatus = "plugged in";
    delay(500);
//    Keyboard.press(KEY_TAB);
//    Keyboard.release(KEY_TAB);
    Keyboard.print("EU CHARGER");
    Keyboard.press(KEY_TAB);
    Keyboard.release(KEY_TAB);  
  }

  
  Serial.print("UK socket is ");
  Serial.print(UKStatus);
  Serial.print("               ");
  Serial.print("Euro socket is ");
  Serial.println(EuroStatus);


  delay(250);


}
