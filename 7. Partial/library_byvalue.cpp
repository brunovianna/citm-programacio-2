#include <string>
#include <iostream>
using namespace std;

// Book class that will be stored in our array
class Book {
private:
    string title;
    string author;
    bool isCheckedOut;

public:
    // Default constructor - needed for array initialization
    Book() {
        title = "";
        author = "";
        isCheckedOut = false;
    }

    // Parameterized constructor
    Book(string t, string a) {
        title = t;
        author = a;
        isCheckedOut = false;
    }

    // Getter methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getCheckedOut() const { return isCheckedOut; }

    // Methods to handle book checkout
    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnBook() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " is already in the library." << endl;
        }
    }

    // Display book information
    void displayInfo() const {
        cout << "Title: " << title << endl
             << "Author: " << author << endl
             << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

// Library class that contains an array of Books
class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];  // Array of Book objects
    int numBooks;           // Current number of books
    string libraryName;

public:
    // Constructor
    Library(string name) {
        libraryName = name;
        numBooks = 0;
    }

    // Add a new book to the library
    bool addBook(string title, string author) {
        if (numBooks < MAX_BOOKS) {
            books[numBooks] = Book(title, author);
            numBooks++;
            return true;
        }
        cout << "Error: Library is full." << endl;
        return false;
    }

    // Find a book by title
    int findBook(string title) const {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].getTitle() == title) {
                return i;
            }
        }
        return -1;  // Book not found
    }

    // Check out a book by title
    void checkOutBook(string title) {
        int index = findBook(title);
        if (index != -1) {
            books[index].checkOut();
        } else {
            cout << "Book not found in library." << endl;
        }
    }

    // Return a book by title
    void returnBook(string title) {
        int index = findBook(title);
        if (index != -1) {
            books[index].returnBook();
        } else {
            cout << "Book not found in library." << endl;
        }
    }

    // Display all books in the library
    void displayCatalog() const {
        cout << "\n=== " << libraryName << " Catalog ===" << endl;
        cout << "Total Books: " << numBooks << endl << endl;
        
        for (int i = 0; i < numBooks; i++) {
            cout << "Book #" << (i + 1) << ":" << endl;
            books[i].displayInfo();
            cout << "-------------------" << endl;
        }
    }

    // Display only available books
    void displayAvailableBooks() const {
        cout << "\n=== Available Books ===" << endl;
        bool foundAvailable = false;
        
        for (int i = 0; i < numBooks; i++) {
            if (!books[i].getCheckedOut()) {
                books[i].displayInfo();
                cout << "-------------------" << endl;
                foundAvailable = true;
            }
        }
        
        if (!foundAvailable) {
            cout << "No books available at this time." << endl;
        }
    }
};

// Example usage
int main() {
    // Create a new library
    Library myLibrary("Community Library");

    // Add some books
    myLibrary.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    myLibrary.addBook("1984", "George Orwell");
    myLibrary.addBook("Pride and Prejudice", "Jane Austen");

    // Display initial catalog
    myLibrary.displayCatalog();

    // Test checkout system
    cout << "\nTesting checkout system:" << endl;
    myLibrary.checkOutBook("1984");
    myLibrary.checkOutBook("1984");  // Try to check out same book twice
    myLibrary.returnBook("1984");

    // Display available books
    myLibrary.displayAvailableBooks();

    // Try to find a non-existent book
    myLibrary.checkOutBook("The Hobbit");

    return 0;
}