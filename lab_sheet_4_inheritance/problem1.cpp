// Assume class person stores the Name, Age and ID, class employee
// stores the designation, basic salary, total overtime(hr) in a month
// and hourly rate and class computedSalary stores the total salary of
// the employee. Implement above concept using appropriate inheritance.

//multilevel inheritance

#include<iostream>
using namespace std;

class person{
    protected:
    char name[50];
    int age,id;
    public:
    void input(){
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
        cout<<"ID: ";
        cin>>id;
    }
};
class employee: public person{
    protected:
    char designation[50];
    float basic_salary,hourly_rate,total_overtime;
    int hourly_overtime;
    public:
    void get_input()
    {
        cout<<"Designation: ";
        cin>>designation;
        cout<<"Basic Salary: ";
        cin>>basic_salary;
        cout<<"Total Overtime hour in month: ";
        cin>>hourly_overtime;
        cout<<"Rate of hourly overtime: ";
        cin>>hourly_overtime;
    }
};
class computedsalary : public employee{
    protected:
    float total_salary;
    public:
    void calculate(){
        total_overtime=hourly_overtime*hourly_rate;
        total_salary=basic_salary+total_overtime;
    }
    void output()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Basic Salary: "<<basic_salary<<endl;
        cout<<"Total overtime: "<<total_overtime<<endl;
        cout<<"Total Salary: "<< total_salary<<endl;
    }

};
int main(){
    computedsalary details;
    cout<<"Enter the employee details: "<<endl;
    details.input();
    details.get_input();
    details.calculate();
    cout<<"\nThe details of the employee is: "<<endl;
    details.output();
    return 0;
}