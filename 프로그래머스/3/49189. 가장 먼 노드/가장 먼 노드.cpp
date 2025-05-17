#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> dist(n + 1, 0);
    vector<vector<int>> adjs(n + 1, vector<int>());
    
    for (const auto& e : edge)
    {
        int a = e[0];
        int b = e[1];
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    dist[1]++;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (auto nxt : adjs[cur])
        {
            if (dist[nxt] != 0 && dist[nxt] <= dist[cur] + 1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    int maxDist = *max_element(dist.begin(), dist.end());
    int answer = 0;
    for (const auto& e : dist)
    {
        if (e == maxDist) answer++;
    }
    
    return answer;
}