// Date: 9th Mar, 2023

// Problem: https://leetcode.com/problems/linked-list-cycle-ii/description/

// Solution -->
class Solution
{
public:
     ListNode *detectCycle(ListNode *head)
     {
          unordered_set<ListNode *> nodes;

          ListNode *temp = head;
          while (temp != NULL)
          {
               if (nodes.find(temp) != nodes.end())
               {
                    return temp;
               }
               nodes.insert(temp);
               temp = temp->next;
          }

          return NULL;
     }
};