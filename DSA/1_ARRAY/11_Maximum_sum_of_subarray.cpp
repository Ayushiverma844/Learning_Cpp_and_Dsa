//Brute force approch

#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;

    int maxSum = 0;
    
    //accept size
    cout<<"Enter size of array : ";
    cin>>n;

    //array of size n
    int arr[n];

    //store value in array
    cout<<"Enter elements: ";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //calculate maximum sum of subarray

    for(int st=0 ; st<n;st++){    //st = start
        int cs = 0;    // current sum
      for(int end=st; end<n ; end++){   
         cs += arr[end];
         maxSum = max(cs,maxSum); 
      }
    }

    cout<<"MAximum subarray sum = "<<maxSum<<endl;
    
    return 0;
}