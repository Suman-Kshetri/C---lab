// 5.class Inventory
// {
// private:
//     int quant;     // number on hand
//     int reorder;   // reorder quantity
//     double price;  // price per unit
//     char *descrip; // description of item
// public:
//     Inventory(int q, int r, double p, char *d)
//     { // initialize data members }
//         ~Inventory()
//         { // release dynamically allocated memory}
//             void print();
//         };
//         //
//         // first derived class
//         //
//         class Auto : public Inventory
//         {
//             char *manufacturer;

//         public:
//             Auto(int q, int r, double p, char *d, char *man)
//             { // initialize base and derive members }
//             }
//             ~Auto()
//             {
//             }
//             void print();
//         };
//         //
//         // Second derived class
//         //
//         class Transmission : public Inventory
//         {
//             char *vendor;

//         public:
//             Transmission(int q, int r, double p, char *d, char *ven)
//             {
//             }
//             ~Transmission() {}
//             void print();
//         };
// a.Write a main () function that creates an instance object of Auto called Car, which has thefollowing initial data: there is a quantity of five(5) on inventory, and two(2) on reorder;the price per unit is $15,545.91, and the escription is that of the car obtained from theToyota. Initialize the object Car, and print out all its vital facts.
// b.A Transmission is purchased from Aztec Inc., and must be inventoried. There are 25 ofthem, with 10 more on reorder. Their price is $1789.98. Instantiate and initialize anobject for Transmission, and provide the same information

#include <iostream>
#include <cstring>
using namespace std;

class Inventory
{
        int quant;     // number on hand
        int reorder;   // reorder quantity
        double price;  // price per unit
        char *descrip; // description of item

public:
        Inventory(int q, int r, double p, char *d)
        {
                quant = q;
                reorder = r;
                price = p;
                descrip = new char[strlen(d) + 1];
                strcpy(descrip, d);
        }
        ~Inventory()
        {
                delete[] descrip;
        }
        void print()
        {
                cout << "Quantity: " << quant << endl;
                cout << "Reorder: " << reorder << endl;
                cout << "Price: $" << price << endl;
                cout << "Description: " << descrip << endl;
        }
};

class Auto : public Inventory
{
        char *manufacturer;

public:
        Auto(int q, int r, double p, char *d, char *man) : Inventory(q, r, p, d)
        {
                manufacturer = new char[strlen(man) + 1];
                strcpy(manufacturer, man);
        }
        ~Auto()
        {
                delete[] manufacturer;
        }
        void print()
        {
                Inventory::print();
                cout << "Manufacturer: " << manufacturer << endl;
        }
};

class Transmission : public Inventory
{
        char *vendor;

public:
        Transmission(int q, int r, double p, char *d, char *ven) : Inventory(q, r, p, d)
        {
                vendor = new char[strlen(ven) + 1];
                strcpy(vendor, ven);
        }
        ~Transmission()
        {
                delete[] vendor;
        }
        void print()
        {
                Inventory::print();
                cout << "Vendor: " << vendor << endl;
        }
};

int main()
{
        Auto Car(5, 2, 15545.91, "A car obtained from the Toyota", "Toyota");
        Car.print();
        cout << endl;
        Transmission Transmission(25, 10, 1789.98, "Transmission purchased from Aztec Inc.", "Aztec Inc.");
        Transmission.print();
        return 0;
} 