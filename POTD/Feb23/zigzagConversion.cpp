// Date: 3rd Feb, 2023

// Problem: https://leetcode.com/problems/zigzag-conversion/

// Solution -->
class Solution
{
public:
     string convert(string s, int numRows)
     {
          vector<string> str(numRows, "");
          int i = 0;
          int n = s.size();

          while (i < n)
          {
               for (int j = 0; j < numRows && i < n; j++)
               {
                    str[j].push_back(s[i++]);
               }

               for (int j = numRows - 2; j >= 1 && i < n; j--)
               {
                    str[j].push_back(s[i++]);
               }
          }

          string ans = "";
          for (auto it : str)
          {
               ans += it;
          }

          return ans;
     }
};