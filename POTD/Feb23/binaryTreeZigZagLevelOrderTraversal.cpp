// Date: 19th Feb, 2023

// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Solution -->
class Solution
{
public:
     vector<vector<int>> zigzagLevelOrder(TreeNode *root)
     {
          vector<vector<int>> ans;

          if (!root)
          {
               return ans;
          }

          queue<TreeNode *> q;
          q.push(root);
          bool flag = false;

          while (!q.empty())
          {
               int size = q.size();
               vector<int> res;

               while (size--)
               {
                    TreeNode *front = q.front();
                    q.pop();
                    res.push_back(front->val);

                    if (front->left)
                    {
                         q.push(front->left);
                    }

                    if (front->right)
                    {
                         q.push(front->right);
                    }
               }

               if (flag)
               {
                    reverse(res.begin(), res.end());
               }

               if (res.size())
               {
                    ans.push_back(res);
               }
               flag = !flag;
          }

          return ans;
     }
};