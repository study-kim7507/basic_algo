#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int init;
vector<pair<int, int>> edges[201];
long long distInit[201];

long long dijkstra(int st, int en)
{
    long long dist[201];
    fill(dist, dist + 201, 0x3f3f3f3f);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : edges[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    
    if (st == init)
    {
        for (int i = 0; i <= 200; i++)
            distInit[i] = dist[i];
    }
    return dist[en];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    init = s;
    
    for (auto fare : fares)
    {
        int u = fare[0];
        int v = fare[1];
        int c = fare[2];
        
        edges[u].push_back({c, v});
        edges[v].push_back({c, u});
    }
    
    long long answer = 0x3f3f3f3f;

    dijkstra(s, a);    
    answer = min(answer, distInit[a] + dijkstra(a, b)); // 1. s->a->b
    answer = min(answer, distInit[b] + dijkstra(b, a)); // 2. s->b->a

    for (int i = 1; i <= n; i++)
        answer = min(answer, distInit[i] + dijkstra(i, a) + dijkstra(i, b));
    
    return answer;
}