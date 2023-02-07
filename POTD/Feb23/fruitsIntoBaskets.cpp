// Date: 7th Feb, 2023

// Problem: https://leetcode.com/problems/fruit-into-baskets/

// Solution -->
class Solution
{
public:
     int totalFruit(vector<int> &fruits)
     {

          int maxFruits = INT_MIN;
          int i = 0;
          int j = 0;

          unordered_map<int, int> mp;

          while (j < fruits.size())
          {
               mp[fruits[j]]++;

               if (mp.size() <= 2)
               {
                    maxFruits = max(maxFruits, j - i + 1);
               }

               else
               {
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0)
                    {
                         mp.erase(fruits[i]);
                    }
                    i++;
               }

               j++;
          }

          return maxFruits;
     }
};