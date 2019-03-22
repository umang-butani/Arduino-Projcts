/*
SparkFun Inventor's Kit 
Example sketch 08

SINGLE SERVO

  Sweep a servo back and forth through its full range of motion.

  A "servo", short for servomotor, is a motor that includes 
  feedback circuitry that allows it to be commanded to move to
  specific positions. This one is very small, but larger servos
  are used extensively in robotics to control mechanical arms,
  hands, etc. You could use it to make a (tiny) robot arm,
  aircraft control surface, or anywhere something needs to be
  moved to specific positions.

Hardware connections:

  The servo has a cable attached to it with three wires.
  Because the cable ends in a socket, you can use jumper wires
  to connect between the Arduino and the servo. Just plug the
  jumper wires directly into the socket.

  Connect the RED wire (power) to 5 Volts (5V)
  Connect the WHITE wire (signal) to digital pin 9
  Connect the BLACK wire (ground) to ground (GND)

  Note that servos can use a lot of power, which can cause your
  Arduino to reset or behave erratically. If you're using large
  servos or many of them, it's best to provide them with their
  own separate 5V supply. See this Arduino Forum thread for info:
  http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1239464763

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// If we had to write a sketch to control a servo from scratch,
// it would be a lot of work. Fortunately, others have done the
// hard work for you. We're going to include a "library"
// that has the functions needed to drive servos.

// A library is an set of additional functions you can add to
// your sketch. Numerous libraries are available for many uses,
// see http://arduino.cc/en/Reference/Libraries for information
// on the standard libraries, and Google for others. When you're
// using a new part, chances are someone has written a library
// for it.

#include <Servo.h>  // servo library

Servo servo1;  // servo control object
Servo servo2;

void setup()
{
  servo1.attach(9);
  servo2.attach(10);
}


void loop()
{
  int position;

 // servo2.write(50);    // Tell servo to go to 90 degrees
  //delay(1000);         // Pause to get it time to move
   //servo2.write(160);   // Tell servo to go to 180 degrees
  //delay(1000);         // Pause to get it time to move
  //servo1.write(0);     // Tell servo to go to 0 degrees
  //delay(1000);         // Pause to get it time to move

  // Change position at a slower speed:

  // To slow down the servo's motion, we'll use a for() loop
  // to give it a bunch of intermediate positions, with 20ms
  // delays between them. You can change the step size to make 
  // the servo slow down or speed up. Note that the servo can't
  // move faster than its full speed, and you won't be able
  // to update it any faster than every 20ms.

  // Tell servo to go to 180 degrees, stepping by two degrees

  for(position = 0; position < 160; position +=1)
  {
    servo1.write(position);  // Move to next position
    delay(10);               // Short pause to allow it to move
     for(position = 50; position < 160; position +=1)
     {
        servo2.write(position);  // Move to next position
         delay(10);               // Short pause to allow it to move
     }
  }
  // Tell servo to go to 0 degrees, stepping by one degree
  for(position = 160; position >= 0; position -= 1)
  {                                
    servo1.write(position);  // Move to next position
    delay(10);               // Short pause to allow it to move
  }
}

