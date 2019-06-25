//A robot class to share data between listeners
#include "Arduino.h"
#include "RBE2001.h"
#if !defined(MYROBOT)
#define MYROBOT

#include "Drive.h"
#include "Arm.h"
#include "Claw.h"

class MyRobot
{
private:
    String *name;
    Drive *drive;
    Arm *arm;
    bool pickOrderReceived;
    int material, angle, position;
    bool approved;

public:
    enum RobotStatus myStatus;
    enum RobotState
    {
        WaitingForPickOrder,
        DrivingToRoof,
        GettingTileFromRoof,
        WaitingForRemovalApproval,
        RemovingFromRoof,
        TurningToStorage,
        DrivingTowardsStorage,
        PlacingOnStorage,
        WaitingForStoragePlacementApproval,
        DroppingOnStorage
    } state;
    bool Position1;
    MyRobot();
    //Creating a function that intializes the material,angle, and position
    void setPickOrder(int material, int angle, int position);
    //Declaring our loop function
    void loop();
    //Setting a name for the Wifi
    String *getName();
    //Declaring our Approved function
    void setApproved(bool approved);
    //Creating pointers for different motors
    Motor *leftMotor;
    Motor *rightMotor;
    Motor *armMotor;
    //Declaring the Claw
    Claw *clawMotor;
};

#endif
