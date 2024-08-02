// Create a class publication that stores the title and price of a
// publication. From this class derive two classes:book, which adds a
// page count and tape, which adds a playing time in minutes. Each of
// these three classes should have getdata() function to get its data
// from the user at the keyboard and putdata() function to display its
// data.

//hierarchical inheritance
#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
        void getdata(){
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price [in US]: ";
        cin >> price;
        // cin.ignore();  
    }

    virtual void putdata(){
        cout << "Title: " << title << endl;
        cout << "Price: $ " << price << endl;
    }

};


class Book : public Publication {
    int pageCount;
public:
    void getdata(){
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();  
    }

    void putdata(){
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
    float playingTime;
public:

    void getdata(){
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore();  
    }

    void putdata(){
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
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
