#ifndef LIBRARIES_RBE2001_SRC_ROBOT_ARM_H_
#define LIBRARIES_RBE2001_SRC_ROBOT_ARM_H_
#include "Motor.h"

class Arm
{
    //Arm function header file  to move our Arm
private:
    //We Declare a motor object to use for our armMotor in private so that our to protect our Motors from getting confused
    Motor *motor;

public:
    //Arm Motor constructor
    Arm(Motor *armMotor);
    // Arm Motor Destructor
    virtual ~Arm();
    // Arm function to control the arm with the PID Library
    void moveTo(double angle, int armSpeed);
};

#endif /* LIBRARIES_RBE2001_SRC_ROBOT_ARM_H_ */
