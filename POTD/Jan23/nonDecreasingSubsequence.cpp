// Date: 20th Jan, 2023

// Problem: https://leetcode.com/problems/non-decreasing-subsequences/description/

// Solution -->
class Solution
{
public:
    void helper(int i, vector<int> nums, set<vector<int>> &ans, vector<int> &curr)
    {
        if (i >= nums.size())
        {
            if (curr.size() >= 2)
            {
                ans.insert(curr);
            }
            return;
        }

        if (curr.size() == 0 || nums[i] >= curr.back())
        {
            curr.push_back(nums[i]);
            helper(i + 1, nums, ans, curr);
            curr.pop_back();
            helper(i + 1, nums, ans, curr);
        }
        else
        {
            helper(i + 1, nums, ans, curr);
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> ans;

        vector<int> curr;
        helper(0, nums, ans, curr);
        return vector(ans.begin(), ans.end());
    }
};