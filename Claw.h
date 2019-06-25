/*
 * claw.h
 *
 *  Created on: Oct 12, 2018
 *  	Author: lokesh
 */

#ifndef LIBRARIES_RBE2001_SRC_ROBOT_CLAW_H_
#define LIBRARIES_RBE2001_SRC_ROBOT_CLAW_H_
#include <ESP32Servo.h>

class Claw
{
private:
    //We declare our claw as a servo in the private class so it get protected from the different Servos
    Servo *claw;

public:
    //Creating a constructor for the claw
    Claw(unsigned char clawPin);
    //Creating a destructor for the claw
    virtual ~Claw();
    //Creating a functions to move the claw for a specific number of degrees
    void clawMove(int clawMove);
};
