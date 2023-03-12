// Date: 12th Mar, 2023

// Problem: https://leetcode.com/problems/merge-k-sorted-lists/submissions/913553136/

// Solution -->
class Solution
{
public:
     ListNode *mergeKLists(vector<ListNode *> &lists)
     {
          int k = lists.size();
          if (k == 0)
          {
               return NULL;
          }
          vector<vector<int>> A(k);
          for (int i = 0; i < k; i++)
          {
               ListNode *node = lists[i];
               while (node != NULL)
               {
                    A[i].push_back(node->val);
                    node = node->next;
               }
          }
          ListNode *head = new ListNode(-1);
          ListNode *cur = head;
          priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
          for (int i = 0; i < k; i++)
          {
               if (A[i].size() != 0)
               {
                    pq.push({A[i][0], i, 0});
               }
          }
          while (!pq.empty())
          {
               vector<int> tp = pq.top();
               int smallest = tp[0];
               int listIdx = tp[1];
               int index = tp[2];
               pq.pop();
               cur->next = new ListNode(smallest);
               cur = cur->next;
               if (index + 1 < A[listIdx].size())
               {
                    pq.push({A[listIdx][index + 1], listIdx, index + 1});
               }
          }
          return head->next;
     }
};