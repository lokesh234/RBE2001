#endif /* LIBRARIES_RBE2001_SRC_ROBOT_CLAW_H_ */

/*
 * Claw.cpp
 *
 *  Created on: Oct 12, 2018
 *  	Author: lokesh
 */
#include <robot/Claw.h>
#include <ESP32Servo.h>

//Defining the constructor from the header file
Claw::Claw(unsigned char clawPin)
{
    claw = new Servo();
    claw->attach(clawPin, 1000, 2000);
}

//Initializing the destructor
Claw::~Claw()
{
}

//Defining the function from the header file
void Claw::clawMove(int clawMove)
{
    claw->write(clawMove);
}
