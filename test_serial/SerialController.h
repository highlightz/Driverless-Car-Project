/*
* Updated on Jan. 11, 2016
*/
#ifndef SERIALCONTROLLER_H
#define SERIALCONTROLLER_H

#include "serial.h"

class SerialController
{
private:
    SimpleSerial serial;

public:
    SerialController( unsigned int baudRate = 115200 );

    void writeToPort( const float angle, const float speed );

private:
    void genSend( float normalized_angle, float normalized_speed, char* send );
};

#endif // SERIALCONTROLLER_H
