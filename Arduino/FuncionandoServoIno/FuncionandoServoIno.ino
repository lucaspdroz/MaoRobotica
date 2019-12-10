// Read data from the serial port and set the position of a servomotor
// according to the value
#include <Servo.h>

Servo thumb, pointer, middle, ring, pinky; // Create servo object to control a servo
                                           // Connect yellow servo wire to digital I/O pin 3 (must be PWM)
int val = 0;                               // Data received from the serial port
int maxAng = 130;
int resetAngle = 0;
void setup() {
  // Attach fingers
    thumb.attach(11);
    pointer.attach(7);
    middle.attach(9);
    ring.attach(2);
    pinky.attach(5);
  // ======== || ========

  // 
  Serial.begin(9600);           // Start serial communication at 9600 bps
  
  //  Reset all position
    thumb.write(reset);
    pointer.write(reset);
    middle.write(reset);
    ring.write(reset);
    pinky.write(reset);
}

void loop() {
  if (Serial.available()) {      // If data is available to read,
    val = Serial.parseInt();         // read it and store it in val
  }

  switch(val) {
    case 1:
      likeHand();
      Serial.print("like");
      break;

    case 2:
      hangloose();
//      Serial.print("hangloose");
      break;

    case 3:
       middleFinger();
//            Serial.print("middle");
      break;
    case 4: 
      punch();
      Serial.print("open");
      break;
     case 5: 
      pinky.write(maxAng);
      Serial.print("reset");
      break;
    default:
       reset();
      Serial.print("reset");
      break;
  }
        delay(3000);
}

void reset() {
  thumb.write(0);
  pointer.write(0);
   middle.write(0);
   ring.write(0);
   pinky.write(0);
}

void likeHand() {
  thumb.write(0);
  pointer.write(maxAng);
   middle.write(maxAng);
   ring.write(maxAng);
   pinky.write(maxAng);
}

void middleFinger() {
  thumb.write(maxAng);
  pointer.write(maxAng);
   middle.write(0);
   ring.write(maxAng);
   pinky.write(maxAng);
}

void hangloose() {
  thumb.write(0);
  pointer.write(maxAng);
   middle.write(maxAng);
   ring.write(maxAng);
   pinky.write(0);
}

void rock() {
  thumb.write(maxAng);
  pointer.write(maxAng);
   middle.write(0);
   ring.write(0);
   pinky.write(maxAng);
}

void dosGuri(){
  thumb.write(maxAng);
  pointer.write(0);
  middle.write(0);
  ring.write(maxAng);
  pinky.write(0);
   
}

void punch() {
  thumb.write(maxAng);
  pointer.write(maxAng);
  middle.write(maxAng);
  ring.write(maxAng);
  pinky.write(maxAng);
}
