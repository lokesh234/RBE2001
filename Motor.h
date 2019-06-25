#ifndef LIBRARIES_RBE2001_SRC_ROBOT_MOTOR_H_
#define LIBRARIES_RBE2001_SRC_ROBOT_MOTOR_H_
#include <ESP32Servo.h>
#include <PID_v1.h>

class Motor
{
private:
    //Declaring our motor as a Servo so we can write PWM signals to it
    Servo *motor;
    //Declaring the encoder
    int encoderBPin;
    //Declaring a count for the ISR
    int count;

public:
    //Defining our Motor Constructor that takes in two encoder pins that do our ISR to get our encoder values
    Motor(unsigned char motorPin,
          unsigned char encoderAPin,
          unsigned char encoderBPin);
    //Defining our Motor Destructor
    virtual ~Motor();
    //Defining a function that gives us a encoder value with out ISR
    long getCount();
    //Defining a function that makes the motor turn a certain degreses
    void turnDegrees(int degrees);
    //Defining a functions that makes the motor move with a given speed
    void setSpeed(int speed);
    //Defining a void ISR
    friend void ISR(void *);
    //Defining our Kp, Ki and Kd values
    double Kp = 1.0, Ki = 0.5, Kd = .05;
    //Defining current, output and setPoints for our PID
    double current, output, setPoint;
    //Creating a PID object
    PID pid;
};

#endif /* LIBRARIES_RBE2001_SRC_ROBOT_MOTOR_H_ */
