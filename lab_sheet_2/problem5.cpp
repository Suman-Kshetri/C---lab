//  Create a 'STRING' class which char* and length as data member and 
// overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations. Use 
// constructor and destructor whenever suitable

#include<iostream>
#include<cstring>

using namespace std;

class STRING{
    char* string;
    int length;
    public:
    STRING()
    {
        string=nullptr;
        length=0;
    }
    STRING(const char* str)
    {
        // Marked as const to ensure it does not modify the objects but it concatenates. if not used the shows error
        length=strlen(str);  // Determine the length of the input string s
        string=new char[length+1]; // Allocate memory for the string plus the null terminator
        strcpy(string,str); // Copy the content of s into the newly allocated memory, including the null terminator
    }
    STRING (const STRING& another)
    {//for string string4=string1 ---- when we need to duplicate an existing STRING object
        length=another.length;
        string=new char[length+1];
        strcpy(string,another.string);
    }

    STRING operator = (const STRING& another)
    {
        length= another.length;
        string=new char[length+1];
        strcpy(string,another.string);
    }
    STRING operator + (const STRING& another)
    {
        STRING temp;
        temp.length=length+another.length;
        temp.string=new char[temp.length+1];
        strcpy(temp.string,string);
        strcat(temp.string,another.string);
        return temp;
    }
    bool operator == (const STRING& another) 
    {
        return strcmp(string, another.string)==0;
    }
    void display() const
    {
        if(string){
        cout<<string<<endl;
        }
        else
        {
        cout<<"Empty string!!";
        }
    }
    ~STRING(){//free the allocated memory
        delete[] string;
    }
};
int main()
{
    STRING string1("SUMAN");
    STRING string2("KSHETRI");
    cout<<"String1= ";
    string1.display();
    cout<<"String2= ";
    string2.display();
    STRING string3=string1+string2;
    cout<<"String3= ";
    string3.display();
    STRING string4;
    string4=string1;
    cout<<"After using Assignment operator[ = ] : ";
    string4.display();

    if(string1==string4)
    {
        cout<<"String1 is equal to the String4";
    }
    else{
        cout<<"String1 is not equal to Sting4";
    }
    return 0;

}