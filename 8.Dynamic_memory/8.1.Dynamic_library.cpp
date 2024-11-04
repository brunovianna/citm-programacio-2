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
    
    Book* books;  // ABook objects pointer without allocation
    int numBooks;           // Current number of books
    int capacity;
    string libraryName;


    void resize(int newCapacity) {
        // Create new array
        Book* newBooks = new Book[newCapacity];
        // Copy existing books
        for (int i = 0; i < numBooks; i++) {
            newBooks[i] = books[i];
        }

        // // Delete old array and update pointer
        delete[] books;
        books = newBooks;
        capacity = newCapacity;
    }
public:
    // Constructor
    Library(string name) {

        libraryName = name;
        numBooks = 0;
        books = new Book[2];
        capacity = 2;

    }

    // Destructor to free dynamic memory
    ~Library() {
        delete[] books;
    }

    // Copy constructor for deep copying
    Library(const Library& other) {
        libraryName = other.libraryName;
        capacity = other.capacity;
        numBooks = other.numBooks;
        books = new Book[capacity];
        
        // Copy each book
        for (int i = 0; i < numBooks; i++) {
            books[i] = other.books[i];
        }
    }


    // Assignment operator for deep copying
    Library& operator=(const Library& other) {
        if (this != &other) {  // Prevent self-assignment
            // Delete existing array
            delete[] books;
            
            // Copy properties
            libraryName = other.libraryName;
            capacity = other.capacity;
            numBooks = other.numBooks;
            
            // Allocate and copy books
            books = new Book[capacity];
            for (int i = 0; i < numBooks; i++) {
                books[i] = other.books[i];
            }
        }
        return *this;
    }

    // Add a new book to the library
    bool addBook(string title, string author) {


       // Resize if array is full
        if (numBooks == capacity) {
            resize(capacity * 2);  // Double the capacity
        }
                                cout << "done";

        books[numBooks] = Book(title, author);
        numBooks++;
        return true;


    }

    // Find a book by title
    // int findBook(string title) const {
    //     for (int i = 0; i < numBooks; i++) {
    //         if (books[i].getTitle() == title) {
    //             return i;
    //         }
    //     }
    //     return -1;  // Book not found
    // }

    Book * findBook(string title)  {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;  // Book not found
    }


    // Check out a book by title
    void checkOutBook(string title) {
        Book *book = findBook(title);
        if ( book != nullptr) {
            book->checkOut();
        } else {
            cout << "Book not found in library." << endl;
        }
    }

    // Return a book by title
    void returnBook(string title) {
        Book *book  = findBook(title);
        if (book != nullptr) {
            books->returnBook();
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

    cout << "here";

    // Create a new library
    Library myLibrary("Community Library");

    // // Add some books
    myLibrary.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    myLibrary.addBook("1984", "Orwell");
    myLibrary.addBook("Don Quijote", "Cervantes");

                        cout << "done";


    // Display initial catalog
    myLibrary.displayCatalog();

    // // Test checkout system
    // cout << "\nTesting checkout system:" << endl;
    // myLibrary.checkOutBook("1984");
    // myLibrary.checkOutBook("1984");  // Try to check out same book twice
    // myLibrary.returnBook("1984");

    // // Display available books
    // myLibrary.displayAvailableBooks();

    // // Try to find a non-existent book
    // myLibrary.checkOutBook("The Hobbit");

    return 0;
}
