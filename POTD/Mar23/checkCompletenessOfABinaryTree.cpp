// Date: 15th Mar, 2023

// Problem: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

// Solution -->
class Solution
{
public:
     bool isCompleteTree(TreeNode *root)
     {
          if (!root)
               return true;

          queue<TreeNode *> q;
          q.push(root);
          bool flag = 0;

          while (!q.empty())
          {
               TreeNode *front = q.front();
               q.pop();

               if (front->left)
               {
                    if (flag)
                         return false;
                    q.push(front->left);
               }
               else
                    flag = 1;

               if (front->right)
               {
                    if (flag)
                         return false;
                    q.push(front->right);
               }
               else
                    flag = 1;
          }

          return true;
     }
};