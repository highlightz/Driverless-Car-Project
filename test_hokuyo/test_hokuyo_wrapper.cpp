#include "hokuyo_wrapper.h"

#include <iostream>
using namespace std;

int main( )
{
    hokuyo_wrapper laser;
    laser.setInterestRadius( 3000 );
    laser.startHokuyo( );
    cv::Mat laserPoints;
    while(1)
    if ( laser.bufferDistance( ) )
    {
        cout << "Success" << endl;
        laser.showDistancePoints( laserPoints );
        cv::imshow( "laser", laserPoints );
        cv::waitKey( 1 );
        laserPoints.setTo( cv::Scalar( 0 ) );
    }

    laser.stopHokuyo( );
    return 0;
}
