#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int n, m;
char board[11][11];
pair<int, int> goal;

// 상, 우, 하, 좌 기울이기
pair<int, int> dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int ans = numeric_limits<int>::max();


// 빨간 구슬 먼저 탈출 시 0
// 파란 구슬 먼저 탈출 시 1
// 두 구슬 동시에 탈출 시 2
// 그 외 3
int tilt(int d)
{
    pair<int, int> redCandy;
    pair<int, int> blueCandy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'B') blueCandy = { i, j };
            else if (board[i][j] == 'R') redCandy = { i, j };
        }
    }

    // 기울이는 방향
    pair<int, int> direction = dir[d];

    // 빨간 구슬 이동
    pair<int, int> nxt_redCandy = redCandy;
    while ((board[nxt_redCandy.first][nxt_redCandy.second] != '#') && (board[nxt_redCandy.first][nxt_redCandy.second] != 'O'))
    {
        nxt_redCandy.first += direction.first;
        nxt_redCandy.second += direction.second;
    }
    if (board[nxt_redCandy.first][nxt_redCandy.second] == '#')
    {
        nxt_redCandy.first -= direction.first;
        nxt_redCandy.second -= direction.second;
    }

    // 파란 구슬 이동
    pair<int, int> nxt_blueCandy = blueCandy;
    while ((board[nxt_blueCandy.first][nxt_blueCandy.second] != '#') && (board[nxt_blueCandy.first][nxt_blueCandy.second] != 'O'))
    {
        nxt_blueCandy.first += direction.first;
        nxt_blueCandy.second += direction.second;
    }
    if (board[nxt_blueCandy.first][nxt_blueCandy.second] == '#')
    {
        nxt_blueCandy.first -= direction.first;
        nxt_blueCandy.second -= direction.second;
    }

    // 구슬이 겹치는 경우, 둘 중 하나 이전 칸으로 이동
    if (nxt_redCandy == nxt_blueCandy)
    {
        // 구슬이 겹치는데, 겹치는 해당 위치가 구멍이면 두 구슬 모두 탈출하게 된다.
        if (nxt_redCandy == goal && nxt_blueCandy == goal)
            return 2;

        int redCandyDist = abs(nxt_redCandy.first - redCandy.first) + abs(nxt_redCandy.second - redCandy.second);
        int blueCandyDist = abs(nxt_blueCandy.first - blueCandy.first) + abs(nxt_blueCandy.second - blueCandy.second);

        if (redCandyDist < blueCandyDist)
        {
            nxt_blueCandy.first -= direction.first;
            nxt_blueCandy.second -= direction.second;
        }

        else
        {
            nxt_redCandy.first -= direction.first;
            nxt_redCandy.second -= direction.second;
        }
    }

    if (nxt_blueCandy == goal) return 1;
    if (nxt_redCandy == goal) return 0;
    
    // 기울이기 전 구슬의 위치는 빈 공간으로
    board[redCandy.first][redCandy.second] = '.';
    board[blueCandy.first][blueCandy.second] = '.';

    // 구슬 이동
    board[nxt_redCandy.first][nxt_redCandy.second] = 'R';
    board[nxt_blueCandy.first][nxt_blueCandy.second] = 'B';

    
    
    return 3;

}

void backtracking(int cnt)
{
    if (cnt > 10)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int backupBoard[11][11];

        // backup
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                backupBoard[i][j] = board[i][j];

        if (tilt(i) == 0) ans = min(ans, cnt);
        else if (tilt(i) == 3) backtracking(cnt + 1);

        // restore
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = backupBoard[i][j];
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'O') goal = { i, j };
        }

    }

    backtracking(1);

    if (ans == numeric_limits<int>::max()) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}