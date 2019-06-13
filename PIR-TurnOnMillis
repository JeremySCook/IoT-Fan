const int PIRPin = 2;     // the number of the pushbutton pin
const int OutPin =  3;      // the number of the LED pin
int PIRState = 0;         // variable for reading the pushbutton status

unsigned long delayValue = 1800000; //30 minutes = 1800 seconds = 1,800,000
unsigned long triggerTime = delayValue;  //initially set to delayValue, so doesn't come on automatically
unsigned long currentTime = millis();


void setup() {
  // initialize the LED pin as an output:
  pinMode(PIRPin, INPUT);
  // initialize the pushbutton pin as an input:
  pinMode(OutPin, OUTPUT);
  Serial.begin(9600); //begin serial
}

void loop() {
  // read the state of the pushbutton value:
  PIRState = digitalRead(PIRPin);
  currentTime = millis();
  //if (millis() == 0) {
    //triggerTime = delayValue; //keeps off when millis() rolls over in ~49 days
  //}
  if (PIRState == HIGH) {
    triggerTime = millis();
    Serial.print("PIR Triggered, triggerTime reset to: "); Serial.print(triggerTime); Serial.print(" Current time: "); Serial.println(currentTime);
  }
  if ((triggerTime > currentTime) && OutPin == HIGH) {
    triggerTime = 0;
  }
  if ((currentTime - triggerTime) < delayValue) { //10 minutes
    digitalWrite(OutPin, HIGH);
    Serial.println("Switch Active");
    delay(100);
  }
  if ((currentTime - triggerTime) >= delayValue) { //no movement for 10 minutes
    digitalWrite(OutPin, LOW);
    Serial.println("Switch Inactive");
    delay(100);
  }
}
