// Modify problem2 to add base class sales that holds an array of three
// floats so that it can record the dollar sales of a particular
// publication for the last three months. Include getdata() function to
// get three Sales amount from the user and a putdata() function to
// display sales figures. Alter the book and tape classes so they are
// derived from both publication and sales. An object of class book or
// tape should input and output sales data along with its other data.

#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price [in US]: ";
        cin >> price;
        // cin.ignore();  
    }

    void putdata(){
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        cout << "Enter sales for the last three months:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();  
    }

    void putdata(){
        cout << "Sales for the last three months:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();  
        Sales::getdata();
    }

    void putdata(){
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        // cin.ignore();  
        Sales::getdata();
    }

    void putdata(){
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
        Sales::putdata();
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Enter details for the book:\n";
    myBook.getdata();

    cout << "\nEnter details for the tape:\n";
    myTape.getdata();

    cout << "\nDetails of the book:\n";
    myBook.putdata();

    cout << "\nDetails of the tape:\n";
    myTape.putdata();

    return 0;
}
