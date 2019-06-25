/*
 * Drive.cpp
 *
 *  Created on: Sep 28, 2018
 *  	Author: lokesh
 */

#include <robot/Drive.h>

//Defining the constructor from the header file
Drive::Drive(Motor *leftMotor, Motor *rightMotor)
{
    left = leftMotor;
    right = rightMotor;
}

//Initializing the destructor
Drive::~Drive()
{
    // TODO Auto-generated destructor stub
}

//Defining the function from the header file
void Drive::driveStraight(int speed, double distance)
{
    left->current = left->getCount() * 0.07031;
    right->current = right->getCount() * 0.07031;
    left->setPoint = distance;
    right->setPoint = distance;
    left->output = speed;
    right->output = speed;
    if (left->pid.Compute() || right->pid.Compute())
    {
        left->setSpeed(90 + speed);
        right->setSpeed(90 - speed);
    }
}

//Defining the function from the header file
void Drive::drive(int speed1, int speed2, double rightDistance, double leftDistance)
{
    left->current = left->getCount() * 0.07031;
    right->current = right->getCount() * 0.07031;
    left->setPoint = leftDistance;
    right->setPoint = rightDistance;
    left->output = speed1;
    right->output = speed2;
    left->pid.SetTunings(1, 0.5, 0.5);
    right->pid.SetTunings(1.0, 0.5, 0.5);
    if (left->pid.Compute())
    {
        left->setSpeed(90 - speed1);
    }
    if (right->pid.Compute())
    {
        right->setSpeed(90 + speed2);
    }
}
