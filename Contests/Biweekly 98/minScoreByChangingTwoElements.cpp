class Solution
{
public:
     int minimizeSum(vector<int> &nums)
     {
          int n = nums.size();
          sort(nums.begin(), nums.end());

          int min1 = nums[n - 1] - nums[0];
          int min2 = nums[n - 1] - nums[2];
          int min3 = nums[n - 3] - nums[0];
          int min4 = nums[n - 2] - nums[1];

          return min({min1, min2, min3, min4});
     }
};