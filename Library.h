#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Library class represents a simple library management system.
class Library
{
private:
    // Inner class 'Book' represents individual books in the library.
    class Book
    {
    private:
        string name;           // Name of the book.
        string author;         // Author of the book.
        int year;              // Year of publication of the book.
        bool availability;     // Availability status of the book.

    public:
        // Constructor to initialize a book with specified attributes.
        Book(string, string, int, bool);

        // Getter functions to retrieve book details.
        string getName();      // Get the name of the book.
        string getAuthor();    // Get the author of the book.
        int getYear();         // Get the year of publication of the book.
        bool getStatus();      // Get the availability status of the book.

        // Setter function to update the availability status of the book.
        void setStatus(bool);
    };

    vector<Book*> books;       // Collection of books in the library.

public:
    // Function to add a book to the library.
    void addBook(string name, string author, int year, bool availability);

    // Function to search for a book by name and author and return its index.
    int searchBook(string, string);

    // Function to delete a book from the library by name and author.
    void deleteBook(string, string);

    // Function to mark a book as borrowed by name and author.
    void getOutBook(string, string);

    // Function to mark a book as returned by name and author.
    void getBackBook(string, string);

    // Function to display the list of books in the library along with their details and availability status.
    void display();
};


