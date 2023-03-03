// Date: 3rd Mar, 2023

// Problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// Solution -->
class Solution
{
public:
     int strStr(string haystack, string needle)
     {

          int n1 = haystack.size();
          int n2 = needle.size();

          if (haystack == needle)
          {
               return 0;
          }

          for (int i = 0; i < n1; i++)
          {

               string str = haystack.substr(i, n2);

               if (str == needle)
               {
                    return i;
               }
          }
          return -1;
     }
};