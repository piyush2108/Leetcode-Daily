// Date: 6th Mar, 2023

// Problem: https://leetcode.com/problems/kth-missing-positive-number/submissions/909937925/

// Solution -->
class Solution
{
public:
     int findKthPositive(vector<int> &arr, int k)
     {
          int missing = 0; // initially number of missing numbers
          missing += arr[0] - 1;
          if (missing >= k)
               return k;

          for (int i = 1; i < arr.size(); i++)
          {
               int temp = missing + arr[i] - arr[i - 1] - 1;
               if (temp >= k)
                    return arr[i - 1] + k - missing;
               missing = temp;
          }

          return arr[arr.size() - 1] + k - missing;
     }
};