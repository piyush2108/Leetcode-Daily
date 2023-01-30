// Date: 16th Jan, 2023

// Problem: https://leetcode.com/problems/insert-interval/

// Solution -->
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        // calculate the total no. of intervals present
        int n = intervals.size();

        vector<vector<int>> ans;
        int i = 0; // to iterate over the intervals

        // push the intervals which are smaller thant the given intervals into ans
        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // if new interval is overlapping with other interval, change the new interval accordingly
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // push the remaining intervals to ans
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};