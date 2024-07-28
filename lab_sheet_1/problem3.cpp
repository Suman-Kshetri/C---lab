// Write a program that checks the order of a medicine from a pharmacy store.
// The program should read the order quantity and the medicine quantity in the
// store. When the order quantity is more than the store quantity, your
// program should display the message “No enough quantity”. When the order
// quantity is less than the store quantity, you have to check that the order
// quantity must be not more than 16 except there is more than 40 items in the
// store. The messages that will be displayed in that cases are “Your order is
// accepted” OR “You cannot order more than 16 item”

#include<iostream>
using namespace std;
class medicine{
    int quantity;
    public:
    void set_data(){
        cin>>quantity;
    }
    int get() const {
        return quantity;
    }
    void check_quantity(const medicine& ,const medicine& );
};

void medicine::check_quantity(const medicine &store, const medicine &order)
{
    if(store.get()<order.get())
    {
        cout<<"The quantity exceeds our store limit";
    }
    else{
        if(store.get()<=40)
        {
            if(order.get()<=16)
            {
                cout<<"Your order has been recorded..";
            }
            else{
                cout<<"You cannot order moe than 16 items:";
            }
        }
        else{
            cout<<"Your order has been recorded...";
        }
    }
    
}
int main(){
    medicine store,order,check;
    cout<<"Enter the store quantity:"<<endl;
    store.set_data();
    cout<<"Enter the order Quantity:"<<endl;
    order.set_data();
    check.check_quantity(store,order);
    return 0;
}
