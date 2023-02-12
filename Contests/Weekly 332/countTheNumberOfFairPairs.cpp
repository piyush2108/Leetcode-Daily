class Solution
{
public:
     long long countFairPairs(vector<int> &nums, int lower, int upper)
     {

          int N = nums.size();
          long long right = N - 1;
          long long count = 0;
          sort(nums.begin(), nums.end());

          while (right > 0)
          {

               auto it1 = lower_bound(nums.begin(), nums.end(), lower - nums[right]);

               long long start = it1 - nums.begin();

               auto it2 = upper_bound(nums.begin(), nums.end(), upper - nums[right]);

               --it2;

               long long end = it2 - nums.begin();

               end = min(end, right - 1);

               if (end - start >= 0)
               {
                    count += (end - start + 1);
               }

               right--;
          }

          return count;
     }
};