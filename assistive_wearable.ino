#include <SoftwareSerial.h>

SoftwareSerial BTSerial(6, 7); // RX, TX pins for HC-01 Bluetooth module
int buzzerPin = 11; // Pin connected to the buzzer
int buzzerDuration = 1000; // Duration for the buzzer to stay ON (in milliseconds)

void setup() {
  // Start serial communication with Bluetooth module
  BTSerial.begin(9600);  
  // Set buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  // Start Serial Monitor (for debugging purposes)
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read from Bluetooth
  if (BTSerial.available()) {
    char receivedChar = BTSerial.read(); // Read the incoming character
    
    // Display received data on Serial Monitor (optional)
    Serial.print("Received: ");
    Serial.println(receivedChar);
    
    // Check if the received character is 'L' or 'l'
    if (receivedChar == 'L' || receivedChar == 'l') {
      digitalWrite(buzzerPin, HIGH); // Turn buzzer ON
      Serial.println("Buzzer ON");
      
      // Keep the buzzer ON for a longer duration
      delay(buzzerDuration); // Wait for buzzerDuration milliseconds
      
      digitalWrite(buzzerPin, LOW); // Turn buzzer OFF after the delay
      Serial.println("Buzzer OFF");
    } else {
      digitalWrite(buzzerPin, LOW); // Turn buzzer OFF immediately if other character
      Serial.println("Buzzer OFF");
    }
  }
}