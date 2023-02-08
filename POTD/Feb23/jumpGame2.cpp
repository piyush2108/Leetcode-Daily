// Date: 8th Feb, 2023

// Problem: https://leetcode.com/problems/jump-game-ii/

// Solution -->
class Solution
{
public:
     int jump(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> dp(n, -1);
          return helper(nums, dp, n, 0);
     }

     int helper(vector<int> &nums, vector<int> &dp, int n, int start)
     {
          if (start == n - 1)
          {
               return dp[start] = 0;
          }

          int maxSteps = nums[start];
          if (maxSteps + start >= n - 1)
          {
               return dp[start] = 1;
          }

          if (dp[start] != -1)
          {
               return dp[start];
          }

          int ans = INT_MAX;
          for (int i = 1; i <= maxSteps; i++)
          {
               ans = min(ans, helper(nums, dp, n, start + i));
          }

          if (ans != INT_MAX)
          {
               ans++;
          }

          return dp[start] = ans;
     }
};