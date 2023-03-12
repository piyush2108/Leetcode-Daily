class Solution
{
public:
     int maxScore(vector<int> &nums)
     {
          sort(nums.begin(), nums.end(), greater<>());
          long long preSum = 0;
          int maxScore = 0;

          for (int i = 0; i < nums.size(); i++)
          {
               preSum += nums[i];
               if (preSum > 0)
               {
                    maxScore += 1;
               }
               else
               {
                    preSum = 0;
               }
          }

          return maxScore;
     }
};