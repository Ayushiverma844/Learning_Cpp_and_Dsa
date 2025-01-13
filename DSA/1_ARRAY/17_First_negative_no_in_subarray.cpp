#include<iostream>
#include<vector>
using namespace std;

vector<int>negative(int arr[],int size,int k){
    int i=0,j=0;
    vector<int>ans;

    while(j<size){
        //if the current window size is less then k , expand the window
        if(j-i+1 < k){
            j++;
        }
        //if the window size is exactly k, process the window 
        else if(j-i+1 == k){
            bool found = false;
            // search for the first negative number in the current window
            for(int idx = i; idx <=j ; idx++){
                if(arr[idx] < 0){
                    ans.push_back(arr[idx]);
                    found = true;
                    break;
                }
            }
            // if no negative number was found , store 0
            if(!found){
                ans.push_back(0);
            }

            //slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[6] = {1,2,3,4,-5,6};
    int k;
    cout<<"Enter size of subarray: ";
    cin>>k;
    vector<int>result = negative(arr,6,k);

    cout<<"First negative numbers of all subarrays: \n";
    for(int val : result){
        cout<<val<<" ";
    }
    return 0;
}