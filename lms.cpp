#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;
public:
    Book(string bookTitle, string bookAuthor) : title(bookTitle), author(bookAuthor), available(true) {}
    string getTitle() const { 
        return title; 
    }
    string getAuthor() const {
       return author; 
    }
    bool isAvailable() const {
       return available; 
    }
    void setAvailability(bool isAvailable) {
         available = isAvailable; }
};

class Student {
private:
    string name;
    int rollNumber;
    Book* issuedBook;
public:
    Student(string studentName, int roll) : name(studentName), rollNumber(roll), issuedBook(nullptr) {}
    string getName() const { 
    return name; 
    }
    int getRollNumber() const { 
    return rollNumber; 
    }
    Book* getIssuedBook() const { 
    return issuedBook; 
    }

    void issueBook(Book* book) {
     issuedBook = book; 
     }

    void returnBook() { 
    issuedBook = nullptr; 
    }
};

int main() {
    char name[100];
    cout<<"Enter username:";
    cin>>name;
    Book books[3] = {
        Book("Hunting Adeline", "Agatha Crishtie"),
        Book("Rich dad Poor Dad", "Robert Kiyosaki"),
        Book("It ends with us", "Coolen Hover")
    };
    Student students[3] = {
        Student("Student1", 101),
        Student("Student2", 102),
        Student("Student3", 103)
    };
    students[0].issueBook(&books[0]);
    // students[0].returnBook();
    cout << "Available Books:" << endl;
        for (int i = 0; i < 3; i++) {
        if (books[i].isAvailable()) {
            cout << "Title: " << books[i].getTitle() << ", Author: " << books[i].getAuthor() <<endl;
        }
    }   

    cout << "\nStudent Records:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << students[i].getName() << ", Roll Number: " << students[i].getRollNumber();
        Book* book = students[i].getIssuedBook();
        if (book != nullptr) {
            cout << ", Issued Book: " << book->getTitle();
        } else {
            cout << ", No book issued";
        }
        cout << endl;
    }

    return 0;
}