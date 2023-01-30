class Solution
{
public:
     const int mod = 1e9 + 7;

     long long power(long long x, long long b)
     {
          long long r = 1;
          while (b)
          {
               if (b & 1)
               {
                    r = r * x % mod;
               }
               x = x * x % mod;
               b >>= 1;
          }

          return r;
     }

     int monkeyMove(int n)
     {
          int ans = power(2, n);
          ans -= 2;
          ans += mod;
          return ans % mod;
     }
};