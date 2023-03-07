// Date: 7th Mar, 2023

// Problem: https://leetcode.com/problems/minimum-time-to-complete-trips/

// Solution -->
class Solution
{
public:
     long long tripsCount(vector<int> &nums, long long time)
     {

          long long trips = 0;

          for (auto i : nums)
          {

               long long val = i;

               trips += (time / val);
          }

          return trips;
     }

     long long minimumTime(vector<int> &nums, int totalTrips)
     {

          long long low = 1;
          long long high = 1e14;

          while (low < high)
          {

               long long mid = (low + high) / 2;

               long long count = tripsCount(nums, mid);

               if (count >= totalTrips)
                    high = mid;

               else
                    low = mid + 1;
          }

          return low;
     }
};