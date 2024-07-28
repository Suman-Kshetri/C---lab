// To write a program to categorize employees based on designation using 
// static data members.
#include<iostream>
using namespace std;
class employee{
 static int manager_count;
static int engineer_count;
static int emp_count;

char name[89];
char designation;
public: 
void getinput()
{
cout<<"Enter name and designation ,Enter m/M for manager \n e/E for engineer for designation:"<<endl;

cin>>name>>designation;

if(designation=='M' || designation=='m'){
manager_count++;
emp_count++;
}
else if(designation=='e' || designation=='E'){
engineer_count++;
emp_count++;
}
else{
    emp_count++;
}
}
static void showcount()
{
    cout<<"Total number of enginneers="<<engineer_count<<endl;
    cout<<"Total number of manager="<<manager_count<<endl;

    cout<<"Total number of employees="<<emp_count<<endl;

}
};
int employee:: manager_count=0;
int employee::engineer_count=0;
int employee::emp_count=0;
int  main()
{
employee e[100];
int n;
cout<<"Enter the value of working personnels:"<<endl;
cin>>n;
for(int i=0;i<n;i++)
e[i].getinput();

employee::showcount();
    return 0;
}