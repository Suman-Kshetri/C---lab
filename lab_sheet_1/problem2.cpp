// Write a program that determines the maximum and the minimum of three 
// numbers
#include <iostream>
using namespace std;

class numbers {
    int num;
public:
    void set_number() {
        cout << "Enter the number:" << endl;
        cin >> num;
    }
    int get_number() const { return num; } //to access the number
};

void find_max_min(const numbers &a, const numbers &b, const numbers &c, int &max, int &min) {
    max = a.get_number();
    min = a.get_number();

    if (b.get_number() > max) {
        max = b.get_number();
    } else if (b.get_number() < min) {
        min = b.get_number();
    }

    if (c.get_number() > max) {
        max = c.get_number();
    } else if (c.get_number() < min) {
        min = c.get_number();
    }
}

int main() {
    numbers num1, num2, num3;
    
    cout << "first number:" << endl;
    num1.set_number();
    cout << "second number:" << endl;
    num2.set_number();
    cout << "third number:" << endl;
    num3.set_number();
    
    int maximum, minimum;
    find_max_min(num1, num2, num3, maximum, minimum);
    
    cout << "Maximum number is: " << maximum << endl;
    cout << "Minimum number is: " << minimum << endl;
    
    return 0;
}
