// Date: 13th Mar, 2023

// Problem: https://leetcode.com/problems/symmetric-tree/description/

// Solution -->
class Solution
{
public:
     bool isSymmetric(TreeNode *root)
     {
          if (!root)
               return false;
          return isSymmetric(root->left, root->right);
     }

     bool isSymmetric(TreeNode *node1, TreeNode *node2)
     {
          if (!node1 && !node2)
               return true;
          if (!node1 || !node2)
               return false;

          if (node1->val != node2->val)
               return false;

          return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
     }
};