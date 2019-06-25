/*
 * Drive.h
 *
 *  Created on: Oct 12, 2018
 *  	Author: lokesh
 */

#ifndef LIBRARIES_RBE2001_SRC_ROBOT_DRIVE_H_
#define LIBRARIES_RBE2001_SRC_ROBOT_DRIVE_H_
#include "Motor.h"
#include "PID_v1.h"

class Drive
{
private:
    Motor *left;
    Motor *right;

public:
    Drive(Motor *leftMotor, Motor *rightMotor);
    virtual ~Drive();
    void driveStraight(int speed, double distance);
    void drive(int speed1, int speed2, double rightDistance, double leftDistance);
};

#endif /* LIBRARIES_RBE2001_SRC_ROBOT_DRIVE_H_ */
