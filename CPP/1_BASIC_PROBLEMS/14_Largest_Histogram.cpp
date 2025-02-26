//Problem Statement:
// You are given an array heights[] where each element represents the height of a bar in a histogram. The width of each bar is 1. Your task is to find the area of the largest rectangle that can be formed within the histogram.

// Input:
// An integer array heights[] of size n where heights[i] represents the height of the i-th bar in the histogram.
// Output:
// Return the maximum rectangular area possible in the histogram.
// Example:
// Input:
// heights = [2,1,5,6,2,3]

// Output:
// 10

// Explanation:
// The largest rectangle is formed using the heights [5,6] with width 2, giving an area of 5 × 2 = 10.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> right(n,0);
            vector<int> left(n,0);
            stack<int> s;
    
           // right smaller
            for(int i = n-1 ; i>=0; i--){
                while(s.size() > 0 && heights[s.top()] >= heights[i]){
                    s.pop();
                }
    
                right[i] = s.empty() ? n : s.top();
                s.push(i);
            }
    
            while(!s.empty()){
                s.pop();
            }
            
            // left smaller
    
            for(int i = 0 ; i< n; i++){
                while(s.size() > 0 && heights[s.top()] >= heights[i]){
                    s.pop();
                }
    
                left[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
    
           int ans = 0;
            for(int i=0;i<n;i++){
                int w = right[i] - left[i] - 1;
                int currArea = heights[i] * w;
                ans = max(ans,currArea);
            }
    
         return ans;
        }
    };

    int main() {
        Solution s;
        vector<int> heights = {2,1,5,6,2,3};
        cout << s.largestRectangleArea(heights) << endl;
        return 0;
    }