// Program to convert Polar Coordinate to Cartesian.

#include <iostream>
#include <cmath>

using namespace std;

class Polar {
private:
    double radius;      
    double theta;  

public:

    Polar(double r, double angle)  {
        radius=r;
        theta=angle;
    }

    void toCartesian(double& x, double& y) const {
        x = radius * cos(theta);
        y = radius * sin(theta);
    }
};
class Cartesian {
private:
    double x;  
    double y;  

public:
    Cartesian(double xCoord, double yCoord) {
        x=xCoord; y=yCoord; 
        }


    void display(){
        cout << "Cartesian coordinates: (" << x << ", " << y << ")\n";      
        cout << "Cartesian coordinates (integer): (" << static_cast<int>(x) << ", " << static_cast<int>(y) << ")\n";
    }
};

int main() {
    double r, theta;
    cout << "Enter radius : ";
    cin >> r;
    cout << "Enter angle (Degree): ";
    cin >> theta;
    theta=theta*M_PI/180;
    Polar polar(r, theta);
    double x, y;
    polar.toCartesian(x, y);
    Cartesian cartesian(x, y);
    cartesian.display();
    return 0;
}
