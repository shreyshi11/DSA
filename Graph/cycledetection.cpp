#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i] = 1;
                
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    for(auto neigh : adj[node]){
                        
                        if(!vis[neigh]){
                            vis[neigh] = 1;
                            q.push({neigh,node});
                        }
                        else if(neigh != parent){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};