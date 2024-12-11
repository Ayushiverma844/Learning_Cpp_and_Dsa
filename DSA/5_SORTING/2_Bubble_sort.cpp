#include <iostream>
using namespace std;


// Bubble sort implementation
void Bubble_sort(int array[],int size){
   
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1- i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                int temp = array[j];
               array[j] =array[j + 1];
               array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout<<"Enter size : ";
    cin>>size;
    int a[size];
    int i, j;

    // Input values into the array
    for (i = 0; i < size; i++) {
        cout<<"Enter value: ";
        cin>>a[i];
    }

    // Display the entered elements
    cout<<"Entered Elements: ";
    for (i = 0; i < size; i++) {
        cout<<" "<<a[i];
    }
    cout<<"\n";

    //call function
    Bubble_sort(a,size);
    
    // Display sorted elements
    printf("Elements after bubble sort: ");
    for (i = 0; i < size; i++) {
        cout<<" "<<a[i];
    }
    cout<<"\n";

    return 0;
}