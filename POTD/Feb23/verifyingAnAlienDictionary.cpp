// Date: 2nd Feb, 2023

// Problem: https://leetcode.com/problems/verifying-an-alien-dictionary/

// Solution -->
class Solution
{
public:
     bool isAlienSorted(vector<string> &words, string order)
     {
          unordered_map<char, int> mp;

          int n = order.size();
          int m = words.size();

          for (int i = 0; i < n; i++)
          {
               mp[order[i]] = i;
          }

          for (int i = 0; i < m - 1; i++)
          {
               if (!compare(words[i], words[i + 1], mp))
               {
                    return false;
               }
          }

          return true;
     }

     bool compare(string &str1, string &str2, unordered_map<char, int> mp)
     {

          int m = str1.size();
          int n = str2.size();

          for (int i = 0; i < min(m, n); i++)
          {
               if (mp[str1[i]] < mp[str2[i]])
               {
                    return true;
               }
               else if (mp[str1[i]] > mp[str2[i]])
               {
                    return false;
               }
          }

          if (n >= m)
          {
               return true;
          }
          else
          {
               return false;
          }
     }
};