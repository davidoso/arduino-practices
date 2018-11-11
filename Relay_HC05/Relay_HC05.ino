#include <SoftwareSerial.h>

// Set bluetooth RX and TX pins
SoftwareSerial bluetooth(10, 11);

// Set Arduino pin to transmit signal to relay
byte relayPin = 7;


void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  String state;
  
  if(bluetooth.available()) {
    state = bluetooth.readString();
    Serial.println(state);
    
    if(state == "off") {
      digitalWrite(relayPin, LOW);
      Serial.print("LED turned off\n");
    }
    
    if(state == "on") {
      digitalWrite(relayPin, HIGH);
      Serial.print("LED turned on\n");
    }
  }
}
