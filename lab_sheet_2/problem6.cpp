// Modify above class to work with compile time memory allocation i.e. with char [].

#include <iostream>
#include <cstring>
#define MAX_LENGTH 100
using namespace std;

class STRING {
private:
    char str[MAX_LENGTH+1];
    int length;

public:
    STRING()
    {
        length=0;
        str[0] = '\0';
    }

    STRING(const char* s) 
    {
        strncpy(str, s, MAX_LENGTH);
        str[MAX_LENGTH ] = '\0';
        length = strlen(str);
    }
        // Here copy constructor isnot called since s3 is already made.
    // STRING(const STRING& s) 
    // {
    //     strncpy(str, s.str, MAX_LENGTH);
    //     str[MAX_LENGTH] = '\0';
    //     length = strlen(str);
    // }

    STRING& operator = (STRING s2) {
        strncpy(str, s2.str, MAX_LENGTH);
        str[MAX_LENGTH] = '\0';
        length = strlen(str);
    }

    STRING operator + (STRING s2) {
        STRING temp;
        strncpy(temp.str, str, MAX_LENGTH );
        temp.str[MAX_LENGTH ] = '\0';
        strncat(temp.str, s2.str, MAX_LENGTH - strlen(temp.str));
        temp.length = strlen(temp.str);
        return temp;
    }

    bool operator == (STRING s2)  {
        return strcmp(str, s2.str) == 0;
    }

    void display()  {
        cout << str << endl;
    }
};

int main() {
    STRING s1("Hello");
    STRING s2(" World");
    STRING s3;
    s3 = s1 + s2;
    STRING s4("Hello World");

    cout << "The 1st string is: ";
    s1.display();
    cout << "The 2nd string is: ";
    s2.display();
    cout << "The concatenated string is: ";
    s3.display();

    if (s3 == s4) {
        cout << "Yes, it matches." << endl;
    } else {
        cout << "No, check the code." << endl;
    }

    return 0;
}