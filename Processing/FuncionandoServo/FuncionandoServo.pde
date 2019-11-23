
import processing.serial.*;
Serial port;                      // Create object from Serial class
float mx = 0.0;
int soma;
int counter;

void setup() { 
  size(200, 200); 
  noStroke(); 
  frameRate(10); 
  // Open the port that the board is connected to and use the same speed (9600 bps) 
  //port = new Serial(this, 9600);  // Comment this line if it's not the correct port
  // If the above does not work uncomment the lines below to choose the correct port
  // List all the available serial ports, preceded by their index number:
  printArray(Serial.list());
  // Instead of 0 input the index number of the port you are using:
  port = new Serial(this, Serial.list()[0], 9600);
} 

void draw() {   
  int option = 4;
  
  if(counter % 2 == 0) {
     option = 1; 
  } else if(counter % 3 == 0){
    option = 2;
  } else {
    option = 4;
  }
  println("Option: "+ option);
  //print(angle + " ");                       // Print the current angle (debug)
  port.write(String.valueOf(option));                       // Write the angle to the serial port
  delay(3000);
  
  counter++;
}
