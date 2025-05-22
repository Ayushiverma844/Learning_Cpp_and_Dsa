//  Problem Statement: Library Management System - Book Lending Tracker
// You are tasked with developing a basic Library Management System that allows a librarian to manage book operations. Implement a program that can:

// Add a new book to the library with its title and author.

// Lend a book to a user if it is available.

// Return a book to the library and mark it as available.

// Dynamically manage memory to store new books when the storage limit is reached.

//  Functional Requirements:
// Implement a class Library with the following functionalities:

// Attributes:

// bookTitle (string)

// author (string)

// isAvailable (boolean)

// Functions:

// addBook(): Accepts book title and author name as input and sets availability to true.

// lendBook(): Issues the book if available, else displays a message.

// returnBook(): Returns the book and updates its availability status.

// Appropriate getter and setter methods for all data members.

// You must also handle dynamic memory reallocation for storing more books when the initial storage limit (10 books) is exceeded.

//  Input Format:

// On each iteration, user will choose one of the options:
// 1. Add Book Details
// 2. Lend Book
// 3. Return Book
// 4. Exit

// For option 1, input:

// Book Title (string)

// Author Name (string)

// For option 2 and 3:

// Book Title (string)

// Output Format:
// Display appropriate messages for each action:

// When a book is added.

// When a book is lent or unavailable.

// When a book is returned or if it's not found.

//  Constraints:
// Initial capacity of the library is 10 books. Increase by 10 when exceeded.

// Titles are case-sensitive and unique.

// Input strings can include spaces.

// Sample Interaction:
// 1.) Add Book Details
// 2.) Lend Book
// 3.) Return Book
// 4.) Exit
// Enter your choice: 1
// Enter Book Title: Clean Code
// Enter Book Author name: Robert C. Martin
// Book Clean Code is now available in the library.

// Enter your choice: 2
// Enter Book Title: Clean Code
// Book Clean Code has been issued. Kindly return this book within the given time period. Thank you for visiting us.

// Enter your choice: 3
// Enter Book Title: Clean Code
// Book Clean Code is returned. Thank you.

// Enter your choice: 4

// -----------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Library {
private:
    string bookTitle, author;
    bool isAvailable;

public:
    // Getter methods
    string get_bookTitle() const {
        return bookTitle;
    }

    string get_author() const {
        return author;
    }

    bool get_isAvailable() const {
        return isAvailable;
    }

    // Setter methods
    void set_bookTitle(const string& bookTitle) {
        this->bookTitle = bookTitle;
    }

    void set_author(const string& author) {
        this->author = author;
    }

    void set_isAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    // Modified addBook function to accept parameters
    void addBook(const string& title, const string& author) {
        this->bookTitle = title;
        this->author = author;
        this->isAvailable = true;
        cout << "✅ Book \"" << bookTitle << "\" is now available in the library.\n";
    }

    void lendBook() {
        if (isAvailable) {
            cout << "📚 Book \"" << bookTitle << "\" has been issued.\n";
            cout << "Kindly return this book within the given time period.\nThank you for visiting us.\n";
            isAvailable = false;
        } else {
            cout << "❌ Sorry, the book \"" << bookTitle << "\" is currently unavailable.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "✅ Book \"" << bookTitle << "\" is returned. Thank you.\n";
        } else {
            cout << "⚠️ This book was not lent out.\n";
        }
    }
};

// Function to reallocate library array when size exceeds limit
void reallocating_size(Library*& library_data, int* size) {
    Library* new_library_data = new Library[*size + 10];
    copy(library_data, library_data + *size, new_library_data);
    *size += 10;
    delete[] library_data;
    library_data = new_library_data;
}

int main() {
    int count = 0, choice, size_array_of_objects = 10;
    string bookTitle, author;
    Library* library_data = new Library[size_array_of_objects];

    do {
        cout << "\n📚 Library Menu";
        cout << "\n1.) Add Book Details";
        cout << "\n2.) Lend Book";
        cout << "\n3.) Return Book";
        cout << "\n4.) Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1: {
                if (count == size_array_of_objects) {
                    reallocating_size(library_data, &size_array_of_objects);
                }

                cout << "Enter Book Title: ";
                getline(cin, bookTitle);
                cout << "Enter Book Author name: ";
                getline(cin, author);

                // Check for duplicate book
                bool isDuplicate = false;
                for (int i = 0; i < count; i++) {
                    if (library_data[i].get_bookTitle() == bookTitle) {
                        isDuplicate = true;
                        break;
                    }
                }

                if (isDuplicate) {
                    cout << "❌ Book \"" << bookTitle << "\" already exists in the library.\n";
                } else {
                    library_data[count].addBook(bookTitle, author);
                    count++;
                }
                break;
            }

            case 2: {
                cout << "Enter Book Title: ";
                getline(cin, bookTitle);
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (library_data[i].get_bookTitle() == bookTitle) {
                        library_data[i].lendBook();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "❌ Sorry, book \"" << bookTitle << "\" not found in library.\n";
                }
                break;
            }

            case 3: {
                cout << "Enter Book Title: ";
                getline(cin, bookTitle);
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (library_data[i].get_bookTitle() == bookTitle) {
                        library_data[i].returnBook();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "❌ No record of book \"" << bookTitle << "\" found.\n";
                }
                break;
            }

            case 4:
                cout << "👋 Exiting the Library System. Thank you!\n";
                break;

            default:
                cout << "⚠️ Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    delete[] library_data; // Free allocated memory
    return 0;
}
