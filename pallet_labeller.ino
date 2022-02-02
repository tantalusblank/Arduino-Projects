#include "Keyboard.h"

int PushButtonDigPin = 2  ;    // Pushbutton pin
int CounterResetDigPin = 3  ;    // CounterReset pin
//int TimerResetDigPin = 4  ;    // TimerReset pin
int StackMax1DigPin = 5  ;    // StackMax1 pin
int StackMax2DigPin = 6  ;    // StackMax2 pin
int Line1DigPin = 7  ;    // Line1 pin
int Line2DigPin = 8  ;    // Line2 pin
int Line3DigPin = 9  ;    // Line3 pin

String SerialStatement = "";

String PushButtonStatus = "not pressed";  // variable to store the value coming from the sensor

String KeyboardInputPart1 = "13";
String KeyboardInputPart2 = "2";
String FullKeyboardOutput;

bool PushButtonBool = HIGH;
bool CounterResetBool = HIGH;
//bool TimerResetBool = HIGH;
bool StackMax1Bool = HIGH;
bool StackMax2Bool = HIGH;
bool Line1Bool = HIGH;
bool Line2Bool = HIGH;
bool Line3Bool = HIGH;


void setup() {
      // initialize serial communication
      Serial.begin(9600); 
      Keyboard.begin();
      pinMode(PushButtonDigPin, INPUT_PULLUP);
      pinMode(CounterResetDigPin, INPUT_PULLUP);
      //pinMode(TimerResetDigPin, OUTPUT);
      pinMode(StackMax1DigPin, INPUT_PULLUP);
      pinMode(StackMax2DigPin, INPUT_PULLUP);
      pinMode(Line1DigPin, INPUT_PULLUP);
      pinMode(Line2DigPin, INPUT_PULLUP);
      pinMode(Line3DigPin, INPUT_PULLUP);
}

void loop() {
  
//Read all inputs  
  PushButtonBool = digitalRead(PushButtonDigPin);
  CounterResetBool = digitalRead(CounterResetDigPin);
//  TimerResetBool = digitalRead(TimerResetDigPin);
  StackMax1Bool = digitalRead(StackMax1DigPin);
  StackMax2Bool = digitalRead(StackMax2DigPin);
  Line1Bool = digitalRead(Line1DigPin);
  Line2Bool = digitalRead(Line2DigPin);
  Line3Bool = digitalRead(Line3DigPin);
  
if (StackMax1Bool == LOW){

//Mod string for first stack max selection
  KeyboardInputPart2 = "3";
  }

if (StackMax2Bool == LOW){

//Mod string for second stack max selection
  KeyboardInputPart2 = "2";
  }

if (Line1Bool == LOW){

//Mod string for first line selection
  KeyboardInputPart1 = "11";
  }

if (Line2Bool == LOW){

//Mod string for second line selection
  KeyboardInputPart1 = "12";
  }

if (Line3Bool == LOW){

//Mod string for third line selection
  KeyboardInputPart1 = "13";
  }

//Build the keyboard string from box settings
FullKeyboardOutput = KeyboardInputPart1 + KeyboardInputPart2;

if (CounterResetBool == LOW){

//Output keyboard string to tell Nicelabel to reset the counter
  FullKeyboardOutput = "RESET";
  Serial.println("RESET");
  Keyboard.print(FullKeyboardOutput);
  Keyboard.press(KEY_TAB);
  Keyboard.release(KEY_TAB);
  delay(1000);  
  }

//Check the button is not pushed and set flag
if (PushButtonBool == HIGH){
  PushButtonStatus = "not pressed";
  }

//If button is pushed, output keyboard string
if ((PushButtonBool == LOW) and (PushButtonStatus == "not pressed")){
  PushButtonStatus = "pressed";
  delay(200);
  Serial.print("The button is ");
  Serial.println(PushButtonStatus);
  Keyboard.print(FullKeyboardOutput);
  Keyboard.press(KEY_TAB);
  Keyboard.release(KEY_TAB);
  delay(120000);    
  }
    
SerialStatement = "The button is " + PushButtonStatus + " set to line " + KeyboardInputPart1 + " and max stack " + KeyboardInputPart2;
Serial.println(SerialStatement);
  
}
