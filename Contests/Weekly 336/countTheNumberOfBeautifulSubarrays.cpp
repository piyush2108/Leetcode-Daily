class Solution
{
public:
     long long beautifulSubarrays(vector<int> &nums)
     {
          int n = nums.size();
          long long ans = 0;

          int *xorArr = new int[n];

          unordered_map<int, int> mp;

          xorArr[0] = nums[0];

          for (int i = 1; i < n; i++)
               xorArr[i] = xorArr[i - 1] ^ nums[i];

          for (int i = 0; i < n; i++)
          {

               int tmp = 0 ^ xorArr[i];

               ans = ans + ((long long)mp[tmp]);

               if (xorArr[i] == 0)
                    ans++;

               mp[xorArr[i]]++;
          }

          return ans;
     }
};