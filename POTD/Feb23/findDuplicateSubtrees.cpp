// Date: 28th Feb, 2023

// Problem: https://leetcode.com/problems/find-duplicate-subtrees/

// Solution -->
class Solution
{
     unordered_map<string, int> freq;
     vector<TreeNode *> duplicates;

public:
     vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
     {
          traverse(root);
          return duplicates;
     }

     string traverse(TreeNode *node)
     {
          if (!node)
               return "x";
          string id = to_string(node->val) + "," + traverse(node->left) + traverse(node->right);
          this->freq[id]++;
          if (this->freq[id] == 2)
          {
               this->duplicates.push_back(node);
          }

          return id;
     }
};