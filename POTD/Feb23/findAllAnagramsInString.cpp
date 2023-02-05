// Date: 5th Feb, 2023

// Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Solution -->
class Solution
{
public:
     vector<int> findAnagrams(string s, string p)
     {
          int n1 = s.size();
          int n2 = p.size();
          vector<int> ans;

          if (n2 > n1)
          {
               return ans;
          }

          unordered_map<char, int> mp;
          for (auto ch : p)
          {
               mp[ch]++;
          }

          int cnt = mp.size();
          int i = 0;
          int j = 0;

          while (j < n1)
          {
               if (mp.find(s[j]) != mp.end())
               {
                    mp[s[j]]--;
                    if (mp[s[j]] == 0)
                    {
                         cnt--;
                    }
               }

               if (j - i + 1 == n2)
               {
                    if (cnt == 0)
                    {
                         ans.push_back(i);
                    }

                    if (mp.find(s[i]) != mp.end())
                    {
                         mp[s[i]]++;
                         if (mp[s[i]] == 1)
                         {
                              cnt++;
                         }
                    }
                    i++;
                    j++;
               }

               else if (j - i + 1 < n2)
               {
                    j++;
               }
          }

          return ans;
     }
};