🔖 Problem Statement: Library Management System - Book Lending Tracker
You are tasked with developing a basic Library Management System that allows a librarian to manage book operations. Implement a program that can:

Add a new book to the library with its title and author.

Lend a book to a user if it is available.

Return a book to the library and mark it as available.

Dynamically manage memory to store new books when the storage limit is reached.

🧾 Functional Requirements:
Implement a class Library with the following functionalities:

Attributes:

bookTitle (string)

author (string)

isAvailable (boolean)

Functions:

addBook(): Accepts book title and author name as input and sets availability to true.

lendBook(): Issues the book if available, else displays a message.

returnBook(): Returns the book and updates its availability status.

Appropriate getter and setter methods for all data members.

You must also handle dynamic memory reallocation for storing more books when the initial storage limit (10 books) is exceeded.

💡 Input Format:
On each iteration, user will choose one of the options:

markdown
Copy
Edit
1. Add Book Details
2. Lend Book
3. Return Book
4. Exit
For option 1, input:

Book Title (string)

Author Name (string)

For option 2 and 3:

Book Title (string)

🖥️ Output Format:
Display appropriate messages for each action:

When a book is added.

When a book is lent or unavailable.

When a book is returned or if it's not found.

✅ Constraints:
Initial capacity of the library is 10 books. Increase by 10 when exceeded.

Titles are case-sensitive and unique.

Input strings can include spaces.

📌 Sample Interaction:
mathematica
Copy
Edit
1.) Add Book Details
2.) Lend Book
3.) Return Book
4.) Exit
Enter your choice: 1
Enter Book Title: Clean Code
Enter Book Author name: Robert C. Martin
Book Clean Code is now available in the library.

Enter your choice: 2
Enter Book Title: Clean Code
Book Clean Code has been issued. Kindly return this book within the given time period. Thank you for visiting us.

Enter your choice: 3
Enter Book Title: Clean Code
Book Clean Code is returned. Thank you.

Enter your choice: 4


// Program to perform basic library operations
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Library {
private:
    string bookTitle, author;
    bool isAvailable; // Change to bool

public:
    // Getter methods
    string get_bookTitle() const {
        return bookTitle;
    }
    string get_author() const {
        return author;
    }
    bool get_isAvailable() const { // Change return type to bool
        return isAvailable;
    }

    // Setter methods
    void set_bookTitle(const string& bookTitle) {
        this->bookTitle = bookTitle;
    }
    void set_author(const string& author) {
        this->author = author;
    }
    void set_isAvailable(bool isAvailable) { // Change parameter type to bool
        this->isAvailable = isAvailable;
    }
    
    void addBook() {
        cout << "Enter Book Title: ";
        getline(cin, bookTitle);
        cout << "Enter Book Author name: ";
        getline(cin, author);
        isAvailable = true; // Use true for available
        cout << "Book " << bookTitle << " is now available in the library." << endl;
    }

    void lendBook() {
        if (isAvailable) {
            cout << "Book " << bookTitle << " has been issued. Kindly return this book within the given time period. Thank you for visiting us." << endl;
            isAvailable = false; // Set to unavailable
        } else {
            cout << "Sorry, currently this book is unavailable." << endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true; // Set back to available
            cout << "Book " << bookTitle << " is returned. Thank you." << endl;
        } else {
            cout << "This book was not lent out." << endl; // Check if it was lent
        }
    }
};

void reallocating_size(Library*& library_data, int* size) { // Pass pointer to pointer
    Library* new_library_data = new Library[*size + 10];
    copy(library_data, library_data + *size, new_library_data);
    *size += 10;
    delete[] library_data;
    library_data = new_library_data; // Update the pointer
}

int main() {
    int count = 0, choice, size_array_of_objects = 10;
    string bookTitle;
    Library* library_data = new Library[size_array_of_objects];

    do {
        cout << "\n1.) Add Book Details";
        cout << "\n2.) Lend Book";
        cout << "\n3.) Return Book";
        cout << "\n4.) Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear newline from input buffer
        switch (choice) {
            case 1:
                if (count == size_array_of_objects) {
                    reallocating_size(library_data, &size_array_of_objects);
                }
                library_data[count++].addBook();
                break;

            case 2:
                cout << "Enter Book Title: ";
                getline(cin, bookTitle);
                {
                    bool found = false; // Use a boolean to track if found
                    for (int i = 0; i < count; i++) {
                        if (library_data[i].get_bookTitle() == bookTitle) {
                            library_data[i].lendBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Sorry, currently this book is unavailable." << endl;
                    }
                }
                break;

            case 3:
                cout << "Enter Book Title: ";
                getline(cin, bookTitle);
                {
                    bool found = false; // Use a boolean to track if found
                    for (int i = 0; i < count; i++) {
                        if (library_data[i].get_bookTitle() == bookTitle) {
                            library_data[i].returnBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "No record of this book found." << endl;
                    }
                }
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    delete[] library_data; // Clean up dynamic memory
    return 0;
}
