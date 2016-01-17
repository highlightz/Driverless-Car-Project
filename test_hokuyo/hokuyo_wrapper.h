/************************
* IP: 192.168.0.10
*************************/

#ifndef HOKUYO_WRAPPER_H
#define HOKUYO_WRAPPER_H

// System Includes
#include <vector>
using namespace std;

// OpenCV Includes, in order to provide a simple gui window
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// Urg Library Includes
#include <urg_cpp/Urg_driver.h>
#include <urg_cpp/math_utilities.h>
#include "Connection_information.h"

using namespace qrk;

class hokuyo_wrapper
{
public:
    //hokuyo_wrapper( int argc, char** argv );
    hokuyo_wrapper( );

    bool startHokuyo( );
    bool stopHokuyo( );

    // Set interest scanning radius, the unit is mm.
    // Default value is 10 meters.
    void setInterestRadius( long radius = 10000 );

    bool bufferDistance( );

    vector< long > getDistance( ) const;

    void showDistancePoints( cv::Mat& bkground );
private:
    Connection_information information;   
    Urg_driver urg;

    bool runStatus;
    long interestRadius;

    vector< long > distance_data;
};
#endif  // HOKUYO_WRAPPER_H
