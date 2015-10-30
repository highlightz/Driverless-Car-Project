#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class DirectionGenerator
{
public:
	double process( vector< long > laser_distance )
	{
		return 0.0;
	}
	void genWaypoint( vector< long > laser_distance, double& x_next_in_laser_frame, double& y_next_in_laser_frame )
	{
		x_next_in_laser_frame = 0.0;
		y_next_in_laser_frame = 0.0;
	}
};

DirectionGenerator dg;

// This struct stores the necessary pose information of a ground vehicle.
struct odometry
{
	double x;  // axis of which points to the right
	double y;  // axis of which points to the earth
	double z;  // axis of which points to the front

	double yaw_rad;  // around y axis, positive when turning right horizontally
};

const double pi = 3.141592;
const double v_max = 2.5;  // unit: m/s
const double proportional_gain = 1.0;  // To be tuned to generate reasonable control speed

void control( odometry anOdom,  // Get odometry data from VO by calling getOdom( ) of libviso2_wrapper 
	      /*vector< long > laser_distance,*/  // Get laser scan data from hokuyo_wrapper
	      double& controlAngle,
	      double& controlSpeed )
{
	// Step 1: SHOULD DO THIS
	// Process laser scan data to generate a best traversing angle (unit: degree),
	// which refers to laser coordinate frame
	//double SafeAngleDeg = dg.process( laser_distance );
	double SafeAngleDeg = 20;

	// Step 2: WANT TO DO THIS
	// x_next and y_next (unit:meter) are referenced to laser coordinate frame
	double x_next = 40;
	double y_next = -37;
	//dg.genWaypoint( laser_distance, x_next, y_next );
	double angleToWaypoint = atan2( x_next - anOdom.z, -y_next - anOdom.x );
	double angleToWaypointDeg = angleToWaypoint * 180 / pi;  // Refers to VO frame
	
	// Transforming to laser frame
	double angleFromLaserToWaypoint = angleToWaypointDeg - ( 90 - anOdom.yaw_rad * 180 / pi );

	// Step 3: WOULD DO THIS
	const double weightOfLocal = 0.0;
	controlAngle = weightOfLocal * SafeAngleDeg + ( 1 - weightOfLocal ) * angleFromLaserToWaypoint;

	// Step 4: velocity control planning
	controlSpeed = v_max / sqrt( abs( proportional_gain * controlAngle ) + 1 );
}

int main( )
{
	odometry anOdom;
	anOdom.x = 22;
	anOdom.z = 22;
	anOdom.yaw_rad = pi/4;

	double w, s;
	control( anOdom, w, s );
	cout << w << ", " << s << endl;
	return 0;
}
