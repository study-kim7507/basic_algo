#include <string>
#include <vector>

using namespace std;

long long dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 0; i <= 200; i++)
        fill(dist[i], dist[i] + 201, 0x3f3f3f3f);
    
    for (int i = 0; i <= 200; i++)
        dist[i][i] = 0;
    
    for (auto fare : fares)
    {
        int u = fare[0];
        int v = fare[1];
        int c = fare[2];
        dist[u][v] = dist[v][u] = c;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    long long answer = dist[s][a] + dist[a][b];
    answer = min(answer, dist[s][b] + dist[b][a]);
    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}