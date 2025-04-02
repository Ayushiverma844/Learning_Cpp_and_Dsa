//Problem Statement:
// You are required to implement a system that processes a list of customers and their parcels. The system should ensure the following operations:

// Input:

// You are given an integer n (1 <= n <= 10), representing the number of customers.

// For each customer, you will get their unique ID (an integer) and the details of the parcel (size and destination).

// Output:

// After processing all customers, print the customer ID and their corresponding parcel processing time.

// For each customer, the processing time should be calculated and printed.

// Details:

// If the customer queue exceeds the maximum limit (10 customers), only the first 10 customers should be processed.

// If a customer tries to enter invalid parcel details (size or destination), an error message should be displayed for that customer.

// After processing each customer, their entry should be removed from the queue.

// Example:

// Input:
// Enter number of customers: 3
// Enter your Id: 1
// Enter size of parcel (small/medium/large): medium
// Enter destination (domestic/international): domestic
// Enter your Id: 2
// Enter size of parcel (small/medium/large): large
// Enter destination (domestic/international): international
// Enter your Id: 3
// Enter size of parcel (small/medium/large): small
// Enter destination (domestic/international): international

// Output:

// Processing 3 customers:
// ------------
// Customer ID: 1
// Size of parcel: medium
// Destination of parcel: domestic
// Processing time is 6 sec
// Parcel for customer processed!!
// -----------------
// Customer ID: 2
// Size of parcel: large
// Destination of parcel: international
// Processing time is 11 sec
// Parcel for customer processed!!
// -----------------
// Customer ID: 3
// Size of parcel: small
// Destination of parcel: international
// Processing time is 7 sec
// Parcel for customer processed!!
// -----------------
// All Customers have been served.

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

class Parcel {
private:
    string size;
    string destination;

public:
    void parcelInput() {
        cout << "Enter size of parcel (small/medium/large): ";
        cin >> size;
        cout << "Enter destination (domestic/international): ";
        cin >> destination;
    }

    void processingTime() const {
        cout << "Size of parcel: " << size;
        cout << "\nDestination of parcel: " << destination;

        if (size == "small" && destination == "domestic") {
            cout << "\nProcessing time is 4 sec\n";
        } else if (size == "small" && destination == "international") {
            cout << "\nProcessing time is 7 sec\n";
        } else if (size == "medium" && destination == "domestic") {
            cout << "\nProcessing time is 6 sec\n";
        } else if (size == "medium" && destination == "international") {
            cout << "\nProcessing time is 9 sec\n";
        } else if (size == "large" && destination == "domestic") {
            cout << "\nProcessing time is 8 sec\n";
        } else if (size == "large" && destination == "international") {
            cout << "\nProcessing time is 11 sec\n";
        } else {
            cout << "\nInvalid input for size or destination.\n";
        }
    }
};

class Queue {
private:
    int front = 0;
    int rear = -1;
    Customer customers[10];
    Parcel parcels[10];

public:
    bool isFull() {
        return rear >= 9;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(const Customer& customer, const Parcel& parcel) {
        if (isFull()) {
            cout << "Queue is Full!! Wait for a while....\n";
            return;
        }
        rear++;
        customers[rear] = customer;
        parcels[rear] = parcel;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!!\n";
            return;
        }
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!!\n";
            return;
        }
        while (!isEmpty()) {
            cout << "Customer ID: " << customers[front].getId() << endl;
            parcels[front].processingTime();
            cout << "Parcel for customer processed!!\n-----------------\n";
            dequeue();  // Remove after processing
        }
        cout << "All Customers have been served.\n";
    }
};

int main() {
    int n;
    Queue queue;
    Customer customer;
    Parcel parcel;

    cout << "Enter number of customers: ";
    cin >> n;

    if (n > 10) {
        cout << "Max customers limit (10) exceeded. Only processing first 10.\n";
        n = 10;
    }

    for (int i = 0; i < n; i++) {
        customer.inputId();
        parcel.parcelInput();
        queue.enqueue(customer, parcel);
    }

    cout << "\nProcessing " << n << " customers:\n------------\n";
    queue.display();

    return 0;
}
