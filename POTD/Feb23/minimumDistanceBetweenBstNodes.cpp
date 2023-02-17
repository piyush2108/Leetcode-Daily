// Date: 17th Feb, 2023

// Problem: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

// Solution -->
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
     int minDiffInBST(TreeNode *root)
     {
          TreeNode *prev = NULL;
          int ans = INT_MAX;
          inorder(root, prev, ans);
          return ans;
     }

     void inorder(TreeNode *root, TreeNode *&prev, int &ans)
     {
          if (!root)
          {
               return;
          }

          inorder(root->left, prev, ans);

          if (prev != NULL)
          {
               ans = min(ans, root->val - prev->val);
          }
          prev = root;

          inorder(root->right, prev, ans);
     }
};