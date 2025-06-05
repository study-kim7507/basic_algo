#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

int dist[51];
vector<pair<int, int>> edges[51];

int solution(int N, vector<vector<int> > road, int K) {
    fill(dist, dist + 51, INF);
    for (auto e : road)
    {
        int u = e[0];
        int v = e[1];
        int c = e[2];
        edges[u].push_back({c, v});
        edges[v].push_back({c, u});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while(!pq.empty())
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
    
    int answer = 0;
    for (int i = 1; i <= N; i++)
        if (dist[i] <= K) answer++;
    
    return answer;
}