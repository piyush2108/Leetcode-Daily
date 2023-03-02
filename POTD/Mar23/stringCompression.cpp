// Date: 2nd Mar, 2023

// Problem: https://leetcode.com/problems/string-compression/

// Solution -->
class Solution
{
public:
     int compress(vector<char> &chars)
     {
          int n = chars.size();
          if (n == 1)
               return n;

          int i = 0, j = 0;
          while (i < n)
          {
               int count = 1;
               while (i < n - 1 and chars[i] == chars[i + 1])
               {
                    count++;
                    i++;
               }
               chars[j++] = chars[i++];
               if (count > 1)
               {
                    string s = to_string(count);
                    for (auto i : s)
                         chars[j++] = i;
               }
          }

          return j;
     }
};