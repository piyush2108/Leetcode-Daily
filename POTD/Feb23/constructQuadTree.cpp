// Date: 27th Feb, 2023

// Problem: https://leetcode.com/problems/construct-quad-tree/

// Solution -->
class Solution
{
public:
     bool check_grid(vector<vector<int>> &grid, int si, int sj, int ei, int ej)
     {
          int num = grid[si][sj];
          for (int i = si; i <= ei; ++i)
          {
               for (int j = sj; j <= ej; ++j)
               {
                    if (grid[i][j] != num)
                         return false;
               }
          }
          return true;
     }

     Node *solve(vector<vector<int>> &grid, int si, int sj, int ei, int ej)
     {
          bool check = check_grid(grid, si, sj, ei, ej);
          if (check == true)
          {
               int val = grid[si][sj];
               Node *tmp = new Node(val, true);
               return tmp;
          }
          int dist = ei - si + 1;
          int halfdist = dist / 2;
          Node *topleft = solve(grid, si, sj, si + halfdist - 1, sj + halfdist - 1);
          Node *topright = solve(grid, si, sj + halfdist, si + halfdist - 1, ej);
          Node *bottomleft = solve(grid, si + halfdist, sj, ei, sj + halfdist - 1);
          Node *bottomright = solve(grid, si + halfdist, sj + halfdist, ei, ej);
          Node *res = new Node(0, false, topleft, topright, bottomleft, bottomright);
          return res;
     }

     Node *construct(vector<vector<int>> &grid)
     {
          return solve(grid, 0, 0, int(grid.size()) - 1, int(grid.size()) - 1);
     }
};