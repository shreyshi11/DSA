#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(int n, vector<vector<int>>& adj)
{
    vector<bool> visited(n, false);
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1};
    adj[1] = {0};
    adj[2] = {};
    adj[3] = {4};
    adj[4] = {3};

    cout << "Number of components: " << countComponents(n, adj);

    return 0;
}