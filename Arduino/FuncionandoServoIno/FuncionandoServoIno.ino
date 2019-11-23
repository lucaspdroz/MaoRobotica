// Read data from the serial port and set the position of a servomotor
// according to the value
#include <Servo.h>

Servo thumb, pointer, middle, ring, pinky; // Create servo object to control a servo
                // Connect yellow servo wire to digital I/O pin 3 (must be PWM)
int val = 0;                     // Data received from the serial port

void setup() {
  // Attach fingers
  thumb.attach(3);
  pointer.attach(12);
  middle.attach(4);
  ring.attach(5);
  pinky.attach(6);
  // ======== || ========

  // 
  Serial.begin(9600);           // Start serial communication at 9600 bps
  
  //  Reset all position
  thumb.write(0);
  pointer.write(0);
  middle.write(0);
  ring.write(0);
  pinky.write(0);
}

void loop() {
  if (Serial.available()) {      // If data is available to read,
    val = Serial.read();         // read it and store it in val
  }

  switch(val) {
    case 'a':
      thumb.write(180);
     break;

    case 'b':
      thumb.write(90);
      pointer.write(90);
      break;
    default:
      likeHand();
      break;
  }
              // Set the servo position
  delay(3000);                     // Wait for the servo to get there
}

void likeHand() {
  thumb.write(180);
  pointer.write(0);
}
