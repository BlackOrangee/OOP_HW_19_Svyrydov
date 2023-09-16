#include "Library.h"

// Implementation of the Library::Book class

// Constructor initializes a Book with specified attributes.
Library::Book::Book(string name, string author, int year, bool availability)
{
	this->name = name;
	this->author = author;
	this->year = year;
	this->availability = availability;
}

// Getter for retrieving the name of the book.
string Library::Book::getName()
{
	return name;
}

// Getter for retrieving the author of the book.
string Library::Book::getAuthor()
{
	return author;
}

// Getter for retrieving the publication year of the book.
int Library::Book::getYear()
{
	return year;
}

// Getter for retrieving the availability status of the book.
bool Library::Book::getStatus()
{
	return availability;
}

// Setter for updating the availability status of the book.
void Library::Book::setStatus(bool availability)
{
	this->availability = availability;
}


// Implementation of the Library class

// Function to add a book to the library.
void Library::addBook(string name, string author, int year, bool availability)
{
	books.push_back(new Book(name, author, year, availability));
}

// Function to search for a book by name and author and return its index in the library.
// Returns -1 if the book is not found.
int Library::searchBook(string name, string author)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->getName() == name && books[i]->getAuthor() == author)
		{
			return i; // Return the index of the found book.
		}
	}
	return -1; // Return -1 to indicate that the book was not found.
}

// Function to delete a book from the library by name and author.
void Library::deleteBook(string name, string author)
{
	// Find the index of the book.
	int bookIndex = searchBook(name, author);

	if (bookIndex == -1)
	{
		return; // Book not found, no action needed.
	}

	// Remove the book from the library.
	books.erase(books.begin() + bookIndex);
}

// Function to mark a book as checked out by setting its status to false.
void Library::getOutBook(string name, string author)
{
	int bookIndex = searchBook(name, author);
	if (bookIndex == -1)
	{
		return; // Book not found, no action needed.
	}

	if (books[bookIndex]->getStatus())
	{
		// Mark the book as checked out (unavailable).
		books[bookIndex]->setStatus(false);
	}
}

// Function to mark a book as returned by setting its status to true.
void Library::getBackBook(string name, string author)
{
	int bookIndex = searchBook(name, author);
	if (bookIndex == -1)
	{
		return; // Book not found, no action needed.
	}

	if (!books[bookIndex]->getStatus())
	{
		// Mark the book as returned (available).
		books[bookIndex]->setStatus(true);
	}
}

// Function to display the list of books in the library, including their details and availability status.
void Library::display()
{
	for (Book* b : books)
	{
		// Print the book's name, author, and year of publication.
		cout << b->getName() << " : " << b->getAuthor() << " : " << b->getYear() << " : ";

		// Check if the book is available or not and print the corresponding status message.
		if (b->getStatus())
		{
			cout << "is available" << endl;
		}
		else
		{
			cout << "is not available" << endl;
		}
	}
}
