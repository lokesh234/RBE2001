#include "RBE2001.h"
#include "MyRobot.h"
#include "Motor.h"
#include "Arm.h"
#include "Claw.h"

// Left Drive Motor Pin and Encoder Pins
const int leftMotorPin = 2;
const int leftEncoderA = 26;
const int leftEncoderB = 27;

// Right Drive Motor Pin and Encoder Pins
const int rightMotorPin = 18;
const int rightEncoderA = 34;
const int rightEncoderB = 39;

// Arm motor Motor Pin and Arm Encoder Pins
const int armMotorPin = 19;
const int armEncoderA = 33;
const int armEncoderB = 32;

// Claw Pin
const int clawPin = 4;

MyRobot::MyRobot()
{
    pickOrderReceived = false;
    approved = false;
    position = 0;
    angle = material = 0;
    //Setting our motor objects
    leftMotor = new Motor(leftMotorPin, leftEncoderA, leftEncoderB);
    rightMotor = new Motor(rightMotorPin, rightEncoderA, rightEncoderB);
    armMotor = new Motor(armMotorPin, armEncoderA, armEncoderB);
    clawMotor = new Claw(clawPin);
    //Setting our arm object
    arm = new Arm(armMotor);
    //Setting our drive object
    drive = new Drive(leftMotor, rightMotor);

    name = new String("BradRobot");
    myStatus = Ready_for_new_task;
    state = WaitingForPickOrder;
    Position1 = true;
}
//Initializing the funciton
void MyRobot::setPickOrder(int material, int angle, int position)
{
    pickOrderReceived = true;
    this->material = material;
    this->angle = angle;
    this->position = position;
}

//Our Main Loop Function with our state Machine
void MyRobot::loop
{
    if (Position1)
    {
        //There is boolean position 1 for knowing which side of the field to use
        state = WaitingForPickOrder;
        switch (state)
        {
        case WaitingForPickOrder:
            if (pickOrderReceived)
            {
                state = DrivingToRoof;
                //Demonstrating that we can receive the pickOrder from the Wifi
                Serial.println(material);
                Serial.println(angle);
                Serial.println(position);
                clawMotor->clawMove(180);
                // set up to drive to roof knowing the material, angle, and position
            }
            break;
        case DrivingToRoof:
            //Our Drive of the motors to get the necessary navigation
            drive->driveStraight(70, -14);
            drive->drive(70, 13, -15, -8);
            drive->driveStraight(40, 5);
            arm->moveTo(33, position);
            clawMotor->clawMove(0);
            arm->moveTo(30, 43);
            drive->driveStraight(10, 4);
            state = GettingTileFromRoof;
            // drive to roof to get the roof section
            break;
        case GettingTileFromRoof:
            drive->drive(40, 40, 4, -2);
            arm->moveTo(position, 30);
            state = WaitingForRemovalApproval;
            // grab the tile from the roof. If done set state=WaitingForRemovalApproval
            break;
        case WaitingForRemovalApproval:
            if (approved)
            {
                state = RemovingFromRoof;
                approved = false;
            }
            break;
            // wait for the approval button to be pressed
            //Raising the arm to have a nice removal of the solar panels
            arm->moveTo(49, 10);
            drive->driveStraight(-20, 2);
            break;
        case TurningToStorage:
            //Turning to the storage area
            drive->drive(10, 10, 6, 4);
            Break;
            //Driving straight towards the storage area
        case DrivingTowardsStorage:
            drive->driveStraight(40, 4);
            arm->moveTo(2, 20);
            break;
        case PlacingOnStorage:
            //Driving a bit further so we can place the plates
            drive->driveStraight(10, 5.5);
            break;
        case WaitingForStoragePlacementApproval:
            if (approved)
            {
                state = DroppingOnStorage;
                approved = false;
            }
            break;
        case DroppingOnStorage:
            //Dropping the plate on the other side
            clawMotor->clawMove(0);
            break;
        }
    }
    Position1 = false;
}
else
{
    // Driving to the other side of the field
    drive->driveStraight(70, 72);
    state = WaitingForPickOrder;
    switch (state)
    {
    case WaitingForPickOrder:
        if (pickOrderReceived)
        {
            state = DrivingToRoof;
            Serial.println(material);
            Serial.println(angle);
            Serial.println(position);
            clawMotor->clawMove(180);
            // set up to drive to roof knowing the material, angle, and position
        }
        break;
    case DrivingToRoof:
        drive->driveStraight(70, -14);
        drive->drive(70, 13, -15, -8);
        drive->driveStraight(40, 5);
        arm->moveTo(33, position);
        clawMotor->clawMove(0);
        arm->moveTo(30, 43);
        drive->driveStraight(10, 4);
        state = GettingTileFromRoof;
        // drive to roof to get the roof section
        break;
    case GettingTileFromRoof:
        drive->drive(40, 40, 4, -2);
        arm->moveTo(position, 30);
        state = WaitingForRemovalApproval;
        // grab the tile from the roof. If done set state=WaitingForRemovalApproval
        break;
    case WaitingForRemovalApproval:
        if (approved)
        {
            state = RemovingFromRoof;
            approved = false;
        }
        break;
        // wait for the approval button to be pressed
    case RemovingFromRoof:
        //Raising the arm to have a nice removal of the solar panels
        arm->moveTo(49, 10);
        drive->driveStraight(-20, 2);
        break;
    case TurningToStorage:
        //Turning to the storage area
        drive->drive(10, 10, 6, 4);
        Break;
        //Driving straight towards the storage area
    case DrivingTowardsStorage:
        drive->driveStraight(40, 4);
        arm->moveTo(2, 20);
        break;
    case PlacingOnStorage:
        //Driving a bit further so we can place the plates
        drive->driveStraight(10, 5.5);
        break;
    case WaitingForStoragePlacementApproval:
        if (approved)
        {
            state = DroppingOnStorage;
            approved = false;
        }
        break;
    case DroppingOnStorage:
        //Dropping the plate on the other side
        clawMotor->clawMove(0);
        break;
    }
}
}

void MyRobot::setApproved(bool approved)
{
    this->approved = approved;
}

String *MyRobot::getName()
{
    return name;
}
