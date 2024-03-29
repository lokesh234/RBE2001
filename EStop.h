/*
 * EStop.h
 *
 *  Created on: Jul 11, 2018
 *  	Author: hephaestus
 */

#ifndef LIBRARIES_RBE2001_SRC_COMMANDS_ESTOP_H_
#define LIBRARIES_RBE2001_SRC_COMMANDS_ESTOP_H_
#include <robot/MyRobot.h>
#include <SimplePacketComs.h>
class EStop : public PacketEventAbstract
{
    MyRobot *robotPointer;

public:
    EStop(MyRobot *robot) : PacketEventAbstract(1989) // Address of this event
    {
        robotPointer = robot;
    }
    ~EStop() {}
    //User function to be called when a packet comes in
    // Buffer contains data from the packet coming in at the start of the function
    // User data is written into the buffer to send it back
    void event(float *buffer);
};

#endif /* LIBRARIES_RBE2001_SRC_COMMANDS_ESTOP_H_ */
