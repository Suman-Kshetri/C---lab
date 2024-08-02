#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    char name[20];

public:
    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
    }

    void print()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class InternalExam : public Student
{
protected:
    int marks[7];

public:
    void input()
    {
        Student::input();
        cout << "For Interanl Exam: " << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << "Enter Marks for Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void print()
    {
        Student::print();
        cout << "For Internal Exam: " << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << "Marks for Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }
};

class FinalExam : public Student 
{
protected:
    int marks[7];

public:
    void input()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << "For Final Exam: " << endl;
            cout << "Enter Marks for Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void print()
    {
        cout << "For Final Exam: " << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << "Marks for Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }
};

class Result : public InternalExam, public FinalExam
{
    float avgMarks;

public:
    Result()
    {
        avgMarks = 0;
    }

    void calculate()
    {
        for (int i = 0; i < 7; i++)
        {
            avgMarks += InternalExam::marks[i] + FinalExam::marks[i];
        }
        avgMarks /= 14;
    }

    void display()
    {
        InternalExam::print();
        FinalExam::print();
        cout << "Average Marks: " << avgMarks << endl;
    }
};

int main()
{
    Result r;
    r.InternalExam::input();
    r.FinalExam::input();
    r.calculate();
    r.display();
    return 0;
} 