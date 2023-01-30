class Solution
{
public:
     int distinctIntegers(int n)
     {
          set<int> distNums;
          queue<int> q;
          q.push(n);

          while (!q.empty())
          {
               int front = q.front();
               distNums.insert(front);
               q.pop();
               for (int i = 1; i <= front; i++)
               {
                    if (front % i == 1)
                    {
                         q.push(i);
                    }
               }
          }

          return distNums.size();
     }
};