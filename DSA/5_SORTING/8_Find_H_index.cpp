// Problem Statement:

// Given a list of integers representing the number of citations for each of a researcher's papers, compute the researcher's H-Index.

// The H-Index is defined as the maximum value h such that the researcher has published h papers that have each been cited at least h times.

// Input:

// An integer n representing the number of papers.

// A list of n integers where each integer represents the number of citations for a paper.

// Output:

// An integer representing the H-Index of the researcher.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // Sorting citations in descending order
        sort(citations.begin(), citations.end(), greater<int>());
        int idx = 0;
        
        // Finding maximum h such that there are h papers with at least h citations
        while (idx < n && citations[idx] > idx) {
            idx++;
        }
        return idx;
    }
};

int main() {
    int n;
    cout << "Enter number of papers: ";
    cin >> n;
    
    vector<int> citations(n);
    cout << "Enter the citations for each paper: ";
    for(int i = 0; i < n; i++) {
        cin >> citations[i];
    }
    
    Solution obj;
    int result = obj.hIndex(citations);
    
    cout << "The H-Index is: " << result << endl;
    
    return 0;
}
