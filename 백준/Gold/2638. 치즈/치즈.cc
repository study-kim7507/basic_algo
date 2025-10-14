// BOJ 2638. 치즈
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	int cheeseCount = 0;
	vector<vector<int>> boards(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> boards[i][j];
			if (boards[i][j] == 1) cheeseCount++;
		}
	}
		

	int time;
	for (time = 1; ; time++)
	{
		// 외부 공기, 내부 공기 분류
		vector<vector<bool>> exteriorAir(n, vector<bool>(m, false));
		queue<pair<int, int>> q;
		
		exteriorAir[0][0] = true;
		q.push({ 0, 0 });

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (boards[nx][ny] == 1) continue;
				if (exteriorAir[nx][ny]) continue;

				exteriorAir[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
		
		// 임시 보드
		vector<vector<int>> tempBoards(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tempBoards[i][j] = boards[i][j];


		// 치즈 녹이기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tempBoards[i][j] == 0) continue;

				int cnt = 0;	// 몇 개의 면이 외부 공기와 맞닿아 있는지 
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (tempBoards[nx][ny] == 1) continue;

					if (tempBoards[nx][ny] == 0 && exteriorAir[nx][ny] == true)
						cnt++;
				}

				if (cnt >= 2)
				{
					boards[i][j] = 0;
					cheeseCount--;
				}
			}
		}


		// 치즈가 다 놓은 경우 탈출
		if (cheeseCount == 0) 
			break;
	}

	std::cout << time << "\n";

	return 0;
}