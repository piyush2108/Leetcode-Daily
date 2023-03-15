// Date: 10th Mar, 2023

// Problem: https://leetcode.com/problems/linked-list-random-node/

// Solution -->
class Solution
{
public:
     typedef ListNode Node;
     Node *head;
     int n;
     int len(Node *head)
     {
          int l = 0;
          Node *temp = head;
          while (temp)
          {
               l++;
               temp = temp->next;
          }
          return l;
     }
     Solution(Node *root)
     {
          head = root;
          n = len(head);
     }

     int getRandom()
     {
          int random = rand() % n;
          Node *temp = head;
          for (int i = 0; i < random; i++)
          {
               temp = temp->next;
          }
          return temp->val;
     }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */