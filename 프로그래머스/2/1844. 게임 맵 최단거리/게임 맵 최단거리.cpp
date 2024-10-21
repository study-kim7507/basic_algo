#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dist[101][101];

int solution(vector<vector<int> > maps)
{
    int m = maps.size();        // 세로
    int n = maps[0].size();     // 가로
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (maps[nx][ny] != 1) continue;
            if (dist[nx][ny] != 0) continue;
            dist[nx][ny] += dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[m-1][n-1] == 0) return -1;
    else return dist[m-1][n-1];
    
}