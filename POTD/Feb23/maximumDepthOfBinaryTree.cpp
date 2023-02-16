// Date: 16th Feb, 2023

// Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
     int maxDepth(TreeNode *root)
     {

          if (!root)
          {
               return 0;
          }

          int leftMax = 0;
          int rightMax = 0;

          if (root->left)
          {
               leftMax = maxDepth(root->left);
          }
          if (root->right)
          {
               rightMax = maxDepth(root->right);
          }

          return 1 + max(leftMax, rightMax);
     }
};