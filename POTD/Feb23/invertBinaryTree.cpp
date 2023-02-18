// Date: 18th Feb, 2023

// Problem: https://leetcode.com/problems/invert-binary-tree/

// Solution -->
class Solution
{
public:
     TreeNode *invertTree(TreeNode *root)
     {
          if (!root)
          {
               return root;
          }

          TreeNode *temp = root->left;
          root->left = root->right;
          root->right = temp;

          invertTree(root->left);
          invertTree(root->right);

          return root;
     }
};