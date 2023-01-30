// Date: 22nd Jan, 2023

// Problem: https://leetcode.com/problems/palindrome-partitioning/description/

// Solution -->
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;

        vector<string> str;
        helper(0, s, ans, str);
        return ans;
    }

    void helper(int index, string s, vector<vector<string>> &ans, vector<string> &str)
    {
        int n = s.size();

        if (index == n)
        {
            ans.push_back(str);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (isPalindrome(s, index, i))
            {
                str.push_back(s.substr(index, i - index + 1));
                helper(i + 1, s, ans, str);
                str.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};