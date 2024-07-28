// Given that an EMPLOYEE class contains following members:
// data members: Employee number, Employee name, Basic, DA, IT, Net Salary
// and print data members. Write a C++ program to read the data of N employee
// and compute Net salary of each employee (DA=52% of Basic and Income Tax
// (IT) =30% of the gross salary)
#include <iostream>
using namespace std;

class EMPLOYEE
{
    int empno;
    char name[50];
    float DA, basic, IT, netsal;

public:
    void getinput()
    {
        cout << "Enter employee no ,name,basic salary";
        cin >> empno >> name >> basic;
    }
    void show()
    {
        cout << "Employee no:" << empno<<endl;
        cout << "Employee name:" << name<<endl;
        cout << "Basic salary:" << basic<<endl;
        cout << "Daily allowance:" << DA<<endl;
        cout << "Income tax:" << IT<<endl;
        cout << "Netsal:" << netsal<<endl;
    }
    void calculate()
    {
        DA = 0.52 * basic;
        netsal = DA + basic;
        IT = 0.30 * netsal;
    }
};
int main()
{
    EMPLOYEE E[100];
    int n, i;

    cout << "How many employee:";
    cin >> n ;
    for(i=1;i<=n;i++){
        E[i].getinput();
        E[i].calculate();
    }
     for (i = 1; i <= n; i++)
    {
        E[i].show();
    }
    return 0;
}