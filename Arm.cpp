#include <robot/Arm.h>

//Defining the constructor from the header file
Arm::Arm(Motor *armMotor)
{
    motor = armMotor;
}

//Initializing the destructor
Arm::~Arm()
{
}
//Defining the function from the header file
void Arm::moveTo(double angle, int armSpeed)
{
    motor->setSpeed(90 + armSpeed);
}
