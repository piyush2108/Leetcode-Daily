// Date: 23rd Feb, 2023

// Problem: https://leetcode.com/problems/ipo/

// Solution -->
class Solution
{
public:
     int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
     {
          vector<pair<int, int>> v;
          for (int i = 0; i < profits.size(); ++i)
               v.push_back({capital[i], profits[i]});
          sort(v.begin(), v.end());
          int i = 0;
          priority_queue<int> maxProfit;
          while (k-- > 0)
          {
               while (i < v.size() && v[i].first <= w)
                    maxProfit.push(v[i++].second);
               if (maxProfit.empty())
                    break;
               w += maxProfit.top();
               maxProfit.pop();
          }
          return w;
     }
};