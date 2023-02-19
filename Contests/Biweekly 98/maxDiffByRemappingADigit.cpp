class Solution
{
public:
     int minMaxDifference(int num)
     {
          string s1 = to_string(num);
          string s2 = to_string(num);

          char digit1 = s1[0];
          char digit2 = s2[0];

          for (int i = 0; i < s1.size(); i++)
          {
               if (s1[i] != '9')
               {
                    digit1 = s1[i];
                    break;
               }
          }

          for (int i = 0; i < s1.size(); i++)
          {
               if (s1[i] == digit1)
               {
                    s1[i] = '9';
               }
          }

          for (int i = 0; i < s1.size(); i++)
          {
               if (s2[i] == digit2)
               {
                    s2[i] = '0';
               }
          }

          return stoi(s1) - stoi(s2);
     }
};