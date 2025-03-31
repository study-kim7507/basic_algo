#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define X first
#define Y second

int n, m;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

bool board[51][51];
bool vis[51][51];


bool bfs(const vector<string>& storage, char cur, int i, int j)
{
    for (int a = 0; a < 51; a++)
        fill(vis[a], vis[a] + 51, false);
    
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                return true;
            }
            if (vis[nx][ny] || !board[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].length();
    cout << n << " " << m << "\n";
    
    for (string request : requests)
    {
        int len = request.length();
        char cur = request[0];
        
        // 길이가 1인 경우 접근 가능한 컨테이너만
        if (len == 1)
        {
            vector<pair<int, int>> v;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j]) continue;
                    if (storage[i][j] != cur) continue;
                    
                    if(bfs(storage, cur, i, j)) v.push_back({i, j});
                }
            }
            for (auto e : v)
                board[e.X][e.Y] = true;
        }
        // 길이가 2이상인 경우 모든 컨테이너 제거
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (storage[i][j] == cur) board[i][j] = true;                    
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
            if (!board[i][j]) answer++;
        }
        cout << "\n";
    }
    
    return answer;
}