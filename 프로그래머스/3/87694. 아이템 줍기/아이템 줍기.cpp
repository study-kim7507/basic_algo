#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int board[101][101];
int vis[101][101];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    // 1. 직사각형을 순회하며 지형을 채움
    // 직사각형 최대 4개, 지형 100x100 => 40000
    for (auto& e : rectangle)
    {
        int stX = e[0] * 2;
        int stY = e[1] * 2;
        int enX = e[2] * 2;
        int enY = e[3] * 2;
        
        for (int y = enY; y >= stY; y--)
        {
            for (int x = enX; x >= stX; x--)
            {
                if (x == stX || x == enX || y == stY || y == enY)
                {
                    if (board[y][x] != 2) board[y][x] = 1;
                }
                else board[y][x] = 2;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterY * 2, characterX * 2});
    vis[characterY * 2][characterX * 2]++;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            if (nx <= 0 || ny <= 0 || nx > 100 || ny > 100) continue;
            if (vis[ny][nx] != 0 && vis[ny][nx] <= vis[cur.first][cur.second] + 1) continue;
            if (board[ny][nx] == 0 || board[ny][nx] == 2) continue;
            
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }

    return vis[itemY * 2][itemX * 2] / 2;
}