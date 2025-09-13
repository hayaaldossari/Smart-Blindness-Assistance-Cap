#include <SoftwareSerial.h>

// Pin setup for ultrasonic sensor
const int trigPin = 5;
const int echoPin = 6;

// Software serial for MP3 communication
SoftwareSerial mySoftwareSerial(8, 7); // RX, TX for MP3 module

// Global variables
bool isPlaying = false;  // Playback status flag
unsigned long lastCheckTime = 0;  // Timing for non-blocking delay
const int checkInterval = 100;    // Interval in milliseconds to check distance

// Function declarations
void playMP3Track(int trackNumber);
void stopMP3Playback();
void setVolume(int volumeLevel);
void loopMP3Track(int trackNumber);
int measureDistance();

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize MP3 module
  Serial.println("Initializing MP3 module...");
  setVolume(20); // Set default volume
  Serial.println("MP3 module ready.");
}

void loop() {
  // Use non-blocking timing
  unsigned long currentTime = millis();
  if (currentTime - lastCheckTime >= checkInterval) {
    lastCheckTime = currentTime;

    int distance = measureDistance();  // Measure distance using the ultrasonic sensor

    // Print distance for debugging
    if (distance == -1) {
      Serial.println("Ultrasonic sensor timeout.");
    } else {
      Serial.print("Distance: ");
      Serial.println(distance);
    }

    // Check distance and control sound playback
    if (distance > 0 && distance < 50 && !isPlaying) {
      loopMP3Track(1);  // Loop MP3 track 1
      isPlaying = true;
    } else if (distance >= 50 && isPlaying) {
      stopMP3Playback();
      isPlaying = false;
    }
  }
}

// Function to measure distance using the ultrasonic sensor
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // Timeout after 30ms
  if (duration == 0) return -1;  // Timeout occurred

  return duration * 0.034 / 2;  // Convert duration to distance in cm
}

// Function to play an MP3 track
void playMP3Track(int trackNumber) {
  Serial.print("Playing MP3 Track: ");
  Serial.println(trackNumber);

  mySoftwareSerial.write((uint8_t)0x7E); // Start byte
  mySoftwareSerial.write((uint8_t)0xFF); // Version
  mySoftwareSerial.write((uint8_t)0x06); // Command length
  mySoftwareSerial.write((uint8_t)0x03); // Command (Play track)
  mySoftwareSerial.write((uint8_t)0x00); // Feedback
  mySoftwareSerial.write((uint8_t)((trackNumber >> 8) & 0xFF)); // High byte of track number
  mySoftwareSerial.write((uint8_t)(trackNumber & 0xFF));        // Low byte of track number
  mySoftwareSerial.write((uint8_t)0xEF); // End byte
  delay(100);
}

// Function to stop MP3 playback
void stopMP3Playback() {
  Serial.println("Stopping MP3 Playback.");

  mySoftwareSerial.write((uint8_t)0x7E); // Start byte
  mySoftwareSerial.write((uint8_t)0xFF); // Version
  mySoftwareSerial.write((uint8_t)0x06); // Command length
  mySoftwareSerial.write((uint8_t)0x16); // Command (Stop playback)
  mySoftwareSerial.write((uint8_t)0x00); // Feedback
  mySoftwareSerial.write((uint8_t)0x00); // Data (No data needed)
  mySoftwareSerial.write((uint8_t)0x00); // Data (No data needed)
  mySoftwareSerial.write((uint8_t)0xEF); // End byte
  delay(100);
}

// Function to loop an MP3 track
void loopMP3Track(int trackNumber) {
  Serial.print("Looping MP3 Track: ");
  Serial.println(trackNumber);

  mySoftwareSerial.write((uint8_t)0x7E); // Start byte
  mySoftwareSerial.write((uint8_t)0xFF); // Version
  mySoftwareSerial.write((uint8_t)0x06); // Command length
  mySoftwareSerial.write((uint8_t)0x08); // Command (Loop track)
  mySoftwareSerial.write((uint8_t)0x00); // Feedback
  mySoftwareSerial.write((uint8_t)((trackNumber >> 8) & 0xFF)); // High byte of track number
  mySoftwareSerial.write((uint8_t)(trackNumber & 0xFF));        // Low byte of track number
  mySoftwareSerial.write((uint8_t)0xEF); // End byte
  delay(100);
}

// Function to set the MP3 volume
void setVolume(int volumeLevel) {
  if (volumeLevel < 0) volumeLevel = 0;
  if (volumeLevel > 30) volumeLevel = 30; // Ensure volume is within 0-30 range

  Serial.print("Setting volume to: ");
  Serial.println(volumeLevel);

  mySoftwareSerial.write((uint8_t)0x7E); // Start byte
  mySoftwareSerial.write((uint8_t)0xFF); // Version
  mySoftwareSerial.write((uint8_t)0x06); // Command length
  mySoftwareSerial.write((uint8_t)0x06); // Command (Set volume)
  mySoftwareSerial.write((uint8_t)0x00); // Feedback
  mySoftwareSerial.write((uint8_t)0x00); // High byte of volume (always 0)
  mySoftwareSerial.write((uint8_t)volumeLevel); // Low byte of volume
  mySoftwareSerial.write((uint8_t)0xEF); // End byte
  delay(100);
}


