#include<iostream>
using namespace std;

int main() {
    int size;
     int mx = -1999999;     // any no.
    cout << "Enter size: ";
    cin >> size;

   
   int a[size];
   
    // Input values
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    
    cout<<"\n--------------\n";
   //maximum till ith element

   for(int i=0;i<size;i++){
    
    mx = max(mx,a[i]);    //update mx by maximum
    cout<<mx<<"\n";

   }

    return 0;
}