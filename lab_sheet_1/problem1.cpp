// Create a 'DISTANCE' class with :
// - feet and inches as data members
// - member function to input distance
// - member function to output distance
// - member function to add two distance objects
// Write a main function to create objects of DISTANCE class. Input two distances
// and
// output the sum

#include<iostream>

using namespace std;

class DISTANCE{
    float feet;
    float inches;
    public:
    void input_distance(){
        cout<<"Enter the feet:"<<endl;
        cin>>feet;
        cout<<"Enter the inches:"<<endl;
        cin>>inches;
    }
    void output_distance(){
        cout<<feet<<" feet "<<inches<<" inches."<<endl;
    }
void sum_of_distance(DISTANCE& n1,DISTANCE& n2)
{
    feet=n1.feet+n2.feet;
    inches=n1.inches+n2.inches;
    while(inches>=12)
    {
        feet=feet+1;
        inches=inches-12;
        
    }
    cout<<feet<<" feet and "<<inches<<" inches.";

}

};
int main()
{
    DISTANCE d1,d2,sum;
    d1.input_distance();
    d2.input_distance();
    cout<<"The first and second distance are: "<<endl;
    d1.output_distance();
    d2.output_distance();
    cout<<"The sum of two distances is: "<<endl;
    sum.sum_of_distance(d1,d2);
    return 0;
}