// Date: 22nd Feb, 2023

// Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

// Solution -->
class Solution
{
public:
     int shipWithinDays(vector<int> &weights, int days)
     {
          int en = 0, st = *max_element(weights.begin(), weights.end());
          for (auto it : weights)
               en += it;
          int w = weights.size();
          while (st <= en)
          {
               int capacity = (st + en) / 2;
               int sum = 0, d = 0;
               for (int x = 0; x < w; x++)
               {
                    if (sum + weights[x] > capacity)
                    {
                         sum = 0;
                         d++;
                    }
                    sum += weights[x];
               }
               if (d + 1 <= days)
                    en = capacity - 1;
               else
                    st = capacity + 1;
          }
          return st;
     }
};