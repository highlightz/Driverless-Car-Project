/*
* Updated on Jan. 11, 2016
*/
#include <iostream>
#include "SerialController.h"

using namespace std;
using namespace boost;


int main( )
{
    SerialController controller( 115200 );

    float angle = 0.5f, speed = 0.1f;
    cout << "angle -- speed: " << endl;
    while ( cin >> angle >> speed )
    {
        controller.writeToPort( angle, speed );
        cout << "angle - speed: " << endl;
    }
    return 0;
}
