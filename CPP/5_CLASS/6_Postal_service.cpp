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
            cout << "\nProcessing time is 4 sec\n";   //(base time =2sec , small = 1sec, domestic = 1sec)
        } else if (size == "small" && destination == "international") {
            cout << "\nProcessing time is 7 sec\n";   //(base time = 2sec , small = 1sec , international = 3sec)
        } else if (size == "medium" && destination == "domestic") {
            cout << "\nProcessing time is 6 sec\n";   //(base time = 2sec , medium = 3sec , domestic = 1 sec)
        } else if (size == "medium" && destination == "international") {
            cout << "\nProcessing time is 9 sec\n";   //(base time = 2sec , medium = 3sec , international = 4sec)
        } else if (size == "large" && destination == "domestic") {
            cout << "\nProcessing time is 8 sec\n";   //(base time = 2sec , large = 5sec , domestic = 1 sec)
        } else if (size == "large" && destination == "international") {
            cout << "\nProcessing time is 11 sec\n";  //(base time = 2sec , large = 3sec , international = 4sec)
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

    void display(int n) {
        if (isEmpty()) {
            cout << "Now Queue is empty!!\n";
            return;
        }
        for (int i = 0; i<n; i++) {
            cout << "Customer "<<i+1<<" ID: " << customers[i].getId() << endl;
            parcels[i].processingTime();
            cout<<"Parcel for customer"<<i+1<<" processed!!\n-----------------\n";
        }
        cout<<"All Customer have been serve..";
    }
};

int main() {
    int n;
    Queue queue;
    Customer customer;
    Parcel parcel;
    cout<<"Enter no of customer: ";
    cin>>n;

  for(int i=0;i<n;i++){
    // Input customer ID
    customer.inputId();
    
    // Input parcel details
    parcel.parcelInput();

    // Enqueue customer and parcel
    queue.enqueue(customer, parcel);
  }

cout<<"\nNo of customer : "<<n<<"\n------------\n";
  
    // Display the queue
    queue.display(n);
    // Dequeue a customer
    queue.dequeue();

    return 0;
}
