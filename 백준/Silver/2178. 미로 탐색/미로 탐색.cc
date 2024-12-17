#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define X first
#define Y second

const int MAX_X = 101;
const int MAX_Y = 101;
int board[MAX_X][MAX_Y];
int dis[MAX_X][MAX_Y];
bool visit[MAX_X][MAX_Y];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	cin >> n >> m;
	for (int x = 1; x <= n; x++) {
		string str;
		cin >> str;
		for (int y = 1; y <= m; y++) {
			board[x][y] = ((int)str[y-1] - 48);
		}
	}
	

	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	visit[1][1] = true;
	dis[1][1] = 1;
	while (!Q.empty()) {
		
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (visit[nx][ny] == 1 || board[nx][ny] == 0) continue;
			Q.push({ nx, ny });
			visit[nx][ny] = true;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
		}
	}

	/*
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			cout << dis[x][y] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dis[n][m] << "\n";
	return 0;
}