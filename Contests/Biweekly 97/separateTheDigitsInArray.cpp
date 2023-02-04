class Solution
{
public:
     vector<int> separateDigits(vector<int> &nums)
     {
          vector<int> ans;
          int n = nums.size();

          for (int i = 0; i < n; i++)
          {

               vector<int> digits;
               int n = nums[i];

               while (n)
               {
                    digits.push_back(n % 10);
                    n = n / 10;
               }

               for (int j = digits.size() - 1; j >= 0; j--)
               {
                    ans.push_back(digits[j]);
                    digits.clear();
               }
          }

          return ans;
     }
};