// Date: 20th Feb, 2023

// Problem: https://leetcode.com/problems/search-insert-position/

// Solution -->
class Solution
{
public:
     int searchInsert(vector<int> &nums, int target)
     {
          int n = nums.size();
          int start = 0;
          int end = n - 1;

          int floor = -1;

          while (start <= end)
          {
               int mid = start + (end - start) / 2;

               if (nums[mid] == target)
               {
                    return mid;
               }

               if (nums[mid] > target)
               {
                    end = mid - 1;
               }
               else
               {
                    floor = mid;
                    start = mid + 1;
               }
          }

          return floor + 1;
     }
};