#include <Arduino.h>
#include <robot/Motor.h>
#include <ESP32Servo.h>
#include <PID_v1.h>

//Defining the function from the header file
void IRAM_ATTR ISR(void *arg)
{
    Motor *motorObj = (Motor *)arg;
    if (digitalRead(motorObj->encoderBPin))
    {
        motorObj->count++;
    }
    else
    {
        motorObj->count--;
    }
}

//Defining the constructor from the header file
Motor::Motor(unsigned char motorPin,
             unsigned char encoderAPin,
             unsigned char encoderBPin)
    : pid(&current, &output, &setPoint, Kp, Ki, Kd, DIRECT)
{
    this->encoderBPin = encoderBPin;
    motor = new Servo();
    motor->attach(motorPin, 1000, 2000);
    count = 0;
    pinMode(encoderAPin, INPUT);
    pinMode(encoderBPin, INPUT);
    attachInterruptArg(digitalPinToInterrupt(encoderAPin), (void (*)(void *))ISR, this, RISING);
}

//Defining the function from the header file
long Motor::getCount()
{
    return count;
}
//Defining the function from the header file
void Motor::setSpeed(int speed)
{
    motor->write(speed);
}
//Defining the function from the header file
void Motor::turnDegrees(int degrees)
{

    //Initializing the destructor
    Motor::~Motor(){};
