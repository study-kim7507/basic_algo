#include <string>
#include <vector>
#include <queue>
using namespace std;

bool vis[201];
vector<int> adj[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (computers[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true) continue;
        
        queue<int> q;
        q.push(i);
        vis[i] = true;
        
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (auto nxt : adj[cur])
            {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        
        answer++;
    }
    
    return answer;
}