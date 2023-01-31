// Date: 31st Jan, 2023

// Problem: https://leetcode.com/problems/best-team-with-no-conflicts/

// Solution -->
class Solution
{
public:
     int bestTeamScore(vector<int> &scores, vector<int> &ages)
     {
          vector<pair<int, int>> ageAndScore;

          for (int i = 0; i < ages.size(); i++)
          {
               ageAndScore.push_back({ages[i], scores[i]});
          }
          sort(ageAndScore.begin(), ageAndScore.end());

          return maxScore(ageAndScore);
     }

     int maxScore(vector<pair<int, int>> ageAndScore)
     {
          int n = ageAndScore.size();

          int ans = 0;
          vector<int> scores(n);
          for (int i = 0; i < n; i++)
          {
               scores[i] = ageAndScore[i].second;
               ans = max(ans, scores[i]);
          }

          for (int i = 0; i < n; i++)
          {
               for (int j = i - 1; j >= 0; j--)
               {
                    if (ageAndScore[i].second >= ageAndScore[j].second)
                    {
                         scores[i] = max(scores[i], ageAndScore[i].second + scores[j]);
                    }
               }
               ans = max(ans, scores[i]);
          }

          return ans;
     }
};