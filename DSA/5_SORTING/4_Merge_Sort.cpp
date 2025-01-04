#include<iostream>
#include<vector>
using namespace std;

//merge function for merging two sorted part
void merge(vector<int>&arr,int st,int mid,int end){
    //create a temporary array
    vector<int>temp;
    int i = st, j = mid+1;

    while(i<=mid && j<=end){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
             temp.push_back(arr[j]);
            j++;
        }
    }

    //if left part is remaining
    while(i<= mid){
         temp.push_back(arr[i]);
            i++;
    } 
    //if right part is still remaining
    while(j<=end){
         temp.push_back(arr[j]);
            j++;
    }

    //after sorting now store elements in orignal array from temparory array
    for(int idx =0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int>&arr,int st,int end){
     if(st<end){
        //calculate mid
        int mid = st +(end-st)/2;
        
        //Recurssive call for left half
        mergeSort(arr,st,mid);
        //Recurssive call for right half
        mergeSort(arr,mid+1,end);

        //merge two sorrted part
        merge(arr,st,mid,end);
     }
}

int main(){
    vector<int>arr = {12,31,35,8,32,17};

    cout<<"Given:==>\n";
      for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;

    //call merge sort 
    mergeSort(arr,0,arr.size()-1);

    //print sorted array
      cout<<"After sorting:==>\n";
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}