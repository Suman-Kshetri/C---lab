// Create a class called 'TIME' that has
// - three integer data members for hours, minutes and seconds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format

#include<iostream>
using namespace std;

class TIME{
    int hours,minute,second;
    public:
    TIME(){
        hours=0;
        minute=0;
        second=0;
    }
    TIME(int hrs,int mins,int sec)
    {
        hours=hrs;
        minute=mins;
        second=sec;
    }
    TIME operator + (TIME time2)
    {
        TIME time;
        time.hours=hours+time2.hours;
        time.minute=minute+time2.minute;
        time.second=second+time2.second;
        while(time.second>=60)
        {
            time.minute+=1;
            time.second-=60;
        }
        while(time.minute>=60)
        {
            time.minute+=1;
            time.minute-=60;
        }
        return time;
    }
    TIME operator - (TIME time2)
    {
        TIME time;
        time.hours=hours-time2.hours;
        time.minute=minute-time2.minute;
        time.second=second-time2.second;
        if(time.hours<0)
        time.hours=(-1)*time.hours;
        else if(time.minute<0)
        time.minute=(-1)*time.minute;
        else if(time.second<0)
        time.second=(-1)*time.second;
        return time;
    }
    void display()
    {
        cout<<"TIME : "<<hours<<" hrs : "<<minute<<" min : "<<second<< " sec "<<endl;
    }
    
    bool operator > (TIME time2)
{
    
    if(hours>time2.hours)
    return true;
    else if(minute>time2.minute)
    return true;
    else if(second>time2.second)
    return true;
}

    bool operator < (TIME time2)
{
    
    if(hours<time2.hours)
    return true;
    else if(minute<time2.minute)
    return true;
    else if(second<time2.second)
    return true;
}

    bool operator == (TIME time2)
{
    
    if(hours==time2.hours)
    return true;
    else if(minute==time2.minute)
    return true;
    else if(second==time2.second)
    return true;
}
};


int main(){
    
    int hrs1,min1,sec1;
    int hrs2,min2,sec2;
    cout<<"Enter the First time: "<<endl;
    cout<<"Hours: ";
    cin>>hrs1;
    cout<<"Minute: ";
    cin>>min1;
    cout<<"SECOND: ";
    cin>>sec1;
    cout<<"Enter the Second time: "<<endl;
    cout<<"Hours: ";
    cin>>hrs2;
    cout<<"Minute: ";
    cin>>min2;
    cout<<"SECOND: ";
    cin>>sec2;
    TIME time1(hrs1,min1,sec1),time2(hrs2,min2,sec2),sum,sub;
    if(time1>time2)
        cout<<"First time is greater than second time "<<endl;
    else if(time1<time2)
        cout<<"Second time is greater than first time "<<endl;
    else if(time1==time2)
        cout<<"Both the time are eqaull";
    sum=time1+time2;
    sum.display();
    sub=time1-time2;
    sub.display();
    return 0;
}