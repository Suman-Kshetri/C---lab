// To write a C++ program to swap two private data members using friend 
// functions.
#include<iostream>
using namespace std;

class numbers{
    int num;
    public:
    
    friend void swap(numbers &,numbers &);

    void get_data(void){
        cin>>num;
    }
    void output(numbers a, numbers b)
    {
        cout<<"A = "<<a.num<<" and  B = "<<b.num<<endl;
    }
};
void swap(numbers &a,numbers &b)
{
    int temp=0;
    temp=a.num;
    a.num=b.num;
    b.num=temp;
}
int main(){
    numbers num1,num2, before_swap,after_swap;
    cout<<"Enter the first number: ";
    num1.get_data();
    cout<<"Enter the second number:  ";
    num2.get_data();
    cout<<"Before Swap: ";
    before_swap.output(num1,num2);
    swap(num1,num2);
    cout<<"After Swap: ";
    after_swap.output(num1,num2);
    return 0;
}