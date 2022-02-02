int GreenLEDPin = 12;     // the number of the green led digital pin
int RedLEDPin =  11;      // the number of the red led digital pin
int Button1Pin =  A0;      // the number of the button1 digital pin
int Button2Pin =  A2;      // the number of the button2 digital pin

int Btn1State;
int Btn2State;

void setup() {
  
  Serial.begin(9600);

  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  //pinMode(Button1Pin, INPUT_PULLUP);
  //pinMode(Button2Pin, INPUT_PULLUP);
      
}

void loop() {

  Btn1State = analogRead(Button1Pin);
  Btn2State = analogRead(Button2Pin);

  Serial.print("Btn1 State is ");
  Serial.print(Btn1State);
  Serial.print(" and Btn2 State is ");
  Serial.println(Btn2State);

  if (Btn1State < 100 && Btn2State < 100){
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(RedLEDPin, LOW);
    Serial.println("Green ON");
  }
    else {
      digitalWrite(RedLEDPin, HIGH);
      digitalWrite(GreenLEDPin, LOW);
      Serial.println("Red ON");
    }

  //delay(1000);
}
