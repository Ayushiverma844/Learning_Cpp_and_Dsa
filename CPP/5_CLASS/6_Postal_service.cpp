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
