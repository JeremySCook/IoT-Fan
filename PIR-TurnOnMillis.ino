const int PIRPin = 2;     // the number of the pushbutton pin
const int OutPin =  3;      // the number of the LED pin
int PIRState = 0;         // variable for reading the pushbutton status

unsigned long delayValue = 600000; //10 minutes = 600 seconds = 600000 milliseconds
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
if ((triggerTime > currentTime) {
    triggerTime = 0; //handles when currentTime rolls over to zero every ~50 days
  }
  if ((PIRState == HIGH)&&(currentTime > 5000)) { //waits 5 seconds after power on to trigger
    triggerTime = millis();
    Serial.print("PIR Triggered, triggerTime reset to: "); 
    Serial.print(triggerTime); 
    Serial.print(" Current time: "); 
    Serial.println(currentTime);
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
