// To write a C++ program to add two private data members using friend functions.
#include<iostream>
using namespace std;

class sum_of_number {
    int num1, num2;
public:
    void get_input() {
        cout << "Enter the first number:" << endl;
        cin >> num1;
        cout << "Enter the second number:" << endl;
        cin >> num2;
    }
    friend void get_sum(sum_of_number&);
};

void get_sum(sum_of_number &n) {
    int sum = n.num1 + n.num2;
    cout << "The sum of the two numbers is: " << sum << endl;
}

int main() {
    sum_of_number num;
    num.get_input();  
    get_sum(num);     
    return 0;
}
