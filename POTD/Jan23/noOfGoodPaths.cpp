Date: 15th Jan, 2023

Problem: https://leetcode.com/problems/number-of-good-paths/description/

Solution -->
class Solution {
private:
    vector<map<int, int>> mp;
    vector<int> flag;
    vector<vector<int>> adj;
    
public:
     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
          
          //total number of nodes present
          int n = vals.size();

          //to store the frequency of values
          mp.resize(n);
          //adjacency list to store the nodes in graph
          adj.resize(n);
          //to keep a check of visited nodes
          flag.resize(n, 0);


          //making adjacency list using given edges
          for(auto edge: edges){
               adj[edge[0]].push_back(edge[1]);
               adj[edge[1]].push_back(edge[0]);
          }

          int ans = 0;
          dfs(0, ans, vals);

          //every single node is considered as a good path
          //add total number of nodes to the final count
          return ans + n;
     }

     void dfs(int u, int &ans, vector<int> &vals){

          flag[u] = 1;

          for(auto it: adj[u]){
               //if the node is encountered previously than skip the calculation
               if(flag[it] == 1){
                    continue;
               }
               int cnt = 0;
               dfs(it, cnt, vals);
               ans += cnt;

               //remove the smaller values from path
               auto it2 = mp[it].lower_bound(vals[u]);
               mp[it].erase(mp[it].begin(), it2);

               if(mp[u].size() < mp[it].size()){
                    swap(mp[u], mp[it]);
               }

               for(auto it3: mp[it]){
                    ans += mp[u][it3.first] * it3.second;
                    mp[u][it3.first] += it3.second;
               }
          }
          ans += mp[u][vals[u]];
          ++mp[u][vals[u]];
     }
};