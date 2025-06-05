#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define INF 0x3f3f3f3f

int dist[20001];
vector<pair<int, int>> adjs[20001];

int solution(int n, vector<vector<int>> edge) {
    fill(dist, dist + 20001, INF);    
    for (auto e : edge)
    {
        int u = e[0];
        int v = e[1];
        
        adjs[u].push_back({1, v});
        adjs[v].push_back({1, u});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : adjs[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    
    int answer = 0;
    int maxDist = *max_element(dist + 1, dist + n + 1);
    for (int i = 1; i <= n; i++)
        if (dist[i] == maxDist) answer++;
    
    return answer;
}