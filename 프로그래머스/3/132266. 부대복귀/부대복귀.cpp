#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edges[100001];

int dijkstra(int st, int en)
{
    int dist[100001];
    fill(dist, dist + 100001, -1);

    queue<int> q;
    dist[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (auto nxt : edges[cur])
        {
            if (dist[nxt] != -1 && dist[nxt] <= dist[cur] + 1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    return dist[en];
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    for (auto road : roads)
    {
        int u = road[0];
        int v = road[1];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    vector<int> answer;
    for (auto source : sources)
    {
        answer.push_back(dijkstra(source, destination));
    }
    
    return answer;
}