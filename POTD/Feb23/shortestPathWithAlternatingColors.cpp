// Date: 10th Feb, 2023

// Problem: https://leetcode.com/problems/shortest-path-with-alternating-colors/

// Solution -->
class Solution
{
public:
     vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
     {

          vector<int> ans(n, -1);

          vector<pair<int, int>> adj[n + 1];

          for (auto edge : redEdges)
          {
               adj[edge[0]].push_back({edge[1], 1});
          }

          for (auto edge : blueEdges)
          {
               adj[edge[0]].push_back({edge[1], 2});
          }

          queue<vector<int>> q;
          q.push({0, 0, -1});
          while (!q.empty())
          {
               auto front = q.front();
               q.pop();

               int node = front[0];
               int edge = front[2];
               if (ans[node] == -1)
               {
                    ans[node] = front[1];
               }

               for (auto &childPair : adj[node])
               {
                    int childV = childPair.first, edgeColorOfChild = childPair.second;
                    if (childV != -1 && (edge == -1 || edge != edgeColorOfChild))
                    {
                         q.push({childV, front[1] + 1, edgeColorOfChild});
                         childPair.first = -1;
                    }
               }
          }

          return ans;
     }
};