// Date: 18th Jan, 2023

// Problem: https://leetcode.com/problems/maximum-sum-circular-subarray/

// Solution -->
class Solution
{
public:
    int sumKadanes(vector<int> &nums)
    {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(sum, ans);
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int> nums)
    {
        int maxSub = sumKadanes(nums);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] *= -1;
        }
        int minSub = sumKadanes(nums);
        if (sum == minSub)
            return maxSub;
        if (sum + minSub == 0)
            return maxSub;
        return max(maxSub, sum + minSub);
    }
};