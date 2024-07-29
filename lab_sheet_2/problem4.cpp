// Create a class called 'TIME' that has
// - three integer data members for hours, minutes and seconds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format

#include <iostream>
using namespace std;

class TIME {
    int hours, minutes, seconds;

public:
    // Default constructor
    TIME() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    TIME(int hrs, int mins, int sec) : hours(hrs), minutes(mins), seconds(sec) {}

    // Overload > operator
    bool operator>(const TIME& time2) const {
        if (hours > time2.hours) return true;
        if (hours < time2.hours) return false;
        if (minutes > time2.minutes) return true;
        if (minutes < time2.minutes) return false;
        return seconds > time2.seconds;
    }

    // Overload < operator
    bool operator<(const TIME& time2) const {
        if (hours < time2.hours) return true;
        if (hours > time2.hours) return false;
        if (minutes < time2.minutes) return true;
        if (minutes > time2.minutes) return false;
        return seconds < time2.seconds;
    }

    // Overload == operator
    bool operator==(const TIME& time2) const {
        return hours == time2.hours && minutes == time2.minutes && seconds == time2.seconds;
    }

    // Overload + operator
    TIME operator+(const TIME& time2) const {
        TIME time;
        time.seconds = seconds + time2.seconds;
        time.minutes = minutes + time2.minutes + time.seconds / 60;
        time.hours = hours + time2.hours + time.minutes / 60;
        time.seconds %= 60;
        time.minutes %= 60;
        return time;
    }

    // Overload - operator
    TIME operator-(const TIME& time2) const {
        TIME time;
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
        int diff = totalSeconds1 - totalSeconds2;

        if (diff < 0) diff = -diff;
        time.hours = diff / 3600;
        time.minutes = (diff % 3600) / 60;
        time.seconds = diff % 60;

        return time;
    }

    // Display function
    void display() const {
        cout << "TIME : "
             << (hours < 10 ? "0" : "") << hours << " hrs : "
             << (minutes < 10 ? "0" : "") << minutes << " min : "
             << (seconds < 10 ? "0" : "") << seconds << " sec" << endl;
    }
};

int main() {
    int hrs1, min1, sec1;
    int hrs2, min2, sec2;

    cout << "Enter the First time: " << endl;
    cout << "Hours: ";
    cin >> hrs1;
    cout << "Minute: ";
    cin >> min1;
    cout << "Second: ";
    cin >> sec1;

    cout << "Enter the Second time: " << endl;
    cout << "Hours: ";
    cin >> hrs2;
    cout << "Minute: ";
    cin >> min2;
    cout << "Second: ";
    cin >> sec2;

    TIME time1(hrs1, min1, sec1), time2(hrs2, min2, sec2);
    TIME sum = time1 + time2;
    TIME sub = time1 - time2;

    if (time1 > time2)
        cout << "First time is greater than second time " << endl;
    else if (time1 < time2)
        cout << "Second time is greater than first time " << endl;
    else
        cout << "Both the times are equal" << endl;

    cout << "Sum of times: ";
    sum.display();
    cout << "Difference of times: ";
    sub.display();

    return 0;
}
