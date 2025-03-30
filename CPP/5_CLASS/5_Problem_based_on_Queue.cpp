// Problem Statement: Library Book Return System
// A library wants to implement a Book Return System to manage book returns and calculate overdue fines. The system should perform the following tasks:

// Book Representation:

// Each book has a title, return time (in days), and overdue days (negative if not overdue).

// Library Management:

// A queue-based system is used to manage returned books.

// The system should process books one by one from the return queue.

// If a book is overdue, a fine of $1.5 per day should be calculated and added to the total fines.

// The system should display the book details, including fines if applicable.

// Processing Returns:

// The system should process all returned books and display their details, including whether a fine is incurred.

// Total Fine Calculation:

// After processing all books, the total fine collected should be displayed.

// Example Execution:
// Input :

// "The Great Gatsby" (Returned 2 days late)

// "1984" (Returned 1 day early, no fine)

// "To Kill a Mockingbird" (Returned 3 days late)

// "The Catcher in the Rye" (Returned on time, no fine)

// Output:

// Book Title: The Great Gatsby  
// Return Time: 5  
// Overdue Days: 2  
// Fine incurred: $3.0  
// ---------------------  
// Book Title: 1984  
// Return Time: 10  
// Overdue Days: -1  
// No fines incurred.  
// ---------------------  
// Book Title: To Kill a Mockingbird  
// Return Time: 8  
// Overdue Days: 3  
// Fine incurred: $4.5  
// ---------------------  
// Book Title: The Catcher in the Rye  
// Return Time: 12  
// Overdue Days: 0  
// No fines incurred.  
// ---------------------  
// Total fines collected: $7.5


#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Book {
private:
    string title;
    int returnTime;  // Time when the book is due
    int overdueDays; // Negative if not overdue

public:
    // Constructor to initialize book attributes
    Book(string title, int returnTime, int overdueDays)
        : title(title), returnTime(returnTime), overdueDays(overdueDays) {}

    // Accessor methods
    string getTitle() const {
        return title;
    }

    int getReturnTime() const {
        return returnTime;
    }

    int getOverdueDays() const {
        return overdueDays;
    }
};

class Library {
private:
    queue<Book> returnQueue; // Queue to manage book returns
    double totalFines;       // Total fines collected

public:
    Library() : totalFines(0.0) {}

    // Method to add a book to the return queue
    void returnBook(const Book& book) {
        returnQueue.push(book);
    }

    // Method to process all returns in the queue
    void processReturns() {
        while (!returnQueue.empty()) {
            Book book = returnQueue.front();
            returnQueue.pop();

            // Calculate fines if overdue
            double fine = 0.0;
            if (book.getOverdueDays() > 0) {
                fine = book.getOverdueDays() * 1.5; // Example fine calculation
                totalFines += fine;
            }

            // Display book details and fines
            cout << "Book Title: " << book.getTitle() << endl;
            cout << "Return Time: " << book.getReturnTime() << endl;
            cout << "Overdue Days: " << book.getOverdueDays() << endl;
            if (book.getOverdueDays() > 0) {
                cout << "Fine incurred: $" << fine << endl;
            } else {
                cout << "No fines incurred." << endl;
            }
            cout << "---------------------" << endl;
        }
    }

    // Method to get total fines collected
    double getTotalFines() const {
        return totalFines;
    }
};

int main() {
    Library library;

    // Create several Book objects
    library.returnBook(Book("The Great Gatsby", 5, 2));  // 2 days overdue
    library.returnBook(Book("1984", 10, -1));              // Not overdue
    library.returnBook(Book("To Kill a Mockingbird", 8, 3)); // 3 days overdue
    library.returnBook(Book("The Catcher in the Rye", 12, 0)); // On time

    // Process returns and calculate fines
    library.processReturns();

    // Display total fines collected
    cout << "Total fines collected: $" << library.getTotalFines() << endl;

    return 0;
}