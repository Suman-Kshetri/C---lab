// To write a C++ program to overload all relational operators to compare 
// US currency with Nepalese currency. Use conversion rate $1=NRs 
// 101.36(Note: make two classes to represent each currency)
#include<iostream>
using namespace std;
class nepali_currency{
    double nepali;
    public:
    void input_nepali_currency()
    {
        cout<<"Enter the nepali currency: Rs ";
        cin>>nepali;
    }
    double get(){
        return nepali;
    }
};
class us_currency{
    double us;
    public:
    void input_us_currency()
    {
        cout<<"Enter the us currency: $ ";
        cin>>us; 
    }
    double get()
    {
        return us;
    }
};

bool operator > (nepali_currency nrs, us_currency us)
{
    if(nrs.get()>us.get()*101.36)
    return true;
    else return false;
}
bool operator < (nepali_currency nrs, us_currency us)
{
    if(nrs.get()<us.get()*101.36)
    return true;
    else return false;
}
bool operator == (nepali_currency nrs, us_currency us)
{
    if(nrs.get()==us.get()*101.36)
    return true;
    else return false;
}
bool operator >= (nepali_currency nrs, us_currency us)
{
    if(nrs.get()>=us.get()*101.36)
    return true;
    else return false;
}
bool operator <= (nepali_currency nrs, us_currency us)
{
    if(nrs.get()<=us.get())
    return true;
    else return false;
}


int main(){
    nepali_currency nrs;
    nrs.input_nepali_currency();
    us_currency us;
    us.input_us_currency();
    if(nrs>us)
        cout<<"Nepali currency is greater than Us currency ";
    else if(nrs<us)
        cout<<"US currency is greater than nepali currency" ;

    else if(nrs==us)
    cout<<"Nepali currency is equal to US currency";
    else if(nrs>=us)
    cout<<"Nepali currency is greater than and equall to US currency";
    else if(nrs<=us)
    cout<<"US currency is greater than and equall to Nepali currency";
    else 
    cout<<"Imput Error!!";
    return 0;
}