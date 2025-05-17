// 최소 신장 트리

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

// {cost, {a, b}}
vector<pair<int, pair<int, int>>> edges;

int f(int a)
{
    if (a == parent[a]) return a;
    return f(parent[a]);
}

void u(int a, int b)
{
    a = f(a);
    b = f(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < 101; i++)
        parent[i] = i;
    
    for (int i = 0; i < costs.size(); i++)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        edges.push_back({cost, {a, b}});
    }
    
    // 비용을 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    int answer = 0;
    for (auto& edge : edges)
    {
        int cost = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;
        
        // 이미 연결되어 있다면 건너 뜀
        if (f(a) == f(b)) continue;
        
        // 연결
        u(a, b);
        answer += cost;
        cnt++;
        
        if (cnt == n - 1) break;
    }
    
    return answer;
}