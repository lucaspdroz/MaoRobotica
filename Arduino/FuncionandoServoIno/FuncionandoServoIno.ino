#include <Servo.h>

// Read data from the serial port and set the position of a servomotor
// according to the value

Servo thumb, pointer, middle, ring, pinky; // Create servo object to control a servo
                                           // Connect yellow servo wire to digital I/O pin 3 (must be PWM)
int val = 0;                               // Data received from the serial port
int maxAng = 130;
int middleAng = 150;
int resetAngle = 0;

void setup() {
  // Attach fingers
    thumb.attach(13);
    pointer.attach(9);
    middle.attach(7);
    ring.attach(4);
    pinky.attach(11);
  // ======== || ========

  // 
  Serial.begin(9600);           // Start serial communication at 9600 bps
  
  //  Reset all position
    thumb.write(resetAngle);
    pointer.write(resetAngle);
    middle.write(resetAngle);
    ring.write(resetAngle);
    pinky.write(resetAngle);
}

void loop() {
  if (Serial.available()) {      // If data is available to read,
    val = Serial.parseInt();         // read it and store it in val
  } else {
    val = 0;
  }

  switch(val) {
    case 1:
      likeHand();
      Serial.print("like");
      break;

    case 2:
      hangloose();
      Serial.print("hangloose");
      break;

    case 3:
      middleFinger();
      Serial.print("middle");
      break;
      
    case 4: 
      punch();
      Serial.print("open");
      break;
      
     case 5: 
      middleFinger();
      Serial.print("reset");
      break;
      
    case 6:
      dosGuri();
      Serial.print("dosGuri");
      break;
    
    case 7:
      gun();
      Serial.print("gun");
      break;
      
     case 8:
       victory();
       Serial.print('Victory');
       break;
     
    default:
      reset();
      Serial.print("reset");
      break;
  }
        delay(3000);
}

void reset() {
  thumb.write(resetAngle);
  pointer.write(resetAngle);
  middle.write(resetAngle);
  ring.write(resetAngle);
  pinky.write(resetAngle);
}

void likeHand() {
  thumb.write(0);
  pointer.write(maxAng);
   middle.write(middleAng);
   ring.write(maxAng);
   pinky.write(maxAng);
}

void middleFinger() {
  thumb.write(maxAng);
  pointer.write(maxAng);
   middle.write(resetAngle);
   ring.write(maxAng);
   pinky.write(maxAng);
}

void hangloose() {
  thumb.write(resetAngle);
  pointer.write(maxAng);
   middle.write(middleAng);
   ring.write(maxAng);
   pinky.write(resetAngle);
}

void rock() {
  thumb.write(maxAng);
  pointer.write(maxAng);
   middle.write(resetAngle);
   ring.write(resetAngle);
   pinky.write(maxAng);
}

void dosGuri(){
  thumb.write(maxAng);
  pointer.write(resetAngle);
  middle.write(resetAngle);
  ring.write(maxAng);
  pinky.write(resetAngle);
   
}

void gun() {
  thumb.write(resetAngle);
  pointer.write(resetAngle);
  middle.write(middleAng);
  ring.write(maxAng);
  pinky.write(maxAng);
}

void victory() {
  thumb.write(maxAng);
  pointer.write(resetAngle);
  middle.write(resetAngle);
  ring.write(maxAng);
  pinky.write(maxAng);
}

void punch() {
  thumb.write(maxAng);
  pointer.write(maxAng);
  middle.write(middleAng);
  ring.write(maxAng);
  pinky.write(maxAng);
}
