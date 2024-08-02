// 4. class Date
// {
//     int day, month, year;

// public:
//     Date();
//     ~Date();
//     void display(); // displays the date
//     Date get();     // accesses the date members
//     void set();     // sets the date members
// };
// class Time
// {
//     int hour;
//     int minute;
//     int second;

// public:
//     Time();
//     ~Time();
//     void display(); // displays the time
//     Time get();     // accesses the time members
//     void set();     // sets the time members
// };
// class DateAndTime : public Date, public Time
// {
// public:
//     void display(); // prints date and time
// };
// a.Define an instance object of class DateTime called Watch.
// b.Write a main () function that would initialize the values through the constructorfunctions, and then allows them to be reset through the set () functions. Be sure anddisplay the results following the constructor before you use the set functions.
// c.Through the use of the display () function, the time and date are to be displayed. Notethat the display () functions in all three

#include <iostream>
using namespace std;
class Date
{
    int day, month, year;

public:
    Date(int y, int m, int d)
    {
        day = d;
        month = m;
        year = y;

        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            cout << "Invalid date" << endl;
            exit(1);
        }
    }

    ~Date()
    {
        cout << "Date object destroyed" << endl;
    }
    void display()
    {
        cout << year << "/" << month << "/" << day << endl;
    }
    // Date get();
    void set()
    {
        cout << "Enter date (yyyy mm dd): ";
        cin >> year >> month >> day;

        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            cout << "Invalid date" << endl;
            exit(1);
        }
    }
};

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        {
            cout << "Invalid time" << endl;
            exit(1);
        }
    }
    ~Time()
    {
        cout << "Time object destroyed" << endl;
    }
    void display()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    // Time get();
    void set()
    {
        cout << "Enter time (hh mm ss) 24 hr format: ";
        cin >> hour >> minute >> second;
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        {
            cout << "Invalid time" << endl;
            exit(1);
        }
    }
};

class DateAndTime : public Date, public Time
{
public:
    DateAndTime(int y, int m, int d, int h, int min, int s) : Date(y, m, d), Time(h, min, s)
    {
    }
    void display()
    {
        Date::display();
        Time::display();
    }
};

int main()
{
    DateAndTime Watch(2021, 10, 10, 20, 12, 24);
    Watch.display();
    Watch.Date::set();
    Watch.Time::set();
    Watch.display();
    return 0;
}