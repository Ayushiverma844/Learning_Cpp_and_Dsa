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