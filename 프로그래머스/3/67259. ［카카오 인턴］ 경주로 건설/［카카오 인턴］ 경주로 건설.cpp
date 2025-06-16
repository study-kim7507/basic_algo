#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define X first
#define Y second

#define INF 0x3f3f3f3f

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
int cost[26][26][4];

int solution(vector<vector<int>> board) {
    n = board.size();
    
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 4; k++)
                cost[i][j][k] = INF;
    
    queue<pair<pair<int, int>, int>> q;
    cost[0][0][0] = cost[0][0][1] = 0;
    q.push({{0, 0}, 0}); q.push({{0, 0}, 1});
    
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X.X + dx[dir];
            int ny = cur.X.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != 0) continue;
            
            int nxtCost = 100;
            if (cur.Y % 2 != dir % 2) nxtCost = 600;
            nxtCost += cost[cur.X.X][cur.X.Y][cur.Y];
            
            if (cost[nx][ny][dir] < nxtCost) continue;
            
            cost[nx][ny][dir] = nxtCost;
            q.push({{nx, ny}, dir});
        }
    }
    
    int answer = INF;
    for (int i = 0; i < 4; i++)
        answer = min(answer, cost[n-1][n-1][i]);
    
    return answer;
}