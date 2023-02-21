// Date: 21st Feb, 2023

// Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/

// Solution -->
class Solution
{
public:
     int singleNonDuplicate(vector<int> &nums)
     {
          int n = nums.size();

          int start = 0;
          int end = n - 2;

          while (start <= end)
          {
               int mid = start + (end - start) / 2;

               if (nums[mid] == nums[mid ^ 1])
               {
                    start = mid + 1;
               }
               else
               {
                    end = mid - 1;
               }
          }

          return nums[start];
     }
};