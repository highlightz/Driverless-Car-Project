/*
* Updated on jan. 11, 2016
*/
#include "SerialController.h"

// Constructor
SerialController::SerialController( unsigned int baudRate )
    : serial( "/dev/ttyUSB0", baudRate )
{
}

// Control Interface
void SerialController::writeToPort( const float angle, const float speed )
{
    // Speed: Limit and Normalize
    const float maxSpeed = 2.4f;
    float limitedSpeed = speed;
    if ( speed > maxSpeed )
    {
        limitedSpeed = maxSpeed;
    }
    if ( speed < -maxSpeed )
    {
        limitedSpeed = -maxSpeed;
    }
    float normalizedSpeed = limitedSpeed / maxSpeed;

    // Angle: Limit and Normalize
    const float maxAngle = 25.0f;
    float limitedAngle = angle;
    if ( angle > maxAngle )
    {
        limitedAngle = maxAngle;
    }
    if ( angle < -maxAngle )
    {
        limitedAngle = -maxAngle;
    }
    float normalizedAngle = limitedAngle / maxAngle;

    // Generate low-layer instructions
    char send[10];
    genSend( normalizedAngle, normalizedSpeed, send );

    // Send to port
    serial.writeString( send );
}

// Protocols
void SerialController::genSend( float normalized_angle, float normalized_speed, char* send )
{
    send[0] = 0xff;
    send[1] = 0xfe;

    // Speed control
    const int *p = (int *)&normalized_speed;
    send[5] = (*p>>24)&0xff;
    send[4] = (*p>>16)&0xff;
    send[3] = (*p>>8)&0xff;
    send[2] = (*p>>0)&0xff;

    // Angle control
    p = (int *)&normalized_angle;
    send[9] = (*p>>24)&0xff;
    send[8] = (*p>>16)&0xff;
    send[7] = (*p>>8)&0xff;
    send[6] = (*p>>0)&0xff;
}
