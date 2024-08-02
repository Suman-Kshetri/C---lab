// Program to convert Nepalese Currency (Rupees and Paisa) to US
// Currency (Dollar and Cents). (Rs. 98.51=1$)

#include <iostream>
#include <cmath>

using namespace std;

class USCurrency {
public:
    int dollars;
    int cents;

    USCurrency(int d = 0, int c = 0) {
         dollars=d; 
         cents=c;
   }

    void display() const {
        cout << "US Currency: $" << dollars << "." << (cents < 10 ? "0" : "") << cents << endl;
    }
};

class NepaleseCurrency {
public:
    int rupees;
    int paisa;

    NepaleseCurrency(int r = 0, int p = 0) : rupees(r), paisa(p) {}

    void getdata() {
        cout << "Enter amount in Nepalese Currency (Rupees and Paisa):\n";
        cout << "Rupees: ";
        cin >> rupees;
        cout << "Paisa: ";
        cin >> paisa;
    }

     USCurrency toUSCurrency() const {
        double totalNepalese = rupees + paisa / 100.0;
        double totalUSD = totalNepalese / 110; // Conversion rate Rs. 110 = 1$
        int dollars = static_cast<int>(totalUSD);
        int cents = static_cast<int>(round((totalUSD - dollars) * 100));
        return USCurrency(dollars, cents);
    }

    void display() const {
        cout << "Nepalese Currency: " << rupees << " Rupees and " << paisa << " Paisa" << endl;
    }
};

int main() {
    NepaleseCurrency nepCurrency;
    nepCurrency.getdata();
    nepCurrency.display();

    USCurrency usCurrency = nepCurrency.toUSCurrency();
    usCurrency.display();

    return 0;
}
