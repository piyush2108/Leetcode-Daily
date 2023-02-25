// Date: 25th Feb, 2023

// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Solution -->
class Solution
{
public:
     int maxProfit(vector<int> &prices)
     {
          int minVal = INT_MAX;
          int profit = 0;

          for (auto price : prices)
          {
               minVal = min(minVal, price);
               profit = max(profit, price - minVal);
          }

          return profit;
     }
};