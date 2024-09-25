// 1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김
// 2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
// 3. 해당 칸을 이미 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 큐에 삽입
// 4. 큐가 빌 때까지 2번을 반복. 모든 칸이 큐에 한 번씩 들어가므로 시간복잡도는 칸이 N개 일때 O(N)

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second


// 모든 파란색 칸을 순회하는 BFS
// 파란색 칸인 경우 1, 빨간색 칸인 경우 0
int board[502][502] = 
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
bool visit[502][502];

int n = 7, m = 10;
int dx[4] = { 0, 1, 0, -1 }; // x는 행
int dy[4] = { 1, 0 ,-1, 0 }; // y는 열

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<pair<int, int>> q;

	// 시작하는 칸은 이미 방문
	visit[0][0] = true;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			// board의 범위 밖인 경우 건너 뜀
			if (nx < 0 || ny < 0 || nx >= n, ny >= m) continue;
			// 이미 방문했거나, 파란색 칸이 아닌 경우는 건너 뜀
			if (visit[nx][ny] || board[nx][ny] != 1) continue;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	return 0;
}