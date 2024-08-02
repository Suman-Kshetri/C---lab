//  Program to convert Cartesian coordinate to Polar
#include<iostream>
#include<cmath>
using namespace std;

class Cartesian{
    double x,y;
    public:
    Cartesian(double xcoord=0, double ycoord=0)
    {
        x=xcoord;
        y=ycoord;
    }
    void topolarform(double& radius, double& angle)
    {
        radius=sqrt(x*x+y*y);
        angle= atan2(y,x);
    }
    void display()
    {
        cout<<"Cartesian Coordinates: ( "<<x<<" , "<<y<< " )  \n";
    }
};
class Polar
{
    double radius;
    double angle;
    public:
    Polar(double r,double theta)
    {
        radius=r;
        angle=theta;
    }
    void display(){
        cout<<"Polar Coordinates: ( "<<radius<<" , "<<angle<<" ) \n";
    }
};

int main(){
    double x,y;
    cout<<"Enter the X coordinate: ";
    cin>>x;
    cout<<"Enter the Y coordinate: ";
    cin>>y;
    Cartesian cartesian(x,y);
    double radius,angle;
    cartesian.topolarform(radius,angle);
    Polar polar (radius, angle);
    polar.display();
    return 0;
}