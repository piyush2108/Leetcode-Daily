// Date: 26th Feb, 2023

// Problem: https://leetcode.com/problems/edit-distance/

// Solution -->
class Solution
{
public:
     int minDistance(string word1, string word2)
     {
          int n1 = word1.size();
          int n2 = word2.size();
          vector<vector<int>> dp(n1, vector<int>(n2, -1));

          return helper(n1 - 1, n2 - 1, word1, word2, dp);
     }

     int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
     {
          if (i < 0)
          {
               return j + 1;
          }
          if (j < 0)
          {
               return i + 1;
          }
          if (s1[i] == s2[j])
          {
               return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
          }

          if (dp[i][j] != -1)
          {
               return dp[i][j];
          }

          int min1 = helper(i - 1, j, s1, s2, dp);
          int min2 = helper(i, j - 1, s1, s2, dp);
          int min3 = helper(i - 1, j - 1, s1, s2, dp);

          return dp[i][j] = 1 + min(min(min1, min2), min3);
     }
};