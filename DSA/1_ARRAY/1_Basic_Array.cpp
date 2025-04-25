// Problem Statement:

// Write a C++ program that demonstrates the following:

// Basic Array Operations:

// Declare an integer array with 5 elements.

// Display the size of the array and the number of elements in the array.

// Array Input and Output Using Loops:

// Declare an array to store marks of 5 students.

// Allow the user to input the marks for 5 students using a loop.

// Display the entered marks after the user provides the input.

// Your program should perform the following:

// Use sizeof to determine the size of the array and the number of elements.

// Use loops to input and output the marks of students.


#include<iostream>
using namespace std;

int main(){
           //BASIC
    {
    //declare an array
    int arr[]={1,2,3,4,5};

    //size of array (size of datatype)*(no of elements)
    //here size will be 4*5 = 20
    cout<<"size of array = "<<sizeof(arr);

    //no of elements (size of array)/(size of datatype)
    //here no of elements will be 
    cout<<"\nno of elements are =  "<<sizeof(arr)/sizeof(int);
    cout<<endl;
    }
        
         //LOOPS ON ARRAY
    {
        int size = 5;
        int marks[size];
       
       //store in array
       cout<<"\nEnter marks of 5 students:\n";
        for(int i=0;i<=size-1;i++){
             cin>>marks[i];
        }
    
      //print
      cout<<"You entered:\n";
      for(int i=0;i<=size-1;i++){
             cout<<""<<marks[i]<<" ";
        }
     
     cout<<"\n";

    }

    return 0;