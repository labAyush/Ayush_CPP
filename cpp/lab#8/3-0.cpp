#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string subject;
    string author;
public:
    // getters
    string getTitle() const { return title; }
    string getSubject() const { return subject; }
    string getAuthor() const { return author; }

    // setters
    void setTitle(const string& t) { title = t; }
    void setSubject(const string& s) { subject = s; }
    void setAuthor(const string& a) { author = a; }
};

class book_file {
    string file_name;
public:
    book_file() {
        cout << "File Name: ";
        cin >> file_name;
    }

    void appendBook(Book b) {
        ofstream outfile(file_name, ios::app);
        if (outfile.is_open()) {
            outfile << b.getTitle() << endl;
            outfile << b.getSubject() << endl;
            outfile << b.getAuthor() << endl;
            outfile.close();
        } else {
            cout << "Unable to open file";
        }
    }

    Book getBook() {
        Book b;
        ifstream infile(file_name);
        if (infile.is_open()) {
            string temp;
            infile >> ws; // to ignore whitespace
            getline(infile, temp);
            b.setTitle(temp);
            getline(infile, temp);
            b.setSubject(temp);
            getline(infile, temp);
            b.setAuthor(temp);
            infile.close();
        } else {
            cout << "Unable to open file";
        }
        return b;
    }
};