#include <Keyboard.h>
#include <Mouse.h>

/*
 * Mute button for MS Teams
 */

// use this option for Windows and Linux:
char ctrlKey = KEY_LEFT_CTRL;
char shftKey = KEY_LEFT_SHIFT;
char winKey = KEY_LEFT_GUI;

// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 4;        // the number of the pushbutton pin
const int DEBOUNCE_DELAY = 50;   // the debounce time; increase if the output flickers

// Variables will change:
int lastSteadyState = LOW;       // the previous steady state from the input pin
int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
int currentState;                // the current reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled

void setup() {
  // initialize the pushbutton pin as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch/button changed, due to noise or pressing:
  if (currentState != lastFlickerableState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    // save the the last flickerable state
    lastFlickerableState = currentState;
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if(lastSteadyState == HIGH && currentState == LOW) {
      //Keyboard.press(winKey);
      //Keyboard.press('1');
      //delay(100);
      //Keyboard.releaseAll();
      //delay(100);
      // Keyboard.println("You pressed the button ");
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('z');
      delay(100);
      Keyboard.releaseAll();
    }
    // save the the last steady state
    lastSteadyState = currentState;
  // Mouse.move(-1, -1, 0);
  }
}
