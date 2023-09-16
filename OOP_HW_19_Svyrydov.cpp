// Task (Part 1):
// Create a program for managing a school library.
// This library can have various books, and each book has its own properties
// such as title, author, publication year, availability, and more.
// Additionally, the library can handle book loans to students.
// 
// Task(Part 2) :
// The class Book should have the following fields:
// - Book title(string).
// - Author(string).
// - Publication year(integer).
// - Availability(boolean).
// 
// The Book class should also have a constructor that allows creating book objects with specified properties, 
// and methods for displaying information about the book.
// 
// Task(Part 3) :
// The class Library should have the following fields:
// -An array(or vector) of objects of the Book class, representing the books in the library.
// 
// The Library class should have the following methods:
// - Adding a new book to the library.
// - Removing a book from the library(if the book is not borrowed).
// - Loaning a book to a student(changing availability).
// - Returning a book by a student(changing availability).
// - Displaying information about all the books in the library.
//

#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    // Create a Library object
    Library library;

    // Add books to the library
    library.addBook("Book1", "Author1", 2000, true);
    library.addBook("Book2", "Author2", 1995, true);
    library.addBook("Book3", "Author3", 2010, false);

    // Display all books in the library
    cout << "Books in the library:" << endl;
    library.display();

    // Search for a book and get its index
    int index = library.searchBook("Book2", "Author2");
    if (index != -1)
    {
        cout << "\nBook2 by Author2 found at index " << index << endl;
    }
    else
    {
        cout << "\nBook2 by Author2 not found." << endl;
    }

    // Mark a book as borrowed
    library.getOutBook("Book1", "Author1");

    // Display updated book availability
    cout << "\nBook availability after marking Book1 as borrowed:" << endl;
    library.display();

    // Mark a book as returned
    library.getBackBook("Book1", "Author1");

    // Display updated book availability
    cout << "\nBook availability after marking Book1 as returned:" << endl;
    library.display();

    // Delete a book from the library
    library.deleteBook("Book3", "Author3");

    // Display updated list of books
    cout << "\nList of books after deleting Book3:" << endl;
    library.display();
}