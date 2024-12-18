//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1


#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int lp = 0, rp = height.size() - 1;

    while (lp < rp) {
        int w = rp - lp; // Corrected width calculation
        int h = min(height[lp], height[rp]);

        int currentWater = h * w;
        maxWater = max(currentWater, maxWater);

        // Move the pointer with the smaller height to potentially find a larger area
        height[lp] < height[rp] ? lp++ : rp--;
    }
    return maxWater;
}

int main() {
    // Example input
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    
    int result = maxArea(height);
    cout << "Maximum area: " << result << endl; // Output the result
    return 0;
}