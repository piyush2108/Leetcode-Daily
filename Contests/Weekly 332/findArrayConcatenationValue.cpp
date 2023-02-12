class Solution
{
public:
     long long findTheArrayConcVal(vector<int> &nums)
     {
          int n = nums.size();
          int start = 0;
          int end = n - 1;
          long long sum = 0;

          while (start < end)
          {
               string s1 = to_string(nums[start]);
               string s2 = to_string(nums[end]);

               sum += stoi(s1 + s2);
               start++;
               end--;
          }

          if (n % 2)
          {
               sum += nums[n / 2];
          }

          return sum;
     }
};