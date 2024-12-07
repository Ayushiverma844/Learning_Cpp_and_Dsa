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