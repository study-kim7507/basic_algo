#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> adj[201];

int bfs(int n, vector<vector<int>> computers)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && computers[i][j] == 1) adj[i].push_back(j);
    
    bool vis[201];
    for (int i = 0; i < n; i++) vis[i] = false;
    
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true) continue;
        queue<int> q;
        q.push(i); vis[i] = true;
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (auto nxt : adj[cur])
            {
                if (vis[nxt] == true) continue;
                q.push(nxt); vis[nxt] = true;
            }
        }
        ans++;
    }
    
    return ans;
}

int solution(int n, vector<vector<int>> computers) {
    return bfs(n, computers);
}