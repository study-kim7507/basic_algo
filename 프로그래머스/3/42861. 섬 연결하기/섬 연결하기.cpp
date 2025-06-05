#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
int uf_find(int x)
{
    if (x != parent[x]) return parent[x] = uf_find(parent[x]);
    return x;
}

void uf_union(int x, int y)
{
    x = uf_find(x);
    y = uf_find(y);
    
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

vector<pair<int, pair<int, int>>> edges;
int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    
    for (auto e : costs)
    {
        int u = e[0];
        int v = e[1];
        int c = e[2];
        
        edges.push_back({c, {u, v}});
        edges.push_back({c, {v, u}});
    }
    
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    int answer = 0;
    for (auto edge : edges)
    {
        if (uf_find(edge.second.first) != uf_find(edge.second.second))
        {
            uf_union(edge.second.first, edge.second.second);
            cnt++;
            answer += edge.first;
            if (cnt == n - 1) break;
        }
    }
    return answer;
}