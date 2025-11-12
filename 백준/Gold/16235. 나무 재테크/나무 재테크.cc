// BOJ_16235. 나무 재테크
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int a[11][11];														// 현재 각 칸에 추가되는 양분의 양
	int board[11][11];													// 현재 각 칸에 보관된 양분의 양
	vector<pair<int, bool>> tree[11][11];							    // 현재 각 칸의 살아있는 나무 및 살아있는지 여부


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			board[i][j] = 5;
		}
	}
		

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(make_pair(z, true));
	}

	for (int i = 0; i < k; i++)
	{
		// 1. 봄 : 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가함.
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				sort(tree[x][y].begin(), tree[x][y].end());
				for (int i = 0; i < tree[x][y].size(); i++)
				{
					if (board[x][y] >= tree[x][y][i].first)
					{
						board[x][y] -= tree[x][y][i].first;
						tree[x][y][i].first += 1;
					}
					else tree[x][y][i].second = false;
				}
			}
		}

		// 2. 여름 : 봄에 죽은 나무가 양분으로 변함. 각각의 죽은 나무의 나이를 2만큼 나눈 값 만큼 양분이 된다
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				while (!tree[x][y].empty())
				{
					if (tree[x][y].back().second == true) break;

					board[x][y] += (tree[x][y].back().first / 2);
					tree[x][y].pop_back();
				}
			}
		}

		// 3. 가을 : 나무가 번식
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				for (int i = 0; i < tree[x][y].size(); i++)
				{
					if (tree[x][y][i].first % 5 != 0) continue;

					for (int dir = 0; dir < 8; dir++)
					{
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
						tree[nx][ny].push_back(make_pair(1, true));
					}
				}
			}
		}

		// 4. 겨울 : 양분 추가
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= n; y++)
				board[x][y] += a[x][y];

	}

	int ans = 0;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			ans += tree[x][y].size();

	std::cout << ans << "\n";

	return 0;
}