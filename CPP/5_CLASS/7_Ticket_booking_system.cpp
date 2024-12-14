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
