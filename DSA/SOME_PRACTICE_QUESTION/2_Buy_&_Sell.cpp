
//PROBLEM : BEST TIME TO BUY AND SELL
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& price){
  // Initialize the best price to buy and max profit
    int bestBuy = price[0];
    int maxProfit = 0;

  // Loop through the prices starting from the second day
    for(int i=1;i< price.size(); i++){
        // If the current price is greater than the bestBuy price, calculate profit
        if(price[i] > bestBuy){
            maxProfit = max(maxProfit , (price[i]-bestBuy));
        }
         // Update the bestBuy price if a lower price is found
        bestBuy = min(bestBuy,price[i]);
    }
     // Return the maximum profit found
    return maxProfit;
}


int main(){
   vector<int> price= {7,1,5,3,6,4};

   //call fu----------nction
   int result = maxProfit( price);

   cout<<"Maximum profit "<<result<<endl;
    return 0;
}