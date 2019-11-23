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
  // middle.attach(4);
  // ring.attach(5);
  // pinky.attach(6);
  // ======== || ========

  // 
  Serial.begin(9600);           // Start serial communication at 9600 bps
  
  //  Reset all position
  thumb.write(0);
  pointer.write(0);
  // middle.write(0);
  // ring.write(0);
  // pinky.write(0);
}

void loop() {
  if (Serial.available()) {      // If data is available to read,
    val = Serial.parseInt();         // read it and store it in val
  }

  switch(val) {
    case 1:
      likeHand();
      break;

    case 2:
      hangloose();
      break;

    case 3:
      middleFinger();
      break;
    case 4: 
      openHand();
      break;
    default:
      reset();
      break;
  }

}

void reset() {
  thumb.write(0);
  pointer.write(0);
  // middle.write(0);
  // ring.write(0);
  // pinky.write(0);
}

void likeHand() {
  thumb.write(180);
  pointer.write(0);
  // middle.write(0);
  // ring.write(0);
  // pinky.write(0);
}

void middleFinger() {
  thumb.write(0);
  pointer.write(0);
  // middle.write(180);
  // ring.write(0);
  // pinky.write(0);
}

void hangloose() {
  thumb.write(180);
  pointer.write(0);
  // middle.write(0);
  // ring.write(0);
  // pinky.write(180);
}

void rock() {
  thumb.write(180);
  pointer.write(180);
  // middle.write(0);
  // ring.write(0);
  // pinky.write(180);
}

void openHand() {
  thumb.write(180);
  pointer.write(180);
//  middle.write(180);
//  ring.write(180);
//  pinky.write(180);
}
