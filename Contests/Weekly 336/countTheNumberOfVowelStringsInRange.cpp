class Solution
{
public:
     int vowelStrings(vector<string> &words, int left, int right)
     {
          if (left < 0 || right > words.size())
          {
               return -1;
          }
          unordered_map<char, int> mp;
          mp.insert({'a', 1});
          mp.insert({'e', 1});
          mp.insert({'i', 1});
          mp.insert({'o', 1});
          mp.insert({'u', 1});
          mp.insert({'A', 1});
          mp.insert({'E', 1});
          mp.insert({'I', 1});
          mp.insert({'O', 1});
          mp.insert({'U', 1});

          int count = 0;
          for (int i = left; i <= right; i++)
          {
               if (mp.find(words[i][0]) != mp.end() && mp.find(words[i][words[i].size() - 1]) != mp.end())
               {
                    count++;
               }
          }

          return count;
     }
};