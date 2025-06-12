#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

vector<int> edges[100001];

int dijkstra(int st, int en)
{
    int dist[100001];
    fill(dist, dist + 100001, INF);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : edges[cur.second])
        {
            if (dist[nxt] <= dist[cur.second] + 1) continue;
            dist[nxt] = dist[cur.second] + 1;
            pq.push({dist[nxt], nxt});
        }
    }
    
    if (dist[en] == INF) return -1;
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