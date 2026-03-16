#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
            bfs(i, adj, visited);
            count++;
        }
    }

    return count;
}