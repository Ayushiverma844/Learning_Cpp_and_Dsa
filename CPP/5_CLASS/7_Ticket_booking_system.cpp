// Problem Statement
// Title: Movie Ticket Booking System with Queue Management

// Problem Description
// You are tasked with implementing a Movie Ticket Booking System where customers are added to a queue and their tickets are processed in a First-In-First-Out (FIFO) manner. Each customer selects a movie, a seating category (regular or VIP), and is assigned a unique customer ID. The system should allow customers to be queued, and the ticket processing time should be calculated based on their seating category.

// Classes to Implement:
// Customer Class:

// Attributes:

// id (integer): A unique identifier for the customer.

// Methods:

// inputId(): Prompts the user to input their customer ID.

// getId(): Returns the customer's ID.

// Ticket Class:

// Attributes:

// movieName (string): The name of the movie selected by the customer. The movie name must be one of the following: "A", "B", "C", "D", or "E".

// seating (string): The seating category chosen by the customer. It can be either "regular" or "vip".

// Methods:

// TicketInfo(): Prompts the user to select a movie and a seating category.

// processingTime(): Based on the seating category:

// For regular seating, the processing time is 8 seconds.

// For VIP seating, the processing time is 6 seconds.

// If the user enters an invalid seating category or movie name, the method should display an error message.

// Queue Class:

// Attributes:

// customers[]: An array that stores customer objects. The queue should support a maximum of 15 customers.

// tickets[]: An array that stores ticket objects corresponding to the customers.

// front: An integer representing the front of the queue (initially set to 0).

// rear: An integer representing the rear of the queue (initially set to -1).

// Methods:

// isFull(): Returns true if the queue is full (i.e., the queue has reached 15 customers).

// isEmpty(): Returns true if the queue is empty.

// enqueue(Customer customer, Ticket ticket): Adds a customer and their ticket to the queue. If the queue is full, display "HOUSEFULL".

// dequeue(): Removes the customer at the front of the queue. If the queue is empty, display "Queue is empty".

// display(int n): Displays the details of all customers in the queue and their processing times. After displaying, remove each customer from the queue using dequeue.

// Constraints:
// The queue can hold up to 15 customers.

// Each movie name should be one of the following valid options: "A", "B", "C", "D", or "E".

// The seating category should be either "regular" or "vip".

// Input validation should be performed to ensure the movie name and seating category are valid.

// Input:
// An integer n representing the number of customers.

// For each customer:

// An integer id representing the customer's ID.

// A string movieName representing the movie selection ("A", "B", "C", "D", or "E").

// A string seating representing the seating category ("regular" or "vip").

// Output:
// For each customer in the queue, display the following information:

// Customer ID.

// Movie Name.

// Seating Category.

// Processing time.

// After processing all customers, display a message indicating that all customers have been served.

// Example:

// Input:
// Enter number of customers: 3
// Enter your Id: 101
// Choose Movie (Movie A/B/C/D/E): A
// Choose seating category (regular/vip): regular

// Enter your Id: 102
// Choose Movie (Movie A/B/C/D/E): B
// Choose seating category (regular/vip): vip

// Enter your Id: 103
// Choose Movie (Movie A/B/C/D/E): C
// Choose seating category (regular/vip): regular


// Outpu

// No of customers: 3
// ------------
// Customer 1
// ID: 101
// Movie: A
// Seating Category: regular
// Processing time is 8 sec
// Ticket for customer 1 processed!!
// -----------------
// Customer 2
// ID: 102
// Movie: B
// Seating Category: vip
// Processing time is 6 sec
// Ticket for customer 2 processed!!
// -----------------
// Customer 3
// ID: 103
// Movie: C
// Seating Category: regular
// Processing time is 8 sec
// Ticket for customer 3 processed!!
// -----------------
// All Customers have been served.
// Note:
// The queue operates on a First-Come, First-Served basis.

// The queue can hold a maximum of 15 customers. If more than 15 customers are added, print "HOUSEFULL".


#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int id;

public:
    void inputId() {
        cout << "Enter your Id: ";
        cin >> id;
    }
    int getId() const {
        return id;
    }
};

class Ticket {
private:
    string movieName; 
    string seating;

public:
    void TicketInfo() {
        cout << "Choose Movie (Movie A/B/C/D/E): ";
        cin >> movieName;
        cout << "Choose seating category (regular/vip): ";
        cin >> seating;
    }

    void processingTime() const {
        cout << "Movie: " << movieName;
        cout << "\nSeating Category: " << seating;

        if (seating == "regular") {
            cout << "\nProcessing time is 8 sec"; // (base time = 3 sec, regular = 5 sec)
        } else if (seating == "vip") {
            cout << "\nProcessing time is 6 sec "; // (base time = 3 sec, vip = 3 sec)
        } else {
            cout << "\nInvalid input for movie name or seating category.\n";
        }
    }
};

class Queue {
private:
    int front = 0;
    int rear = -1;
    Customer customers[15];
    Ticket tickets[15];

public:
    bool isFull() {
        return rear >= 14; 
    }

    bool isEmpty() {
        return front > rear; 
    }

    void enqueue(const Customer& customer, const Ticket& ticket) {
        if (isFull()) {
            cout << "HOUSEFULL!!....\n";
            return ;
        }
        rear = (rear + 1) ; 
        customers[rear] = customer;
        tickets[rear] = ticket;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!!\n";
            return;
        }
        front++ ; 
    }

    void display(int n) {
        if (isEmpty()) {
            cout << "Now Queue is empty!!\n";
            return;
        }
       
        
        for(int i=0 ; i<n ; i++) {
            cout << "Customer " <<(i+1)<<"\nID:  "<< customers[i].getId() << "\n";
            tickets[i].processingTime();
            cout << "Ticket for customer " <<(i+1)<< " processed!!\n-----------------\n";
        } 
        cout << "All Customers have been served.\n";
    }
};

int main() {
    int n;
    Queue queue;
    cout << "Enter number of customers: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Customer customer;
        Ticket ticket;

        // Input customer ID
        customer.inputId();
        
        // Input ticket details
        ticket.TicketInfo();

        // Enqueue customer and ticket
        queue.enqueue(customer, ticket);
    }

    cout << "\nNo of customers: " << n << "\n------------\n";
    
        queue.display(n); // Display the queue after each dequeue

        queue.dequeue(); // Dequeue each customer    
    return 0;
}
