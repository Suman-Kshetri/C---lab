// Overload >> and << operators to input and display time.

#include<iostream>
#include<iomanip>
using namespace std;

class TIME {
    int hrs,min,sec;
    public:
    friend istream& operator >> (istream& input, TIME& time);
    friend ostream& operator << (ostream& output, TIME& time);
};
istream& operator >> (istream& input,TIME& time)
{
        input>>time.hrs>>time.min>>time.sec;
}
ostream& operator << (ostream& output, TIME& time)
{
    output<<setw(2) << setfill('0') <<time.hrs<<" hrs : "<<setw(2) << setfill('0') <<time.min<<" min : "<<setw(2) << setfill('0') <<time.sec<<" sec";
}
int main(){
    TIME time;
    cout<<"Enter the time :";
    cin>>time;
    cout<<"The time is: "<< time;
    return 0;
}