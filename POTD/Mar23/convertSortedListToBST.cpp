// Date: 11th Mar, 2023

// Problem: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

// Solution -->
class Solution
{
     ListNode *findMid(ListNode *head)
     {
          ListNode *slow = head;
          ListNode *fast = head;
          ListNode *prev = head;
          while (fast && fast->next)
          {
               prev = slow;
               slow = slow->next;
               fast = fast->next->next;
          }
          if (prev)
          {
               prev->next = NULL;
          }
          return slow;
     }
     TreeNode *func(ListNode *head)
     {
          if (head == NULL)
               return NULL;
          ListNode *mid = findMid(head);
          TreeNode *root = new TreeNode(mid->val);

          if (head == mid)
          {
               return root;
          }
          root->left = func(head);
          root->right = func(mid->next);
          return root;
     }

public:
     TreeNode *sortedListToBST(ListNode *head)
     {
          return func(head);
     }
};